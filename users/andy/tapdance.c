#include "tapdance.h"

__attribute__ ((weak)) bool is_win_mode(void) { return true; }
__attribute__ ((weak)) void tap_cmd_ctl(uint16_t keycode) {}
__attribute__ ((weak)) void tap_cmd_alt(uint16_t keycode) {}
__attribute__ ((weak)) void register_cmd_alt(void) {}
__attribute__ ((weak)) void unregister_cmd_alt(void) {}

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
