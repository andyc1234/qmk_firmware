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

static td_tap_t app_tap_state = { .state = TD_NONE };
static td_tap_t c12_tap_state = { .state = TD_NONE };
static td_tap_t c35_tap_state = { .state = TD_NONE };
static td_tap_t lnk_tap_state = { .state = TD_NONE };
static td_tap_t tab_tap_state = { .state = TD_NONE };
static td_tap_t vi6_tap_state = { .state = TD_NONE };
static td_tap_t sl7_tap_state = { .state = TD_NONE };
static td_tap_t sl8_tap_state = { .state = TD_NONE };

void app_finished(qk_tap_dance_state_t *state, void *user_data) {
    app_tap_state.state = cur_dance(state);
    switch (app_tap_state.state) {
        case TD_SINGLE_TAP:  tap_cmd_alt(KC_TAB); break;
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

void c12_finished(qk_tap_dance_state_t *state, void *user_data) {
    c12_tap_state.state = cur_dance(state);
    switch (c12_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code(KC_1); break;
        case TD_SINGLE_HOLD: tap_cmd_ctl(KC_1); break;
        case TD_DOUBLE_TAP:  tap_code(KC_2); break;
        case TD_DOUBLE_HOLD: tap_cmd_ctl(KC_2); break;
        default: break;
    }
    c12_tap_state.state = TD_NONE;
}

void c35_finished(qk_tap_dance_state_t *state, void *user_data) {
    c35_tap_state.state = cur_dance(state);
    switch (c35_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code(KC_3); break;
        case TD_SINGLE_HOLD: tap_cmd_ctl(KC_3); break;
        case TD_DOUBLE_TAP:  tap_code(KC_4); break;
        case TD_DOUBLE_HOLD: tap_cmd_ctl(KC_4); break;
        case TD_TRIPLE_TAP:  tap_code(KC_5); break;
        case TD_TRIPLE_HOLD: tap_cmd_ctl(KC_5); break;
        default: break;
    }
    c35_tap_state.state = TD_NONE;
}

void insert_link_markdown(int words) {
    for (int i=0; i<words; i++) { tap_code16(LALT(KC_LEFT)); }
    tap_code(KC_LBRC);
    for (int i=0; i<words; i++) { tap_code16(LALT(KC_RGHT)); }
    tap_code(KC_RBRC);
    tap_code16(KC_LPRN);
    tap_code16(KC_RPRN);
    tap_code(KC_LEFT);
}

void insert_link_xwiki(int words) {
    for (int i=0; i<words; i++) { tap_code16(LALT(KC_LEFT)); }
    tap_code(KC_LBRC);
    tap_code(KC_LBRC);
    for (int i=0; i<words; i++) { tap_code16(LALT(KC_RGHT)); }
    tap_code16(KC_RABK);
    tap_code16(KC_RABK);
    tap_code(KC_RBRC);
    tap_code(KC_RBRC);
    tap_code(KC_LEFT);
    tap_code(KC_LEFT);
}

void lnk_finished(qk_tap_dance_state_t *state, void *user_data) {
    lnk_tap_state.state = cur_dance(state);
    switch (lnk_tap_state.state) {
        case TD_SINGLE_TAP:  insert_link_markdown(1); break;
        case TD_DOUBLE_TAP:  insert_link_markdown(2); break;
        case TD_TRIPLE_TAP:  insert_link_markdown(3); break;
        case TD_SINGLE_HOLD: insert_link_xwiki(1); break;
        case TD_DOUBLE_HOLD: insert_link_xwiki(2); break;
        case TD_TRIPLE_HOLD: insert_link_xwiki(3); break;
        default: break;
    }
    lnk_tap_state.state = TD_NONE;
}

void tab_finished(qk_tap_dance_state_t *state, void *user_data) {
    tab_tap_state.state = cur_dance(state);
    switch (tab_tap_state.state) {
        case TD_SINGLE_TAP:  tap_cmd_ctl(KC_T); break;
        case TD_SINGLE_HOLD: tap_code16(LALT(KC_HOME)); break;
        case TD_DOUBLE_TAP:  tap_code16(LSFT(KC_TAB)); tap_code16(LSFT(KC_TAB)); tap_code(KC_B); break;
        default: break;
    }
    tab_tap_state.state = TD_NONE;
}

void vi6_finished(qk_tap_dance_state_t *state, void *user_data) {
    vi6_tap_state.state = cur_dance(state);
    switch (vi6_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code16(LCTL(LSFT(KC_6))); break;
        case TD_SINGLE_HOLD: tap_code16(LCMD(LSFT(KC_5))); break;
        case TD_DOUBLE_TAP:  tap_code(KC_6); break;
        case TD_DOUBLE_HOLD: tap_cmd_ctl(KC_6); break;
        default: break;
    }
    vi6_tap_state.state = TD_NONE;
}

void sl7_finished(qk_tap_dance_state_t *state, void *user_data) {
    sl7_tap_state.state = cur_dance(state);
    switch (sl7_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code16(LOPT(LSFT(KC_DOWN))); break;
        case TD_SINGLE_HOLD: tap_code16(LCMD(KC_RBRC)); break;
        case TD_DOUBLE_TAP:  tap_code(KC_7); break;
        case TD_DOUBLE_HOLD: tap_cmd_ctl(KC_7); break;
        default: break;
    }
    sl7_tap_state.state = TD_NONE;
}

void sl8_finished(qk_tap_dance_state_t *state, void *user_data) {
    sl8_tap_state.state = cur_dance(state);
    switch (sl8_tap_state.state) {
        case TD_SINGLE_TAP:  tap_code16(LOPT(LSFT(KC_UP))); break;
        case TD_SINGLE_HOLD: tap_code16(LCMD(KC_LBRC)); break;
        case TD_DOUBLE_TAP:  tap_code(KC_8); break;
        case TD_DOUBLE_HOLD: tap_cmd_ctl(KC_8); break;
        default: break;
    }
    sl8_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [APP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, app_finished, NULL),
    [C12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c12_finished, NULL),
    [C35] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c35_finished, NULL),
    [LNK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lnk_finished, NULL),
    [TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_finished, NULL),
    [VI6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vi6_finished, NULL),
    [SL7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sl7_finished, NULL),
    [SL8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sl8_finished, NULL),
};
