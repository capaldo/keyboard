// ——————————————————————————————————————————————————————————————————
// Copyright 2018 MechMerlin
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ——————————————————————————————————————————————————————————————————

// ——————————————————————————————————————————————————————————————————
// defaults
// ——————————————————————————————————————————————————————————————————
#pragma once
#include "config_common.h"

// USB Device descriptor parameter 
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    1upkeyboards
#define PRODUCT         1up60hse
#define DESCRIPTION     A custom 60% keyboard

// key matrix size 
#define MATRIX_ROWS 5
#define MATRIX_COLS 14
#define MATRIX_ROW_PINS { B3, B2, B1, B0, D4 }
#define MATRIX_COL_PINS { C7, F7, F6, F5, F4, F1, E6, D1, D0, D2, D3, D5, D6, D7 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW
#define BACKLIGHT_PIN B7
#define BACKLIGHT_BREATHING
#define BACKLIGHT_LEVELS 5
#define RGB_DI_PIN F0
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#endif

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 5

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap 
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack 
#define LOCKING_RESYNC_ENABLE
// ——————————————————————————————————————————————————————————————————

// ——————————————————————————————————————————————————————————————————
// leader key macros
// ——————————————————————————————————————————————————————————————————
// set the timeout for leader key
#define LEADER_TIMEOUT 300

