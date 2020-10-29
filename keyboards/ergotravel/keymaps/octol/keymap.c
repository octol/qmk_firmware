#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

#define CTL_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    RESET,            _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,          _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, _______, KC_LGUI, KC_LALT,          LOWER,   KC_SPC,           KC_ENT,  RAISE,            KC_RALT, KC_RGUI, _______, KC_RCTL
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,          _______,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  _______, KC_LCBR,  KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, _______,          _______,     KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,  KC_COLN, KC_DQUO, \
  _______, _______,  _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,          _______,     KC_COLN, KC_QUOT, KC_DQUO, _______, _______, _______, \
  _______, _______,  _______, _______,          _______, _______,          _______, _______,              _______, _______, _______, _______  \

  ),

  [_RAISE] = LAYOUT(

  KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,    KC_5,     _______,          _______,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,  \
  _______, _______, KC_BTN1,KC_MS_U,KC_BTN2, _______,  _______,          _______,   KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, KC_MS_L,KC_MS_D,KC_MS_R, _______,  _______,          _______,   KC_HOME,   KC_PGUP, KC_PGDN, KC_END,  _______, _______, \
  _______, _______, _______,_______,         _______,  _______,          _______,   _______,            _______, _______, _______, _______  \

  ),

  [_ADJUST] = LAYOUT(
     _______, _______, _______, _______, _______, _______, _______,         _______,  _______, _______, _______, _______, _______, _______,
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
     _______, _______, _______, _______, _______, _______, _______,         _______,  _______, _______, _______, KC_F11,  KC_F12,  _______,
     _______, _______, _______, _______,          _______, _______,         _______,  _______,          _______, _______, _______, _______
  )

};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
