/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBINIT_UTILS_H
#define LIBINIT_UTILS_H

#include <string>

void property_override(const std::string& prop, const std::string& value, bool add = true);

void set_ro_build_prop(const std::string &prop, const std::string &value, bool product = false);

struct prop_copy_pair {
	std::string src;
	std::string dest;
};

void apply_copy_pair(const struct prop_copy_pair* pairs, const int size);
#endif // LIBINIT_UTILS_H
