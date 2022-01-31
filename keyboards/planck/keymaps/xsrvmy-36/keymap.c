#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include "g/keymap_combo.h"


#define LAYOUT_36KEY(\
	k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,\
	k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,\
	k20,k21,k22,k23,k24,k25,k26,k27,k28,k29,\
	k30,k31,k32,k33,k34,k35\
) LAYOUT(\
	k00,k01,k02,k03,k04,RGB_TOG,KC_NO,k05,k06,k07,k08,k09,\
	k10,k11,k12,k13,k14,AU_ON,AU_OFF,k15,k16,k17,k18,k19,\
	k20,k21,k22,k23,k24,KC_NO,KC_NO,k25,k26,k27,k28,k29,\
	KC_LCTL,KC_LGUI,KC_LALT,k30,k31,k32,k33,k34,k35,KC_RALT,KC_RGUI,KC_RCTL\
)

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
	SHIFTED_BASE,
	ENGRAM,
	SYMBOL,
	NAVIGATION,
	ADJUST,
	STENO,
	LAYER_COUNT,
};

enum my_keycodes {
	AOEUI = SAFE_RANGE,
};

float my_dvorak_song[][2] = SONG(DVORAK_AMERICAN);
float my_plover_song[][2] = SONG(PLOVER_JVOICE);

#define KC_TAB_SM LT(SYMBOL, KC_TAB)
#define KC_ESC_NV LT(NAVIGATION, KC_ESC)
#define KC_S_BASE MO(SHIFTED_BASE)
#define KC_DVORAK DF(BASE)
#define KC_STENO DF(STENO)
#define KC_ENGRAM DF(ENGRAM)
#define KC_RESET RESET

bool no_combo = false;

void keyboard_post_init_user(void) {
	rgblight_setrgb(255, 255, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case DF(BASE):
		if (record->event.pressed) {
			audio_set_tempo(30);
			PLAY_SONG(my_dvorak_song);
			no_combo = false;
			rgblight_setrgb(255, 255, 0);
		}
		break;
	case DF(ENGRAM):
		if (record->event.pressed) {
			no_combo = false;
			rgblight_setrgb(0, 255, 0);
		}
		break;
	case DF(STENO):
		if (record->event.pressed) {
			audio_set_tempo(25);
			PLAY_SONG(my_plover_song);
			no_combo = true;
			rgblight_setrgb(0, 255, 204);
		}
		break;
	case RESET:
		if (record->event.pressed) {
			rgblight_setrgb(0, 0, 0);
		}
		break;
	}
	return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
	if (state >> 2 || no_combo) {
		combo_disable();
	} else {
		combo_enable();
	}
	return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	if (state >> 2 || no_combo) {
		combo_disable();
	} else {
		combo_enable();
	}
	layer_state_t new_state = update_tri_layer_state(state, SYMBOL, NAVIGATION, ADJUST);

	return new_state;
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
	if (KEYCODE_IS_MOD(combo->keycode)) {
		return true;
	}
	return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_36KEY_MODS(
QUOT,	COMMA,	DOT,	P,	Y,			F,	G,	C,	R,	L,
A,	O,	E,	U,	I,			D,	H,	T,	N,	S,
SCLN,	Q,	J,	K,	X,			B,	M,	W,	V,	Z,
			TAB_SM,	S_BASE,	BSPC,	ENTER,	SPACE,	ESC_NV
),
[SHIFTED_BASE] = LAYOUT_36KEY(
KC_QUOT,KC_COMMA,KC_DOT,S(KC_P),S(KC_Y),		S(KC_F),S(KC_G),S(KC_C),S(KC_R),S(KC_L),
S(KC_A),S(KC_O),S(KC_E),S(KC_U),S(KC_I),		S(KC_D),S(KC_H),S(KC_T),S(KC_N),S(KC_S),
KC_SCLN,S(KC_Q),S(KC_J),S(KC_K),S(KC_X),		S(KC_B),S(KC_M),S(KC_W),S(KC_V),S(KC_Z),
			_______,_______,_______,_______,_______,_______
),
[ENGRAM] = LAYOUT_36KEY_KC(
B,	Y,	O,	U,	Z,			Q,	L,	D,	W,	V,
C,	I,	E,	A,	COMMA,			DOT,	H,	T,	S,	N,
G,	X,	J,	K,	SCLN,			QUOT,	R,	M,	F,	P,
			TAB_SM,	RSFT,	BSPC,	ENTER,	SPACE,	ESC_NV
),
[SYMBOL] = LAYOUT_36KEY_MODS(
AMPR,	EXLM,	QUES,	UNDS,	CIRC,			ASTR,	7,	8,	9,	SLASH,
AT,	HASH,	EQUAL,	PLUS,	PERC,			EQUAL,	4,	5,	6,	MINUS,
GRAVE,	BSLS,	LBRC,	RBRC,	DLR,			PLUS  ,	1,	2,	3,	DOT,
			TRNS,	TRNS,	TRNS,	TRNS,	0,	TRNS
),
[NAVIGATION] = LAYOUT_36KEY_MODS(
F1,	F2,	F3,	F4,	NO,			PGUP,	HOME,	UP,	END,	INS,
F5,	F6,	F7,	F8,	NO,			PGDN,	LEFT,	DOWN,	RIGHT,	PSCR,
F9,	F10,	F11,	F12,	NO,			NO,	PGDN,	PGUP,	INS,	PSCR,
			TRNS,	TRNS,	DEL,	TRNS,	TRNS,	TRNS
),
//[STENO] = LAYOUT_planck_grid(
//KC_NO,  STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,STN_ST3,STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
//KC_NO,  STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2,STN_ST4,STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
//KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
//KC_NO,  DF(0),  KC_NO,  STN_NC, STN_A,  STN_O,  STN_E,  STN_U,  STN_NC, KC_NO,  DF(1),  KC_NO
//),
[STENO] = LAYOUT_planck_grid(
MI_OCT_0,MI_C,  MI_D,   MI_E,   MI_F,   MI_G,   MI_A,   MI_B,   MI_C_1, MI_D_1, MI_E_1, MI_F_1,
KC_NO,  MI_C_2, MI_D_2, MI_E_2, MI_F_2, MI_G_2, MI_A_2, MI_B_2, MI_C_3, MI_D_3, MI_E_3, MI_F_3,
KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
KC_NO,  DF(0),  KC_NO,  MI_C_4, MI_D_4, MI_E_4, MI_F_4, MI_G_4, MI_A_4, KC_NO,  DF(1),  KC_NO
),
[ADJUST] = LAYOUT_36KEY_KC(
DVORAK,	NO,	NO,	NO,	STENO,			NO,	WH_L,	MS_U,	WH_R,	NO,
NO,	BTN3,	BTN1,	BTN2,	ENGRAM,			NO,	MS_L,	MS_D,	MS_R,	NO,
LGUI,	LALT,	LCTL,	LSFT,	RESET,			NO,	WH_D,	WH_U,	NO,	NO,
			TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS
),
};
