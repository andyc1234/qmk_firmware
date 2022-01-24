#pragma once

// Plug USB into the left half of the keyboard
// see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
#define MASTER_LEFT

// Serial comms between halves. Change if using I2C
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

// I suspect this is only needed for certain ProMicros
// Not sure what the disadvantages are / why it isn't on by default
#define SPLIT_USB_DETECT

#define RGB_DI_PIN D3
#define RGBLED_NUM 58
#define RGBLED_SPLIT { 29, 29 }
#define RGBLIGHT_SPLIT
#define RGBLIGHT_SLEEP

#undef TAPPING_TERM
#define TAPPING_TERM 250

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4
#define ENCODER_DIRECTION_FLIP
