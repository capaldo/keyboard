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
// ——————————————————————————————————————————————————————————————————
 
    // AUTOPARENTHESIS
     case AUTOPARENTHESIS:
      if (record->event.pressed) {
	  SEND_STRING("()");
      } 
      else {
	  SEND_STRING(SS_TAP(X_LEFT));
      }
      break;

// ——————————————————————————————————————————————————————————————————

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
	  SEND_STRING("""");
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
	    ),
    // ipados default TODO
    [4] = LAYOUT_60_ansi(
	    // 14 keys
	    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
	    // 14 keys
	    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
	    // 13 keys
	    HYPR(KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
	    // 12 keys
	    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
	    // 8 keys
	    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, MO(1)
	    ),
    // ipados blink TODO
    [5] = LAYOUT_60_ansi(
	    // 14 keys
	    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
	    // 14 keys
	    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
	    // 13 keys
	    HYPR(KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
	    // 12 keys
	    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
	    // 8 keys
	    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, MO(1)
	    ),
    // ipados macros TODO
    [6] = LAYOUT_60_ansi(
	    // 14 keys
	    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
	    // 14 keys
	    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
	    // 13 keys
	    HYPR(KC_NO), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
	    // 12 keys
	    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
	    // 8 keys
	    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, MO(1)
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

// A
// ————————————————————————————————————————

// B
// ————————————————————————————————————————

    // bc to because
    SEQ_TWO_KEYS(KC_B, KC_C) {
	SEND_STRING("because");
    }

    // btw to by the way
    SEQ_THREE_KEYS(KC_B, KC_T, KC_W) {
	SEND_STRING("by the way");
    }

    // brb to be right back
    SEQ_THREE_KEYS(KC_B, KC_R, KC_B) {
	SEND_STRING("be right back");
    }

    // bw to between
    SEQ_TWO_KEYS(KC_B, KC_W) {
	SEND_STRING("between");
    }

// C
// ————————————————————————————————————————

// D
// ————————————————————————————————————————

    // dn to do not
    SEQ_TWO_KEYS(KC_D, KC_N) {
	SEND_STRING("do not");
    }

// E
// ————————————————————————————————————————
// F
// ————————————————————————————————————————
// G
// ————————————————————————————————————————
// H
// ————————————————————————————————————————

// I
// ————————————————————————————————————————

    // idt to I dont think
    SEQ_THREE_KEYS(KC_I, KC_D, KC_T) {
	SEND_STRING("I dont think");
    }

    // idts to I dont think
    SEQ_FOUR_KEYS(KC_I, KC_D, KC_T, KC_S) {
	SEND_STRING("I dont think so");
    }

    // ily to I love you
    SEQ_THREE_KEYS(KC_I, KC_L, KC_Y) {
	SEND_STRING("I love you");
    }

    // ilyt to I love you too
    SEQ_FOUR_KEYS(KC_I, KC_L, KC_Y, KC_T) {
	SEND_STRING("I love you too");
    }

    // info to information
    SEQ_FOUR_KEYS(KC_I, KC_N, KC_F, KC_O) {
	SEND_STRING("information");
    }

// J
// ————————————————————————————————————————

    // jk to just kidding
    SEQ_TWO_KEYS(KC_J, KC_K) {
	SEND_STRING("just kidding");
    }

// K
// ————————————————————————————————————————

// L
// ————————————————————————————————————————

// M
// ————————————————————————————————————————

// N
// ————————————————————————————————————————

// O
// ————————————————————————————————————————

// P
// ————————————————————————————————————————

    // prob to probably
    SEQ_FOUR_KEYS(KC_P, KC_R, KC_O, KC_B) {
	SEND_STRING("probably");
    }

// Q
// ————————————————————————————————————————

// R
// ————————————————————————————————————————

// S
// ————————————————————————————————————————

    // sup to whats up
    SEQ_THREE_KEYS(KC_S, KC_U, KC_P) {
	SEND_STRING("whats up");
    }

// T
// ————————————————————————————————————————

    // thru to through
    SEQ_FOUR_KEYS(KC_T, KC_H, KC_R, KC_U) {
	SEND_STRING("through");
    }

// U
// ————————————————————————————————————————


// V
// ————————————————————————————————————————


// W
// ————————————————————————————————————————


// X
// ————————————————————————————————————————


// Y
// ————————————————————————————————————————


// Z
// ————————————————————————————————————————


    }
  }
