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

// left hand home row mod aliases
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// right hand home row mod aliases
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Tap Dance
// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_TAP,
//     TD_DOUBLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP, // Send two single taps
//     TD_TRIPLE_TAP,
//     TD_TRIPLE_HOLD
// } td_state_t;

// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_t;

// enum {
//     DYN_MCRO,
// };

// td_state_t cur_dance(tap_dance_state_t *state);
// void dance_macro_finished(tap_dance_state_t *state, void *user_data);
// void dance_macro_finished(tap_dance_state_t *state, void *user_data);

// Leader Key Sequences
void leader_start_user(void) {
    // do nothing for now
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_G)) {
        SEND_STRING("github");
    } else if (leader_sequence_one_key(KC_C)) {
        SEND_STRING(SS_TAP(KC_LGUI) SS_DELAY(250) "calc" SS_TAP(KC_ENT));
    } else if (leader_sequence_one_key(KC_D)) {
        SEND_STRING(SS_TAP(KC_LGUI) SS_DELAY(250) "discord" SS_TAP(KC_ENT));
    } else if (leader_sequence_one_key(KC_Y)) {
        SEND_STRING(SS_LCTL("l") SS_DELAY(100) SS_LCTL("a") SS_DELAY(100) "www.youtube.com" SS_TAP(KC_ENT));
    } else if (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_TAP(KC_LGUI) SS_DELAY(250) "steam" SS_TAP(KC_ENT));
    } else if (leader_sequence_one_key(KC_O)) {
        SEND_STRING(SS_TAP(KC_LGUI) SS_DELAY(250) "obs" SS_TAP(KC_ENT));
    } else if (leader_sequence_one_key(KC_V)) {
        SEND_STRING(SS_TAP(KC_LGUI) SS_DELAY(250) "vscode" SS_TAP(KC_ENT));
    } else if (leader_sequence_two_keys(KC_L, KC_C)) {
        SEND_STRING(SS_LCTL("l") SS_DELAY(100) SS_LCTL("a") SS_DELAY(100) "www.leetcode.com" SS_TAP(KC_ENT));
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_4x6_5(
                            //ROW 1//
                            QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //ROW 2//
                             KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //ROW 3//
                             //KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,//
                             // HOME ROW MODS GACS
                             KC_LSFT, GUI_A, ALT_S, CTL_D, SFT_F, KC_G, KC_H, SFT_J, CTL_K, ALT_L, GUI_SCLN, KC_QUOT,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //ROW 4//
                             KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             //THUMB CLUSTERS ROW 1, ROW 2//
                             QK_LEAD, KC_SPC, MO(1), MO(2), KC_UP, KC_RGHT, KC_ENT, KC_DEL, KC_LEFT, KC_DOWN),

    [1] = LAYOUT_split_4x6_5(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             QK_BOOT, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_P7, KC_P8, KC_P9, _______, KC_PLUS,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_LPRN, KC_RPRN, KC_P4, KC_P5, KC_P6, KC_MINS, KC_PIPE,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_EQL, KC_UNDS,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             KC_LCTL, KC_HOME, KC_TRNS, KC_TRNS, KC_RALT, KC_RGUI, KC_SPC, KC_BSPC, KC_RCTL, KC_ENT),

    [2] = LAYOUT_split_4x6_5(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, RM_PREV,  RM_TOGG, RM_NEXT, KC_LBRC, KC_RBRC, _______, KC_NUM, KC_INS, KC_SCRL, KC_MUTE,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_LPRN, KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             KC_LCTL, KC_HOME, KC_TRNS, KC_TRNS, KC_RALT, QK_BOOT, KC_SPC, KC_BSPC, KC_RCTL, KC_ENT),
};

// Dynamic Macro Playback/Start/Stop
// td_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return TD_DOUBLE_HOLD;
//         else return TD_DOUBLE_TAP;
//     }
//     if (state->count == 3) {
//         if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
//         else return TD_TRIPLE_HOLD;
//     } else return TD_UNKNOWN;
// }

// static td_tap_t keytap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };

// void dance_macro_finished(tap_dance_state_t *state, void *user_data) {
//     keytap_state.state = cur_dance(state);
//     switch (keytap_state.state) {
//         case TD_SINGLE_TAP: dynamic_macro_play_user(1); dynamic_macro_led_blink(); break;
//         case TD_DOUBLE_TAP: dynamic_macro_record_start_user(1); dynamic_macro_led_blink(); break;
//         case TD_SINGLE_HOLD: dynamic_macro_record_end_user(1); dynamic_macro_led_blink(); break;
//         default: break;
//     }
// }

// void dance_macro_reset(tap_dance_state_t *state, void *user_data) {
//     keytap_state.state = TD_NONE;
// }

// tap_dance_action_t tap_dance_actions[] = {
//     [DYN_MCRO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_macro_finished, dance_macro_reset)
// };