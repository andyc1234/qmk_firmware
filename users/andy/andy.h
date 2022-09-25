#pragma once

#include "quantum.h"

#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 25
#define RGBLIGHT_SLEEP

#define CC_WHITE  0, 0, RGBLIGHT_LIMIT_VAL
#define CC_RED    0, 255, RGBLIGHT_LIMIT_VAL
#define CC_YELLOW 43, 255, RGBLIGHT_LIMIT_VAL
#define CC_GREEN  85, 255, RGBLIGHT_LIMIT_VAL
#define CC_BLUE   155, 255, RGBLIGHT_LIMIT_VAL

enum layer_names {
    _BASE = 0,
    _SHORTCUT,
    _NUMSYM,
    _NAVIGATE,
    _SLAYER
};

enum custom_keycodes {
    WNDNEXT = SAFE_RANGE,
    WNDPREV,
    LNSTART,
    LNEND,
    SL_1,
    SL_2,
    SL_3,
    SL_4,
    SL_5,
    SL_A,
    SL_C,
    SL_CO,
    SL_E,
    SL_G,
    SL_H,
    SL_I,
    SL_K,
    SL_M,
    SL_N,
    SL_O,
    SL_P,
    SL_PE,
    SL_SL,
    SL_W,
    SL_Z,
    NEW_SAFE_RANGE
};

// Reference: https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes
#define NUM_SYM MO(_NUMSYM)
#define SLAYER  OSL(_SLAYER)

#define SPC_CTL LCTL_T(KC_SPC)
#define ENT_CTL LCTL_T(KC_ENT)
#define BSP_ALT LALT_T(KC_BSPC)
#define Z_SFT   LSFT_T(KC_Z)
#define SLH_SFT RSFT_T(KC_SLSH)

#define ESC_SC  LT(_SHORTCUT, KC_ESC)
#define QUOT_SC LT(_SHORTCUT, KC_QUOT)
#define TAB_NUM LT(_NUMSYM, KC_TAB)
#define ENT_NAV LT(_NAVIGATE, KC_ENT)
#define CPY_CUT LT(_BASE, KC_C)
#define PST_FND LT(_BASE, KC_P)
#define CMD_9   LT(_BASE, KC_9)
#define CMD_0   LT(_BASE, KC_0)
#define TOG_WIN LT(_BASE, KC_W)

#define FIREFOX LCAG(KC_F)
#define CHROME  LCAG(KC_G)
#define CHIME   LCAG(KC_C)
#define SLACK   LCAG(KC_S)
#define PDF     LCAG(KC_P)
#define VLC     LCAG(KC_V)
#define PAINT   LCAG(KC_B)
#define DBEAVER LCAG(KC_D)
#define NOTES   LCAG(KC_N)
#define EXCEL   LCAG(KC_X)
#define ITERM   LCAG(KC_I)
#define OUTLOOK LCAG(KC_O)

#define FFGNEXT LCTL(KC_GRV)
#define FFGPREV LCTL(LSFT(KC_GRV))
#define QUIT    LCTL(LSFT(KC_Q))
#define TAB_UP  LCTL(KC_PGUP)
#define TAB_DN  LCTL(KC_PGDN)
