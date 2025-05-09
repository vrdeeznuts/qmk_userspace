/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

enum layer_names {
    _BASE,
    _SYM,
    _FN,
    _NAV,
};

#define SYM MO(_SYM)
#define FN MO(_FN)
#define NAV MO(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_4x6_5(
                            //ROW 1//
                            QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //ROW 2//
                             KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //ROW 3//
                             KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //ROW 4//
                             KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //THUMB CLUSTERS ROW 1, ROW 2//
                             KC_LGUI, KC_SPC, KC_LALT,   KC_RSFT, KC_ENT, KC_BSPC,        NAV, SYM,   FN, KC_DEL),

    [_SYM] = LAYOUT_split_4x6_5(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             KC_PGUP, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP, KC_END, KC_LBRC, KC_BSLS,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             KC_PGDN, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RBRC, KC_EQL,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_FN] = LAYOUT_split_4x6_5(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             RM_PREV, RM_NEXT, RM_SPDU,  RM_SPDD, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             RM_TOGG, _______, RM_VALU, RM_VALD, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    [_NAV] = LAYOUT_split_4x6_5(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______,  _______, _______, _______, MS_WHLU, _______, MS_UP, _______, _______, _______,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, MS_BTN3, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, MS_WHLD, _______, _______, _______, _______, _______,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, _______, MS_BTN1, MS_BTN2)
};
