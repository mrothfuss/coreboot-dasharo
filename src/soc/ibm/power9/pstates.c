/* SPDX-License-Identifier: GPL-2.0-only */

#include "homer.h"
#include <cpu/power/mvpd.h>
#include <assert.h>
#include <lib.h>
#include <string.h>		// memcpy

#define IDDQ_MEASUREMENTS    6
#define MAX_UT_PSTATES       64     // Oversized
#define FREQ_STEP_KHZ        16666

#include "pstates_include/p9_pstates_occ.h"
#include "pstates_include/p9_pstates_pgpe.h"

#ifndef _BIG_ENDIAN
#error "_BIG_ENDIAN not defined"
#endif

/* Comes from p9_resclk_defines.H */
static const int resclk_freq_mhz[] =
     {0, 1500, 2000, 3000, 3400, 3700, 3900, 4100};

static ResonantClockingSetup resclk =
{
	{ },		// pstates - filled by code
	{  3,  3, 21, 23, 24, 22, 20, 19},	// idx
	{
		{0x2000}, {0x3000}, {0x1000}, {0x0000},
		{0x0010}, {0x0030}, {0x0020}, {0x0060},
		{0x0070}, {0x0050}, {0x0040}, {0x00C0},
		{0x00D0}, {0x00F0}, {0x00E0}, {0x00A0},
		{0x00B0}, {0x0090}, {0x0080}, {0x8080},
		{0x9080}, {0xB080}, {0xA080}, {0xE080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080},
		{0xF080}, {0xF080}, {0xF080}, {0xF080}
	},	// Array containing the transition steps
	0,		// Delay between steps (in nanoseconds)
	{ 0, 1, 3, 2},	// L3 clock stepping array
	580		// L3 voltage threshold
};

static void copy_poundW_v2_to_v3(PoundW_data_per_quad *v3, PoundW_data *v2)
{
	memset(v3, 0, sizeof(PoundW_data_per_quad));

	/* Copy poundW */
	for (int i = 0; i < NUM_OP_POINTS; i++) {
		v3->poundw[i].ivdd_tdp_ac_current_10ma =
		     v2->poundw[i].ivdd_tdp_ac_current_10ma;
		v3->poundw[i].ivdd_tdp_dc_current_10ma =
		     v2->poundw[i].ivdd_tdp_dc_current_10ma;
		v3->poundw[i].vdm_overvolt_small_thresholds =
		     v2->poundw[i].vdm_overvolt_small_thresholds;
		v3->poundw[i].vdm_large_extreme_thresholds =
		     v2->poundw[i].vdm_large_extreme_thresholds;
		v3->poundw[i].vdm_normal_freq_drop =
		     v2->poundw[i].vdm_normal_freq_drop;
		v3->poundw[i].vdm_normal_freq_return =
		     v2->poundw[i].vdm_normal_freq_return;
		v3->poundw[i].vdm_vid_compare_per_quad[0] =
		     v2->poundw[i].vdm_vid_compare_ivid;
		v3->poundw[i].vdm_vid_compare_per_quad[1] =
		     v2->poundw[i].vdm_vid_compare_ivid;
		v3->poundw[i].vdm_vid_compare_per_quad[2] =
		     v2->poundw[i].vdm_vid_compare_ivid;
		v3->poundw[i].vdm_vid_compare_per_quad[3] =
		     v2->poundw[i].vdm_vid_compare_ivid;
		v3->poundw[i].vdm_vid_compare_per_quad[4] =
		     v2->poundw[i].vdm_vid_compare_ivid;
		v3->poundw[i].vdm_vid_compare_per_quad[5] =
		     v2->poundw[i].vdm_vid_compare_ivid;
	}

	/* Copy resistance data */
	memcpy(&v3->resistance_data, &v2->resistance_data,
	       sizeof(v2->resistance_data));

	v3->resistance_data.r_undervolt_allowed = v2->undervolt_tested;
}

static void check_valid_poundV(struct voltage_bucket_data *bucket)
{
	struct voltage_data *data = &bucket->nominal;
	assert(bucket != NULL);

	for (int i = 0; i < NUM_OP_POINTS; i++) {	// skip powerbus
		if (data[i].freq == 0 || data[i].vdd_voltage == 0 ||
		    data[i].idd_current == 0 || data[i].vcs_voltage == 0 ||
		    data[i].ics_current == 0)
			die("Bad #V data\n");
	}
	// TODO: check if values increase with operating points
}

static void check_valid_poundW(PoundW_data_per_quad *poundW_bucket,
                               uint64_t functional_cores)
{
	uint8_t prev_vid_compare_per_quad[MAXIMUM_QUADS] = {};
	/*
	 * TODO: If the #W version is less than 3, validate Turbo VDM large
	 * threshold not larger than -32mV to filter out parts that have bad VPD.
	 */

	for (int op = 0; op < NUM_OP_POINTS; op++) {
		/* Assuming WOF is enabled - check that TDP VDD currents are nonzero */
		if (poundW_bucket->poundw[op].ivdd_tdp_ac_current_10ma == 0 ||
		    poundW_bucket->poundw[op].ivdd_tdp_dc_current_10ma == 0)
			die("TDP VDD current equals zero\n");

		/* Assuming VDM is enabled - validate threshold values */
		for (int quad = 0; quad < MAXIMUM_QUADS; quad++) {
			if (!IS_EQ_FUNCTIONAL(quad, functional_cores))
				continue;

			if (poundW_bucket->poundw[op].vdm_vid_compare_per_quad[quad] == 0)
				die("VID compare per quad is zero for quad %d\n", quad);

			if (poundW_bucket->poundw[op].vdm_vid_compare_per_quad[quad] <
			    prev_vid_compare_per_quad[quad])
				die("VID compare per quad is decreasing for quad %d\n", quad);

			prev_vid_compare_per_quad[quad] = 
			        poundW_bucket->poundw[op].vdm_vid_compare_per_quad[quad];
		}

		/* For threshold to be valid... */
		if (/* overvolt threshold must be <= 7 or == 0xC */
		    ((poundW_bucket->poundw[op].vdm_overvolt_small_thresholds & 0xF0)  > 0x70 &&
		     (poundW_bucket->poundw[op].vdm_overvolt_small_thresholds & 0xF0) != 0xC0) ||
		    /* small threshold must be != 8 and != 9 */
		    ((poundW_bucket->poundw[op].vdm_overvolt_small_thresholds & 0x0F) == 0x08 ||
		     (poundW_bucket->poundw[op].vdm_overvolt_small_thresholds & 0x0F) == 0x09) ||
		    /* large threshold must be != 8 and != 9 */
		    ((poundW_bucket->poundw[op].vdm_large_extreme_thresholds & 0xF0) == 0x80 ||
		     (poundW_bucket->poundw[op].vdm_large_extreme_thresholds & 0xF0) == 0x90) ||
		    /* extreme threshold must be != 8 and != 9 */
		    ((poundW_bucket->poundw[op].vdm_large_extreme_thresholds & 0x0F) == 0x08 ||
		     (poundW_bucket->poundw[op].vdm_large_extreme_thresholds & 0x0F) == 0x09) ||
		    /* N_L must be <= 7 */
		    (poundW_bucket->poundw[op].vdm_normal_freq_drop & 0x0F) > 7 ||
		    /* N_S must be <= N_L */
		    (((poundW_bucket->poundw[op].vdm_normal_freq_drop & 0xF0) >> 4) >
		     (poundW_bucket->poundw[op].vdm_normal_freq_drop & 0x0F)) ||
		    /* S_N must be <= N_S */
		    ((poundW_bucket->poundw[op].vdm_normal_freq_return & 0x0F) >
		     ((poundW_bucket->poundw[op].vdm_normal_freq_drop & 0xF0) >> 4)) ||
		    /* L_S must be <= N_L - S_N */
		    (((poundW_bucket->poundw[op].vdm_normal_freq_return & 0xF0) >> 4) >
		     ((poundW_bucket->poundw[op].vdm_normal_freq_drop & 0x0F) -
		      (poundW_bucket->poundw[op].vdm_normal_freq_return & 0x0F))))
			die("Bad #W threshold values\n");
	}
}

static void check_valid_iddq(IddqTable *iddq)
{
	if (iddq->iddq_version == 0               ||
	    iddq->good_quads_per_sort == 0        ||
	    iddq->good_normal_cores_per_sort == 0 ||
	    iddq->good_caches_per_sort == 0)
		die("Bad IDDQ data\n");

	for (int i = 0; i < IDDQ_MEASUREMENTS; i++) {
		if (iddq->ivdd_all_cores_off_caches_off[i] & 0x8000)
			iddq->ivdd_all_cores_off_caches_off[i] = 0;
	}
}

static inline
uint32_t sysp_mv_offset(uint32_t i_100ma, SysPowerDistParms sysparams)
{
	// 100mA*uOhm/10 -> uV
	return (i_100ma * (sysparams.loadline_uohm + sysparams.distloss_uohm) / 10 +
	        sysparams.distoffset_uv) / 1000;
}

static const
uint8_t grey_map [] =
{
    /*   0mV  0x00*/ 0,
    /* - 8mV  0x01*/ 1,
    /* -24mV  0x02*/ 3,
    /* -16mV  0x03*/ 2,
    /* -56mV  0x04*/ 7,
    /* -48mV  0x05*/ 6,
    /* -32mV  0x06*/ 4,
    /* -40mV  0x07*/ 5,
    /* -96mV  0x08*/ 12,
    /* -96mV  0x09*/ 12,
    /* -96mV  0x0a*/ 12,
    /* -96mV  0x0b*/ 12,
    /* -64mV  0x0c*/ 8,
    /* -72mV  0x0d*/ 9,
    /* -88mV  0x0e*/ 11,
    /* -80mV  0x0f*/ 10
};

static uint16_t calc_slope(uint32_t y1, uint32_t y0, uint32_t x1, uint32_t x0)
{
	uint32_t half = (x1 - x0) / 2;
	return (((y1 - y0) << 12) + half) / (x1 - x0);
}

static void calculate_slopes(GlobalPstateParmBlock *gppb,
                             PoundW_data_per_quad *pW)
{
	VpdOperatingPoint *ops = gppb->operating_points_set[VPD_PT_SET_BIASED];

	for (int op = 0; op < NUM_OP_POINTS; op++) {
		/*
		 * Even though vid_point_set doesn't have space for per-quad data,
		 * Hostboot still writes to the same field for each functional quad.
		  */
		gppb->vid_point_set[op] = pW->poundw[op].vdm_vid_compare_per_quad[0];

		gppb->threshold_set[op][VDM_OVERVOLT_INDEX] =
		   grey_map[(pW->poundw[op].vdm_overvolt_small_thresholds >> 4) & 0x0F];
		gppb->threshold_set[op][VDM_SMALL_INDEX] =
		   grey_map[pW->poundw[op].vdm_overvolt_small_thresholds  & 0x0F];
		gppb->threshold_set[op][VDM_LARGE_INDEX] =
		   grey_map[(pW->poundw[op].vdm_large_extreme_thresholds >> 4) & 0x0F];
		gppb->threshold_set[op][VDM_XTREME_INDEX] =
		   grey_map[pW->poundw[op].vdm_large_extreme_thresholds & 0x0F];

		gppb->jump_value_set[op][VDM_N_S_INDEX] =
		   (pW->poundw[op].vdm_normal_freq_drop >> 4) & 0x0F;
		gppb->jump_value_set[op][VDM_N_L_INDEX] =
		   pW->poundw[op].vdm_normal_freq_drop & 0x0F;
		gppb->jump_value_set[op][VDM_L_S_INDEX] =
		   (pW->poundw[op].vdm_normal_freq_return >> 4) & 0x0F;
		gppb->jump_value_set[op][VDM_S_N_INDEX] =
		   pW->poundw[op].vdm_normal_freq_return & 0x0F;
	}

	/* Slopes are saved in 4.12 fixed point format */
	for (int sl = 0; sl < VPD_NUM_SLOPES_REGION; sl++) {
		gppb->PsVIDCompSlopes[sl] = calc_slope(gppb->vid_point_set[sl+1],
		                                       gppb->vid_point_set[sl],
		                                       ops[sl].pstate,
		                                       ops[sl+1].pstate);

		for (int i = 0; i < NUM_THRESHOLD_POINTS; i++) {
			gppb->PsVDMThreshSlopes[sl][i] = calc_slope(gppb->threshold_set[sl+1][i],
			                                            gppb->threshold_set[sl][i],
			                                            ops[sl].pstate,
			                                            ops[sl+1].pstate);
		}

		for (int i = 0; i < NUM_JUMP_VALUES; i++) {
			gppb->PsVDMJumpSlopes[sl][i] = calc_slope(gppb->jump_value_set[sl+1][i],
			                                          gppb->jump_value_set[sl][i],
			                                          ops[sl].pstate,
			                                          ops[sl+1].pstate);
		}
	}

	#define OPS gppb->operating_points_set
	for (int set = 0; set < NUM_VPD_PTS_SET; set++) {
		for (int sl = 0; sl < VPD_NUM_SLOPES_REGION; sl++) {
			gppb->PStateVSlopes[set][sl] = calc_slope(OPS[set][sl+1].vdd_mv,
			                                          OPS[set][sl].vdd_mv,
			                                          OPS[set][sl].pstate,
			                                          OPS[set][sl+1].pstate);
			gppb->VPStateSlopes[set][sl] = calc_slope(OPS[set][sl].pstate,
			                                          OPS[set][sl+1].pstate,
			                                          OPS[set][sl+1].vdd_mv,
			                                          OPS[set][sl].vdd_mv);
		}
	}
	#undef OPS
}

static uint32_t calculate_sm_voltage(uint8_t sm_pstate,
                                     GlobalPstateParmBlock *gppb)
{
	int op = NUM_OP_POINTS - 1;
	VpdOperatingPoint *ops = gppb->operating_points_set[VPD_PT_SET_BIASED_SYSP];
	uint16_t *slopes = gppb->PStateVSlopes[VPD_PT_SET_BIASED_SYSP];

	while (op >= 0 && (ops[op].pstate < sm_pstate))
		op--;

	assert(ops[op].pstate >= sm_pstate);

	/* sm_pstate is somewhere between op and op+1 */
	return ops[op].vdd_mv + ((ops[op].pstate - sm_pstate) * slopes[op] >> 12);
}

/* resclk is always sorted */
static void update_resclk(int ref_freq_khz)
{
	uint8_t prev_idx = resclk.resclk_index[0];
	for (int i = 0; i < RESCLK_FREQ_REGIONS; i++) {
		if (resclk_freq_mhz[i] * 1000 > ref_freq_khz)
			break;

		/* If freq == 0 round pstate down - can't have negative frequency */
		if (resclk_freq_mhz[i] == 0) {
			resclk.resclk_freq[i] = ref_freq_khz / FREQ_STEP_KHZ;
			continue;
		}

		/* If freq > ref_freq - cap and use previous index */
		if (resclk_freq_mhz[i] * 1000 > ref_freq_khz) {
			resclk.resclk_freq[i] = 0;
			resclk.resclk_index[i] = prev_idx;
			continue;
		}

		/* Otherwise always round pstate up */
		resclk.resclk_freq[i] = (ref_freq_khz - resclk_freq_mhz[i] * 1000 +
		                         FREQ_STEP_KHZ - 1) / FREQ_STEP_KHZ;

		prev_idx = resclk.resclk_index[i];
	}
}

/* Assumption: no bias is applied to operating points */
void build_parameter_blocks(struct homer_st *homer, uint64_t functional_cores)
{
	uint8_t buf[512];
	uint32_t size = sizeof(buf);
	struct voltage_kwd *poundV = (struct voltage_kwd *)&buf;
	struct voltage_bucket_data *bucket = NULL;
	struct voltage_bucket_data poundV_bucket = {};
	PoundW_data_per_quad poundW_bucket = {};
	char record[] = "LRP0";
	struct cme_img_header *cme_hdr = (struct cme_img_header *)
	           &homer->cpmr.cme_sram_region[INT_VECTOR_SIZE];
	cme_hdr->pstate_offset = cme_hdr->core_spec_ring_offset +
	                         cme_hdr->max_spec_ring_len;
	cme_hdr->custom_length = ALIGN_UP(sizeof(LocalPstateParmBlock), 32) / 32 +
	                         cme_hdr->max_spec_ring_len;

	/*
	 * OCC Pstate Parameter Block and Global Pstate Parameter Block are filled
	 * directly in their final place as we go.
	 *
	 * Local Pstate Parameter Block in Hostboot uses an array with entry for
	 * each quad (note there are two CMEs per quad, those are written with the
	 * same entry). Nevertheless, data written to LPPB for each quad (and CME)
	 * is identical - the only field that could have per-quad data is VID comp,
	 * but it is filled with data for quad 0. It looks as if the code was made
	 * with anticipation of #W v3, but that version is not yet used.
	 *
	 * Here, we use CME 0 on quad 0 as a template that is filled as we go. This
	 * structure is then copied to other functional CMEs. Note that the first
	 * CME doesn't have to be functional, but always writing to its region is
	 * much easier than finding out proper source for memcpy later.
	 */
	OCCPstateParmBlock *oppb = (OCCPstateParmBlock *)homer->ppmr.occ_parm_block;
	GlobalPstateParmBlock *gppb = (GlobalPstateParmBlock *)
	           &homer->ppmr.pgpe_sram_img[homer->ppmr.header.hcode_len];
	LocalPstateParmBlock *lppb = (LocalPstateParmBlock *)
	           &homer->cpmr.cme_sram_region[cme_hdr->pstate_offset];

	/* OPPB - constant fields */

	oppb->magic = OCC_PARMSBLOCK_MAGIC; // "OCCPPB00"
	oppb->frequency_step_khz = FREQ_STEP_KHZ;
	oppb->wof.tdp_rdp_factor = 0; 	// ATTR_TDP_RDP_CURRENT_FACTOR 0 from talos.xml
	oppb->nest_leakage_percent = 60; // ATTR_NEST_LEAKAGE_PERCENT from hb_temp_defaults.xml

	/* FIXME: uncomment after WOF_DATA is prepared */
	//oppb->wof.wof_enabled = 1;		// Assuming wof_init() succeeds
	oppb->wof.tdp_rdp_factor = 0;		// ATTR_TDP_RDP_CURRENT_FACTOR from talos.xml
	oppb->nest_leakage_percent = 60;	// ATTR_NEST_LEAKAGE_PERCENT from hb_temp_defaults.xml
	/*
	 * As the Vdn dimension is not supported in the WOF tables, hardcoding this
	 * value to the OCC as non-zero to keep it happy.
	 */
	oppb->ceff_tdp_vdn = 1;

	/* Default values are from talos.xml */
	oppb->vdd_sysparm.loadline_uohm = 254;
	oppb->vdd_sysparm.distloss_uohm =   0;
	oppb->vdd_sysparm.distoffset_uv =   0;

	oppb->vcs_sysparm.loadline_uohm =   0;
	oppb->vcs_sysparm.distloss_uohm =  64;
	oppb->vcs_sysparm.distoffset_uv =   0;

	oppb->vdn_sysparm.loadline_uohm =   0;
	oppb->vdn_sysparm.distloss_uohm =  50;
	oppb->vdn_sysparm.distoffset_uv =   0;

	/* GPPB -constant fields */

	gppb->magic = PSTATE_PARMSBLOCK_MAGIC; // "PSTATE00"
	gppb->options.options = 0;
	gppb->frequency_step_khz = FREQ_STEP_KHZ;

	/*
	 * VpdBias External and Internal Biases for Global and Local parameter
	 * blocks - assumed no bias, filled with 0. HOMER was already cleared so
	 * no need to repeat it.
	 */

	/* Default values are from talos.xml */
	gppb->vdd_sysparm.loadline_uohm = 254;
	gppb->vdd_sysparm.distloss_uohm =   0;
	gppb->vdd_sysparm.distoffset_uv =   0;

	gppb->vcs_sysparm.loadline_uohm =   0;
	gppb->vcs_sysparm.distloss_uohm =  64;
	gppb->vcs_sysparm.distoffset_uv =   0;

	gppb->vdn_sysparm.loadline_uohm =   0;
	gppb->vdn_sysparm.distloss_uohm =  50;
	gppb->vdn_sysparm.distoffset_uv =   0;

	/* External VRM parameters - values are internal defaults */
	gppb->ext_vrm_transition_start_ns           =  8000;
	gppb->ext_vrm_transition_rate_inc_uv_per_us = 10000;
	gppb->ext_vrm_transition_rate_dec_uv_per_us = 10000;
	gppb->ext_vrm_stabilization_time_us         =     5;
	gppb->ext_vrm_step_size_mv                  =    50;

	/* WOV parameters - values are internal defaults */
	gppb->wov_sample_125us                =    2;
	gppb->wov_max_droop_pct               =  125;
	gppb->wov_underv_perf_loss_thresh_pct =    5;
	gppb->wov_underv_step_incr_pct        =    5;
	gppb->wov_underv_step_decr_pct        =    5;
	gppb->wov_underv_max_pct              =    0;
	gppb->wov_overv_vmax_mv               = 1150;
	gppb->wov_overv_step_incr_pct         =    5;
	gppb->wov_overv_step_decr_pct         =    5;
	gppb->wov_overv_max_pct               =  100;

	/* Avs Bus topology - values come from talos.xml */
	gppb->avs_bus_topology.vdd_avsbus_num  = 0;
	gppb->avs_bus_topology.vdd_avsbus_rail = 0;
	gppb->avs_bus_topology.vdn_avsbus_num  = 1;
	gppb->avs_bus_topology.vdn_avsbus_rail = 0;
	gppb->avs_bus_topology.vcs_avsbus_num  = 0;
	gppb->avs_bus_topology.vcs_avsbus_rail = 1;

	/* LPPB - constant fields */
	lppb->magic = LOCAL_PARMSBLOCK_MAGIC;		// "CMEPPB00"

	/* Default values are from talos.xml */
	lppb->vdd_sysparm.loadline_uohm = 254;
	lppb->vdd_sysparm.distloss_uohm =   0;
	lppb->vdd_sysparm.distoffset_uv =   0;


	/* Read and validate #V */

	for (int quad = 0; quad < MAXIMUM_QUADS; quad++) {
		if (!IS_EQ_FUNCTIONAL(quad, functional_cores))
			continue;

		record[3] = '0' + quad;
		if (!mvpd_extract_keyword(record, "#V", buf, &size)) {
			die("Failed to read %s record from MVPD", record);
		}

		assert(poundV->version == VOLTAGE_DATA_VERSION);
		assert(size >= sizeof(struct voltage_kwd));

		/*
		 * Q: How does Hostboot decide which bucket to use?
		 * A: It checks if bucket's PB freq equals PB freq saved in attribute.
		 * Q: Where does PB freq attribute value come from?
		 * A: #V - it is first non-zero value.
		 *
		 * Given that in any case we would have to iterate over all buckets,
		 * there is no need to read PB freq again.
		 */
		for (int i = 0; i < VOLTAGE_BUCKET_COUNT; i++) {
			if (poundV->buckets[i].powerbus.freq != 0) {
				bucket = &poundV->buckets[i];
				break;
			}
		}

		check_valid_poundV(bucket);

		if (poundV_bucket.id == 0) {
			memcpy(&poundV_bucket, bucket, sizeof(poundV_bucket));
			continue;
		}

		/* Frequencies must match */
		if (bucket->nominal.freq     != poundV_bucket.nominal.freq     ||
		    bucket->powersave.freq   != poundV_bucket.powersave.freq   ||
		    bucket->turbo.freq       != poundV_bucket.turbo.freq       ||
		    bucket->ultra_turbo.freq != poundV_bucket.ultra_turbo.freq ||
		    bucket->powerbus.freq    != poundV_bucket.powerbus.freq)
			die("Frequency mismatch in #V MVPD between quads\n");

		/*
		 * Voltages don't have to match, but we want to know the bucket ID for
		 * the highest voltage. Note: vdd_voltage in powerbus is actually VDN.
		 */
		if (bucket->nominal.vdd_voltage     > poundV_bucket.nominal.vdd_voltage     ||
		    bucket->powersave.vdd_voltage   > poundV_bucket.powersave.vdd_voltage   ||
		    bucket->turbo.vdd_voltage       > poundV_bucket.turbo.vdd_voltage       ||
		    bucket->ultra_turbo.vdd_voltage > poundV_bucket.ultra_turbo.vdd_voltage ||
		    bucket->powerbus.vdd_voltage    > poundV_bucket.powerbus.vdd_voltage)
			memcpy(&poundV_bucket, bucket, sizeof(poundV_bucket));
	}

	assert(poundV_bucket.id != 0);
	struct voltage_data *vd = &poundV_bucket.nominal;


	/* OPPB - #V data */

	/* Save UltraTurbo frequency as reference */
	oppb->frequency_max_khz = vd[VPD_PV_ULTRA].freq * 1000;
	oppb->nest_frequency_mhz = vd[VPD_PV_POWERBUS].freq;

	for (int op = 0; op < NUM_OP_POINTS; op++) {
		/* Assuming no bias */
		oppb->operating_points[op].frequency_mhz  = vd[op].freq;
		oppb->operating_points[op].vdd_mv         = vd[op].vdd_voltage;
		oppb->operating_points[op].idd_100ma      = vd[op].idd_current;
		oppb->operating_points[op].vcs_mv         = vd[op].vcs_voltage;
		oppb->operating_points[op].ics_100ma      = vd[op].ics_current;
		/* Integer math rounds pstates down (i.e. towards higher frequency) */
		oppb->operating_points[op].pstate =
		    (oppb->frequency_max_khz - vd[op].freq * 1000) / oppb->frequency_step_khz;
	}

	/* Sort operating points - swap power saving with nominal */
	{
		VpdOperatingPoint nom;
		nom = oppb->operating_points[VPD_PV_NOMINAL];
		oppb->operating_points[POWERSAVE] =
		     oppb->operating_points[VPD_PV_POWERSAVE];
		oppb->operating_points[NOMINAL] = nom;
	}

	/* GPPB - #V data */

	gppb->reference_frequency_khz = oppb->frequency_max_khz;
	gppb->nest_frequency_mhz = oppb->nest_frequency_mhz;
	/* This is Pstate value that would be assigned to frequency of 0 */
	gppb->dpll_pstate0_value = gppb->reference_frequency_khz /
	                           gppb->frequency_step_khz;

	update_resclk(gppb->reference_frequency_khz);
	memcpy(&gppb->resclk, &resclk, sizeof(ResonantClockingSetup));

	/*
	 * Global PPB VDM iVRM are set based on attributes, but all of them are by
	 * default 0. HOMER was memset to 0, so no need to do anything more.
	 *
	 * For Local PPBs, VDM is explicitly set to 0 even when attributes have
	 * different values. iVRM are still set based on attributes.
	 */

	memcpy(gppb->operating_points, oppb->operating_points,
	       sizeof(gppb->operating_points));
	{
		
		memcpy(gppb->operating_points_set[VPD_PT_SET_RAW], oppb->operating_points,
			   sizeof(gppb->operating_points));
		memcpy(gppb->operating_points_set[VPD_PT_SET_SYSP], oppb->operating_points,
			   sizeof(gppb->operating_points));
		/* Assuming no bias */
		memcpy(gppb->operating_points_set[VPD_PT_SET_BIASED],
			   oppb->operating_points, sizeof(gppb->operating_points));
		memcpy(gppb->operating_points_set[VPD_PT_SET_BIASED_SYSP],
			   oppb->operating_points, sizeof(gppb->operating_points));

		for (int op = 0; op < NUM_OP_POINTS; op++) {
			gppb->operating_points_set[VPD_PT_SET_SYSP][op].vdd_mv +=
			  sysp_mv_offset(gppb->operating_points_set[VPD_PT_SET_SYSP][op].idd_100ma,
			                 gppb->vdd_sysparm);
			gppb->operating_points_set[VPD_PT_SET_SYSP][op].vcs_mv +=
			  sysp_mv_offset(gppb->operating_points_set[VPD_PT_SET_SYSP][op].ics_100ma,
			                 gppb->vcs_sysparm);
			gppb->operating_points_set[VPD_PT_SET_BIASED_SYSP][op].vdd_mv +=
			  sysp_mv_offset(gppb->operating_points_set[VPD_PT_SET_BIASED_SYSP][op].idd_100ma,
			                 gppb->vdd_sysparm);
			gppb->operating_points_set[VPD_PT_SET_BIASED_SYSP][op].vcs_mv +=
			  sysp_mv_offset(gppb->operating_points_set[VPD_PT_SET_BIASED_SYSP][op].ics_100ma,
			                 gppb->vdd_sysparm);
		}
	}

	/* LPPB - #V data */

	/* LPPB has neither reference frequency nor step size, use GPPB values */
	lppb->dpll_pstate0_value = gppb->reference_frequency_khz /
	                           gppb->frequency_step_khz;
	memcpy(lppb->operating_points, oppb->operating_points,
	       sizeof(lppb->operating_points));
	memcpy(&lppb->resclk, &resclk, sizeof(ResonantClockingSetup));

	/*
	 * #W is in CRP0, there is no CRP1..5 for other quads. Format of #W:
	 * - Version:               1 byte
	 * - #V Bucket ID #1:       1 byte
	 * - VDM Data for bucket 1: varies by version
	 * - #V Bucket ID #2:       1 byte
	 * - ...
	 * - #V Bucket ID #6:       1 byte
	 * - VDM Data for bucket 6: varies by version
	 *
	 * Size of each VDM data (excluding bucket ID) by version:
	 * - 0x1 -     0x28 bytes
	 * - 0x2-0xF - 0x3C bytes
	 * - 0x30 -    0x87 bytes
	 *
	 * Following code supports the second and third version only.
	 *
	 * HOSTBUG: Hostboot reads #W for each (functional) quad, does all the
	 * parsing and then writes it to one output buffer, overwriting data written
	 * previously. As there is only one #W, this doesn't make any sense. It also
	 * first parses/writes, then tests if bucket ID even match.
	 */
	size = sizeof(buf);
	if (!mvpd_extract_keyword("CRP0", "#W", buf, &size)) {
		die("Failed to read %s record from MVPD", "CRP0");
	}

	if ((buf[0] < 0x2 || buf[0] > 0xF) && buf[0] != 0x30)
		die("Unsupported version (%#x) of #W MVPD\n", buf[0]);

	if (buf[0] == 0x30) {
		/* Version 3, just find proper bucket and copy data */
		assert(size >= 1 + VOLTAGE_BUCKET_COUNT *
		                   (1 + sizeof(PoundW_data_per_quad)));
		for (int i = 0; i < VOLTAGE_BUCKET_COUNT; i++) {
			/* Version + i * (bucket ID + bucket data) */
			int offset = 1 + i * (1 + sizeof(PoundW_data_per_quad));
			if (buf[offset] == poundV_bucket.id) {
				memcpy(&poundW_bucket, &buf[offset + 1], sizeof(poundW_bucket));
				break;
			}
		}
	}
	else {
		/* Version 2, different data size (0x3C) and format */
		/*
		 * HOSTBUG: we should be able to use sizeof(PoundW_data), but we can't.
		 * #W is packed in MVPD, but not in the type's definition.
		 */
		assert(size >= 1 + VOLTAGE_BUCKET_COUNT * (1 + 0x3C));
		for (int i = 0; i < VOLTAGE_BUCKET_COUNT; i++) {
			/* Version + i * (bucket ID + bucket data) */
			int offset = 1 + i * (1 + 0x3C);
			if (buf[offset] == poundV_bucket.id) {
				copy_poundW_v2_to_v3(&poundW_bucket,
				                     (PoundW_data *)&buf[offset + 1]);
				break;
			}
		}
	}

	/* Sort operating points - swap power saving with nominal */
	{
		poundw_entry_per_quad_t nom;
		nom = poundW_bucket.poundw[VPD_PV_NOMINAL];
		poundW_bucket.poundw[POWERSAVE] =
		        poundW_bucket.poundw[VPD_PV_POWERSAVE];
		poundW_bucket.poundw[NOMINAL] = nom;
	}

	check_valid_poundW(&poundW_bucket, functional_cores);


	/* OPPB - #W data */

	oppb->lac_tdp_vdd_turbo_10ma =
	         poundW_bucket.poundw[TURBO].ivdd_tdp_ac_current_10ma;
	oppb->lac_tdp_vdd_nominal_10ma =
	         poundW_bucket.poundw[NOMINAL].ivdd_tdp_ac_current_10ma;

	/* Calculate safe mode frequency/pstate/voltage */
	{
		/*
		 * Assumption: N_L values are the same for PS and N operating points.
		 * Not sure if this is always true so assert just in case.
		 *
		 * This makes calculation of jump value much easier.
		 */
		assert((poundW_bucket.poundw[POWERSAVE].vdm_normal_freq_drop & 0x0F) ==
		       (poundW_bucket.poundw[NOMINAL].vdm_normal_freq_drop & 0x0F));
		uint8_t jump_value =
		        poundW_bucket.poundw[POWERSAVE].vdm_normal_freq_drop & 0x0F;

		uint32_t sm_freq = (oppb->frequency_max_khz -
		                    (oppb->operating_points[POWERSAVE].pstate *
		                     oppb->frequency_step_khz))
		                   * 32 / (32 - jump_value);

		uint8_t sm_pstate = (oppb->frequency_max_khz - sm_freq) /
		                    oppb->frequency_step_khz;

		assert(sm_pstate < oppb->operating_points[POWERSAVE].pstate);

		oppb->pstate_min = sm_pstate;
		/* Reverse calculation to deal with rounding caused by integer math */
		oppb->frequency_min_khz = oppb->frequency_max_khz -
		                          sm_pstate * oppb->frequency_step_khz;

		assert(oppb->frequency_min_khz < oppb->frequency_max_khz);
	}

	/* GPPB - #W data */

	calculate_slopes(gppb, &poundW_bucket);
	gppb->safe_frequency_khz = oppb->frequency_min_khz;
	gppb->safe_voltage_mv = calculate_sm_voltage(oppb->pstate_min, gppb);
	gppb->wov_underv_vmin_mv = gppb->safe_voltage_mv;

	printk(BIOS_DEBUG, "Safe mode freq = %d kHZ, voltage = %d mv\n",
		   gppb->safe_frequency_khz, gppb->safe_voltage_mv);

	/* LPPB - #W data */
	/*
	 * This basically repeats calculate_slopes() for LPPB. Unfortunately, the
	 * structures aren't compatible.
	 */
	memcpy(lppb->vid_point_set, gppb->vid_point_set,
	       sizeof(lppb->vid_point_set));
	memcpy(lppb->threshold_set, gppb->threshold_set,
	       sizeof(lppb->threshold_set));
	memcpy(lppb->jump_value_set, gppb->jump_value_set,
	       sizeof(lppb->jump_value_set));
	memcpy(lppb->PsVIDCompSlopes, gppb->PsVIDCompSlopes,
	       sizeof(lppb->PsVIDCompSlopes));
	memcpy(lppb->PsVDMThreshSlopes, gppb->PsVDMThreshSlopes,
	       sizeof(lppb->PsVDMThreshSlopes));
	memcpy(lppb->PsVDMJumpSlopes, gppb->PsVDMJumpSlopes,
	       sizeof(lppb->PsVDMJumpSlopes));


	/*
	 * IDDQ - can't read straight to IddqTable, see comment before spare bytes
	 * in struct definition.
	 */
	size = sizeof(buf);
	if (!mvpd_extract_keyword("CRP0", "IQ", buf, &size)) {
		die("Failed to read %s record from MVPD", "CRP0");
	}
	assert(size >= sizeof(IddqTable));
	memcpy(&oppb->iddq, buf, sizeof(IddqTable));

	check_valid_iddq(&oppb->iddq);

	/*
	 * Pad was re-purposed, Hostboot developers created additional union. The
	 * new union is in the same header file, few lines above the structure, but
	 * the original field still uses 'uint32_t pad', instead of new type. This
	 * leads to the following monstrosity.
	 */
	((GPPBOptionsPadUse *)&gppb->options.pad)->fields.good_cores_in_sort =
	       oppb->iddq.good_normal_cores_per_sort;

	/* TODO: WOF */
	//~ // ----------------
	//~ // WOF initialization
	//~ // ----------------
	//~ wof_init(o_buf = &homer->ppmr.wof_tables):
		//~ - Search for proper data in WOFDATA PNOR partition
		//~ - WOFDATA is 3M, make sure CBFS_CACHE is big enough
		//~ - search until match is found:
		  //~ - core count
		  //~ - socket power (nominal, as read from #V)
		  //~ - frequency (nominal, as read from #V)
		  //~ - if version >= WOF_TABLE_VERSION_POWERMODE (2):
			//~ - mode matches current mode (WOF_MODE_NOMINAL = 1) or wildcard (WOF_MODE_UNKNOWN = 0)
		//~ - structures used:
		  //~ - wofImageHeader_t from plat_wof_access.C
			//~ - check magic and version
		  //~ - wofSectionTableEntry_t from plat_wof_access.C
		  //~ - WofTablesHeader_t from p9_pstates_common.h
		//~ memcpy(o_buf, &WofTablesHeader_t /* for found entry */, wofSectionTableEntry_t[found_entry_idx].size)

		//~ // Just the header, rest needs parsing
		//~ memcpy(homer->ppmr.wof_tables, o_buf, sizeof(WofTablesHeader_t))

		//~ for vfrt_index in 0..((WofTablesHeader_t*)o_buf->vdn_size * (WofTablesHeader_t*)o_buf->vdd_size * ACTIVE_QUADS) -1:
			//~ src = o_buf                  + sizeof(WofTablesHeader_t) + vfrt_index * 128 /* vRTF size */
			//~ dst = homer->ppmr.wof_tables + sizeof(WofTablesHeader_t) + vfrt_index * sizeof(HomerVFRTLayout_t) /* 256B */
			//~ update_vfrt (src, dst):
				//~ - Assumption: no bias, makes this function so much easier
				//~ // Data in src has 8B header followed by 5*24 bytes of frequency information, such that freq = value*step_size + 1GHz.
				//~ // Data in dst has (almost) the same header followed by 5*24 bytes of Pstates.
				//~ // Copy header
				//~ memcpy(dst, src, 8)
				//~ // Flip type from System to Homer
				//~ dst.type_version |= 0x10
				//~ assert(dst.magic = "VT")
				//~ for idx in 0..5*24 -1:
					//~ dst[8+idx] = freq_to_pstate(src[8+idx])		// rounded properly

	/* Copy LPPB to functional CMEs */
	for (int cme = 1; cme < MAX_CMES_PER_CHIP; cme++) {
		if (!IS_EX_FUNCTIONAL(cme, functional_cores))
			continue;

		memcpy(&homer->cpmr.cme_sram_region[cme * cme_hdr->custom_length * 32 +
		                                    cme_hdr->pstate_offset],
		       lppb, sizeof(LocalPstateParmBlock));
	}

	/* Finally, update headers */
	homer->ppmr.header.gppb_offset = homer->ppmr.header.hcode_offset +
	                                 homer->ppmr.header.hcode_len;
	homer->ppmr.header.gppb_len    = ALIGN_UP(sizeof(GlobalPstateParmBlock), 8);

	homer->ppmr.header.oppb_offset = offsetof(struct ppmr_st, occ_parm_block);
	homer->ppmr.header.oppb_len    = ALIGN_UP(sizeof(OCCPstateParmBlock), 8);

	/* Assuming >= CPMR_2.0 */
	homer->ppmr.header.lppb_offset = 0;
	homer->ppmr.header.lppb_len = 0;

	homer->ppmr.header.pstables_offset = offsetof(struct ppmr_st, pstate_table);
	homer->ppmr.header.pstables_len    = PSTATE_OUTPUT_TABLES_SIZE;	// 16 KiB

	homer->ppmr.header.wof_table_offset = OCC_WOF_TABLES_OFFSET;
	homer->ppmr.header.wof_table_len    = OCC_WOF_TABLES_SIZE;

	homer->ppmr.header.sram_img_size = homer->ppmr.header.hcode_len +
	                                   homer->ppmr.header.gppb_len;
}
