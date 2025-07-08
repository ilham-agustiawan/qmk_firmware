#include QMK_KEYBOARD_H

enum layers {
  BASE,
  CURSOR,
  NUMBER,
  FUNCTION,
  SYMBOL,
  MOUSE,
  WIN,
};


enum custom_keycodes {
  CAPS_WORD = SAFE_RANGE,
  ALT_TAB,
  TOG_MAC_LINUX,              // Toggle between macOS and Linux
  MY_COPY,                    // Custom keycode for copy
  MY_PASTE,                   // Custom keycode for paste
  MY_CUT,                     // Custom keycode for cut
  MY_CLOSE,                   // Custom keycode for close
  CMD_PAL,                    // Custom keycode for command palette
  CMD_CTRL,               // Custom keycode for command swap
  LEADER_TMUX,                // custom keycode for leader key to activate tmux-like behavior
  BSPC_WORD,
  MY_COLON,
};

// Home row mods for QWERTY layer for windows and linux
#define QHOME_Z LGUI_T(KC_Z)
#define QHOME_X LALT_T(KC_X)
#define QHOME_C LCTL_T(KC_C)
#define QHOME_V LSFT_T(KC_V)
#define QHOME_B HYPR_T(KC_B)
#define QHOME_PGUP LT(FUNCTION,KC_PGUP)
#define QHOME_PGDN LT(NUMBER,KC_PGDN)

#define QHOME_N    HYPR_T(KC_N)
#define QHOME_M    RSFT_T(KC_M)
#define QHOME_COMM CTL_T(KC_COMM)
#define QHOME_DOT  ALT_T(KC_DOT)
#define QHOME_RBC  RALT_T(KC_RBRC)
#define QHOME_SCLN LGUI_T(KC_SCLN)
#define QHOME_LBRC LT(MOUSE,KC_LBRC)

#define CAPS_WORD QK_CAPS_WORD_TOGGLE

// For windows and linux
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Gui  |  Alt  | Ctrl  | Shift |   | Shift | Ctrl  |  Alt  |  Gui  |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+


// For mac
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Ctrl  |  Alt  | Gui  | Shift |   | Shift |  Gui |  Alt  |  Ctrl  |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+

// clang-format off
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  [BASE] = LAYOUT_5x6(
    KC_EQL,  KC_1,   KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,
    KC_TAB,  KC_Q,   KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,  KC_BSLS,
    CMD_CTRL,    KC_A,   KC_S,     KC_D,     KC_F,     KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,  QHOME_SCLN, KC_QUOT,
    OSM(MOD_LSFT), QHOME_Z,   QHOME_X,  QHOME_C,  QHOME_V,  QHOME_B,             QHOME_N, QHOME_M,  QHOME_COMM,QHOME_DOT ,KC_SLSH,OSM(MOD_RSFT),
    QHOME_PGUP, QHOME_PGDN,                                                          KC_LBRC, QHOME_RBC,
    MO(CURSOR), KC_BSPC,                                                        LT(MOUSE,KC_SPC), MO(SYMBOL),
    XXX, KC_ESC,                                                                KC_ENT, QK_REP,
    XXX,XXX,                                                                    OSM(MOD_RSFT), KC_MEH
  ),

  [CURSOR] = LAYOUT_5x6(
    _______,CG_LSWP,CG_LNRM,TOG_MAC_LINUX,_______,_______,                          _______,_______,_______,_______,_______,_______,
    _______,MY_CLOSE,C(KC_W),MY_COPY,MY_PASTE,_______,                              _______,S(KC_TAB),KC_TAB,_______,_______,_______,
    CAPS_WORD,ALT_TAB,G(KC_TILD),_______,LEADER_TMUX,QK_REP,                        KC_LEFT,KC_DOWN, KC_UP,KC_RGHT,CAPS_WORD,_______,
    KC_CAPS,OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_LCTL),OSM(MOD_LSFT),_______,        KC_HOME,KC_PGDN, KC_PGUP,KC_END,_______,_______,
    C(S(KC_C)),C(S(KC_V)),                           _______,_______,
    _______,_______,            QK_LLCK,_______,
    _______,_______,            _______,_______,
    _______,QK_BOOT,            _______,_______
  ),

  [SYMBOL] = LAYOUT_5x6(
        KC_GRV,  KC_LBRC, KC_LPRN, KC_RPRN,  KC_RBRC, KC_DOT,                        _______,_______,_______,_______,_______,_______,
        KC_EXLM, KC_ASTR, KC_LCBR, KC_RCBR,  KC_SCLN, KC_QUES,                       BSPC_WORD, S(KC_TAB), KC_TAB ,C(KC_ENT),CMD_PAL,_______,
        KC_HASH, KC_CIRC, KC_EQL,  KC_UNDS,  KC_DLR,  KC_AT,                         KC_BSPC, KC_ENT, KC_SPC, KC_DEL, MY_COLON,_______,
        KC_TILD, KC_LT,   KC_PPLS, KC_MINS,  KC_GT,   KC_SLSH,                       KC_ESC, OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RGUI), _______,
                   KC_AMPR, KC_PIPE,                                                                _______ ,_______,
                          KC_COLN ,KC_PERC,                                                              _______,_______,
                          _______,_______,                                                               _______,_______,
                          _______,_______,                                                               _______,_______
  ),

  [NUMBER] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                                 KC_TILD,  KC_DLR,   KC_HASH,   KC_AT,   KC_EXLM,    KC_CIRC,
    _______,_______,_______,_______,_______,_______,                                 KC_LT,    KC_7,     KC_8,      KC_9,    KC_COLN,    KC_PERC,
    _______,_______,_______,_______,_______,_______,                                 KC_GT,    KC_4,     KC_5,      KC_6,    KC_PMNS,    KC_PPLS,
    _______,OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_LCTL),OSM(MOD_LSFT),QK_LLCK,         KC_0,   KC_1,     KC_2,      KC_3,    KC_PSLS,    KC_PAST,
    _______,_______,                                                                              KC_LPRN,  KC_RPRN,
    _______,_______,            _______,_______,
    _______,_______,            _______,_______,
    _______,_______,            _______,_______

  ),


  [FUNCTION] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                                   KC_MSEL,  KC_MPLY,   KC_MPRV,    KC_MNXT,   KC_MSTP,    KC_CIRC,
    _______,_______,_______,_______,_______,_______,                                   KC_MAIL,  KC_F7,     KC_F8,      KC_F9,     KC_F10,     KC_WSCH,
    _______,_______,_______,_______,_______,_______,                                   KC_CALC,  KC_F4,     KC_F5,      KC_F6,     KC_F11,     KC_WFAV,
    _______,OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_LCTL),OSM(MOD_LSFT),_______,           KC_MYCM,  KC_F1,     KC_F2,      KC_F3,     KC_F12,     KC_PSCR,
    _______,_______,                                                                                      KC_APP,  KC_HELP,
    _______,_______,            _______,KC_MUTE,
    _______,_______,            _______,_______,
    _______,_______,            KC_VOLU,KC_VOLD
  ),

  [MOUSE] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                   _______  , _______ , _______ , _______ ,_______ ,_______ ,
    _______,_______,KC_WH_L,KC_MS_U,KC_WH_R,_______,                            _______,_______,_______,_______ ,_______,_______,
    _______,KC_BTN3,KC_MS_L,KC_MS_D,KC_MS_R,_______,                             _______,KC_ACL0,KC_ACL1,KC_ACL2,_______,_______,
    _______,KC_BTN4,KC_BTN5,KC_WH_D,KC_WH_U,_______,                             _______,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI,_______,
    _______,_______,                            _______ ,_______,
    _______,KC_BTN1,            _______,_______,
    _______,KC_BTN2,            _______,_______,
    _______,_______,            _______,_______

  ),
};


#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_MINS:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QHOME_X:
    case QHOME_Z:
    case QHOME_SCLN:
    case QHOME_RBC:
    case QHOME_C:
      return TAPPING_TERM + 25;

    case QHOME_V:
    case QHOME_M:
      return TAPPING_TERM - 25;

    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case QHOME_N:
    case QHOME_B:
    case QHOME_X:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

/* bool get_chordal_hold( */
/*         uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, */
/*         uint16_t other_keycode, keyrecord_t* other_record) { */
/*   switch (tap_hold_keycode) { */
/*     case QHOME_V: */
/*     case QHOME_M: */
/*       return true; */
/*   } */
/*   return get_chordal_hold_default(tap_hold_record, other_record); */
/* } */

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
  // Only apply Flow Tap when following a letter key, and not hotkeys.
  if (get_tap_keycode(prev_keycode) <= KC_Z &&
      (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) == 0) {
    switch (keycode) {
      // Bottom row mods - standard timing
      case QHOME_Z:      // GUI
      case QHOME_SCLN:   // GUI
      case QHOME_X:      // Alt
      case QHOME_DOT:    // Alt
      case QHOME_RBC:    // Right Alt
        return FLOW_TAP_TERM;

      case QHOME_C:      // Control
      case QHOME_COMM:   // Control
        return FLOW_TAP_TERM - 25;
    }
  }
  return 0;  // Disable Flow Tap otherwise.
}

bool is_alt_tab_active = false;
bool is_mac_mode = true;  // Initialize to true for macOS
static uint16_t my_esc_ctrl_cmd_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
uprintf("kc: %s\n", get_keycode_string(keycode));
  // Process case modes
    //
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          if (is_mac_mode) {
            register_code(KC_LGUI);
          } else {
            register_code(KC_LALT);
          }
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;

    case KC_ENTER:
      if (record->event.pressed) {
        if (is_alt_tab_active) {
          if (is_mac_mode) {
            unregister_code(KC_LGUI);
          } else {
            unregister_code(KC_LALT);
          }
          is_alt_tab_active = false;
          return false;
        }
      }
      return true;

    case KC_ESCAPE:
        if (record->event.pressed) {
            if (is_alt_tab_active) {
                // register_code(KC_ESCAPE); // Sending actual ESC to OS can be good.
                // tap_code(KC_ESCAPE); // More robust way to send ESC if that's the goal.
                                      // If the goal is just to cancel *your* alt-tab mode:
                if (is_mac_mode) {
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_LALT);
                }
                unregister_code(KC_TAB); // Ensure Tab is also released
                // unregister_code(KC_ESCAPE); // if you registered it above
                is_alt_tab_active = false;
                // If you want ESC to also be sent to the OS to close dialogs/menus:
                // return true; // after unregistering your modifiers.
                // Or, tap_code(KC_ESCAPE) before unregistering.
                // For now, let's assume ESC just cancels your mode and sends nothing extra or sends ESC *before* cancelling.
                // To send ESC to cancel OS's Alt-Tab visual AND your mode:
                tap_code(KC_ESCAPE); // Send an actual ESC key press to the OS
                // The modifiers will be released by the tap_code if they were part of it,
                // but since they are held by your logic, they are still held.
                // So, unregister them manually after.
                // (The lines above for unregistering LGUI/LALT/TAB are already correct for cancelling your mode)
                return false; // We handled it.
            }
        }
        return true;
    case KC_BSPC: {
      static uint16_t registered_key = KC_NO;
      if (record->event.pressed) {  // On key press.
        const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
        uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
        uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
        if (shift_mods) {  // At least one shift key is held.
          registered_key = KC_DEL;
          // If one shift is held, clear it from the mods. But if both
          // shifts are held, leave as is to send Shift + Del.
          if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SHIFT);
          }
        } else {
          registered_key = KC_BSPC;
        }

        register_code(registered_key);
        set_mods(mods);
      } else {  // On key release.
        unregister_code(registered_key);
      }
    } return false;

    case TOG_MAC_LINUX:
      if (record->event.pressed) {
        // Toggle between macOS and Linux modes
        is_mac_mode = !is_mac_mode;
      }
      return false; // Skip all further processing of this key

    case CMD_PAL:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_SPC) : LALT(KC_SPC));
        }
        return false; // Skip all further processing of this key

    case MY_COPY:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_C) : LCTL(KC_C));
        }
        return false;

    case MY_PASTE:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_V) : LCTL(KC_V));
        }
        return false;

    case MY_CUT:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_X) : LCTL(KC_X));
        }
        return false; // Skip all further processing of this key

    case MY_CLOSE:
        if (record->event.pressed) {
            if (is_mac_mode) {
                tap_code16(LGUI(KC_Q));
            } else {
                tap_code16(LALT(KC_F4));
            }
        }
        return false; // Skip all further processing of this key

    case CMD_CTRL:
        if (record->event.pressed) {
            // Keydown
            my_esc_ctrl_cmd_timer = timer_read(); // Start the timer
            if (is_mac_mode) {
              register_code(KC_LGUI); // Or KC_RGUI depending on your preference
            } else {
              register_code(KC_LCTL); // Or KC_RCTL
            }
        } else {
            // Keyup
            if (timer_elapsed(my_esc_ctrl_cmd_timer) < TAPPING_TERM) {
              // It's a tap
              if (is_mac_mode) {
                unregister_code(KC_LGUI);
              } else {
                unregister_code(KC_LCTL);
              }
              tap_code(KC_ESC);
            } else {
              // It's a hold
              if (is_mac_mode) {
                unregister_code(KC_LGUI);
              } else {
                unregister_code(KC_LCTL);
              }
            }
        }
        return false; // Skip all other key processing

    case BSPC_WORD:
        if (record->event.pressed) {
            if (is_mac_mode) {
                // Mac: Option + Backspace
                tap_code16(LALT(KC_BSPC));
            } else {
                // Linux/Windows: Ctrl + Backspace
                tap_code16(LCTL(KC_BSPC));
            }
        }
        return false; // Skip all further processing of this key

    case LEADER_TMUX:
        if (record->event.pressed) {
            tap_code16(LCTL(KC_F)); // Send Ctrl + F to activate tmux-like behavior
         }
        return false;

    case MY_COLON:
        if (record->event.pressed) {
            SEND_STRING(":"); // Send colon or semicolon based on OS
        }
        return false; // Skip all further processing of this key

    default:
      return true;
  }
}

void matrix_scan_user(void) {
  if (IS_LAYER_OFF(CURSOR) && is_alt_tab_active) {
      if (is_mac_mode) {
        unregister_code(KC_LGUI);
      } else {
        unregister_code(KC_LALT);
      }
      is_alt_tab_active = false;
    }
}
