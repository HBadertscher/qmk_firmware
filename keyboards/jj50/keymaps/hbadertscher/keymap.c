/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <keymap_german_ch.h>
#define ______ KC_TRNS
#define _DEFLT 0
#define _RAISE 1


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |  $   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Enter |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ö  |  ä   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Shift |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Raise | Alt  | Left |Right | Bksp |    Space    |Enter | Up   | Down |  ü   | Raise|
     * `-----------------------------------------------------------------------------------'
     */
    [_DEFLT] = LAYOUT( \
        KC_ESC,  CH_1,    CH_2,    CH_3,    CH_4,    CH_5,    CH_6,    CH_7,    CH_8,    CH_9,    CH_0,    KC_BSPC,      \
        KC_TAB,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,    CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    CH_DLR,      \
        KC_ENT,  CH_A,    CH_S,    CH_D,    CH_F,    CH_G,    CH_H,    CH_J,    CH_K,    CH_L,    CH_OE,   CH_AE,      \
        KC_LSFT, MT(MOD_LCTL, CH_Y),    CH_X,    CH_C,    CH_V,    CH_B,    CH_N,    CH_M,    CH_COMM, CH_DOT,  MT(MOD_RCTL, CH_MINS), KC_RSFT,      \
     MO(_RAISE), KC_LALT, KC_LEFT, KC_RIGHT,KC_BSPC, KC_SPC,  KC_SPC,  KC_ENT,  KC_UP,   KC_DOWN, CH_UE,   MO(_RAISE)   \
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   /  |   @  |   {  |   }  |  !   |  ?   |   7  |   8  |   9  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------|------|
     * |      |   #  |   ~  |   (  |   )  |  \   |      |   4  |   5  |   6  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------|------|
     * | Caps |   %  |   ^  |   [  |   ]  |  |   |      |   1  |   2  |   3  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------|------|
     * |      |      |      |      |      |             |      0      |   .  |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_RAISE] = LAYOUT( \
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,  \
       _______, CH_SLSH, CH_AT,   CH_LCBR, CH_RCBR, CH_EXLM, CH_QST,  CH_7,    CH_8,    CH_9,    _______, _______, \
       _______, CH_HASH, CH_TILD, CH_LPRN, CH_RPRN, CH_BSLS, _______, CH_4,    CH_5,    CH_6,    _______, _______, \
       KC_CAPS, CH_PERC, CH_CARR, CH_LBRC, CH_RBRC, CH_PIPE, _______, CH_1,    CH_2,    CH_3,    _______, _______, \
       _______, _______, _______, _______, _______, _______, _______, CH_0,    CH_0,    CH_DOT,  _______, _______\
    )
};


void keyboard_post_init_user(void) {
    // Disable RGB light by default
    rgblight_disable_noeeprom();
}

uint32_t layer_state_set_user(uint32_t state) {
    // This is called after each pressed key I think
    switch (biton32(state)) {
        case _RAISE:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        default:
            rgblight_disable_noeeprom();
            break;
    }
    return state;
}
