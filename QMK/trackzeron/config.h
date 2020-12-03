/*
Copyright 2020 MK

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x6d6b //MK
#define PRODUCT_ID   0x747a //TZ 
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

//#define UNUSED_PINS {
//  D6, D7, B6, B5, E7, E6, C2, C7, A0, A1, A2, A3,
//}

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

//set polling rate in ms
#define USB_POLLING_INTERVAL_MS 1

//send more than one key per scan
#define QMK_KEYS_PER_SCAN 4
