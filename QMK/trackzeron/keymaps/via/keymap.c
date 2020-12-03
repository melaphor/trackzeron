/* Copyright 2020 MK
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
#include QMK_KEYBOARD_H

#define LCLK M(0)
#define RCLK M(1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [0] = LAYOUT(
        KC_PAUSE, KC_TAB,
        KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_SLASH, KC_KP_0,
        KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,
 KC_KP_4, LCLK, RCLK, KC_KP_5, KC_KP_6,
 	    KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT),
 [1] =  LAYOUT( \
      KC_TRNS, KC_TRNS,           \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),
[2] =  LAYOUT( \
     KC_TRNS, KC_TRNS,           \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),
[3] =  LAYOUT( \
     KC_TRNS, KC_TRNS,           \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {               
    case LCLK:
      if (record->event.pressed) {
        register_code(KC_MS_BTN1);
      } else {
        unregister_code(KC_MS_BTN1);
      }
      break;
     
     case RCLK:
      if (record->event.pressed) {
        register_code(KC_MS_BTN2);
      } else {
        unregister_code(KC_MS_BTN2);
      }
      break; 
  }
  return true;
}
