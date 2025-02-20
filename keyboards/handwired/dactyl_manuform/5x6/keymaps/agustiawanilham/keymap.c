#ifdef USE_VIM
#include "qmk-vim/src/vim.h"
#include "qmk-vim/src/modes.h"
#endif

#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif  // ACHORDION_ENABLE

#ifdef ORBITAL_MOUSE_ENABLE
#include "features/orbital_mouse.h"
#endif  // ORBITAL_MOUSE_ENABLE

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
  TOG_VIM                     // Toggle vim mode
};

// Home row mods for QWERTY layer for windows and linux
#define QHOME_Z LGUI_T(KC_Z)
#define QHOME_X LALT_T(KC_X)
#define QHOME_C LCTL_T(KC_C)
#define QHOME_V LSFT_T(KC_V)
#define QHOME_B HYPR_T(KC_B)
#define QHOME_PGUP LT(FUNCTION,KC_PGUP)

#define QHOME_N    HYPR_T(KC_N)
#define QHOME_M    RSFT_T(KC_M)
#define QHOME_COMM CTL_T(KC_COMM)
#define QHOME_DOT  ALT_T(KC_DOT)
#define QHOME_RBC  RALT_T(KC_RBRC)
#define QHOME_SCLN LGUI_T(KC_SCLN)

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

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  [BASE] = LAYOUT_5x6(
    KC_EQL,        KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                         KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,
    KC_TAB,        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                         KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,  KC_BSLS,
    KC_LCTL,        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                        KC_H,   KC_J,   KC_K,   KC_L,  QHOME_SCLN, KC_QUOT,
    KC_LSFT, QHOME_Z,QHOME_X,QHOME_C,QHOME_V,QHOME_B,                           QHOME_N, QHOME_M,  QHOME_COMM,QHOME_DOT ,KC_SLSH,KC_RSFT,
    QHOME_PGUP,KC_PGDN,                                                            KC_LBRC, QHOME_RBC,
    MO(CURSOR),  LT(NUMBER,KC_BSPC),                                            LT(MOUSE,KC_SPC), MO(SYMBOL),
    LT(FUNCTION,KC_DEL),  KC_ESC,                                               KC_ENT, QK_LEAD,
    RGUI(KC_SPC),  OSM(MOD_LSFT),                                               OSM(MOD_RSFT), KC_DOWN
  ),

  [CURSOR] = LAYOUT_5x6(
    QK_BOOT,CG_LSWP,CG_LNRM,_______,_______,TOG_VIM,                                TOG_MAC_LINUX,_______,_______,_______,_______,_______,
    _______,_______,C(KC_W),_______,_______,_______,                                MY_COPY, KC_TAB,  S(KC_TAB),RGUI(KC_SPC),MY_PASTE,MY_CUT,
    _______,ALT_TAB,G(KC_TILD),_______,C(KC_F),C(KC_V),                                KC_LEFT,   KC_DOWN, KC_UP,     KC_RGHT,  CAPS_WORD,KC_CAPS,
    _______,KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,C(KC_C),                                KC_HOME,   KC_PGDN, KC_PGUP,   KC_END,   QK_REP, KC_DEL,
    RGUI(KC_C),RGUI(KC_V),                           _______,_______,
    _______,_______,            QK_LLCK,_______,
    _______,_______,            _______,_______,
    _______,_______,            _______,_______

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
    _______,OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_LCTL),OSM(MOD_LSFT),_______,                                   KC_MYCM,  KC_F1,     KC_F2,      KC_F3,     KC_F12,     KC_PSCR,
    _______,_______,                                                                                      KC_APP,  KC_HELP,
    _______,_______,            _______,KC_MUTE,
    _______,_______,            _______,_______,
    _______,_______,            KC_VOLU,KC_VOLD
  ),

  [SYMBOL] = LAYOUT_5x6( KC_TILD, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_QUES,                       C(KC_6),_______,_______,_______,_______,_______,
                        KC_SLSH, KC_LCBR, KC_GRV,  KC_QUOT, KC_RCBR, KC_AT,                          C(KC_SPC), KC_TAB, S(KC_TAB),C(KC_ENT),RGUI(KC_SPC),_______,
                        KC_HASH, KC_CIRC, KC_DQUO, KC_UNDS, KC_DLR,  KC_PERC,                        KC_BSPC, KC_ENT, KC_SPC,  KC_DEL,_______,_______,
                        KC_EXLM, KC_LT,   KC_MINS, KC_EQL,  KC_GT,   KC_PPLS,                        QK_REP, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), _______,
                        KC_AMPR, KC_PIPE,                                    _______ ,_______,
                        KC_COLN ,KC_ASTR,            _______,_______,
                        _______,_______,            _______,_______,
                        _______,_______,            _______,_______
  ),
  [MOUSE] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                   _______  , _______ , _______ , _______ ,_______ ,_______ ,
    _______,_______,OM_BTN1,OM_U,OM_BTN2,_______,                            _______,_______,_______,_______ ,_______,_______,
    _______,_______,OM_L,OM_D,OM_R,OM_SLOW,                             _______,_______,_______,_______,_______,_______,
    _______,_______,_______,OM_W_D,OM_W_U,_______,                             _______,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI,_______,
    _______,_______,                            _______ ,_______,
    OM_U,KC_BTN2,            _______,_______,
    _______,KC_BTN3,            _______,_______,
    _______,KC_BTN4,            _______,_______

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

#ifdef ACHORDION_ENABLE
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows outside the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.
  const uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  if (!(1 <= row && row <= 3)) { return true; }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
      return 800;  // Use a timeout of 800 ms.
  }
}

#endif  // ACHORDION_ENABLE

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Ring fingers
    case QHOME_X:
    case QHOME_DOT:
      return TAPPING_TERM + 50;

    // Pinkies
    case QHOME_Z:
    case QHOME_C:
      return TAPPING_TERM + 50;

    // Middle fingers
    case QHOME_COMM:
    case QHOME_SCLN:
      return TAPPING_TERM - 10;

    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case QHOME_N:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

void leader_start_user(void) {
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_V)) {
        toggle_vim_mode();
    }
}

bool is_alt_tab_active = false;
bool is_mac_mode = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process case modes
  if (!process_vim_mode(keycode, record)) {
      return false;
  }
#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) { return false; }
#endif  // ACHORDION_ENABLE
#ifdef ORBITAL_MOUSE_ENABLE
  if (!process_orbital_mouse(keycode, record)) { return false; }
#endif  // ORBITAL_MOUSE_ENABLE

  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LGUI);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;

    case KC_ENTER:
      if (record->event.pressed) {
        if (is_alt_tab_active) {
          unregister_code(KC_LGUI);
          is_alt_tab_active = false;
          return false;
        }
      }
      return true;

    case KC_Q:
      if (record->event.pressed) {
        if (is_alt_tab_active) {
          register_code(KC_Q);
          return false;
        }
      }
      return true;

    case KC_ESCAPE:
      if (record->event.pressed) {
        if (is_alt_tab_active) {
          register_code(KC_ESCAPE);
          unregister_code(KC_LGUI);
          unregister_code(KC_ESCAPE);
          is_alt_tab_active = false;
          return false;
        }
      }
      return true;

    case TOG_MAC_LINUX:
      if (record->event.pressed) {
        // Toggle between macOS and Linux modes
        is_mac_mode = !is_mac_mode;
        toggle_vim_for_mac();
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
      return false; // Skip all further processing of this key

    case MY_CUT:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_X) : LCTL(KC_X));
        }
        return false; // Skip all further processing of this key

    case TOG_VIM:
      if (record->event.pressed) {
        toggle_vim_mode();
      }
      return false; // Skip all further processing of this key

    default:
      return true;
  }
}

void matrix_scan_user(void) {
  /* achordion_task(); */
  if (is_alt_tab_active) {
    if (IS_LAYER_OFF(CURSOR)){
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }
}

void housekeeping_task_user(void) {
#ifdef ACHORDION_ENABLE
  achordion_task();
#endif  // ACHORDION_ENABLE
#ifdef RGB_MATRIX_ENABLE
  lighting_task();
#endif  // RGB_MATRIX_ENABLE
#ifdef ORBITAL_MOUSE_ENABLE
  orbital_mouse_task();
#endif  // ORBITAL_MOUSE_ENABLE
#ifdef SELECT_WORD_ENABLE
  select_word_task();
#endif  // SELECT_WORD_ENABLE
#ifdef SENTENCE_CASE_ENABLE
  sentence_case_task();
#endif  // SENTENCE_CASE_ENABLE
}
