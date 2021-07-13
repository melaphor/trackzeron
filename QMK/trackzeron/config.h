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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x16d0
#define PRODUCT_ID   0x10aa
#define DEVICE_VER   0x0001
#define MANUFACTURER MK
#define PRODUCT      TRACKzeron

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 5

#define DIRECT_PINS { \
  { NO_PIN, C0, D3, NO_PIN, NO_PIN }, \
  { NO_PIN, E1, D2,     F7,     F3 }, \
  { NO_PIN, E0, D1,     F6,     F2 }, \
  {    C1, D5, D0,     F5,     F1 }, \
  { NO_PIN, D4, B7,     F4,     F0 } \
}


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Much more so than a keyboard, speed matters for a mouse. So we'll go for as high
   a polling rate as possible. */
#define USB_POLLING_INTERVAL_MS 1
#define USB_MAX_POWER_CONSUMPTION 100

