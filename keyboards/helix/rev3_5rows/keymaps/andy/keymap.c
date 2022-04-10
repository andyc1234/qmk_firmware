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
#include "tapdance.h"

// qmk flash -kb helix/rev3_5rows -km andy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_BTN1, KC_BTN3, KC_BTN2, TD(C35), KC_WH_U, KC_WH_D,                   TD(VI6), TD(SL7), TD(SL8), CMD_9,  CMD_0,   KC_PGUP,
    TD(C12), KC_Q,    KC_W,    KC_F,    KC_P,    KC_V,                      KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_PGDN,
    ESC_SC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,   KC_O,    QUOT_SC,
    KC_LCMD, Z_SFT,   KC_X,    KC_C,    KC_D,    KC_B,    TD(APP), TD(TAB), KC_K,    KC_H,    KC_COMM, KC_DOT, SLH_SFT, KC_RCMD,
    KC_LEFT, KC_RGHT, PST_FND, CPY_CUT, TAB_NUM, SPC_CTL, BSP_ALT, TD(MUX), ENT_NAV, NUM_SYM, TOG_WIN, SLAYER, KC_DOWN, KC_UP
  ),

  [_SHORTCUT] = LAYOUT(
    XXXXXXX, FFGPREV, FFGNEXT, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,
    XXXXXXX, XXXXXXX, XXXXXXX, FIREFOX, PDF,     VLC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,
    KC_CAPS, XXXXXXX, XXXXXXX, SLACK,   XXXXXXX, CHROME,                   XXXXXXX, NOTES,   XXXXXXX, ITERM,   OUTLOOK, XXXXXXX,
    XXXXXXX, _______, EXCEL,   CHIME,   DBEAVER, PAINT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
    KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, TAB_UP,  TAB_DN, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_NUMSYM] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F12,
    XXXXXXX, KC_LCBR, KC_RCBR, KC_HASH, KC_CIRC, KC_PERC,                   KC_BSLS, KC_7,  KC_8,    KC_9,    KC_PLUS, KC_TILD,
    XXXXXXX, KC_LPRN, KC_RPRN, KC_EXLM, KC_DLR,  KC_ASTR,                   KC_MINS, KC_4,  KC_5,    KC_6,    KC_EQL,  KC_GRV,
    _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_AMPR, KC_AT,   XXXXXXX, XXXXXXX, KC_UNDS, KC_1,  KC_2,    KC_3,    KC_DOT,  _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______, KC_0,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_NAVIGATE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, LNSTART, KC_UP,   LNEND,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, TD(LNK),                   XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, WNDPREV, XXXXXXX, WNDNEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SLAYER] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, SL_W,    XXXXXXX, SL_P,    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, SL_A,    XXXXXXX, XXXXXXX, XXXXXXX, SL_G,                      SL_M,    SL_N,    SL_E,    SL_I,    SL_O,    XXXXXXX,
    XXXXXXX, SL_Z,    XXXXXXX, SL_C,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SL_H,    SL_CO,   SL_PE,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};
