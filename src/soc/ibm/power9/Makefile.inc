## SPDX-License-Identifier: GPL-2.0-only

ifeq ($(CONFIG_CPU_IBM_POWER9),y)

bootblock-y += bootblock.c
bootblock-y += rom_media.c
romstage-y += rom_media.c
romstage-y += romstage.c
romstage-y += mvpd.c
romstage-y += vpd.c
romstage-y += powerbus.c
romstage-y += istep_8_1.c
romstage-y += istep_8_2.c
romstage-y += istep_8_3.c
romstage-y += istep_8_4.c
romstage-y += istep_10_10.c
romstage-y += istep_10_12.c
romstage-y += istep_10_13.c
romstage-y += istep_13_2.c
romstage-y += istep_13_3.c
romstage-y += istep_13_4.c
romstage-y += istep_13_6.c
romstage-y += istep_13_8.c
romstage-y += istep_13_9.c
romstage-y += istep_13_10.c
romstage-y += istep_13_11.c
romstage-y += istep_13_13.c
romstage-y += istep_14_1.c
romstage-y += istep_14_2.c
romstage-y += istep_14_3.c
romstage-y += istep_14_5.c
romstage-y += i2c.c
romstage-y += ccs.c
romstage-y += mcbist.c
romstage-y += timer.c
romstage-y += fsi.c
romstage-y += sbeio.c
ramstage-y += chip.c
ramstage-y += homer.c
ramstage-y += rom_media.c
ramstage-y += timer.c
ramstage-y += istep_18_11.c
ramstage-y += istep_18_12.c
ramstage-y += mvpd.c
ramstage-y += vpd.c
ramstage-y += tor.c
ramstage-y += rs4.c
ramstage-y += powerbus.c
ramstage-y += pstates.c
ramstage-y += xive.c
ramstage-y += int_vectors.S
ramstage-y += i2c.c
ramstage-y += occ.c
ramstage-y += fsi.c

endif