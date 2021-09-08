/* SPDX-License-Identifier: GPL-2.0-only */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <commonlib/helpers.h>

/* Pad configuration in ramstage */
static const struct pad_config gpio_table[] = {

	/* ------- GPIO Community 0 ------- */

	/* ------- GPIO Group GPP_B ------- */
	PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),
	PAD_CFG_GPI_TRIG_OWN(GPP_B2, UP_20K, DEEP, OFF, ACPI),
	PAD_CFG_GPI_INT(GPP_B3, NONE, PLTRST, LEVEL),
	PAD_NC(GPP_B4, NONE),
	PAD_NC(GPP_B5, NONE),
	PAD_NC(GPP_B6, NONE),
	PAD_NC(GPP_B7, NONE),
	PAD_CFG_GPO(GPP_B8, 1, DEEP),
	PAD_NC(GPP_B9, NONE),
	PAD_NC(GPP_B10, NONE),
	PAD_CFG_NF(GPP_B11, NONE, PWROK, NF1),
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_B14, 0, DEEP),
	PAD_CFG_GPO(GPP_B15, 1, DEEP),
	PAD_NC(GPP_B16, NONE),
	PAD_NC(GPP_B17, NONE),
	PAD_NC(GPP_B18, NONE),
	PAD_NC(GPP_B19, NONE),
	PAD_NC(GPP_B20, NONE),
	PAD_NC(GPP_B21, NONE),
	PAD_NC(GPP_B22, NONE),
	PAD_CFG_GPO(GPP_B23, 0, DEEP),

	/* ------- GPIO Group GPP_T (TGL UP3 only) ------- */
	PAD_NC(GPP_T2, NONE),
	PAD_NC(GPP_T3, NONE),

	/* ------- GPIO Group GPP_A ------- */
	PAD_CFG_NF(GPP_A0, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A5, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
	PAD_NC(GPP_A7, NONE),
	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF2),
	PAD_CFG_NF(GPP_A9, NONE, DEEP, NF2),
	PAD_NC(GPP_A10, NONE),
	PAD_NC(GPP_A11, NONE),
	PAD_NC(GPP_A12, NONE),
	PAD_CFG_GPO(GPP_A13, 1, PLTRST),
	PAD_NC(GPP_A14, NONE),
	PAD_NC(GPP_A15, NONE),
	PAD_NC(GPP_A16, NONE),
	PAD_NC(GPP_A17, NONE),
	PAD_CFG_NF(GPP_A18, NONE, DEEP, NF1),
	PAD_NC(GPP_A19, NONE),
	PAD_NC(GPP_A20, NONE),
	PAD_NC(GPP_A21, NONE),
	PAD_NC(GPP_A22, NONE),
	PAD_CFG_GPO(GPP_A23, 0, PLTRST),

	/* ------- GPIO Community 1 ------- */

	/* ------- GPIO Group GPP_S ------- */
	PAD_NC(GPP_S0, NONE),
	PAD_NC(GPP_S1, NONE),
	PAD_NC(GPP_S2, NONE),
	PAD_NC(GPP_S3, NONE),
	PAD_NC(GPP_S4, NONE),
	PAD_NC(GPP_S5, NONE),
	PAD_NC(GPP_S6, NONE),
	PAD_NC(GPP_S7, NONE),

	/* ------- GPIO Group GPP_H ------- */
	PAD_CFG_GPO(GPP_H0, 1, PLTRST),
	PAD_NC(GPP_H1, NONE),
	PAD_NC(GPP_H2, NONE),
	PAD_CFG_GPI_TRIG_OWN(GPP_H3, DN_20K, DEEP, OFF, ACPI),
	PAD_CFG_NF(GPP_H4, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1),
	PAD_NC(GPP_H6, NONE),
	PAD_NC(GPP_H7, NONE),
	PAD_CFG_GPI_TRIG_OWN(GPP_H8, DN_20K, DEEP, OFF, ACPI),
	PAD_CFG_GPI_TRIG_OWN(GPP_H9, DN_20K, DEEP, OFF, ACPI),
	PAD_CFG_NF(GPP_H10, NONE, DEEP, NF1),
	PAD_NC(GPP_H11, NONE),
	PAD_NC(GPP_H12, NONE),
	PAD_NC(GPP_H13, NONE),
	PAD_NC(GPP_H14, NONE),
	PAD_NC(GPP_H15, NONE),
	PAD_CFG_NF(GPP_H16, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H17, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H18, NONE, DEEP, NF1),
	PAD_NC(GPP_H19, NONE),
	PAD_NC(GPP_H20, NONE),
	PAD_NC(GPP_H21, NONE),
	PAD_NC(GPP_H22, NONE),
	PAD_NC(GPP_H23, NONE),

	/* ------- GPIO Group GPP_D ------- */
	PAD_CFG_GPI_TRIG_OWN(GPP_D0, NONE, DEEP, OFF, ACPI),
	PAD_CFG_GPO(GPP_D1, 1, PLTRST),
	PAD_CFG_GPI_TRIG_OWN(GPP_D2, NONE, PLTRST, OFF, ACPI),
	PAD_CFG_GPI_TRIG_OWN(GPP_D3, NONE, PLTRST, OFF, ACPI),
	PAD_NC(GPP_D4, NONE),
	PAD_CFG_NF(GPP_D5, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D6, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D7, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D8, NONE, DEEP, NF1),
	PAD_NC(GPP_D9, NONE),
	PAD_CFG_GPI_TRIG_OWN(GPP_D10, DN_20K, DEEP, OFF, ACPI),
	PAD_CFG_GPI_TRIG_OWN(GPP_D11, DN_20K, DEEP, OFF, ACPI),
	PAD_CFG_GPI_TRIG_OWN(GPP_D12, DN_20K, DEEP, OFF, ACPI),
	PAD_CFG_GPO(GPP_D13, 0, DEEP),
	PAD_CFG_GPO(GPP_D14, 1, PLTRST),
	PAD_NC(GPP_D15, NONE),
	PAD_NC(GPP_D16, NONE),
	PAD_CFG_GPI_TRIG_OWN(GPP_D17, DN_20K, DEEP, OFF, ACPI),
	PAD_CFG_GPI_TRIG_OWN(GPP_D18, DN_20K, DEEP, OFF, ACPI),
	PAD_NC(GPP_D19, NONE),

	/* ------- GPIO Group GPP_U (TGL UP3 only) ------- */
	PAD_CFG_GPO(GPP_U4, 0, PLTRST),
	PAD_CFG_GPO(GPP_U5, 1, PLTRST),

	/* ------- GPIO Community 2 ------- */

	/* ------- GPIO Group GPD ------- */
	PAD_CFG_NF(GPD0, UP_20K, RSMRST, NF1),
	PAD_CFG_NF(GPD1, NATIVE, RSMRST, NF1),
	PAD_CFG_GPI_TRIG_OWN(GPD2, NONE, RSMRST, OFF, ACPI),
	PAD_CFG_NF(GPD3, UP_20K, RSMRST, NF1),
	PAD_CFG_NF(GPD4, NONE, RSMRST, NF1),
	PAD_CFG_NF(GPD5, NONE, RSMRST, NF1),
	PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPD7, 1, RSMRST),
	PAD_CFG_NF(GPD8, NONE, RSMRST, NF1),
	PAD_CFG_NF(GPD9, NONE, RSMRST, NF1),
	PAD_CFG_NF(GPD10, UP_20K, DEEP, NF1),
	PAD_CFG_GPI_TRIG_OWN(GPD11, UP_20K, DEEP, OFF, ACPI),

	/* ------- GPIO Community 4 ------- */

	/* ------- GPIO Group GPP_C ------- */
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
	PAD_NC(GPP_C2, NONE),
	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
	PAD_NC(GPP_C5, NONE),
	PAD_CFG_NF(GPP_C6, NONE, RSMRST, NF1),
	PAD_CFG_NF(GPP_C7, NONE, RSMRST, NF1),
	PAD_NC(GPP_C8, NONE),
	PAD_NC(GPP_C9, NONE),
	PAD_NC(GPP_C10, NONE),
	PAD_NC(GPP_C11, NONE),
	PAD_NC(GPP_C12, NONE),
	PAD_NC(GPP_C13, NONE),
	PAD_CFG_GPI_APIC_LOW(GPP_C14, UP_20K, DEEP),
	PAD_NC(GPP_C15, NONE),
	PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C20, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_C21, UP_20K, DEEP, NF1),
	PAD_CFG_GPO(GPP_C22, 1, PLTRST),
	PAD_CFG_GPI_SCI(GPP_C23, NONE, DEEP, LEVEL, INVERT),

	/* ------- GPIO Group GPP_F ------- */
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F1, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F3, UP_20K, DEEP, NF1),
	PAD_NC(GPP_F4, NONE),
	PAD_NC(GPP_F5, NONE),
	PAD_NC(GPP_F6, NONE),
	PAD_CFG_GPO(GPP_F7, 1, DEEP),
	PAD_NC(GPP_F8, NONE),
	PAD_CFG_GPO(GPP_F9, 1, DEEP),
	PAD_NC(GPP_F10, NONE),
	PAD_NC(GPP_F11, NONE),
	PAD_NC(GPP_F12, NONE),
	PAD_NC(GPP_F13, NONE),
	PAD_NC(GPP_F14, NONE),
	PAD_NC(GPP_F15, NONE),
	PAD_NC(GPP_F16, NONE),
	PAD_CFG_GPI_TRIG_OWN(GPP_F17, NONE, PLTRST, OFF, ACPI),
	PAD_NC(GPP_F18, NONE),
	PAD_NC(GPP_F19, NONE),
	PAD_NC(GPP_F20, NONE),
	PAD_CFG_GPI_TRIG_OWN(GPP_F21, DN_20K, DEEP, OFF, ACPI),
	PAD_NC(GPP_F22, NONE),
	PAD_NC(GPP_F23, NONE),

	/* ------- GPIO Group GPP_E ------- */
	PAD_NC(GPP_E0, NONE),
	PAD_CFG_GPO(GPP_E1, 0, PLTRST),
	PAD_CFG_GPI_SCI(GPP_E2, NONE, DEEP, LEVEL, INVERT),
	PAD_CFG_GPI_TRIG_OWN(GPP_E3, DN_20K, DEEP, OFF, ACPI),
	PAD_NC(GPP_E4, NONE),
	PAD_NC(GPP_E5, NONE),
	PAD_NC(GPP_E6, NONE),
	PAD_CFG_GPI_SMI(GPP_E7, NONE, PLTRST, EDGE_SINGLE, INVERT),
	PAD_NC(GPP_E8, NONE),
	PAD_NC(GPP_E9, NONE),
	PAD_NC(GPP_E10, NONE),
	PAD_NC(GPP_E11, NONE),
	PAD_NC(GPP_E12, NONE),
	PAD_NC(GPP_E13, NONE),
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
	PAD_NC(GPP_E15, NONE),
	PAD_CFG_GPI_TRIG_OWN(GPP_E16, DN_20K, DEEP, OFF, ACPI),
	PAD_NC(GPP_E17, NONE),
	PAD_NC(GPP_E18, NONE),
	PAD_NC(GPP_E19, NONE),
	PAD_NC(GPP_E20, NONE),
	PAD_NC(GPP_E21, NONE),
	PAD_NC(GPP_E22, NONE),
	PAD_NC(GPP_E23, NONE),

	/* ------- GPIO Community 5 ------- */

	/* ------- GPIO Group GPP_R ------- */
	PAD_CFG_NF(GPP_R0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_R1, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_R2, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_R3, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_R4, NONE, DEEP, NF1),
	PAD_NC(GPP_R5, NONE),
	PAD_NC(GPP_R6, NONE),
	PAD_NC(GPP_R7, NONE),
};

/* Early pad configuration in bootblock */
static const struct pad_config early_gpio_table[] = {
	PAD_CFG_NF(GPP_C20, UP_20K, DEEP, NF1), /* UART2_RXD */
	PAD_CFG_NF(GPP_C21, UP_20K, DEEP, NF1), /* UART2_TXD */
};

const struct pad_config *variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}
