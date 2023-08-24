#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#include "../../../../../quantum/quantum.h"

#define LAYOUT_KC(K1, K2, K3, K4, K5, K6, K7, K8, K9, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K50, K51, K52, K53, K54, K55, K56) LAYOUT(KC_##K1, KC_##K2, KC_##K3, KC_##K4, KC_##K5, KC_##K6, KC_##K7, KC_##K8, KC_##K9, KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47, KC_##K48, KC_##K49, KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56)
#define LAYOUT_KC_MODS(K1, K2, K3, K4, K5, K6, K7, K8, K9, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K50, K51, K52, K53, K54, K55, K56) LAYOUT(KC_##K1, KC_##K2, KC_##K3, KC_##K4, KC_##K5, KC_##K6, KC_##K7, KC_##K8, KC_##K9, KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, LGUI_T(KC_##K38), LALT_T(KC_##K39), LCTL_T(KC_##K40), LSFT_T(KC_##K41), KC_##K42, KC_##K43, KC_##K44, KC_##K45, RSFT_T(KC_##K46), RCTL_T(KC_##K47), RALT_T(KC_##K48), RGUI_T(KC_##K49), KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56)

/***** LAYER NAMES *****/
#define _APTMOD 0
#define _QWERTY 1
#define _LOWER 8
#define _RAISE 9
#define _ADJUST 10

/***** KC_ ALIAS *****/
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO
#define KC_RESET QK_BOOT
#define KC_LOWER MO(_LOWER)
#define KC_RAISE MO(_RAISE)

#define KC_QWERTY DF(_QWERTY)
#define KC_APTMOD DF(_APTMOD)

/***** KEYMAP *****/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_APTMOD] = LAYOUT_KC(
		XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,				XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,
		XXXX,	W,	G,	D,	F,	V,				Q,	L,	U,	O,	Y,	XXXX,
		XXXX,	R,	S,	T,	H,	B,				J,	N,	E,	A,	I,	XXXX,
		XXXX,	X,	C,	M,	P,	K,	XXXX,		XXXX,	Z,	DOT,	QUOT,	COMMA,	SCLN,	XXXX,
						LOWER,	LSFT,	BSPC,		ENTER,	SPACE,	RAISE
	),

	[_QWERTY] = LAYOUT_KC(
		GRAVE,	1,	2,	3,	4,	5,				6,	7,	8,	9,	0,	MINUS,
		LBRC,	Q,	W,	E,	R,	T,				Y,	U,	I,	O,	P,	RBRC,
		LSFT,	A,	S,	D,	F,	G,				H,	J,	K,	L,	SCLN,	QUOT,
		LCTL,	Z,	X,	C,	V,	B,	DEL,		BSLS,	N,	M,	COMMA,	DOT,	SLASH,	EQUAL,
						ESC,	SPACE,	BSPC,		ENTER,	SPACE,	RAISE
	),

	[_LOWER] = LAYOUT_KC(
		XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,				XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,
		XXXX,	GRAVE,	COMMA,	DOT,	ESC,	XXXX,				XXXX,	MINUS,	EQUAL,	SLASH,	BSLS,	XXXX,
		XXXX,	1,	2,	3,	4,	5,				6,	7,	8,	9,	0,	XXXX,
		XXXX,	LGUI,	LALT,	LCTL,	LSFT,	COLON,	XXXX,		XXXX,	XXXX,	RSFT,	RCTL,	RALT,	RGUI,	XXXX,
						____,	____,	____,		____,	____,	____
	),

	[_RAISE] = LAYOUT_KC(
		XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,				XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,
		XXXX,	F1,	F2,	F3,	F4,	F10,				PGUP,	HOME,	UP,	END,	DEL,	XXXX,
		XXXX,	F5,	F6,	F7,	F8,	F9,				PGDN,	LEFT,	DOWN,	RIGHT,	TAB,	XXXX,
		XXXX,	LGUI,	LALT,	LCTL,	LSFT,	F11,	XXXX,		XXXX,	F12,	RSFT,	RCTL,	RALT,	RGUI,	XXXX,
						____,	____,	____,		____,	____,	____
	),

	[_ADJUST] = LAYOUT_KC(
		XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,				XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	RESET,
		XXXX,	QWERTY,	APTMOD,	XXXX,	XXXX,	XXXX,				XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,
		XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,				XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,
		XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,		XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,	XXXX,
						____,	____,	____,		____,	____,	____
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
	if (get_highest_layer(state) != _APTMOD) {
		combo_disable();
	} else {
		combo_enable();
	}
	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
