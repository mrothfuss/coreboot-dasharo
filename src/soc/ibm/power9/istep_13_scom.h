/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef ISTEP_13_SCOM_H
#define ISTEP_13_SCOM_H

#include <cpu/power/scom.h>

#define PSU_HOST_SBE_MBOX0_REG			0x000D0050
#define PSU_HOST_SBE_MBOX1_REG			0x000D0051

#define PSU_SBE_DOORBELL_REG				0x000D0060
#define PSU_SBE_DOORBELL_REG_WAND			0x000D0061
#define PSU_SBE_DOORBELL_REG_WOR			0x000D0062
#define PSU_HOST_DOORBELL_REG				0x000D0063
#define PSU_HOST_DOORBELL_REG_WAND			0x000D0064
#define PSU_HOST_DOORBELL_REG_WOR			0x000D0065

#define MCD0_FIR_MASK_REG				0x03011003
#define MCD1_FIR_MASK_REG				0x03011403

#define NEST_CPLT_CTRL1				0x05000001

#define MCSLOW_CPLT_CTRL0				0x07000000
#define MCSLOW_CPLT_CTRL0_WOR				0x07000010
#define MCSLOW_CPLT_CTRL0_WCLEAR			0x07000020
#define MCSLOW_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC	0
#define MCSLOW_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC	1
#define MCSLOW_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC	2
#define MCSLOW_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC	3

#define MCSLOW_CPLT_CTRL1				0x07000001
#define MCSLOW_CPLT_CTRL1_WOR				0x07000011
#define MCSLOW_CPLT_CTRL1_WCLEAR			0x07000021

#define MCSLOW_CPLT_CONF0				0x07000008

#define MCSLOW_CPLT_STAT0				0x07000100
#define MCSLOW_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC	8
#define MCSLOW_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC	9

#define MBACALFIR					0x07010900
#define MBACALFIR_MASK					0x07010903
#define MBACALFIR_ACTION0				0x07010906
#define MBACALFIR_ACTION1				0x07010907
#define MBACALFIR_MBA_RECOVERABLE_ERROR		0
#define MBACALFIR_MBA_NONRECOVERABLE_ERROR		1
#define MBACALFIR_REFRESH_OVERRUN			2
#define MBACALFIR_RCD_PARITY_ERROR			4
#define MBACALFIR_DDR_CAL_TIMEOUT_ERR			5
#define MBACALFIR_DDR_CAL_RESET_TIMEOUT		7
#define MBACALFIR_DDR_MBA_EVENT_N			8
#define MBACALFIR_WRQ_RRQ_HANG_ERR			9
#define MBACALFIR_SM_1HOT_ERR				10
#define MBACALFIR_ASYNC_IF_ERROR			11
#define MBACALFIR_CMD_PARITY_ERROR			12
#define MBACALFIR_PORT_FAIL				13
#define MBACALFIR_RCD_CAL_PARITY_ERROR		14

#define MBA_DSM0Q					0x0701090A
#define MBA_DSM0Q_CFG_RODT_START_DLY			0
#define MBA_DSM0Q_CFG_RODT_START_DLY_LEN		6
#define MBA_DSM0Q_CFG_RODT_END_DLY			6
#define MBA_DSM0Q_CFG_RODT_END_DLY_LEN			6
#define MBA_DSM0Q_CFG_WODT_START_DLY			12
#define MBA_DSM0Q_CFG_WODT_START_DLY_LEN		6
#define MBA_DSM0Q_CFG_WODT_END_DLY			18
#define MBA_DSM0Q_CFG_WODT_END_DLY_LEN			6
#define MBA_DSM0Q_CFG_WRDONE_DLY			24
#define MBA_DSM0Q_CFG_WRDONE_DLY_LEN			6
#define MBA_DSM0Q_CFG_WRDATA_DLY			30
#define MBA_DSM0Q_CFG_WRDATA_DLY_LEN			6
#define MBA_DSM0Q_CFG_RDTAG_DLY				36
#define MBA_DSM0Q_CFG_RDTAG_DLY_LEN			6

#define MBA_TMR0Q					0x0701090B
#define MBA_TMR0Q_RRDM_DLY				0
#define MBA_TMR0Q_RRDM_DLY_LEN				4
#define MBA_TMR0Q_RRSMSR_DLY				4
#define MBA_TMR0Q_RRSMSR_DLY_LEN			4
#define MBA_TMR0Q_RRSMDR_DLY				8
#define MBA_TMR0Q_RRSMDR_DLY_LEN			4
#define MBA_TMR0Q_RROP_DLY				12
#define MBA_TMR0Q_RROP_DLY_LEN				4
#define MBA_TMR0Q_WWDM_DLY				16
#define MBA_TMR0Q_WWDM_DLY_LEN				4
#define MBA_TMR0Q_WWSMSR_DLY				20
#define MBA_TMR0Q_WWSMSR_DLY_LEN			4
#define MBA_TMR0Q_WWSMDR_DLY				24
#define MBA_TMR0Q_WWSMDR_DLY_LEN			4
#define MBA_TMR0Q_WWOP_DLY				28
#define MBA_TMR0Q_WWOP_DLY_LEN				4
#define MBA_TMR0Q_RWDM_DLY				32
#define MBA_TMR0Q_RWDM_DLY_LEN				5
#define MBA_TMR0Q_RWSMSR_DLY				37
#define MBA_TMR0Q_RWSMSR_DLY_LEN			5
#define MBA_TMR0Q_RWSMDR_DLY				42
#define MBA_TMR0Q_RWSMDR_DLY_LEN			5
#define MBA_TMR0Q_WRDM_DLY				47
#define MBA_TMR0Q_WRDM_DLY_LEN				4
#define MBA_TMR0Q_WRSMSR_DLY				51
#define MBA_TMR0Q_WRSMSR_DLY_LEN			6
#define MBA_TMR0Q_WRSMDR_DLY				57
#define MBA_TMR0Q_WRSMDR_DLY_LEN			6

#define MBA_TMR1Q					0x0701090C
#define MBA_TMR1Q_RRSBG_DLY				0
#define MBA_TMR1Q_RRSBG_DLY_LEN				4
#define MBA_TMR1Q_WRSBG_DLY				4
#define MBA_TMR1Q_WRSBG_DLY_LEN				6
#define MBA_TMR1Q_CFG_TFAW				10
#define MBA_TMR1Q_CFG_TFAW_LEN				6
#define MBA_TMR1Q_CFG_TRCD				16
#define MBA_TMR1Q_CFG_TRCD_LEN				5
#define MBA_TMR1Q_CFG_TRP				21
#define MBA_TMR1Q_CFG_TRP_LEN				5
#define MBA_TMR1Q_CFG_TRAS				26
#define MBA_TMR1Q_CFG_TRAS_LEN				6
#define MBA_TMR1Q_CFG_WR2PRE				41
#define MBA_TMR1Q_CFG_WR2PRE_LEN			7
#define MBA_TMR1Q_CFG_RD2PRE				48
#define MBA_TMR1Q_CFG_RD2PRE_LEN			4
#define MBA_TMR1Q_TRRD					52
#define MBA_TMR1Q_TRRD_LEN				4
#define MBA_TMR1Q_TRRD_SBG				56
#define MBA_TMR1Q_TRRD_SBG_LEN				4
#define MBA_TMR1Q_CFG_ACT_TO_DIFF_RANK_DLY		60
#define MBA_TMR1Q_CFG_ACT_TO_DIFF_RANK_DLY_LEN		4

#define MBA_WRQ0Q					0x0701090D
#define MBA_WRQ0Q_CFG_WRQ_FIFO_MODE			5
#define MBA_WRQ0Q_CFG_WRQ_FIFO_MODE_LEN			1
#define MBA_WRQ0Q_CFG_DISABLE_WR_PG_MODE		6
#define MBA_WRQ0Q_CFG_WRQ_ACT_NUM_WRITES_PENDING	55
#define MBA_WRQ0Q_CFG_WRQ_ACT_NUM_WRITES_PENDING_LEN	4

#define MBA_RRQ0Q					0x0701090E
#define MBA_RRQ0Q_CFG_RRQ_FIFO_MODE			6
#define MBA_RRQ0Q_CFG_RRQ_FIFO_MODE_LEN			1
#define MBA_RRQ0Q_CFG_RRQ_ACT_NUM_READS_PENDING		57
#define MBA_RRQ0Q_CFG_RRQ_ACT_NUM_READS_PENDING_LEN	4

#define MBA_CAL0Q					0x0701090F
#define MBA_CAL0Q_RESET_RECOVER			57

#define MBA_CAL3Q					0x07010912

#define MBA_FARB0Q					0x07010913
#define MBA_FARB0Q_CFG_2N_ADDR			17
#define MBA_FARB0Q_CFG_PARITY_AFTER_CMD		38
#define MBA_FARB0Q_CFG_RCD_PROTECTION_TIME		48
#define MBA_FARB0Q_CFG_RCD_PROTECTION_TIME_LEN		6
#define MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY		54
#define MBA_FARB0Q_CFG_OE_ALWAYS_ON			55
#define MBA_FARB0Q_CFG_PORT_FAIL_DISABLE		57
#define MBA_FARB0Q_CFG_OPT_RD_SIZE			61
#define MBA_FARB0Q_CFG_OPT_RD_SIZE_LEN			3

#define MBA_FARB1Q					0x07010914
#define MBA_FARB1Q_CFG_SLOT0_S0_CID			0
#define MBA_FARB1Q_CFG_SLOT0_S1_CID			3
#define MBA_FARB1Q_CFG_SLOT0_S2_CID			6
#define MBA_FARB1Q_CFG_SLOT0_S3_CID			9
#define MBA_FARB1Q_CFG_SLOT0_S4_CID			12
#define MBA_FARB1Q_CFG_SLOT0_S5_CID			15
#define MBA_FARB1Q_CFG_SLOT0_S6_CID			18
#define MBA_FARB1Q_CFG_SLOT0_S7_CID			21
#define MBA_FARB1Q_CFG_SLOT1_S0_CID			24
#define MBA_FARB1Q_CFG_SLOT1_S1_CID			27
#define MBA_FARB1Q_CFG_SLOT1_S2_CID			30
#define MBA_FARB1Q_CFG_SLOT1_S3_CID			33
#define MBA_FARB1Q_CFG_SLOT1_S4_CID			36
#define MBA_FARB1Q_CFG_SLOT1_S5_CID			39
#define MBA_FARB1Q_CFG_SLOT1_S6_CID			42
#define MBA_FARB1Q_CFG_SLOT1_S7_CID			45

#define MBA_FARB2Q					0x07010915
#define MBA_FARB2Q_CFG_RANK0_RD_ODT			0
#define MBA_FARB2Q_CFG_RANK0_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK1_RD_ODT			4
#define MBA_FARB2Q_CFG_RANK1_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK2_RD_ODT			8
#define MBA_FARB2Q_CFG_RANK2_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK3_RD_ODT			12
#define MBA_FARB2Q_CFG_RANK3_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK4_RD_ODT			16
#define MBA_FARB2Q_CFG_RANK4_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK5_RD_ODT			20
#define MBA_FARB2Q_CFG_RANK5_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK6_RD_ODT			24
#define MBA_FARB2Q_CFG_RANK6_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK7_RD_ODT			28
#define MBA_FARB2Q_CFG_RANK7_RD_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK0_WR_ODT			32
#define MBA_FARB2Q_CFG_RANK0_WR_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK1_WR_ODT			36
#define MBA_FARB2Q_CFG_RANK1_WR_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK2_WR_ODT			40
#define MBA_FARB2Q_CFG_RANK2_WR_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK3_WR_ODT			44
#define MBA_FARB2Q_CFG_RANK3_WR_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK4_WR_ODT			48
#define MBA_FARB2Q_CFG_RANK4_WR_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK5_WR_ODT			52
#define MBA_FARB2Q_CFG_RANK5_WR_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK6_WR_ODT			56
#define MBA_FARB2Q_CFG_RANK6_WR_ODT_LEN			4
#define MBA_FARB2Q_CFG_RANK7_WR_ODT			60
#define MBA_FARB2Q_CFG_RANK7_WR_ODT_LEN			4

#define MBA_FARB3Q					0x07010916
#define MBA_FARB3Q_CFG_NM_N_PER_SLOT			0
#define MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN		15
#define MBA_FARB3Q_CFG_NM_N_PER_PORT			15
#define MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN		16
#define MBA_FARB3Q_CFG_NM_M				31
#define MBA_FARB3Q_CFG_NM_M_LEN				14
#define MBA_FARB3Q_CFG_NM_RAS_WEIGHT			47
#define MBA_FARB3Q_CFG_NM_CAS_WEIGHT			48
#define MBA_FARB3Q_CFG_NM_CAS_WEIGHT_LEN		3
#define MBA_FARB3Q_CFG_NM_CHANGE_AFTER_SYNC		53

#define MBA_FARB4Q					0x07010917
#define MBA_FARB4Q_EMERGENCY_N				27
#define MBA_FARB4Q_EMERGENCY_N_LEN			15
#define MBA_FARB4Q_EMERGENCY_M				42
#define MBA_FARB4Q_EMERGENCY_M_LEN			14

#define MBA_FARB5Q					0x07010918
#define MBA_FARB5Q_CFG_DDR_DPHY_NCLK			0
#define MBA_FARB5Q_CFG_DDR_DPHY_NCLK_LEN		2
#define MBA_FARB5Q_CFG_DDR_DPHY_PCLK			2
#define MBA_FARB5Q_CFG_DDR_DPHY_PCLK_LEN		2
#define MBA_FARB5Q_CFG_DDR_RESETN			4
#define MBA_FARB5Q_CFG_CCS_ADDR_MUX_SEL		5
#define MBA_FARB5Q_CFG_CCS_INST_RESET_ENABLE		6
#define MBA_FARB5Q_CFG_FORCE_MCLK_LOW_N		8

#define MBAREF0Q					0x07010932
#define MBAREF0Q_CFG_REFRESH_ENABLE			0
#define MBAREF0Q_CFG_REFRESH_PRIORITY_THRESHOLD		5
#define MBAREF0Q_CFG_REFRESH_PRIORITY_THRESHOLD_LEN	3
#define MBAREF0Q_CFG_REFRESH_INTERVAL			8
#define MBAREF0Q_CFG_REFRESH_INTERVAL_LEN		11
#define MBAREF0Q_CFG_TRFC				30
#define MBAREF0Q_CFG_TRFC_LEN				10
#define MBAREF0Q_CFG_REFR_TSV_STACK			40
#define MBAREF0Q_CFG_REFR_TSV_STACK_LEN			10
#define MBAREF0Q_CFG_REFR_CHECK_INTERVAL		50
#define MBAREF0Q_CFG_REFR_CHECK_INTERVAL_LEN		11

#define MBARPC0Q					0x07010934
#define MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE		2
#define MBARPC0Q_CFG_MIN_MAX_DOMAINS			5
#define MBARPC0Q_CFG_PUP_AVAIL				6
#define MBARPC0Q_CFG_PUP_AVAIL_LEN			5
#define MBARPC0Q_CFG_PDN_PUP				11
#define MBARPC0Q_CFG_PDN_PUP_LEN			5
#define MBARPC0Q_CFG_PUP_PDN				16
#define MBARPC0Q_CFG_PUP_PDN_LEN			5
#define MBARPC0Q_RESERVED_21				21
#define MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_ENABLE	22
#define MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_TIME		23
#define MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_TIME_LEN	10

#define MBASTR0Q					0x07010935
#define MBASTR0Q_CFG_STR_ENABLE				0
#define MBASTR0Q_CFG_ENTER_STR_TIME			2
#define MBASTR0Q_CFG_ENTER_STR_TIME_LEN			10
#define MBASTR0Q_CFG_TCKESR				12
#define MBASTR0Q_CFG_TCKESR_LEN				5
#define MBASTR0Q_CFG_TCKSRE				17
#define MBASTR0Q_CFG_TCKSRE_LEN				5
#define MBASTR0Q_CFG_TCKSRX				22
#define MBASTR0Q_CFG_TCKSRX_LEN				5
#define MBASTR0Q_CFG_TXSDLL				27
#define MBASTR0Q_CFG_TXSDLL_LEN				11
#define MBASTR0Q_CFG_SAFE_REFRESH_INTERVAL		46
#define MBASTR0Q_CFG_SAFE_REFRESH_INTERVAL_LEN		11

#define ECC_FIR_MASK					0x07010A03
#define ECC_FIR_ACTION0				0x07010A06
#define ECC_FIR_ACTION1				0x07010A07
#define FIR_MAINLINE_AUE				13
#define FIR_MAINLINE_UE				14
#define FIR_MAINLINE_RCD				15
#define FIR_MAINLINE_IAUE				16
#define FIR_MAINLINE_IUE				17
#define ECC_FIR_MAINTENANCE_AUE			33
#define ECC_FIR_MAINTENANCE_IAUE			36
#define MCA_FIR_MAINTENANCE_IUE			37
#define ECC_FIR_SCOM_PARITY_CLASS_STATUS		41
#define ECC_FIR_SCOM_PARITY_CLASS_RECOVERABLE		42
#define ECC_FIR_WRITE_RMW_CE				45

#define RECR						0x07010A0A
#define MBSECCQ_DISABLE_MEMORY_ECC_CHECK_CORRECT	0
#define MBSECCQ_DISABLE_MEMORY_ECC_CORRECT		1
#define MBSECCQ_READ_POINTER_DELAY			6
#define MBSECCQ_READ_POINTER_DELAY_LEN			3
#define MBSECCQ_VAL_TO_DATA_DELAY			16
#define MBSECCQ_VAL_TO_DATA_DELAY_LEN			3
#define MBSECCQ_DELAY_VALID_1X				19
#define MBSECCQ_NEST_VAL_TO_DATA_DELAY			20
#define MBSECCQ_NEST_VAL_TO_DATA_DELAY_LEN		2
#define MBSECCQ_DELAY_NONBYPASS				22
#define MBSECCQ_ENABLE_UE_NOISE_WINDOW			26
#define MBSECCQ_ENABLE_TCE_CORRECTION			27
#define MBSECCQ_USE_ADDRESS_HASH			29
#define MBSECCQ_DATA_INVERSION				30
#define MBSECCQ_DATA_INVERSION_LEN			2
#define MBSECCQ_RESERVED_40				40

#define DBGR						0x07010A0B
#define DBGR_ECC_WAT_ACTION_SELECT			9
#define DBGR_ECC_WAT_SOURCE				11

#define FWMS0						0x07010A18

#define AACR						0x07010A29
#define AACR_ADDRESS					1
#define AACR_ADDRESS_LEN       				9
#define AACR_AUTOINC					10
#define AACR_ECCGEN					11

#define AADR						0x07010A2A
#define AAER						0x07010A2B

#define WRTCFG						0x07010A38

#define IOM_PHY0_DDRPHY_FIR_REG			0x07011000
#define IOM_PHY0_DDRPHY_FIR_MASK_REG			0x07011003
#define IOM_PHY0_DDRPHY_FIR_ACTION0_REG		0x07011006
#define IOM_PHY0_DDRPHY_FIR_ACTION1_REG		0x07011007
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_0	54
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_1	55
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_2	56
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_3	57
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_4	58
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_5	59
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_6	60
#define IOM_PHY0_DDRPHY_FIR_REG_DDR_FIR_ERROR_7	61

#define MCBISTFIR					0x07012300
#define MCBISTFIRMASK					0x07012303
#define MCBISTFIRACT0					0x07012306
#define MCBISTFIRACT1					0x07012307
#define MCBISTFIRQ_COMMAND_ADDRESS_TIMEOUT		1
#define MCBISTFIRQ_INTERNAL_FSM_ERROR			2
#define MCBISTFIRQ_MCBIST_BRODCAST_OUT_OF_SYNC	3
#define MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE		10
#define MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE		13
#define MCBISTFIRQ_SCOM_FATAL_REG_PE			14

#define CCS_INST_ARR0_00				0x07012315
#define CCS_INST_ARR0_00_CCS_DDR_ACTN			20
#define CCS_INST_ARR0_00_CCS_DDR_CKE			24
#define CCS_INST_ARR0_00_CCS_DDR_CKE_LEN		4
#define CCS_INST_ARR0_00_CCS_DDR_CSN_0_1		32
#define CCS_INST_ARR0_00_CCS_DDR_CSN_0_1_LEN		2
#define CCS_INST_ARR0_00_CCS_DDR_CSN_2_3		36
#define CCS_INST_ARR0_00_CCS_DDR_CSN_2_3_LEN		2
#define CCS_INST_ARR0_00_CCS_DDR_CAL_TYPE		56
#define CCS_INST_ARR0_00_CCS_DDR_CAL_TYPE_LEN		4

#define CCS_INST_ARR1_00				0x07012335
#define CCS_INST_ARR1_00_IDLES				0
#define CCS_INST_ARR1_00_IDLES_LEN			16
#define CCS_INST_ARR1_00_DDR_CAL_RANK			53
#define CCS_INST_ARR1_00_DDR_CAL_RANK_LEN		4
#define CCS_INST_ARR1_00_DDR_CALIBRATION_ENABLE		57
#define CCS_INST_ARR1_00_CCS_END			58
#define CCS_INST_ARR1_00_GOTO_CMD			59
#define CCS_INST_ARR1_00_GOTO_CMD_LEN			5

#define MBSEC0Q					0x07012355
#define MBSEC1Q					0x07012356

#define MBSTRQ						0x07012357
#define MBSTRQ_CFG_PAUSE_ON_MPE			34
#define MBSTRQ_CFG_PAUSE_ON_UE			35
#define MBSTRQ_CFG_PAUSE_ON_AUE			37
#define MBSTRQ_CFG_NCE_SOFT_SYMBOL_COUNT_ENABLE	55
#define MBSTRQ_CFG_NCE_INTER_SYMBOL_COUNT_ENABLE	56
#define MBSTRQ_CFG_NCE_HARD_SYMBOL_COUNT_ENABLE	57

#define MCBSTATQ					0x07012366

#define WATCFG0AQ					0x07012380
#define WATCFG0AQ_CFG_WAT_EVENT_SEL			0
#define WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN			48

#define WATCFG0BQ					0x07012381
#define WATCFG0BQ_CFG_WAT_MSKA				0
#define WATCFG0BQ_CFG_WAT_MSKA_LEN			44
#define WATCFG0BQ_CFG_WAT_CNTL				44
#define WATCFG0BQ_CFG_WAT_CNTL_LEN			17

#define WATCFG0DQ					0x07012383
#define WATCFG0DQ_CFG_WAT_PATA				0
#define WATCFG0DQ_CFG_WAT_PATA_LEN			44

#define WATCFG3AQ					0x0701238F
#define WATCFG3AQ_CFG_WAT_EVENT_SEL			0
#define WATCFG3AQ_CFG_WAT_EVENT_SEL_LEN			48

#define WATCFG3BQ					0x07012390
#define WATCFG3BQ_CFG_WAT_MSKA				0
#define WATCFG3BQ_CFG_WAT_MSKA_LEN			44
#define WATCFG3BQ_CFG_WAT_CNTL				44
#define WATCFG3BQ_CFG_WAT_CNTL_LEN			17

#define CCS_CNTLQ					0x070123A5
#define CCS_CNTLQ_CCS_START				0
#define CCS_CNTLQ_CCS_STOP				1

#define CCS_STATQ					0x070123A6
#define CCS_STATQ_CCS_IP				0
#define CCS_STATQ_CCS_DONE				1

#define CCS_MODEQ					0x070123A7
#define CCS_MODEQ_CCS_STOP_ON_ERR			0
#define CCS_MODEQ_CCS_UE_DISABLE			1
#define CCS_MODEQ_DDR_CAL_TIMEOUT_CNT			8
#define CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_LEN		16
#define CCS_MODEQ_CFG_CCS_PARITY_AFTER_CMD		24
#define CCS_MODEQ_COPY_CKE_TO_SPARE_CKE			26
#define CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_MULT		30
#define CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_MULT_LEN		2

#define MCBMR0Q					0x070123A8

#define MCBPARMQ					0x070123AF

#define MCBDRSRQ					0x070123BC
#define MCBDRCRQ					0x070123BD
#define MCBFD0Q					0x070123BE

#define MCBSA0Q					0x070123CC
#define MCBEA0Q					0x070123CE

#define MCBAGRAQ					0x070123D6
#define MCBAGRAQ_CFG_MAINT_ADDR_MODE_EN		10
#define MCBAGRAQ_CFG_MAINT_DETECT_SRANK_BOUNDARIES	12

#define MCB_CNTLQ					0x070123DB
#define MCB_CNTLQ_MCB_START				0

#define MCB_CNTLSTATQ					0x070123DC
#define MCB_CNTLSTATQ_MCB_IP				0
#define MCB_CNTLSTATQ_MCB_DONE			1
#define MCB_CNTLSTATQ_MCB_FAIL			2

#define MCBCFGQ					0x070123E0
#define MCBCFGQ_CFG_LOG_COUNTS_IN_TRACE		36
#define MCBCFGQ_CFG_PAUSE_ON_ERROR_MODE		57
#define MCBCFGQ_CFG_PAUSE_ON_ERROR_MODE_LEN	2

#define DBGCFG0Q					0x070123E8
#define DBGCFG0Q_CFG_DBG_ENABLE				0
#define DBGCFG0Q_CFG_DBG_PICK_MCBIST01			23
#define DBGCFG0Q_CFG_DBG_PICK_MCBIST01_LEN		11

#define DBGCFG1Q					0x070123E9
#define DBGCFG1Q_CFG_WAT_ENABLE			0

#define DBGCFG2Q					0x070123EA
#define DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL			0
#define DBGCFG2Q_CFG_WAT_LOC_EVENT0_SEL_LEN		20
#define DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL			20
#define DBGCFG2Q_CFG_WAT_LOC_EVENT1_SEL_LEN		20

#define DBGCFG3Q					0x070123EB
#define DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL		20
#define DBGCFG3Q_CFG_WAT_GLOB_EVENT0_SEL_LEN		3
#define DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL		23
#define DBGCFG3Q_CFG_WAT_GLOB_EVENT1_SEL_LEN		3
#define DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE		37
#define DBGCFG3Q_CFG_WAT_ACT_SET_SPATTN_PULSE_LEN	4

#define MCSLOW_SYNC_CONFIG				0x07030000
#define MCSLOW_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS	4
#define MCSLOW_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED	7

#define MCSLOW_OPCG_ALIGN				0x07030001
#define MCSLOW_OPCG_ALIGN_INOP_ALIGN			0
#define MCSLOW_OPCG_ALIGN_INOP_ALIGN_LEN		4
#define MCSLOW_OPCG_ALIGN_INOP_WAIT			19
#define MCSLOW_OPCG_ALIGN_SCAN_RATIO			47
#define MCSLOW_OPCG_ALIGN_SCAN_RATIO_LEN		5
#define MCSLOW_OPCG_ALIGN_OPCG_WAIT_CYCLES		52
#define MCSLOW_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN		12

#define MCSLOW_OPCG_REG0				0x07030002
#define MCSLOW_OPCG_RUNN_MODE				0
#define MCSLOW_OPCG_RUN_SCAN0				2

#define MCSLOW_SCAN_REGION_TYPE			0x07030005
#define MCSLOW_SCAN_REGION_TYPE_SCAN_REGION_UNIT10	14
#define MCSLOW_SCAN_REGION_TYPE_SCAN_TYPE_BNDY	56

#define MCSLOW_CLK_REGION				0x07030006
#define MCSLOW_CLK_REGION_CLOCK_CMD			0
#define MCSLOW_CLK_REGION_CLOCK_CMD_LEN			2
#define MCSLOW_CLK_REGION_CLOCK_REGION_UNIT10		14
#define MCSLOW_CLK_REGION_SEL_THOLD_SL		48
#define MCSLOW_CLK_REGION_SEL_THOLD_NSL		49
#define MCSLOW_CLK_REGION_SEL_THOLD_ARY		50

#define MCSLOW_CLOCK_STAT_SL				0x07030008
#define MCSLOW_CLOCK_STAT_NSL				0x07030009
#define MCSLOW_CLOCK_STAT_ARY				0x0703000A

#define MCSLOW_XFIR					0x07040000
#define MCSLOW_FIR_MASK				0x07040002
#define MCSLOW_LOCAL_FIR				0x0704000A
#define MCSLOW_LOCAL_FIR_MASK				0x0704000D
#define MCSLOW_LOCAL_FIR_ACTION0			0x07040010
#define MCSLOW_LOCAL_FIR_ACTION1			0x07040011

#define PCBSLMC01_MULTICAST_GROUP_1			0x070F0001
#define PCBSLMC01_MULTICAST_GROUP_2			0x070F0002

#define PCBSLMC01_PLL_LOCK_REG			0x070F0019

#define PCBSLMC01_SLAVE_CONFIG_REG			0x070F001E

#define PCBSLMC01_ERROR_REG				0x070F001F

#define PCBSLMC01_NET_CTRL0				0x070F0040
#define PCBSLMC01_NET_CTRL0_WAND			0x070F0041
#define PCBSLMC01_NET_CTRL0_WOR			0x070F0042
#define PCBSLMC01_NET_CTRL0_PCB_EP_RESET		1
#define PCBSLMC01_NET_CTRL0_PLL_TEST_EN		3
#define PCBSLMC01_NET_CTRL0_PLL_RESET			4
#define PCBSLMC01_NET_CTRL0_PLL_BYPASS		5
#define PCBSLMC01_NET_CTRL0_FENCE_EN			18

#define PCBSLMC01_NET_CTRL1				0x070F0044
#define PCBSLMC01_NET_CTRL1_WAND			0x070F0045
#define PCBSLMC01_NET_CTRL1_WOR			0x070F0046
#define PCBSLMC01_NET_CTRL1_CLK_DCC_BYPASS_EN		1
#define PCBSLMC01_NET_CTRL1_CLK_PDLY_BYPASS_EN	2

#define DDRPHY_DP16_DQ_BIT_ENABLE0_P0_0		0x800000000701103F
#define DDRPHY_DP16_DFT_PDA_CONTROL_P0_0		0x800000010701103F

#define DDRPHY_DP16_CONFIG0_P0_0			0x800000030701103F
#define DP16_CONFIG0_FLUSH				51
#define DP16_CONFIG0_INIT_IO				54
#define DP16_CONFIG0_ADVANCE_PING_PONG		55
#define DP16_CONFIG0_DELAY_PING_PONG_HALF		58

/* Names come from documentation, they are inconsistent there too. */
#define DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0	0x800000040701103F
#define DDRPHY_DP16_READ_CLOCK_RANK_PAIR1_P0_0	0x800001040701103F
#define DDRPHY_DP16_READ_CLOCK_RANK_PAIR2_P0_0	0x800002040701103F
#define DDRPHY_DP16_READ_CLOCK_RANK_PAIR3_P0_0	0x800003040701103F
#define DDRPHY_DP16_WRCLK_EN_RP0_P0_0			0x800000050701103F
#define DDRPHY_DP16_WRCLK_EN_RP1_P0_0			0x800001050701103F
#define DDRPHY_DP16_WRCLK_EN_RP2_P0_0			0x800002050701103F
#define DDRPHY_DP16_WRCLK_EN_RP3_P0_0			0x800003050701103F

#define DDRPHY_DP16_SYSCLK_PR0_P0_0			0x800000070701103F
#define DDRPHY_DP16_SYSCLK_PR1_P0_0			0x8000007F0701103F

#define DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0	0x800000090701103F

#define DDRPHY_DP16_DRIFT_LIMITS_P0_0			0x8000000A0701103F
#define DD2_BLUE_EXTEND_RANGE				48
#define DD2_BLUE_EXTEND_RANGE_LEN			2

#define DDRPHY_DP16_RD_LVL_STATUS0_P0_0		0x8000000E0701103F
#define DDRPHY_DP16_RD_LVL_STATUS2_P0_0		0x800000100701103F

#define DDRPHY_DP16_RD_DIA_CONFIG5_P0_0		0x800000120701103F
#define DYN_MCTERM_CNTL_EN				49
#define PER_CAL_UPDATE_DISABLE			52
#define PERCAL_PWR_DIS					59

#define DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0		0x800000130701103F
#define DDRPHY_DP16_DQS_GATE_DELAY_RP1_P0_0		0x800001130701103F
#define DDRPHY_DP16_DQS_GATE_DELAY_RP2_P0_0		0x800002130701103F
#define DDRPHY_DP16_DQS_GATE_DELAY_RP3_P0_0		0x800003130701103F

#define DDRPHY_DP16_RD_STATUS0_P0_0			0x800000140701103F

#define DDRPHY_DP16_RD_VREF_DAC_0_P0_0			0x800000160701103F
#define DDRPHY_DP16_RD_VREF_DAC_1_P0_0			0x8000001F0701103F
#define DDRPHY_DP16_RD_VREF_DAC_2_P0_0			0x800000C00701103F
#define DDRPHY_DP16_RD_VREF_DAC_3_P0_0			0x800000C10701103F
#define DDRPHY_DP16_RD_VREF_DAC_4_P0_0			0x800000C20701103F
#define DDRPHY_DP16_RD_VREF_DAC_5_P0_0			0x800000C30701103F
#define DDRPHY_DP16_RD_VREF_DAC_6_P0_0			0x800000C40701103F
#define DDRPHY_DP16_RD_VREF_DAC_7_P0_0			0x800000C50701103F
#define BIT0_VREF_DAC					49
#define BIT0_VREF_DAC_LEN				7
#define BIT1_VREF_DAC					57
#define BIT1_VREF_DAC_LEN				7

#define DDRPHY_DP16_WR_ERROR0_P0_0			0x8000001B0701103F

#define DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0		0x800000200701103F
#define NIB_0_DQSEL_CAP				48
#define NIB_0_DQSEL_CAP_LEN			2
#define NIB_0_DQSEL_RES				53
#define NIB_0_DQSEL_RES_LEN			3
#define NIB_1_DQSEL_CAP				56
#define NIB_1_DQSEL_CAP_LEN			2
#define NIB_1_DQSEL_RES				61
#define NIB_1_DQSEL_RES_LEN			3

#define DDRPHY_DP16_CTLE_CTL_BYTE1_P0_0		0x800000210701103F
#define NIB_2_DQSEL_CAP				48
#define NIB_2_DQSEL_CAP_LEN			2
#define NIB_2_DQSEL_RES				53
#define NIB_2_DQSEL_RES_LEN			3
#define NIB_3_DQSEL_CAP				56
#define NIB_3_DQSEL_CAP_LEN			2
#define NIB_3_DQSEL_RES				61
#define NIB_3_DQSEL_RES_LEN			3

#define DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_0		0x800000220701103F
#define S0ACENSLICENDRV_DC				48
#define S0ACENSLICENDRV_DC_LEN				3
#define S0ACENSLICEPDRV_DC				51
#define S0ACENSLICEPDRV_DC_LEN				3
#define S0ACENSLICEPTERM_DC				56

#define DDRPHY_DP16_ACBOOST_CTL_BYTE1_P0_0		0x800000230701103F
#define S1ACENSLICENDRV_DC				48
#define S1ACENSLICENDRV_DC_LEN				3
#define S1ACENSLICEPDRV_DC				51
#define S1ACENSLICEPDRV_DC_LEN				3
#define S1ACENSLICEPTERM_DC				56

#define DDRPHY_DP16_DLL_CNTL0_P0_0			0x800000240701103F
#define DDRPHY_DP16_DLL_CNTL1_P0_0			0x800000250701103F
#define INIT_RXDLL_CAL_RESET				48

#define DDRPHY_DP16_DLL_VREG_CONTROL0_P0_0		0x8000002A0701103F
#define DDRPHY_DP16_DLL_VREG_CONTROL1_P0_0		0x8000002B0701103F
#define RXREG_VREG_COMPCON_DC				48
#define RXREG_VREG_COMPCON_DC_LEN			3
#define RXREG_VREG_DRVCON_DC				53
#define RXREG_VREG_DRVCON_DC_LEN			3
#define RXREG_VREG_REF_SEL_DC				56
#define RXREG_VREG_REF_SEL_DC_LEN			3

#define DDRPHY_DP16_DLL_VREG_COARSE0_P0_0		0x8000002C0701103F
#define DDRPHY_DP16_DLL_VREG_COARSE1_P0_0		0x8000002D0701103F

#define DDRPHY_DP16_WR_VREF_STATUS0_P0_0		0x8000002E0701103F
#define DDRPHY_DP16_WR_VREF_STATUS1_P0_0		0x8000002F0701103F

#define DDRPHY_DP16_DQSCLK_OFFSET_P0_0		0x800000370701103F
#define DQS_OFFSET					49
#define DQS_OFFSET_LEN					7

#define DDRPHY_DP16_WR_DELAY_VALUE_0_RP0_REG_P0_0	0x800000380701103F

#define DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0	0x8000005E0701103F
#define DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR1_P0_0	0x8000015E0701103F
#define DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR2_P0_0	0x8000025E0701103F
#define DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR3_P0_0	0x8000035E0701103F
#define WR_VREF_RANGE_DRAM0				49
#define WR_VREF_VALUE_DRAM0				50
#define WR_VREF_VALUE_DRAM0_LEN				6
#define WR_VREF_RANGE_DRAM1				57
#define WR_VREF_VALUE_DRAM1				58
#define WR_VREF_VALUE_DRAM1_LEN				6

#define DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR0_P0_0	0x8000005F0701103F
#define DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR1_P0_0	0x8000015F0701103F
#define DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR2_P0_0	0x8000025F0701103F
#define DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR3_P0_0	0x8000035F0701103F
#define WR_VREF_RANGE_DRAM2				49
#define WR_VREF_VALUE_DRAM2				50
#define WR_VREF_VALUE_DRAM2_LEN				6
#define WR_VREF_RANGE_DRAM3				57
#define WR_VREF_VALUE_DRAM3				58
#define WR_VREF_VALUE_DRAM3_LEN				6

#define DDRPHY_DP16_WR_VREF_CONFIG0_P0_0		0x8000006C0701103F
#define WR_CTR_1D_MODE_SWITCH				48
#define WR_CTR_RUN_FULL_1D				49
#define WR_CTR_2D_SMALL_STEP_VAL			52
#define WR_CTR_2D_BIG_STEP_VAL				53
#define WR_CTR_2D_BIG_STEP_VAL_LEN			4
#define WR_CTR_NUM_BITS_TO_SKIP				57
#define WR_CTR_NUM_BITS_TO_SKIP_LEN			3
#define WR_CTR_NUM_NO_INC_VREF_COMP			60
#define WR_CTR_NUM_NO_INC_VREF_COMP_LEN			3

#define DDRPHY_DP16_SYSCLK_PR_VALUE_P0_0		0x800000730701103F
#define BB_LOCK0					48
#define BB_LOCK1					56

#define DDRPHY_DP16_WRCLK_PR_P0_0			0x800000740701103F
#define TSYS_WRCLK					49
#define TSYS_WRCLK_LEN					7

#define DDRPHY_DP16_IO_TX_CONFIG0_P0_0			0x800000750701103F
#define DDRPHY_DP16_IO_TX_CONFIG0_STRENGTH		48
#define DDRPHY_DP16_IO_TX_CONFIG0_STRENGTH_LEN		4

#define DDRPHY_DP16_RD_VREF_CAL_EN_P0_0		0x800000760701103F

#define DDRPHY_DP16_DLL_CONFIG1_P0_0			0x800000770701103F
#define S0INSDLYTAP					61
#define S1INSDLYTAP					62

#define DDRPHY_DP16_IO_TX_FET_SLICE_P0_0		0x800000780701103F
#define EN_SLICE_N_WR					49
#define EN_SLICE_N_WR_LEN				7
#define EN_SLICE_P_WR					57
#define EN_SLICE_P_WR_LEN				7

#define DDRPHY_DP16_RD_VREF_CAL_ERROR_P0_0		0x8000007A0701103F

#define DDRPHY_DP16_IO_TX_PFET_TERM_P0_0		0x8000007B0701103F

#define DDRPHY_DP16_DQ_BIT_DISABLE_RP0_P0_0		0x8000007C0701103F
#define DDRPHY_DP16_DQS_BIT_DISABLE_RP0_P0_0		0x8000007D0701103F

#define DDRPHY_DP16_WR_VREF_ERROR0_P0_0		0x800000AE0701103F
#define DDRPHY_DP16_WR_VREF_ERROR1_P0_0		0x800000AF0701103F

#define DDRPHY_DP16_WR_VREF_CONFIG1_P0_0		0x800000EC0701103F
#define WR_CTR_VREF_RANGE_SELECT			48
#define WR_CTR_VREF_RANGE_CROSSOVER			49
#define WR_CTR_VREF_RANGE_CROSSOVER_LEN			7
#define WR_CTR_VREF_SINGLE_RANGE_MAX			56
#define WR_CTR_VREF_SINGLE_RANGE_MAX_LEN		7

/* Yes, MASK1 is supposed to be before MASK0. */
#define DDRPHY_DP16_WR_VREF_ERROR_MASK1_P0_0		0x800000FA0701103F
#define DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0		0x800000FB0701103F

#define DDRPHY_ADR_BIT_ENABLE_P0_ADR0			0x800040000701103F
#define DDRPHY_ADR_DIFFPAIR_ENABLE_P0_ADR1		0x800044010701103F

#define DDRPHY_ADR_DELAY0_P0_ADR0			0x800040040701103F
#define DDRPHY_ADR_DELAY1_P0_ADR0			0x800040050701103F
#define DDRPHY_ADR_DELAY2_P0_ADR0			0x800040060701103F
#define DDRPHY_ADR_DELAY3_P0_ADR0			0x800040070701103F
#define DDRPHY_ADR_DELAY4_P0_ADR0			0x800040080701103F
#define DDRPHY_ADR_DELAY5_P0_ADR0			0x800040090701103F
#define DDRPHY_ADR_DELAY0_P0_ADR1			0x800044040701103F
#define DDRPHY_ADR_DELAY1_P0_ADR1			0x800044050701103F
#define DDRPHY_ADR_DELAY2_P0_ADR1			0x800044060701103F
#define DDRPHY_ADR_DELAY3_P0_ADR1			0x800044070701103F
#define DDRPHY_ADR_DELAY4_P0_ADR1			0x800044080701103F
#define DDRPHY_ADR_DELAY5_P0_ADR1			0x800044090701103F
#define DDRPHY_ADR_DELAY0_P0_ADR2			0x800048040701103F
#define DDRPHY_ADR_DELAY1_P0_ADR2			0x800048050701103F
#define DDRPHY_ADR_DELAY2_P0_ADR2			0x800048060701103F
#define DDRPHY_ADR_DELAY3_P0_ADR2			0x800048070701103F
#define DDRPHY_ADR_DELAY4_P0_ADR2			0x800048080701103F
#define DDRPHY_ADR_DELAY5_P0_ADR2			0x800048090701103F
#define DDRPHY_ADR_DELAY0_P0_ADR3			0x80004C040701103F
#define DDRPHY_ADR_DELAY1_P0_ADR3			0x80004C050701103F
#define DDRPHY_ADR_DELAY2_P0_ADR3			0x80004C060701103F
#define DDRPHY_ADR_DELAY3_P0_ADR3			0x80004C070701103F
#define ADR_DELAY_EVEN					49
#define ADR_DELAY_EVEN_LEN				7
#define ADR_DELAY_ODD					57
#define ADR_DELAY_ODD_LEN				7

#define DDRPHY_ADR_DELAY1_P0_ADR1			0x800044050701103F
#define DDRPHY_ADR_DELAY3_P0_ADR1			0x800044070701103F

#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0	0x800040200701103F
#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0	0x800040210701103F
#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1	0x800044200701103F
#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1	0x800044210701103F
#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2	0x800048200701103F
#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2	0x800048210701103F
#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3	0x80004C200701103F
#define DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR3	0x80004C210701103F
#define SLICE_SEL0					48
#define SLICE_SEL1					50
#define SLICE_SEL2					52
#define SLICE_SEL3					54
#define SLICE_SEL4					56
#define SLICE_SEL5					58
#define SLICE_SEL6					60
#define SLICE_SEL7					62

#define DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0		0x800080310701103F
#define DDRPHY_ADR_DLL_VREG_CONFIG_1_STRENGTH		59
#define DDRPHY_ADR_DLL_VREG_CONFIG_1_STRENGTH_LEN	4

#define ADR_SYSCLK_CNTRL_PR_P0_ADR32S0		0x800080320701103F

#define DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0	0x800080330701103F

#define ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0		0x800080340701103F

#define DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL_P0_ADR32S0	0x800080350701103F
#define FLUSH						48
#define INIT_IO					50

#define DDRPHY_ADR_DLL_CNTL_P0_ADR32S0		0x8000803A0701103F
#define INIT_RXDLL_CAL_RESET				48

#define DDRPHY_ADR_DLL_VREG_CONTROL_P0_ADR32S0	0x8000803D0701103F

#define DDRPHY_ADR_DLL_VREG_COARSE_P0_ADR32S0		0x8000803E0701103F

#define DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0		0x8000C0000701103F
#define DP_DLL_CAL_GOOD				48
#define DP_DLL_CAL_ERROR				49
#define DP_DLL_CAL_ERROR_FINE				50
#define ADR_DLL_CAL_GOOD				51
#define ADR_DLL_CAL_ERROR				52
#define ADR_DLL_CAL_ERROR_FINE			53
#define ZCAL_DONE					63

#define DDRPHY_PC_RANK_PAIR0_P0			0x8000C0020701103F
#define DDRPHY_PC_RANK_PAIR1_P0			0x8000C0030701103F
#define DDRPHY_PC_RANK_PAIR2_P0			0x8000C0300701103F
#define DDRPHY_PC_RANK_PAIR3_P0			0x8000C0310701103F

#define DDRPHY_PC_CONFIG0_P0				0x8000C00C0701103F
#define DDR4_CMD_SIG_REDUCTION			54
#define DDR4_VLEVEL_BANK_GROUP			62

#define DDRPHY_PC_CONFIG1_P0				0x8000C00D0701103F
#define WRITE_LATENCY_OFFSET				48
#define WRITE_LATENCY_OFFSET_LEN			4
#define READ_LATENCY_OFFSET				52
#define READ_LATENCY_OFFSET_LEN				4
#define MEMORY_TYPE					59
#define MEMORY_TYPE_LEN					3
#define DDR4_LATENCY_SW					62

#define DDRPHY_PC_RESETS_P0				0x8000C00E0701103F
#define SYSCLK_RESET					49
#define ENABLE_ZCAL					51

#define DDRPHY_PC_MIRROR_CONFIG_P0			0x8000C0110701103F
#define ADDR_MIRROR_RP1_PRI				50
#define ADDR_MIRROR_RP1_SEC				51
#define ADDR_MIRROR_RP3_PRI				54
#define ADDR_MIRROR_RP3_SEC				55

#define DDRPHY_PC_ERROR_STATUS0_P0			0x8000C0120701103F

#define DDRPHY_PC_INIT_CAL_CONFIG0_P0			0x8000C0160701103F
#define ABORT_ON_CAL_ERROR				58
#define ENA_RANK_PAIR_MSB				60

#define DDRPHY_PC_INIT_CAL_CONFIG1_P0			0x8000C0170701103F
#define REFRESH_COUNT					48
#define REFRESH_COUNT_LEN				4
#define REFRESH_CONTROL					52
#define REFRESH_CONTROL_LEN				2
#define REFRESH_ALL_RANKS				54
#define CMD_SNOOP_DIS					55
#define REFRESH_INTERVAL				57
#define REFRESH_INTERVAL_LEN				7

#define DDRPHY_PC_INIT_CAL_ERROR_P0			0x8000C0180701103F

#define DDRPHY_PC_INIT_CAL_STATUS_P0			0x8000C0190701103F

#define DDRPHY_PC_CSID_CFG_P0				0x8000C0330701103F

#define DDRPHY_SEQ_CONFIG0_P0				0x8000C4020701103F
#define TWO_CYCLE_ADDR_EN				49
#define DELAYED_PAR					54
#define PAR_A17_MASK					62

#define DDRPHY_SEQ_ODT_WR_CONFIG0_P0			0x8000C40A0701103F
#define DDRPHY_SEQ_ODT_RD_CONFIG1_P0			0x8000C40F0701103F
#define ODT_RD_VALUES0					48
#define ODT_RD_VALUES0_LEN				4
#define ODT_RD_VALUES1					56
#define ODT_RD_VALUES1_LEN				4

#define DDRPHY_SEQ_MEM_TIMING_PARAM0_P0			0x8000C4120701103F
#define TMOD_CYCLES					48
#define TMOD_CYCLES_LEN					4
#define TRCD_CYCLES					52
#define TRCD_CYCLES_LEN					4
#define TRP_CYCLES					56
#define TRP_CYCLES_LEN					4
#define TRFC_CYCLES					60
#define TRFC_CYCLES_LEN					4

#define DDRPHY_SEQ_MEM_TIMING_PARAM1_P0			0x8000C4130701103F
#define TZQINIT_CYCLES					48
#define TZQINIT_CYCLES_LEN				4
#define TZQCS_CYCLES					52
#define TZQCS_CYCLES_LEN				4
#define TWLDQSEN_CYCLES					56
#define TWLDQSEN_CYCLES_LEN				4
#define TWRMRD_CYCLES					60
#define TWRMRD_CYCLES_LEN				4

#define DDRPHY_SEQ_MEM_TIMING_PARAM2_P0			0x8000C4140701103F
#define TODTLON_OFF_CYCLES				48
#define TODTLON_OFF_CYCLES_LEN				4

#define DDRPHY_SEQ_RD_WR_DATA0_P0			0x8000C4000701103F
#define DDRPHY_SEQ_RD_WR_DATA1_P0			0x8000C4010701103F
#define RD_RW_DATA_REG0					48
#define RD_RW_DATA_REG0_LEN				16
#define RD_RW_DATA_REG1					48
#define RD_RW_DATA_REG1_LEN				16

#define DDRPHY_SEQ_ERROR_STATUS0_P0			0x8000C4080701103F

#define DDRPHY_SEQ_ODT_WR_CONFIG0_P0			0x8000C40A0701103F
#define ODT_WR_VALUES0					48
#define ODT_WR_VALUES0_LEN				4
#define ODT_WR_VALUES1					56
#define ODT_WR_VALUES1_LEN				4

#define DDRPHY_SEQ_ODT_WR_CONFIG1_P0			0x8000C40B0701103F
#define ODT_WR_VALUES2					48
#define ODT_WR_VALUES2_LEN				4
#define ODT_WR_VALUES3					56
#define ODT_WR_VALUES3_LEN				4

#define DDRPHY_SEQ_ODT_RD_CONFIG0_P0			0x8000C40E0701103F
#define ODT_RD_VALUES0					48
#define ODT_RD_VALUES0_LEN				4
#define ODT_RD_VALUES1					56
#define ODT_RD_VALUES1_LEN				4

#define DDRPHY_SEQ_ODT_RD_CONFIG1_P0			0x8000C40F0701103F
#define ODT_RD_VALUES2					48
#define ODT_RD_VALUES2_LEN				4
#define ODT_RD_VALUES3					56
#define ODT_RD_VALUES3_LEN				4

#define DDRPHY_RC_CONFIG0_P0				0x8000C8000701103F
#define GLOBAL_PHY_OFFSET				48
#define GLOBAL_PHY_OFFSET_LEN				4
#define PERFORM_RDCLK_ALIGN				62

#define DDRPHY_RC_CONFIG1_P0				0x8000C8010701103F

#define DDRPHY_RC_CONFIG2_P0				0x8000C8020701103F
#define CONSEC_PASS					48
#define CONSEC_PASS_LEN					5

#define DDRPHY_RC_ERROR_STATUS0_P0			0x8000C8050701103F

#define DDRPHY_RC_CONFIG3_P0				0x8000C8070701103F
#define COARSE_CAL_STEP_SIZE				51
#define COARSE_CAL_STEP_SIZE_LEN			4

#define DDRPHY_RC_RDVREF_CONFIG0_P0			0x8000C8090701103F

#define DDRPHY_RC_RDVREF_CONFIG1_P0			0x8000C80A0701103F
#define CMD_PRECEDE_TIME				48
#define CMD_PRECEDE_TIME_LEN				8
#define MPR_LOCATION					56
#define MPR_LOCATION_LEN				4
#define CALIBRATION_ENABLE				60
#define SKIP_RDCENTERING				61

#define DDRPHY_WC_CONFIG0_P0				0x8000CC000701103F
#define TWLO_TWLOE					48
#define TWLO_TWLOE_LEN					8
#define WL_ONE_DQS_PULSE				56
#define FW_WR_RD					57
#define FW_WR_RD_LEN					6
#define CUSTOM_INIT_WRITE				63

#define DDRPHY_WC_CONFIG1_P0				0x8000CC010701103F
#define BIG_STEP					48
#define BIG_STEP_LEN					4
#define SMALL_STEP					54
#define WR_PRE_DLY					55
#define WR_PRE_DLY_LEN					6

#define DDRPHY_WC_CONFIG2_P0				0x8000CC020701103F
#define NUM_VALID_SAMPLES				48
#define NUM_VALID_SAMPLES_LEN				4
#define FW_RD_WR					52
#define FW_RD_WR_LEN					6
#define IPW_WR_WR					58
#define IPW_WR_WR_LEN					4

#define DDRPHY_WC_ERROR_STATUS0_P0			0x8000CC030701103F

#define DDRPHY_WC_CONFIG3_P0				0x8000CC050701103F
#define MRS_CMD_DQ_OFF					55
#define MRS_CMD_DQ_OFF_LEN				6

#define DDRPHY_WC_RTT_WR_SWAP_ENABLE_P0			0x8000CC060701103F
#define WL_ENABLE_RTT_SWAP				48
#define WR_CTR_ENABLE_RTT_SWAP				49
#define WR_CTR_VREF_COUNTER_RESET_VAL			50
#define WR_CTR_VREF_COUNTER_RESET_VAL_LEN		10

#define DDRPHY_APB_CONFIG0_P0				0x8000D0000701103F
#define RESET_ERR_RPT					49

#define DDRPHY_APB_ERROR_STATUS0_P0			0x8000D0010701103F

#endif	// ISTEP_13_SCOM_H