/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 * Copyright 2020 MK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"
#include "spi_master.h"
#include "pmw3360.h"
#include "analog.h"
#include "pointing_device.h"

void process_mouse(report_mouse_t* mouse_report);
void process_mouse_user(report_mouse_t* mouse_report, int16_t x, int16_t y);

#define LAYOUT( \
     k01, k02,           \
     k11, k12, k13, k14, \
     k21, k22, k23, k24, \
k30, k31, k32, k33, k34, \
     k41, k42, k43, k44 \
) { \
    {KC_NO, k01, k02, KC_NO, KC_NO}, \
    {KC_NO, k11, k12,   k13,   k14}, \
    {KC_NO, k21, k22,   k23,   k24}, \
    {k30,   k31, k32,   k33,   k34}, \
    {KC_NO, k41, k42,   k43,   k44} \
}

typedef union {
  uint32_t raw;
  struct {
    uint8_t    dpi_config;
  };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;

enum ploopy_keycodes {
    DPI_CONFIG = SAFE_RANGE,
    PLOOPY_SAFE_RANGE,
};
