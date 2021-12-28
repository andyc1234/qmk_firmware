#pragma once

#include "quantum.h"
/* #include "action.h" */
/* #include "version.h" */

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
    SL_A,
    SL_C,
    SL_G,
    SL_L,
    SL_P,
    SL_W,
    SL_Z,
    NEW_SAFE_RANGE
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;

enum {
    C12,
    APP
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
#define NEW_TAB LT(_BASE, KC_T)
#define CPY_CUT LT(_BASE, KC_C)
#define PST_FND LT(_BASE, KC_P)
#define TMUX    LT(_BASE, KC_SPC)
#define CMD_3   LT(_BASE, KC_3)
#define CMD_4   LT(_BASE, KC_4)
#define CMD_5   LT(_BASE, KC_5)
#define VIM_6   LT(_BASE, KC_6)
#define CMD_7   LT(_BASE, KC_7)
#define CMD_8   LT(_BASE, KC_8)
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
#define EXCEL   LCAG(KC_E)
#define ITERM   LCAG(KC_I)
#define OUTLOOK LCAG(KC_O)

#define FFGNEXT LCTL(KC_GRV)
#define FFGPREV LCTL(LSFT(KC_GRV))
#define QUIT    LCTL(LSFT(KC_Q))
#define TAB_UP  LCTL(KC_PGUP)
#define TAB_DN  LCTL(KC_PGDN)
