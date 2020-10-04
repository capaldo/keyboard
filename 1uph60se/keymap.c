#include QMK_KEYBOARD_H

// ——————————————————————————————————————————————————————————————————
// macro definitions
// ——————————————————————————————————————————————————————————————————
enum custom_keycodes {
    AUTOPARENTHESIS = SAFE_RANGE,
    AUTOBRACKETS,
    AUTODOUBLEQUOTES,
    AUTOSINGLEQUOTES,
    VIMESCAPE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

	// AUTOPARENTHESIS
	case AUTOPARENTHESIS:
	    if (record->event.pressed) {
		SEND_STRING("()");
	    } 
	    else {
		SEND_STRING(SS_TAP(X_LEFT));
	    }
	    break;

	// AUTOBRACKETS
	case AUTOBRACKETS:
	    if (record->event.pressed) {
		SEND_STRING("[]");
	    } 
	    else {
		SEND_STRING(SS_TAP(X_LEFT));
	    }
	    break;

	    // ——————————————————————————————————————————————————————————————————

	    // AUTOSINGLEQUOTES
	case AUTOSINGLEQUOTES:
	    if (record->event.pressed) {
		SEND_STRING("''");
	    } 
	    else {
		SEND_STRING(SS_TAP(X_LEFT));
	    }
	    break;

	    // ——————————————————————————————————————————————————————————————————

	    // AUTODOUBLEQUOTES
	case AUTODOUBLEQUOTES:
	    if (record->event.pressed) {
		SEND_STRING("\"\"");
	    } 
	    else {
		SEND_STRING(SS_TAP(X_LEFT));
	    }
	    break;

	    // ——————————————————————————————————————————————————————————————————

	    // VIMESCAPE
	case VIMESCAPE:
	    if (record->event.pressed) {
		SEND_STRING(";;");
	    } 
	    else {
	    }
	    break;

	    // ——————————————————————————————————————————————————————————————————
    }
    return true;
};
// ——————————————————————————————————————————————————————————————————


// ——————————————————————————————————————————————————————————————————

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // base
    [0] = LAYOUT_60_ansi(
	    // 14 keys
	    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
	    // 14 keys
	    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_LEAD, 
	    // 13 keys
	    HYPR(KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
	    // 12 keys
	    MEH(KC_NO), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
	    // 8 keys
	    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, MO(1)
	    ),

    // miscellaneous
    [1] = LAYOUT_60_ansi(
	    // 14 keys
	    KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, AUTOPARENTHESIS, KC_F10, KC_F11, KC_F12, KC_DEL,
	    // 14 keys
	    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, AUTOBRACKETS, KC_RBRC, KC_BSLS, 
	    // 13 keys
	    HYPR(KC_NO), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_G, KC_H, KC_J, KC_K, KC_L, VIMESCAPE, AUTOSINGLEQUOTES, KC_ENT, 
	    // 12 keys
	    MEH(KC_NO), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    // 8 keys
	    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, MO(2), KC_TRNS
	    ),
    // macros + other miscellaneous
    [2] = LAYOUT_60_ansi(
	    // 14 keys
	    KC_TILDE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
	    // 14 keys
	    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
	    // 13 keys
	    HYPR(KC_NO), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, AUTODOUBLEQUOTES, KC_ENT, 
	    // 12 keys
	    MEH(KC_NO), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    // 8 keys
	    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(3), KC_TRNS, KC_TRNS
	    ),
    // lighting
    [3] = LAYOUT_60_ansi(
	    // 14 keys
	    RGB_TOG, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_SPD, RGB_SPI, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
	    // 14 keys
	    KC_TAB, RGB_MODE_PLAIN, RGB_MODE_GRADIENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
	    // 13 keys
	    HYPR(KC_NO), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
	    // 12 keys
	    MEH(KC_NO), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    // 8 keys
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	    )
};

// ——————————————————————————————————————————————————————————————————
// leader macros aka hotstrings
// ——————————————————————————————————————————————————————————————————
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
	leading = false;
	leader_end();

	SEQ_ONE_KEY(KC_I) {
	    SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
	}

	SEQ_ONE_KEY(KC_A) {
	    SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
	}
	
	SEQ_ONE_KEY(KC_W) {
	    SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
	}
	
	SEQ_ONE_KEY(KC_B) {
	    SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
	}

	SEQ_TWO_KEYS(KC_2, KC_W) {
	    SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
	    SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
	}
	
	SEQ_TWO_KEYS(KC_S, KC_R) {
	    SEND_STRING(SS_DOWN(X_LGUI));
	    SEND_STRING(SS_DOWN(X_LSHIFT));
	    SEND_STRING(SS_TAP(X_RIGHT));
	    SEND_STRING(SS_UP(X_LGUI));
	    SEND_STRING(SS_UP(X_LSHIFT));
	}

	SEQ_TWO_KEYS(KC_S, KC_L) {
	    SEND_STRING(SS_DOWN(X_LGUI));
	    SEND_STRING(SS_DOWN(X_LSHIFT));
	    SEND_STRING(SS_TAP(X_LEFT));
	    SEND_STRING(SS_UP(X_LGUI));
	    SEND_STRING(SS_UP(X_LSHIFT));
	}
    }
}
