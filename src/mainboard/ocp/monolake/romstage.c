/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2013 Google Inc.
 * Copyright (C) 2015 Intel Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stddef.h>
#include <soc/romstage.h>
#include <drivers/intel/fsp1_0/fsp_util.h>
#include <drivers/vpd/vpd.h>
#include <cpu/x86/msr.h>
#include <cf9_reset.h>
#include <console/console.h>
#include <device/pci_ops.h>
#include <soc/pci_devs.h>
#include <soc/lpc.h>

/* Define the strings for UPD variables that could be customized */
#define FSP_VAR_HYPERTHREADING "HyperThreading"

/**
 * /brief mainboard call for setup that needs to be done before fsp init
 *
 */
void early_mainboard_romstage_entry(void)
{
	/*
	 * Sometimes the system boots in an invalid state, where random values
	 * have been written to MSRs and then the MSRs are locked.
	 * Seems to always happen on warm reset.
	 *
	 * Power cycling or a board_reset() isn't sufficient in this case, so
	 * issue a full_reset() to "fix" this issue.
	 */
	msr_t msr = rdmsr(IA32_FEATURE_CONTROL);
	if (msr.lo & 1) {
		console_init();
		printk(BIOS_EMERG, "Detected broken platform state. Issuing full reset\n");
		full_reset();
	}
}

/**
 * /brief mainboard call for setup that needs to be done after fsp init
 *
 */
void late_mainboard_romstage_entry(void)
{
	// IPMI through BIC
	pci_write_config32(PCI_DEV(0, LPC_DEV, LPC_FUNC), LPC_GEN2_DEC,
			   0x0c0ca1);
}

/*
 * This function sets up global variable to store VPD binary blob info,
 * and use settings in the binary blob to configure UPD.
 */
static void board_configure_upd(UPD_DATA_REGION *UpdData)
{
	u8 val;

	if (vpd_get_bool(FSP_VAR_HYPERTHREADING, VPD_RW, &val))
		UpdData->HyperThreading = val;
}

/**
 * /brief customize fsp parameters, use data stored in VPD binary blob
 * to configure FSP UPD variables.
 */
void romstage_fsp_rt_buffer_callback(FSP_INIT_RT_BUFFER *FspRtBuffer)
{
	UPD_DATA_REGION *UpdData = FspRtBuffer->Common.UpdDataRgnPtr;

	if (CONFIG(VPD))
		board_configure_upd(UpdData);
}
