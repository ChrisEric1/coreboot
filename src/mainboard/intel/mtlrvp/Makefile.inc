## SPDX-License-Identifier: GPL-2.0-or-later

all-$(CONFIG_CHROMEOS) += chromeos.c

bootblock-y += bootblock.c

romstage-y += romstage.c

ramstage-y += ec.c
ramstage-y += mainboard.c

smm-$(CONFIG_HAVE_SMI_HANDLER) += smihandler.c

VARIANT_DIR:=$(call strip_quotes,$(CONFIG_VARIANT_DIR))
BASEBOARD_DIR:=$(call strip_quotes,$(CONFIG_BASEBOARD_DIR))

subdirs-y += variants/baseboard/$(BASEBOARD_DIR)
subdirs-y += variants/baseboard/$(BASEBOARD_DIR)/memory
subdirs-y += variants/$(VARIANT_DIR)

CPPFLAGS_common += -I$(src)/mainboard/$(MAINBOARDDIR)/variants/baseboard/include
CPPFLAGS_common += -I$(src)/mainboard/$(MAINBOARDDIR)/variants/baseboard/$(BASEBOARD_DIR)/include
