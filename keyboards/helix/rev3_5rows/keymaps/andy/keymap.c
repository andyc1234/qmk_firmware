/* Copyright 2020 yushakobo
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
#include "andy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_BTN1, KC_BTN3, KC_BTN2, KC_3,    KC_4,    KC_5,                      KC_6,    KC_7, KC_8,    KC_9,    KC_0,    KC_PGUP,
    ONE_TWO, KC_Q,    KC_W,    KC_F,    KC_P,    KC_V,                      KC_J,    KC_L, KC_U,    KC_Y,    KC_SCLN, KC_PGDN,
    ESC_SC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N, KC_E,    KC_I,    KC_O,    QUOT_SC,
    KC_LCMD, Z_SFT,   KC_X,    KC_C,    KC_D,    KC_B,    CMD_TAB, NEW_TAB, KC_K,    KC_H, KC_COMM, KC_DOT,  SLH_SFT, KC_RCMD,
    KC_LEFT, KC_RGHT, PST_FND, CPY_CUT, TAB_NUM, SPC_CTL, BSP_ALT, TMUX,    ENT_CTL, NAVI, KC_HOME, KC_END,  KC_DOWN, KC_UP
  ),

  [_SHORTCUT] = LAYOUT(
    _______, FFGPREV, FFGNEXT, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, FIREFOX, PDF,     VLC,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, SLACK,   _______, CHROME,                   _______, NOTES,   EXCEL,   ITERM,   OUTLOOK, _______,
    QUIT,    _______, _______, CHIME,   DBEAVER, PAINT,  _______, _______, _______, _______, _______, _______, _______, _______,
    KC_VOLD, KC_VOLU, _______, _______, TAB_UP,  TAB_DN, KC_DEL,  _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUMSYM] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_CAPS, KC_LCBR, KC_RCBR, KC_HASH, KC_CIRC, KC_PERC,                   KC_BSLS, KC_7,  KC_8,    KC_9,    KC_PLUS, KC_TILD,
    _______, KC_LPRN, KC_RPRN, KC_EXLM, KC_DLR,  KC_ASTR,                   KC_MINS, KC_4,  KC_5,    KC_6,    KC_EQL,  KC_GRV,
    _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_AMPR, KC_AT,   _______, _______, KC_UNDS, KC_1,  KC_2,    KC_3,    KC_DOT,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,  _______, _______, _______, _______
  ),

  [_NAVIGATE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, LNSTART, KC_UP,   LNEND,   _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                   _______, KC_LSFT, KC_LSFT, _______, _______, _______,
    _______, _______, WNDPREV, XXXXXXX, WNDNEXT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};
