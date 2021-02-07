/*
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

// Layer shorthand
enum layer_names {
    _BASE,
    _SYMB,
    _NUM,
    _ADJUST,
};

#define PREV_TAB LCTL(KC_PGUP)
#define NEXT_TAB LCTL(KC_PGDN)

#define RCTL_QUOT RCTL_T(KC_QUOT)
#define RALT_DOT  RALT_T(KC_DOT)

#define SV_AA RALT(KC_W)
#define SV_AE RALT(KC_Q)
#define SV_OE RALT(KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------'
     *          | LCTRL  | FN     | LALT   | LGUI   |      SPACE      |      SPACE      | LEFT   | DOWN  | UP      | RIGHT  |
     *          '-----------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_ortho_hhkb(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME, KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_LCTL, KC_LGUI, KC_LALT, MO(_SYMB),        KC_SPC,  KC_ENT,           MO(_NUM),KC_RALT, KC_RGUI, KC_RCTRL
    ),

    [_SYMB] = LAYOUT_ortho_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, _______, _______, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,  _______, PREV_TAB,
        _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, KC_COLN, KC_QUOT, KC_DQUO, _______, _______, NEXT_TAB,
                 _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT_ortho_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, SV_AA,   SV_AE,   SV_OE,   _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
                 _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_ortho_hhkb(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_TOG, KC_APP,  _______, _______, RESET,   _______, _______, _______, _______, _______, KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, _______,
                 _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
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
const uint16_t PROGMEM combo_dquo[] = {KC_COMM, KC_DOT, COMBO_END};

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
  COMBO(combo_dquo, KC_DQUO),
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMB, _NUM, _ADJUST);
}
