#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define LAYOUT_36KEY_KC(\
	k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,\
	k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,\
	k20,k21,k22,k23,k24,k25,k26,k27,k28,k29,\
	k30,k31,k32,k33,k34,k35\
) LAYOUT_36KEY(\
	KC_##k00,KC_##k01,KC_##k02,KC_##k03,KC_##k04,KC_##k05,KC_##k06,KC_##k07,KC_##k08,KC_##k09,\
	KC_##k10,KC_##k11,KC_##k12,KC_##k13,KC_##k14,KC_##k15,KC_##k16,KC_##k17,KC_##k18,KC_##k19,\
	KC_##k20,KC_##k21,KC_##k22,KC_##k23,KC_##k24,KC_##k25,KC_##k26,KC_##k27,KC_##k28,KC_##k29,\
	KC_##k30,KC_##k31,KC_##k32,KC_##k33,KC_##k34,KC_##k35\
)

#define LAYOUT_36KEY_MODS(\
	k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,\
	k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,\
	k20,k21,k22,k23,k24,k25,k26,k27,k28,k29,\
	k30,k31,k32,k33,k34,k35\
) LAYOUT_36KEY(\
	KC_##k00,KC_##k01,KC_##k02,KC_##k03,KC_##k04,KC_##k05,KC_##k06,KC_##k07,KC_##k08,KC_##k09,\
	KC_##k10,KC_##k11,KC_##k12,KC_##k13,KC_##k14,KC_##k15,KC_##k16,KC_##k17,KC_##k18,KC_##k19,\
	GUI_T(KC_##k20),ALT_T(KC_##k21),CTL_T(KC_##k22),SFT_T(KC_##k23),KC_##k24,KC_##k25,SFT_T(KC_##k26),CTL_T(KC_##k27),ALT_T(KC_##k28),GUI_T(KC_##k29),\
	KC_##k30,KC_##k31,KC_##k32,KC_##k33,KC_##k34,KC_##k35\
)

enum layer_names {
	BASE,
	SYMBOL,
	NAVIGATION,
	ADJUST
};

#define KC_TAB_SM LT(SYMBOL, KC_TAB)
#define KC_ESC_NV LT(NAVIGATION, KC_ESC)
#define KC_DVORAK DF(BASE)
#define KC_RESET RESET

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, SYMBOL, NAVIGATION, ADJUST);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_36KEY_MODS(
QUOT,	COMMA,	DOT,	P,	Y,			F,	G,	C,	R,	L,
A,	O,	E,	U,	I,			D,	H,	T,	N,	S,
SCLN,	Q,	J,	K,	X,			B,	M,	W,	V,	Z,
			TAB_SM,	BSPC,	LSFT,	ENTER,	SPACE,	ESC_NV
),
[SYMBOL] = LAYOUT_36KEY_MODS(
AMPR,	EXLM,	QUES,	UNDS,	CIRC,			ASTR,	7,	8,	9,	SLASH,
AT,	HASH,	EQUAL,	PLUS,	PERC,			EQUAL,	4,	5,	6,	MINUS,
GRAVE,	BSLS,	LBRC,	RBRC,	DLR,			PLUS  ,	1,	2,	3,	DOT,
			TRNS,	TRNS,	TRNS,	TRNS,	0,	TRNS
),
[NAVIGATION] = LAYOUT_36KEY_MODS(
F1,	F2,	F3,	F4,	NO,			HASH,	HOME,	UP,	END,	PIPE,
F5,	F6,	F7,	F8,	NO,			AT,	LEFT,	DOWN,	RIGHT,	TILDE,
F9,	F10,	F11,	F12,	NO,			NO,	PGDN,	PGUP,	INS,	PSCR,
			TRNS,	DEL,	TRNS,	TRNS,	TRNS,	TRNS
),
[ADJUST] = LAYOUT_36KEY_KC(
DVORAK,	NO,	NO,	NO,	NO,			NO,	WH_L,	MS_U,	WH_R,	NO,
NO,	NO,	BTN1,	BTN2,	BTN3,			NO,	MS_L,	MS_D,	MS_R,	NO,
NO,	NO,	NO,	NO,	RESET,			NO,	WH_D,	WH_U,	NO,	NO,
			TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS
),
};
