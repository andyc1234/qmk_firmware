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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE = 0,
  _SHORTCUT,
  _NUMSYM,
  _NAVIGATE,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  ADJUST,
  RGBRST
};

// Reference: https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAVI MO(_NAVIGATE)

#define SPC_CTL LCTL_T(KC_SPC)
#define ENT_CTL LCTL_T(KC_ENT)
#define BSP_ALT LALT_T(KC_BSPC)
#define Z_SFT   LSFT_T(KC_Z)
#define SLH_SFT RSFT_T(KC_SLSH)

#define ESC_SC  LT(_SHORTCUT, KC_ESC)
#define QUOT_SC LT(_SHORTCUT, KC_QUOT)
#define TAB_NUM LT(_NUMSYM, KC_TAB)
#define CMD_TAB LT(_BASE, KC_TAB)
#define NEW_TAB LT(_BASE, KC_T)
#define CPY_CUT LT(_BASE, KC_C)
#define PST_FND LT(_BASE, KC_P)
#define TMUX    LT(_BASE, KC_SPC)
#define ONE_TWO LT(_BASE, KC_1)

#define FIREFOX LCAG(KC_F)
#define CHROME  LCAG(KC_G)
#define CHIME   LCAG(KC_C)
#define SLACK   LCAG(KC_S)
#define PDF     LCAG(KC_P)
#define VLC     LCAG(KC_V)
#define PAINT   LCAG(KC_B)
#define DBEAVER LCAG(KC_D)
#define NOTES   LCAG(KC_N)
#define EXCEL   LCAG(KC_E)
#define ITERM   LCAG(KC_I)
#define OUTLOOK LCAG(KC_O)

#define FFGNEXT LCTL(KC_GRV)
#define FFGPREV LCTL(LSFT(KC_GRV))
#define QUIT    LCTL(LSFT(KC_Q))
#define TAB_UP  LCTL(KC_PGUP)
#define TAB_DN  LCTL(KC_PGDN)

#define WNDNEXT LALT(KC_RGHT)
#define WNDPREV LALT(KC_LEFT)
#define LNSTART LCMD(KC_LEFT)
#define LNEND   LCMD(KC_RGHT)

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

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |  (   |   )  |  F12 |      |      | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
      KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_LPRN, KC_RPRN, KC_F12,  _______, _______, KC_HOME, KC_END,  _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |PageDn|PageUp|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_BSPC,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|EEPRST|      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | Mac  |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, RESET,   RGBRST,  EEP_RST, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, AG_NORM,                   AG_SWAP, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD
      )

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_TAB:
      if (record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_TAB));
      } else if (record->event.pressed) {
        tap_code16(LCMD(KC_GRV));
      }
      return false;
      break;
    case NEW_TAB:
      if (record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_T));
      } else if (record->event.pressed) {
        tap_code16(LALT(KC_HOME));
      }
      return false;
      break;
    case CPY_CUT:
      if (record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_C));
      } else if (record->event.pressed) {
        tap_code16(LCMD(KC_X));
      }
      return false;
      break;
    case PST_FND:
      if (record->tap.count && record->event.pressed) {
        tap_code16(LCMD(KC_V));
      } else if (record->event.pressed) {
        tap_code16(LCMD(KC_F));
      }
      return false;
      break;
    case TMUX:
      if (record->tap.count && record->event.pressed) {
        tap_code16(LCTL(KC_SPC));
      } else if (record->event.pressed) {
        tap_code16(LCTL(KC_SPC));
        tap_code16(KC_LBRC);
      }
      return false;
      break;
    case ONE_TWO:
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_1);
      } else if (record->event.pressed) {
        tap_code16(KC_2);
      }
      return false;
      break;
    case EISU:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LANG2);
        }else{
          tap_code16(LALT(KC_GRAVE));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LANG1);
        }else{
          tap_code16(LALT(KC_GRAVE));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_RAISE);
      } else {
        layer_off(_LOWER);
        layer_off(_RAISE);
      }
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}
