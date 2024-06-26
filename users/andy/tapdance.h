#pragma once

#include "andy.h"

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
    APP,
    C12,
    C35,
    LNK,
    MUX,
    SL7,
    SL8,
    TAB,
    VI6,
    WIN,
};
