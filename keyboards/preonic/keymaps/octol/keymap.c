/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

/* Combo map
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |     ESC     |      |      |      |     ESC     |     BSLS    |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |     BSPC   TAB     |      |     LT     COLN   GT      |      |      |
 * |------+------+------+------+------+------|-ENT--+------+------+------+------+------|
 * |      |      |     MINS   ENTER   |      |     QUOT   UNDS    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |Ctrl/Esc| A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |      | Gui  | Alt  |Lower |    Space    |Raise | Alt  | Gui  |      | Ctrl |
     * `-----------------------------------------------------------------------------------'
     */
	[_QWERTY] = LAYOUT_preonic_grid( \
      KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, \
      KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
      LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT, \
      KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      KC_LCTL,        _______, KC_LGUI, KC_LALT, MO(1), KC_SPC, KC_SPC, MO(2), KC_RALT, KC_RGUI, _______, KC_RCTL
    ),
    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  _   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   {  |   }  |   (  |   )  |   |  |   +  |   -  |   _  |   =  | Home | End  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |   [  |   ]  |   \  |   :  |   '  |   "  | PgUp |  Up  | PgDn |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |Adjust|      | Left | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
	[_LOWER] = LAYOUT_preonic_grid( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_UNDS, \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_DEL, \
      _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,   KC_HOME, KC_END, \
      _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_COLN, KC_QUOT, KC_DQUO, KC_PGUP,  KC_UP,   KC_PGDN, \
      _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, MO(3),   _______, KC_LEFT,  KC_DOWN, KC_RGHT \
    ),
    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Ins  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |MBtn1 | MUp  |MBtn2 |      | Left | Down |  Up  |Right |   -  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |MLeft |MDown |MRight|      | Home | PgUp | PgDn | End  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |Adjust|             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
	[_RAISE] = LAYOUT_preonic_grid( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS, \
      _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS, _______, \
      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, \
      _______, _______, _______, _______, MO(3),   KC_ENT,  KC_ENT,  _______, _______, _______, _______, _______ \
    ),
    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Reset|Debug |      |      |      |      |TermOn|TermOf|      |      |  F12 |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |Aud on|AudOff|AGnorm|AGswap|RGBtog|      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
	[_ADJUST] = LAYOUT_preonic_grid( \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11, \
      _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_F12, \
      _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, RGB_TOG, _______,  _______, _______, _______, \
      _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______ \
    )
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_D, KC_F, COMBO_END};
//const uint16_t PROGMEM combo_del[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_dash[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM combo_esc2[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_bksl[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_ent2[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_less[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_coln[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_more[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_unds[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_bspc, KC_BSPC),
  COMBO(combo_tab, KC_TAB),
  //COMBO(combo_del, KC_DEL),
  COMBO(combo_dash, KC_MINS),
  COMBO(combo_ent, KC_ENT),

  COMBO(combo_esc2, KC_ESC),
  COMBO(combo_bksl, KC_BSLS),
  COMBO(combo_ent2, KC_ENT),
  COMBO(combo_less, KC_LT),
  COMBO(combo_coln, KC_COLN),
  COMBO(combo_more, KC_GT),
  COMBO(combo_quot, KC_QUOT),
  COMBO(combo_unds, KC_UNDS)
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
