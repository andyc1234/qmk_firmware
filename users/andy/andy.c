#include "andy.h"

static bool is_win = false;

bool is_win_mode(void) {
    return is_win;
}

void indicate_win_mode(void) {
    if (is_win_mode()) { rgblight_sethsv_at(CC_RED, 0); }
    else { rgblight_sethsv_at(CC_WHITE, 0); }
}

void toggle_win_mode(void) {
    is_win = !is_win;
    indicate_win_mode();
}

void tap_cmd_ctl(uint16_t keycode) {
    if (is_win_mode()) { tap_code16(LCTL(keycode)); }
    else { tap_code16(LCMD(keycode)); }
}

void tap_cmd_alt(uint16_t keycode) {
    if (is_win_mode()) { tap_code16(LALT(keycode)); }
    else { tap_code16(LCMD(keycode)); }
}

void register_alt_ctl(uint16_t keycode) {
    if (is_win_mode()) { register_code16(LCTL(keycode)); }
    else { register_code16(LALT(keycode)); }
}

void unregister_alt_ctl(uint16_t keycode) {
    if (is_win_mode()) { unregister_code16(LCTL(keycode)); }
    else { unregister_code16(LALT(keycode)); }
}

void register_cmd_alt(void) {
    if (is_win_mode()) { register_code(KC_LALT); }
    else { register_code(KC_LCMD); }
}

void unregister_cmd_alt(void) {
    if (is_win_mode()) { unregister_code(KC_LALT); }
    else { unregister_code(KC_LCMD); }
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CPY_CUT:
        if (record->tap.count && record->event.pressed) { tap_cmd_ctl(KC_C); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_X); }
        return false; break;
    case PST_FND:
        if (record->tap.count && record->event.pressed) { tap_cmd_ctl(KC_V); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_F); }
        return false; break;
    case CMD_9:
        if (record->tap.count && record->event.pressed) { tap_code(KC_9); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_9); }
        return false; break;
    case CMD_0:
        if (record->tap.count && record->event.pressed) { tap_code(KC_0); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_0); }
        return false; break;
    case TOG_WIN:
        if (!record->tap.count && record->event.pressed) { toggle_win_mode(); }
        return false; break;
    case WNDNEXT:
        if (record->event.pressed) { register_alt_ctl(KC_RGHT); }
        else { unregister_alt_ctl(KC_RGHT); }
        return false; break;
    case WNDPREV:
        if (record->event.pressed) { register_alt_ctl(KC_LEFT); }
        else { unregister_alt_ctl(KC_LEFT); }
        return false; break;
    case LNSTART:
        if (record->event.pressed) {
            if (is_win_mode()) { tap_code(KC_HOME); }
            else { tap_code16(LCMD(KC_LEFT)); }
        }
        return false; break;
    case LNEND:
        if (record->event.pressed) {
            if (is_win_mode()) { tap_code(KC_END); }
            else { tap_code16(LCMD(KC_RGHT)); }
        }
        return false; break;
    }
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}

void keyboard_post_init_user(void) {
    rgblight_sethsv(CC_WHITE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SHORTCUT: rgblight_sethsv(CC_BLUE); break;
        case _NUMSYM:   rgblight_sethsv(CC_GREEN); break;
        case _NAVIGATE: rgblight_sethsv(CC_YELLOW); break;
        case _SLAYER:   rgblight_sethsv(CC_RED); break;
        default:        rgblight_sethsv(CC_WHITE); indicate_win_mode(); break;
    }
    return state;
}
