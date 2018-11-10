#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _NL 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS/FN|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  LT(_NL, KC_CAPS), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_FL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |~ ` |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |KP7|KP8|KP9|   |   |   |PrtSc|Ins |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   |KP4|KP5|KP6|   |   |        |Hme |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |KP1|KP2|KP3|   |   McL|MsU|End |
   * |----------------------------------------------------------------|
   * |    |    |    |         KP0           |Dot|   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_GRV ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,  KC_P7,  KC_P8,  KC_P9,_______,_______,_______, KC_PSCR,KC_INS, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,  KC_P4,  KC_P5,  KC_P6,_______,_______,        _______,KC_HOME, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,  KC_P1,  KC_P2,  KC_P3,_______,KC_BTN1, KC_MS_U, KC_END, \
  _______,_______,_______,                 KC_P0,               KC_PDOT,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),

  /* Keymap _NL: "New" Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |    |
   * |----------------------------------------------------------------|
   * |     |LMu|   |SMu|   |   |   |  B|  U|  S|  I|  E|  R|PrtSc|    |
   * |----------------------------------------------------------------|
   * |      |   |PMu|PP |NMu|   |Lef|Dow|Up |Rig|   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |VUp|VDn|VMt|   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[_NL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,_______,_______ ,  \
  _______,KC_MSEL,_______,KC_MSTP,_______, _______,_______,   KC_B,   KC_U,   KC_S,   KC_I,   KC_E,   KC_R, KC_PSCR,_______, \
  _______,_______,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,_______,_______,        _______,_______, \
  _______,KC_VOLU,KC_VOLD,KC_MUTE,_______,_______, _______,_______,_______,_______,_______,_______, _______, _______, \
  _______,_______,_______,                 _______,               _______,_______,_______,_______,_______, _______),
};
