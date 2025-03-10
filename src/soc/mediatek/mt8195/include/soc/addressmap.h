/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __SOC_MEDIATEK_MT8195_INCLUDE_SOC_ADDRESSMAP_H__
#define __SOC_MEDIATEK_MT8195_INCLUDE_SOC_ADDRESSMAP_H__

enum {
	MCUSYS_BASE		= 0x0C530000,
	MCUPM_SRAM_BASE		= 0x0C540000,
	MCUPM_CFG_BASE		= 0x0C560000,
	BUS_TRACE_MONITOR_BASE	= 0x0D040000,
	IO_PHYS			= 0x10000000,
};

enum {
	MCUCFG_BASE		= MCUSYS_BASE + 0x00008000,
};

enum {
	CKSYS_BASE		= IO_PHYS,
	INFRACFG_AO_BASE	= IO_PHYS + 0x00001000,
	INFRACFG_AO_MEM_BASE	= IO_PHYS + 0x00002000,
	GPIO_BASE		= IO_PHYS + 0x00005000,
	SPM_BASE		= IO_PHYS + 0x00006000,
	RGU_BASE		= IO_PHYS + 0x00007000,
	GPT_BASE		= IO_PHYS + 0x00008000,
	EINT_BASE		= IO_PHYS + 0x0000B000,
	APMIXED_BASE		= IO_PHYS + 0x0000C000,
	SYSTIMER_BASE		= IO_PHYS + 0x00017000,
	INFRACFG_AO_BCRM_BASE	= IO_PHYS + 0x00022000,
	PMIF_SPI_BASE		= IO_PHYS + 0x00024000,
	PMICSPI_MST_BASE	= IO_PHYS + 0x00025000,
	PMIF_SPMI_BASE		= IO_PHYS + 0x00027000,
	SPMI_MST_BASE		= IO_PHYS + 0x00029000,
	DEVAPC_INFRA_AO_BASE	= IO_PHYS + 0x00030000,
	DEVAPC_PERI_AO_BASE	= IO_PHYS + 0x00034000,
	DEVAPC_PERI2_AO_BASE	= IO_PHYS + 0x00038000,
	DEVAPC_PERI_PAR_AO_BASE	= IO_PHYS + 0x0003C000,
	DEVAPC_FMEM_AO_BASE	= IO_PHYS + 0x00044000,
	DBG_TRACKER_BASE	= IO_PHYS + 0x00208000,
	PERI_TRACKER_BASE	= IO_PHYS + 0x00218000,
	EMI0_BASE		= IO_PHYS + 0x00219000,
	EMI1_BASE		= IO_PHYS + 0x0021D000,
	I2C_DMA_BASE		= IO_PHYS + 0x00220080,
	EMI1_SUB_BASE		= IO_PHYS + 0x00225000,
	EMI0_MPU_BASE		= IO_PHYS + 0x00226000,
	DEVAPC_INFRA2_AO_BASE   = IO_PHYS + 0x00228000,
	DRAMC_CHA_AO_BASE	= IO_PHYS + 0x00230000,
	INFRA_TRACKER_BASE	= IO_PHYS + 0x00314000,
	SSPM_SRAM_BASE		= IO_PHYS + 0x00400000,
	SSPM_CFG_BASE		= IO_PHYS + 0x00440000,
	SCP_CFG_BASE		= IO_PHYS + 0x00700000,
	DPM_PM_SRAM_BASE	= IO_PHYS + 0x00900000,
	DPM_DM_SRAM_BASE	= IO_PHYS + 0x00920000,
	DPM_CFG_BASE		= IO_PHYS + 0x00940000,
	DPM_PM_SRAM_BASE2	= IO_PHYS + 0x00A00000,
	DPM_DM_SRAM_BASE2	= IO_PHYS + 0x00A20000,
	DPM_CFG_BASE2		= IO_PHYS + 0x00A40000,
	UART0_BASE		= IO_PHYS + 0x01001100,
	AUXADC_BASE             = IO_PHYS + 0x01002000,
	PERICFG_AO_BASE		= IO_PHYS + 0x01003000,
	SPI0_BASE		= IO_PHYS + 0x0100A000,
	SPI1_BASE		= IO_PHYS + 0x01010000,
	SPI2_BASE		= IO_PHYS + 0x01012000,
	SPI3_BASE		= IO_PHYS + 0x01013000,
	SPI4_BASE		= IO_PHYS + 0x01018000,
	SPI5_BASE		= IO_PHYS + 0x01019000,
	SPIS0_BASE		= IO_PHYS + 0x0101D000,
	SPIS1_BASE		= IO_PHYS + 0x0101E000,
	SSUSB_IPPC_BASE		= IO_PHYS + 0x01203E00,
	MSDC0_BASE		= IO_PHYS + 0x01230000,
	UFSHCI_BASE		= IO_PHYS + 0x01270000,
	SFLASH_REG_BASE		= IO_PHYS + 0x0132C000,
	EFUSEC_BASE		= IO_PHYS + 0x01C10000,
	MIPITX_BASE		= IO_PHYS + 0x01C80000,
	IOCFG_BM_BASE		= IO_PHYS + 0x01D10000,
	IOCFG_BL_BASE		= IO_PHYS + 0x01D30000,
	IOCFG_BR_BASE		= IO_PHYS + 0x01D40000,
	I2C_BASE		= IO_PHYS + 0x01E00000,
	IOCFG_LM_BASE		= IO_PHYS + 0x01E20000,
	SSUSB_SIF_BASE		= IO_PHYS + 0x01E40300,
	IOCFG_RB_BASE		= IO_PHYS + 0x01EB0000,
	IOCFG_TL_BASE		= IO_PHYS + 0x01F40000,
	MSDC0_TOP_BASE		= IO_PHYS + 0x01F50000,
	APU_MBOX_BASE		= IO_PHYS + 0x09000000,
	APUSYS_APC_AO_BASE	= IO_PHYS + 0x090F8000,
	APUSYS_NOC_DAPC_AO_BASE	= IO_PHYS + 0x090FC000,
	DISP_OVL0_BASE		= IO_PHYS + 0x0C000000,
	DISP_RDMA0_BASE		= IO_PHYS + 0x0C002000,
	DISP_COLOR0_BASE	= IO_PHYS + 0x0C003000,
	DISP_CCORR0_BASE	= IO_PHYS + 0x0C004000,
	DISP_AAL0_BASE		= IO_PHYS + 0x0C005000,
	DISP_GAMMA0_BASE	= IO_PHYS + 0x0C006000,
	DISP_DITHER0_BASE	= IO_PHYS + 0x0C007000,
	DSI0_BASE		= IO_PHYS + 0x0C008000,
	DISP_DSC0_BASE		= IO_PHYS + 0x0C009000,
	DISP_OVL1_BASE		= IO_PHYS + 0x0C00A000,
	DISP_MERGE0_BASE	= IO_PHYS + 0x0C014000,
	DP_INTF0_BASE		= IO_PHYS + 0x0C015000,
	DISP_MUTEX_BASE		= IO_PHYS + 0x0C016000,
	SMI_LARB0		= IO_PHYS + 0x0C018000,
	VDOSYS0_BASE		= IO_PHYS + 0x0C01A000,
	SMI_BASE		= IO_PHYS + 0x0C01B000,
	EDP_BASE		= IO_PHYS + 0x0C500000,
};
#endif
