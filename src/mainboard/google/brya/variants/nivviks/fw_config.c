/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <baseboard/gpio.h>
#include <bootstate.h>
#include <console/console.h>
#include <fw_config.h>

static const struct pad_config lte_disable_pads[] = {
	/* A8  : WWAN_RF_DISABLE_ODL */
	PAD_NC(GPP_A8, NONE),
	/* D6  : WWAN_EN */
	PAD_NC(GPP_D6, NONE),
	/* F12 : WWAN_RST_L */
	PAD_NC(GPP_F12, NONE),
	/* H19 : SOC_I2C_SUB_INT_ODL */
	PAD_NC(GPP_H19, NONE),
	/* H23 : WWAN_SAR_DETECT_ODL */
	PAD_NC(GPP_H23, NONE),
};

static void fw_config_handle(void *unused)
{
	if (!fw_config_probe(FW_CONFIG(DB_USB, DB_1C_LTE))) {
		printk(BIOS_INFO, "Disable LTE-related GPIO pins.\n");
		gpio_configure_pads(lte_disable_pads, ARRAY_SIZE(lte_disable_pads));
	}
}
BOOT_STATE_INIT_ENTRY(BS_DEV_ENABLE, BS_ON_ENTRY, fw_config_handle, NULL);
