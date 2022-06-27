/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_utils.h>
#include "vendor_init.h"

#include <android-base/properties.h>

using android::base::GetProperty;

struct prop_copy_pair config[] = {
	{
		.src = "ro.boot.debug_level",
		.dest = "ro.debug_level",
	},
	{
		.src = "ro.boot.bootloader",
		.dest = "ro.build.PDA",
	},
};

void vendor_load_properties() {
    std::string model;

    model = GetProperty("ro.boot.product.model", "");
    if (model.empty()) {
       model = GetProperty("ro.boot.em.model", "");
    }
    set_ro_build_prop("model", model, true);
    set_ro_build_prop("product", model, false);

    apply_copy_pair(config, sizeof(config)/sizeof(struct prop_copy_pair));
}
