#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Bspc  │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │Ct/Esc│ A │ S │ D │ F │ G │ H │ J │ K │ L │3/;│ ' │ Enter  │
     * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────┤
     * │LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  RShift   │
     * ├────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬─────┤
     * │LCtl│LGui│LAlt│         Space         │RAlt│ L1 │RGui│RCtl │
     * └────┴────┴────┴───────────────────────┴────┴────┴────┴─────┘
    */
	[0] = LAYOUT_60_ansi( \
        KC_GESC,      KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,    KC_7,   KC_8,    KC_9,   KC_0,          KC_MINS, KC_EQL,  KC_BSPC, \
        KC_TAB,       KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,          KC_LBRC, KC_RBRC, KC_BSLS, \
        LCTL_T(KC_ESC), KC_A,  KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,   KC_K,    KC_L,   LT(3,KC_SCLN), KC_QUOT, KC_ENT, \
        /*LT(2,KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,   KC_K,    KC_L,   LT(3,KC_SCLN), KC_QUOT, KC_ENT, \*/
        KC_LSFT,      KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,       KC_RSFT, \
        KC_LCTL,      KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RGUI, KC_RCTL \
    ),

    /* Layer 1 - Function layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  Del  │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │PgU│ ↑ │PgD│HUI│HUD│SAI│SAD│VAI│VAD│PSc│ ↑ │Ins│Reset│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │ ← │ ↓ │ → │TOG│MOD│ ← │ ↓ │ ↑ │ → │ ← │ → │        │
     * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────┤
     * │       │   │   │   │   │   │Hom│End│PgU│PgD│ ↓ │           │
     * ├────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬─────┤
     * │    │    │    │                       │    │    │    │     │
     * └────┴────┴────┴───────────────────────┴────┴────┴────┴─────┘
    */
	[1] = LAYOUT_60_ansi( \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_DEL, \
        KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_PSCR, KC_UP,   KC_INS, RESET, \
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, RGB_TOG, RGB_MOD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LEFT, KC_RGHT, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_DOWN, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    ),

    /* Layer 2 - Function layer with Ctrl on PgUp/PgDown
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Del   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │PgU│ ↑ │PgD│HUI│HUD│SAI│SAD│VAI│VAD│PSc│ ↑ │Ins│Reset│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │ ← │ ↓ │ → │TOG│MOD│ ← │ ↓ │ ↑ │ → │ ← │ → │        │
     * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────┤
     * │       │   │   │   │   │   │Hom│End│C+U│C+D│ ↓ │           │
     * ├────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬─────┤
     * │    │    │    │                       │    │    │    │     │
     * └────┴────┴────┴───────────────────────┴────┴────┴────┴─────┘
    */
	[2] = LAYOUT_60_ansi( \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,         KC_F9,         KC_F10,  KC_F11,  KC_F12, KC_DEL, \
        KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI,       RGB_VAD,       KC_PSCR, KC_UP,   KC_INS, RESET, \
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, RGB_TOG, RGB_MOD, KC_LEFT, KC_DOWN, KC_UP,         KC_RGHT,       KC_LEFT, KC_RGHT, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END,  LCTL(KC_PGUP), LCTL(KC_PGDN), KC_DOWN, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    ),

    /* Layer 3 - Extra nav layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │LSh│LCt│LGu│LAl│   │ ← │ ↓ │ ↑ │ → │   │   │        │
     * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────┤
     * │       │   │   │   │   │   │   │   │   │   │   │           │
     * ├────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬─────┤
     * │    │    │    │                       │    │    │    │     │
     * └────┴────┴────┴───────────────────────┴────┴────┴────┴─────┘
    */
	[3] = LAYOUT_60_ansi( \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    )
};
