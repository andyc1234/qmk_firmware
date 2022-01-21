#include QMK_KEYBOARD_H
#include "andy.h"
#include "encoder.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_BTN1, KC_BTN3, KC_BTN2, CMD_3,   TD(APP), CMD_5,                     VIM_6,   NEW_TAB, CMD_8,   CMD_9,  CMD_0,   KC_PGUP,
    TD(C12), KC_Q,    KC_W,    KC_F,    KC_P,    KC_V,                      KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_PGDN,
    ESC_SC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,   KC_O,    QUOT_SC,
    KC_LCMD, Z_SFT,   KC_X,    KC_C,    KC_D,    KC_B,    TD(APP), NEW_TAB, KC_K,    KC_H,    KC_COMM, KC_DOT, SLH_SFT, KC_RCMD,
                      PST_FND, CPY_CUT, TAB_NUM, SPC_CTL, BSP_ALT, TMUX,    ENT_NAV, NUM_SYM, TOG_WIN, SLAYER
  ),

  [_SHORTCUT] = LAYOUT(
    XXXXXXX, FFGPREV, FFGNEXT, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,
    XXXXXXX, XXXXXXX, XXXXXXX, FIREFOX, PDF,     VLC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,
    XXXXXXX, XXXXXXX, XXXXXXX, SLACK,   XXXXXXX, CHROME,                   XXXXXXX, NOTES,   EXCEL,   ITERM,   OUTLOOK, XXXXXXX,
    XXXXXXX, _______, XXXXXXX, CHIME,   DBEAVER, PAINT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
                      KC_VOLD, KC_VOLU, TAB_UP,  TAB_DN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_NUMSYM] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_CAPS, KC_LCBR, KC_RCBR, KC_HASH, KC_CIRC, KC_PERC,                   KC_BSLS, KC_7,  KC_8,    KC_9,    KC_PLUS, KC_TILD,
    XXXXXXX, KC_LPRN, KC_RPRN, KC_EXLM, KC_DLR,  KC_ASTR,                   KC_MINS, KC_4,  KC_5,    KC_6,    KC_EQL,  KC_GRV,
    _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_AMPR, KC_AT,   XXXXXXX, XXXXXXX, KC_UNDS, KC_1,  KC_2,    KC_3,    KC_DOT,  _______,
                      XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_DEL,  XXXXXXX, _______, KC_0,  XXXXXXX, XXXXXXX
  ),

  [_NAVIGATE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, LNSTART, KC_UP,   LNEND,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                   XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, WNDPREV, XXXXXXX, WNDNEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SLAYER] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, SL_W,    XXXXXXX, SL_P,    XXXXXXX,                   XXXXXXX, SL_L,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, SL_A,    XXXXXXX, XXXXXXX, XXXXXXX, SL_G,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, SL_Z,    XXXXXXX, SL_C,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

void set_led_color(custom_color color) {
    int brightness = 50;
    switch (color) {
        case CC_WHITE: rgblight_sethsv(0, 0, brightness); break;
        case CC_RED: rgblight_sethsv(0, 255, brightness); break;
        case CC_YELLOW: rgblight_sethsv(43, 255, brightness); break;
        case CC_GREEN: rgblight_sethsv(85, 255, brightness); break;
        case CC_BLUE: rgblight_sethsv(170, 255, brightness); break;
        default: break;
    }
}

void keyboard_post_init_user(void) {
    set_led_color(CC_WHITE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SHORTCUT: set_led_color(CC_BLUE); break;
        case _NUMSYM: set_led_color(CC_GREEN); break;
        case _NAVIGATE: set_led_color(CC_YELLOW); break;
        case _SLAYER: set_led_color(CC_RED); break;
        default: set_led_color(CC_WHITE); break;
    }
    return state;
}
