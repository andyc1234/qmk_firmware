#include "andy.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
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
    }
    return process_record_keymap(keycode, record);
}
