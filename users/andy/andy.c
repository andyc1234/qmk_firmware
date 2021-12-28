#include "andy.h"

static bool is_win = false;

bool is_win_mode(void) {
    return is_win;
}

void toggle_win_mode(void) {
    is_win = !is_win;
}

void tap_cmd_ctl(uint16_t keycode) {
    if (is_win_mode()) { tap_code16(LCTL(keycode)); }
    else { tap_code16(LCMD(keycode)); }
}

void tap_cmd_alt(uint16_t keycode) {
    if (is_win_mode()) { tap_code16(LALT(keycode)); }
    else { tap_code16(LCMD(keycode)); }
}

void tap_alt_ctl(uint16_t keycode) {
    if (is_win_mode()) { tap_code16(LCTL(keycode)); }
    else { tap_code16(LALT(keycode)); }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case NEW_TAB:
        if (record->tap.count && record->event.pressed) { tap_cmd_ctl(KC_T); }
        else if (record->event.pressed) { tap_code16(LALT(KC_HOME)); }
        return false; break;
    case CPY_CUT:
        if (record->tap.count && record->event.pressed) { tap_cmd_ctl(KC_C); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_X); }
        return false; break;
    case PST_FND:
        if (record->tap.count && record->event.pressed) { tap_cmd_ctl(KC_V); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_F); }
        return false; break;
    case TMUX:
        if (record->tap.count && record->event.pressed) { tap_code16(LCTL(KC_SPC)); }
        else if (record->event.pressed) { tap_code16(LCTL(KC_SPC)); tap_code16(KC_LBRC); }
        return false; break;
    case CMD_3:
        if (record->tap.count && record->event.pressed) { tap_code(KC_3); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_3); }
        return false; break;
    case CMD_4:
        if (record->tap.count && record->event.pressed) { tap_code(KC_4); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_4); }
        return false; break;
    case CMD_5:
        if (record->tap.count && record->event.pressed) { tap_code(KC_5); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_5); }
        return false; break;
    case VIM_6:
        if (record->tap.count && record->event.pressed) { tap_code(KC_6); }
        else if (record->event.pressed) { tap_code16(LCTL(LSFT(KC_6))); }
        return false; break;
    case CMD_7:
        if (record->tap.count && record->event.pressed) { tap_code(KC_7); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_7); }
        return false; break;
    case CMD_8:
        if (record->tap.count && record->event.pressed) { tap_code(KC_8); }
        else if (record->event.pressed) { tap_cmd_ctl(KC_8); }
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
        if (record->event.pressed) { tap_alt_ctl(KC_RGHT); }
        return false; break;
    case WNDPREV:
        if (record->event.pressed) { tap_alt_ctl(KC_LEFT); }
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
    return process_record_keymap(keycode, record);
}

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
    case 1:
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
        break;
    case 2:
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
        break;
    case 3:
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
        break;
    default:
        return TD_UNKNOWN; break;
    }
}

static td_tap_t c12_tap_state = { .state = TD_NONE };
static td_tap_t app_tap_state = { .state = TD_NONE };

void c12_finished(qk_tap_dance_state_t *state, void *user_data) {
    c12_tap_state.state = cur_dance(state);
    switch (c12_tap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_1); break;
        case TD_SINGLE_HOLD: tap_cmd_ctl(KC_1); break;
        case TD_DOUBLE_TAP: tap_code(KC_2); break;
        case TD_DOUBLE_HOLD: tap_cmd_ctl(KC_2); break;
        default: break;
    }
    c12_tap_state.state = TD_NONE;
}

void app_finished(qk_tap_dance_state_t *state, void *user_data) {
    app_tap_state.state = cur_dance(state);
    switch (app_tap_state.state) {
        case TD_SINGLE_TAP: tap_cmd_alt(KC_TAB); break;
        case TD_SINGLE_HOLD: tap_code16(LCMD(KC_GRV)); break;
        case TD_DOUBLE_TAP:
            register_cmd_alt();
            tap_code(KC_TAB); tap_code(KC_TAB);
            unregister_cmd_alt();
            break;
        case TD_TRIPLE_TAP:
            register_cmd_alt();
            tap_code(KC_TAB); tap_code(KC_TAB); tap_code(KC_TAB);
            unregister_cmd_alt();
            break;
        default: break;
    }
    app_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [C12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c12_finished, NULL),
    [APP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, app_finished, NULL)
};
