#pragma once

#define MASTER_LEFT

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 140
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY

#define FLOW_TAP_TERM 140

// Enable Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
#define CHORDAL_HOLD

// Use Left Ctrl + Right Ctrl to activate the Command feature.
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)

// Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

#define SELECT_WORD_TIMEOUT 2000  // When idle, clear state after 2 seconds.

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_8BIT

#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.

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
