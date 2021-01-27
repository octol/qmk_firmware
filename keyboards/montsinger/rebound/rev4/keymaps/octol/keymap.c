#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define PREV_TAB LCTL(KC_PGUP)
#define NEXT_TAB LCTL(KC_PGDN)

#define SV_AA RALT(KC_W)
#define SV_AE RALT(KC_Q)
#define SV_OE RALT(KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_all(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
   KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC, KC_ENT,  KC_ENT,  KC_ENT,  RAISE,   KC_RALT, KC_RGUI, KC_RCTL
),

[_LOWER] = LAYOUT_all(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_DEL,
  KC_ESC,  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, _______, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,   KC_HOME, KC_END,
  _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_COLN, KC_QUOT, KC_DQUO, KC_PGUP,  KC_UP,   KC_PGDN,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT,  KC_DOWN, KC_RGHT
),

[_RAISE] = LAYOUT_all(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, SV_AA,   SV_AE,   SV_OE,   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] =  LAYOUT_all(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, KC_F11,  KC_F12,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_esc[]  = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_lsft[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_tab[]  = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_mins[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {KC_X, KC_V, COMBO_END};

const uint16_t PROGMEM combo_esc2[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_bsls[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_lt[]   = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_coln[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_gt[]   = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_rsft[] = {KC_J, KC_L, COMBO_END};
//const uint16_t PROGMEM combo_ent2[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_unds[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_del, KC_DEL),
  COMBO(combo_bspc, KC_BSPC),
  COMBO(combo_lsft, KC_LSFT),
  COMBO(combo_tab, KC_TAB),
  COMBO(combo_mins, KC_MINS),
  COMBO(combo_ent, KC_ENT),

  COMBO(combo_esc2, KC_ESC),
  COMBO(combo_bsls, KC_BSLS),
  COMBO(combo_lt, KC_LT),
  COMBO(combo_coln, KC_COLN),
  COMBO(combo_gt, KC_GT),
  COMBO(combo_rsft, KC_RSFT),
  /*COMBO(combo_ent2, KC_ENT),*/
  COMBO(combo_quot, KC_QUOT),
  COMBO(combo_unds, KC_UNDS),
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code16(S(KC_VOLD));
    } else {
      tap_code16(KC_VOLU);
    }
}
