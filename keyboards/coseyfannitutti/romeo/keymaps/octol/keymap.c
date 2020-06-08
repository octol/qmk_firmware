/* Copyright 2019 COSEYFANNITUTTI
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

#define CT_PGUP     LCTL(KC_PGUP)
#define CT_PGDN     LCTL(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
      KC_LSFT, KC_SLSH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, MO(1), KC_RALT, MO(3), MO(2) ),

  // Symbol and vim arrow layer
  [1] = LAYOUT_all(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_MINS, KC_EQL,  KC_SLSH, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______ ),

  // Extra Nav layer
  [2] = LAYOUT_all(
      _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, _______, _______, _______, _______, _______, KC_PSCR, KC_INS,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  CT_PGUP, CT_PGDN, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______ ),

  // System layer
  [3] = LAYOUT_all(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, RESET,
      KC_VOLU, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______,
      KC_VOLD, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SCLN, KC_QUOT, KC_MINS, KC_EQL,  KC_SLSH, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______ )
};
