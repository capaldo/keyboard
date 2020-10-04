#include QMK_KEYBOARD_H

#define _FIRST 0
#define _SECOND 1
#define _THIRD 2

#undef RGB_BACKLIGHT_ENABLED
#define RGB_BACKLIGHT_ENABLED 0

enum custom_keycodes {
    YABAI_LEFT = SAFE_RANGE,
    YABAI_RIGHT,
    ALFRED
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case YABAI_LEFT:
        if (record->event.pressed) {
	    SEND_STRING(SS_DOWN(X_LCMD));
	    SEND_STRING(SS_DOWN(X_LOPT));
	    SEND_STRING("z");
        } else {
	    SEND_STRING(SS_UP(X_LCMD));
	    SEND_STRING(SS_UP(X_LOPT));
        }
        break;
    case YABAI_RIGHT:
        if (record->event.pressed) {
	    SEND_STRING(SS_DOWN(X_LCMD));
	    SEND_STRING(SS_DOWN(X_LOPT));
	    SEND_STRING("c");
        } else {
	    SEND_STRING(SS_UP(X_LCMD));
	    SEND_STRING(SS_UP(X_LOPT));
        }
        break;
    case ALFRED:
        if (record->event.pressed) {
	    SEND_STRING(SS_DOWN(X_LCMD));
	    SEND_STRING(SS_DOWN(X_LCTL));
	    SEND_STRING(SS_DOWN(X_LOPT));
	    SEND_STRING(SS_DOWN(X_LSFT));
	    SEND_STRING(" ");
        } else {
	    SEND_STRING(SS_UP(X_LCMD));
	    SEND_STRING(SS_UP(X_LCTL));
	    SEND_STRING(SS_UP(X_LOPT));
	    SEND_STRING(SS_UP(X_LSFT));
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FIRST] = LAYOUT( 
	    KC_KP_7, KC_KP_8, KC_KP_9, 
	    YABAI_LEFT, TO(_SECOND), YABAI_RIGHT, 
	    KC_KP_1, KC_KP_2, KC_KP_3, 
	    ALFRED 
	    ),
    [_SECOND] = LAYOUT( 
	    KC_KP_7, KC_KP_8, KC_KP_9, 
	    KC_KP_4, TO(_THIRD), KC_KP_6, 
	    KC_KP_1, KC_KP_2, KC_KP_3, 
	    ALFRED 
	    ),
    [_THIRD] = LAYOUT( 
	    KC_KP_7, KC_KP_8, KC_KP_9, 
	    KC_KP_4, TO(_FIRST), KC_KP_6, 
	    KC_KP_1, KC_KP_2, KC_KP_3, 
	    ALFRED 
	    )
};

