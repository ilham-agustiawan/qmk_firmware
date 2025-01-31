/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#define MASTER_LEFT
//#define MASTER_RIGHT

//#define EE_HANDS

/* QMK */

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
// #define TAPPING_TERM_PER_KEY
// #define TAPPING_FORCE_HOLD_PER_KEY
#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY

// When idle, turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

#define SELECT_WORD_TIMEOUT 2000  // When idle, clear state after 2 seconds.

#define ACHORDION_STREAK

#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.

// Use Left Ctrl + Right Ctrl to activate the Command feature.
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       20
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
