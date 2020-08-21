/** @file
 *
 * This file is automatically generated.
 *
 */

#ifndef __FSPMUPD_H__
#define __FSPMUPD_H__

#include <FspUpd.h>

/** Fsp M Configuration
**/
typedef struct __packed {
	/** Offset 0x0040**/	uint32_t                    pci_express_base_addr;
	/** Offset 0x0044**/	uint32_t                    serial_port_base;
	/** Offset 0x0048**/	uint32_t                    serial_port_use_mmio;
	/** Offset 0x004C**/	uint32_t                    serial_port_stride;
	/** Offset 0x0050**/	uint32_t                    serial_port_baudrate;
	/** Offset 0x0054**/	uint32_t                    serial_port_refclk;
	/** Offset 0x0058**/	uint32_t                    telemetry_vddcr_vdd_slope;
	/** Offset 0x005C**/	uint32_t                    telemetry_vddcr_vdd_slope2;
	/** Offset 0x0060**/	uint32_t                    telemetry_vddcr_vdd_slope3;
	/** Offset 0x0064**/	uint32_t                    telemetry_vddcr_vdd_slope4;
	/** Offset 0x0068**/	uint32_t                    telemetry_vddcr_vdd_slope5;
	/** Offset 0x006C**/	uint32_t                    telemetry_vddcr_vdd_offset;
	/** Offset 0x0070**/	uint32_t                    telemetry_vddcr_soc_slope;
	/** Offset 0x0074**/	uint32_t                    telemetry_vddcr_soc_offset;
	/** Offset 0x0078**/	uint8_t                     aa_mode_en;
	/** Offset 0x0079**/	uint8_t                     unused2;
	/** Offset 0x007A**/	uint8_t                     unused3;
	/** Offset 0x007B**/	uint8_t                     unused4;
	/** Offset 0x007C**/	uint32_t                    fast_ppt_limit;
	/** Offset 0x0080**/	uint32_t                    slow_ppt_limit;
	/** Offset 0x0084**/	uint32_t                    slow_ppt_time_constant;
	/** Offset 0x0088**/	uint32_t                    psi0_current_limit;
	/** Offset 0x008C**/	uint32_t                    psi0_soc_current_limit;
	/** Offset 0x0090**/	uint32_t                    thermctl_limit;
	/** Offset 0x0094**/	uint32_t                    vrm_maximum_current_limit;
	/** Offset 0x0098**/	uint32_t                    vrm_soc_maximum_current_limit;
	/** Offset 0x009C**/	uint32_t                    sustained_power_limit;
	/** Offset 0x00A0**/	uint32_t                    stapm_time_constant;
	/** Offset 0x00A4**/	uint32_t                    prochot_l_deassertion_ramp_time;
	/** Offset 0x00A8**/	uint32_t                    vrm_current_limit;
	/** Offset 0x00AC**/	uint32_t                    vrm_soc_current_limit;
	/** Offset 0x00B0**/	uint32_t                    vddcr_soc_voltage_margin;
	/** Offset 0x00B4**/	uint32_t                    vddcr_vdd_voltage_margin;
	/** Offset 0x00B8**/	uint32_t                    smu_feature_control_defines;
	/** Offset 0x00BC**/	uint32_t                    smu_feature_control_defines_ext;
	/** Offset 0x00C0**/	uint8_t                     sb_tsi_alert_comparator_mode_en;
	/** Offset 0x00C1**/	uint8_t                     system_config;
	/** Offset 0x00C2**/	uint8_t                     core_dldo_bypass;
	/** Offset 0x00C3**/	uint8_t                     min_soc_vid_offset;
	/** Offset 0x00C4**/	uint8_t                     aclk_dpm0_freq_400MHz;
	/** Offset 0x00C5**/	uint8_t                     unused5;
	/** Offset 0x00C6**/	uint8_t                     unused6;
	/** Offset 0x00C7**/	uint8_t                     unused7;
	/** Offset 0x00C8**/	uint32_t                    tseg_size;
	/** Offset 0x00CC**/	uint8_t                     pspp_policy;
	/** Offset 0x00CD**/	uint8_t                     audio_soundwire;
	/** Offset 0x00CE**/	uint8_t                     hd_audio_enable;
	/** Offset 0x00CF**/	uint8_t                     unused9;
	/** Offset 0x00D0**/	uint32_t                    bert_size;
	/** Offset 0x00D4**/	uint8_t                     UnusedUpdSpace0;
	/** Offset 0x00D5**/	uint8_t                     ccx_down_core_mode;
	/** Offset 0x00D6**/	uint8_t                     ccx_disable_smt;
	/** Offset 0x00D7**/	uint8_t                     UnusedUpdSpace1[41];
	/** Offset 0x0100**/	uint16_t                    Reserved100;
	/** Offset 0x0102**/	uint16_t                    UpdTerminator;
} FSP_M_CONFIG;

/** Fsp M UPD Configuration
**/
typedef struct __packed {
	/** Offset 0x0000**/	FSP_UPD_HEADER              FspUpdHeader;
	/** Offset 0x0020**/	FSPM_ARCH_UPD               FspmArchUpd;
	/** Offset 0x0040**/	FSP_M_CONFIG                FspmConfig;
} FSPM_UPD;

#endif
