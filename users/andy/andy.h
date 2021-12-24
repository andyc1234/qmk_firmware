#pragma once

#include "quantum.h"
/* #include "action.h" */
/* #include "version.h" */

enum layer_names {
  _BASE = 0,
  _SHORTCUT,
  _NUMSYM,
  _NAVIGATE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  ADJUST,
  RGBRST,
  NEW_SAFE_RANGE
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
