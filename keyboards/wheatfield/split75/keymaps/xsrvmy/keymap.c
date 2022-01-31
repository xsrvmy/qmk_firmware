#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#define LAYOUT_KC(K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,K13,K14,K15,K16,\
K17,K18,K19,K20,K21,K22,K23,K24,K25,K26,K27,K28,K29,K30,K31,K32,K33,\
K34,K35,K36,K37,K38,K39,K40,K41,K42,K43,K44,K45,K46,K47,K48,K49,K50,\
K51,K52,K53,K54,K55,K56,K57,K58,K59,K60,K61,K62,K63,K64,K65,K66,\
K67,K68,K69,K70,K71,K72,K73,K74,K75,K76,K77,K78,K79,K80,K81,K82,\
K83,K84,K85,K86,K87,K88,K89,K90,K91,K92,K93,K94,K95,K96) LAYOUT(\
KC_##K1,KC_##K2,KC_##K3,KC_##K4,KC_##K5,KC_##K6,KC_##K7,KC_##K8,KC_##K9,KC_##K10,KC_##K11,KC_##K12,KC_##K13,KC_##K14,KC_##K15,KC_##K16,\
KC_##K17,KC_##K18,KC_##K19,KC_##K20,KC_##K21,KC_##K22,KC_##K23,KC_##K24,KC_##K25,KC_##K26,KC_##K27,KC_##K28,KC_##K29,KC_##K30,KC_##K31,KC_##K32,KC_##K33,\
KC_##K34,KC_##K35,KC_##K36,KC_##K37,KC_##K38,KC_##K39,KC_##K40,KC_##K41,KC_##K42,KC_##K43,KC_##K44,KC_##K45,KC_##K46,KC_##K47,KC_##K48,KC_##K49,KC_##K50,\
KC_##K51,KC_##K52,KC_##K53,KC_##K54,KC_##K55,KC_##K56,KC_##K57,KC_##K58,KC_##K59,KC_##K60,KC_##K61,KC_##K62,KC_##K63,KC_##K64,KC_##K65,KC_##K66,\
KC_##K67,KC_##K68,KC_##K69,KC_##K70,KC_##K71,KC_##K72,KC_##K73,KC_##K74,KC_##K75,KC_##K76,KC_##K77,KC_##K78,KC_##K79,KC_##K80,KC_##K81,KC_##K82,\
KC_##K83,KC_##K84,KC_##K85,KC_##K86,KC_##K87,KC_##K88,KC_##K89,KC_##K90,KC_##K91,KC_##K92,KC_##K93,KC_##K94,KC_##K95,KC_##K96\
)

enum layer_names {
  DVORAK,
  QWERTY,
  CHORDED,
  SYMBOL,
  NAVIGATE,
  MOUSE,
  STENO1,
  STENO2,
  ADJUST
};

// steno keys as KC
// #define KC_ST_NUM STN_NUM
// #define KC_ST_SL STN_SL
// #define KC_ST_TL STN_TL
// #define KC_ST_KL STN_KL
// #define KC_ST_PL STN_PL
// #define KC_ST_WL STN_WL
// #define KC_ST_HL STN_HL
// #define KC_ST_RL STN_RL
// #define KC_ST_A STN_A
// #define KC_ST_O STN_O
// #define KC_ST_STR STN_STR
// #define KC_ST_E STN_E
// #define KC_ST_U STN_U
// #define KC_ST_FR STN_FR
// #define KC_ST_PR STN_PR
// #define KC_ST_RR STN_RR
// #define KC_ST_BR STN_BR
// #define KC_ST_LR STN_LR
// #define KC_ST_GR STN_GR
// #define KC_ST_TR STN_TR
// #define KC_ST_SR STN_SR
// #define KC_ST_DR STN_DR
// #define KC_ST_ZR STN_ZR
// 
// #define KC_ST_N1 STN_N1
// #define KC_ST_N2 STN_N2
// #define KC_ST_N3 STN_N3
// #define KC_ST_N4 STN_N4
// #define KC_ST_N5 STN_N5
// #define KC_ST_N6 STN_N6
// #define KC_ST_N7 STN_N7
// #define KC_ST_N8 STN_N8
// #define KC_ST_N9 STN_N9
// #define KC_ST_NA STN_NA
// #define KC_ST_NB STN_NB
// #define KC_ST_NC STN_NC
// #define KC_ST_S1 STN_S1
// #define KC_ST_S2 STN_S2
// #define KC_ST_ST1 STN_ST1
// #define KC_ST_ST2 STN_ST2
// #define KC_ST_ST3 STN_ST3
// #define KC_ST_ST4 STN_ST4
// #define KC_ST_FN STN_FN
// #define KC_ST_RS1 STN_RES1
// #define KC_ST_RS2 STN_RES2
// #define KC_ST_PWR STN_PWR

#define KC_DVRK DF(DVORAK)
#define KC_QWER DF(QWERTY)
#define KC_CHORD DF(CHORDED)
#define KC_STEN1 DF(STENO1)
#define KC_STEN2 DF(STENO2)
#define KC_ADJST OSL(ADJUST)

#define KC_RESET RESET

#define KC_MS_ESC LT(MOUSE, KC_ESC)
#define KC_GUI_SC GUI_T(KC_SCLN)
#define KC_ALT_Q ALT_T(KC_Q)
#define KC_CTL_J CTL_T(KC_J)
#define KC_SFT_K SFT_T(KC_K)
#define KC_SFT_M SFT_T(KC_M)
#define KC_CTL_W CTL_T(KC_W)
#define KC_ALT_V ALT_T(KC_V)
#define KC_GUI_Z GUI_T(KC_Z)

#define KC_OS_SFT OSM(MOD_LSFT)
#define KC_OS_SYM OSL(SYMBOL)
#define KC_OS_NAV OSL(NAVIGATE)
#define KC_MO_NAV MO(NAVIGATE)

// const uint16_t PROGMEM combo_ht1[] = {KC_A, KC_QUOT, COMBO_END};
// const uint16_t PROGMEM combo_ht2[] = {KC_O, KC_COMMA, COMBO_END};
// const uint16_t PROGMEM combo_ht3[] = {KC_E, KC_DOT, COMBO_END};
// const uint16_t PROGMEM combo_ht4[] = {KC_U, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_ht5[] = {KC_I, KC_Y, COMBO_END};
// const uint16_t PROGMEM combo_ht6[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM combo_ht7[] = {KC_H, KC_G, COMBO_END};
// const uint16_t PROGMEM combo_ht8[] = {KC_T, KC_C, COMBO_END};
// const uint16_t PROGMEM combo_ht9[] = {KC_N, KC_R, COMBO_END};
// const uint16_t PROGMEM combo_ht0[] = {KC_S, KC_L, COMBO_END};
// 
// const uint16_t PROGMEM combo_lh345[] = {KC_A, KC_O, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_lh234[] = {KC_O, KC_E, KC_U, COMBO_END};
// const uint16_t PROGMEM combo_lh234_in[] = {KC_E, KC_U, KC_I, COMBO_END};
// const uint16_t PROGMEM combo_lt345[] = {KC_QUOT, KC_COMMA, KC_DOT, COMBO_END};
// const uint16_t PROGMEM combo_lt234[] = {KC_COMMA, KC_DOT, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_lt234_in[] = {KC_DOT, KC_P, KC_Y, COMBO_END};
// 
// const uint16_t PROGMEM combo_rh345[] = {KC_S, KC_N, KC_T, COMBO_END};
// const uint16_t PROGMEM combo_rh234[] = {KC_N, KC_T, KC_H, COMBO_END};
// const uint16_t PROGMEM combo_rh234_in[] = {KC_T, KC_H, KC_D, COMBO_END};
// const uint16_t PROGMEM combo_rt345[] = {KC_L, KC_R, KC_C, COMBO_END};
// const uint16_t PROGMEM combo_rt234[] = {KC_R, KC_C, KC_G, COMBO_END};
// const uint16_t PROGMEM combo_rt234_in[] = {KC_C, KC_G, KC_F, COMBO_END};
// 
// 
// combo_t key_combos[COMBO_COUNT] = {
//   COMBO(combo_ht1, KC_AT),
//   COMBO(combo_ht2, KC_HASH),
//   COMBO(combo_ht3, KC_DOLLAR),
//   COMBO(combo_ht4, KC_EXCLAIM),
//   COMBO(combo_ht5, KC_UNDERSCORE),
//   COMBO(combo_ht6, KC_MINUS),
//   COMBO(combo_ht7, KC_QUESTION),
//   COMBO(combo_ht8, KC_CIRCUMFLEX),
//   COMBO(combo_ht9, KC_AMPERSAND),
//   COMBO(combo_ht0, KC_ASTERISK),
// 
//   COMBO(combo_lh345, KC_NO),
//   COMBO(combo_lh234, KC_NO),
//   COMBO(combo_lh234_in, KC_NO),
//   COMBO(combo_lt345, KC_NO),
//   COMBO(combo_lt234, KC_NO),
//   COMBO(combo_lt234_in, KC_NO),
// 
//   COMBO(combo_rh345, KC_NO),
//   COMBO(combo_rh234, KC_NO),
//   COMBO(combo_rh234_in, KC_NO),
//   COMBO(combo_rt345, KC_NO),
//   COMBO(combo_rt234, KC_NO),
//   COMBO(combo_rt234_in, KC_NO)
// };

void plover_on(void);
void plover_off(void);

void plover_on(void) {
  register_code(KC_LCTL);
  register_code(KC_LALT);
  register_code(KC_LSFT);
  register_code(KC_F1);
  unregister_code(KC_F1);
  unregister_code(KC_LSFT);
  unregister_code(KC_LALT);
  unregister_code(KC_LCTL);
}

void plover_off(void) {
  register_code(KC_LCTL);
  register_code(KC_LALT);
  register_code(KC_LSFT);
  register_code(KC_F2);
  unregister_code(KC_F2);
  unregister_code(KC_LSFT);
  unregister_code(KC_LALT);
  unregister_code(KC_LCTL);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case KC_STEN1:
      case KC_STEN2:
	plover_on();
	break;
      case KC_CHORD:
	plover_off();
	break;
      case KC_DVRK:
      case KC_QWER:
	plover_off();
	break;
    }
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVORAK] = LAYOUT_KC(
			ESC,	F1,	F2,	F3,	F4,	F5,	F6,			F7,	F8,	F9,	F10,	F11,	F12,	PSCR,	INS,	DEL,
NO,	NO,		GRAVE,	1,	2,	3,	4,	5,	6,			7,	8,	9,	0,	LBRC,	RBRC,	BSPC,		HOME,
NO,	NO,		TAB,	QUOT,	COMM,	DOT,	P,	Y,			F,	G,	C,	R,	L,	SLSH,	EQUAL,	BSLS,		PGUP,
NO,	NO,		ESC,	A,	O,	E,	U,	I,			D,	H,	T,	N,	S,	MINUS,	ENTER,			PGDN,
NO,	NO,		LSFT,	SCLN,	Q,	J,	K,	X,			B,	M,	W,	V,	Z,	RSFT,			UP,	END,
ADJST,	NO,		LCTL,	LGUI,	LALT,	SPC,		SPC,			SPC,				RALT,	APP,	RCTL,	LEFT,	DOWN,	RIGHT
),
  [QWERTY] = LAYOUT_KC(
			ESC,	F1,	F2,	F3,	F4,	F5,	F6,			F7,	F8,	F9,	F10,	F11,	F12,	PSCR,	INS,	DEL,
NO,	NO,		GRAVE,	1,	2,	3,	4,	5,	6,			7,	8,	9,	0,	MINUS,	EQUAL,	BSPC,		HOME,
NO,	NO,		TAB,	Q,	W,	E,	R,	T,			Y,	U,	I,	O,	P,	LBRC,	RBRC,	BSLS,		PGUP,
NO,	NO,		ESC,	A,	S,	D,	F,	G,			H,	J,	K,	L,	SCLN,	QUOT,	ENTER,			PGDN,
NO,	NO,		LSFT,	Z,	X,	C,	V,	B,			N,	M,	COMM,	DOT,	SLSH,	RSFT,			UP,	END,
ADJST,	NO,		LCTL,	LGUI,	LALT,	SPC,		SPC,			SPC,				RALT,	APP,	RCTL,	LEFT,	DOWN,	RIGHT
),
  [CHORDED] = LAYOUT_KC(
			NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,
NO,	NO,		GRAVE,	1,	2,	3,	4,	5,	6,			7,	8,	9,	0,	BSPC,	NO,	BSPC,		HOME,
NO,	NO,		TAB,	QUOT,	COMMA,	DOT,	P,	Y,			F,	G,	C,	R,	L,	SLSH,	NO,	NO,		PGUP,
NO,	NO,		MS_ESC,	A,	O,	E,	U,	I,			D,	H,	T,	N,	S,	MINUS,	ENTER,			PGDN,
NO,	NO,		OS_SFT,	GUI_SC,	ALT_Q,	CTL_J,	SFT_K,	X,			B,	SFT_M,	CTL_W,	ALT_V,	GUI_Z,	OS_SFT,			UP,	END,
ADJST,	NO,		NO,	NO,	NO,	MO_NAV,		OS_SYM,			SPC,				ENTER,	NO,	NO,	LEFT,	DOWN,	RIGHT
),
  [SYMBOL] = LAYOUT_KC(
			NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,
NO,	NO,		NO,	1,	2,	3,	4,	5,	6,			7,	8,	9,	0,	BSPC,	NO,	NO,		NO,
NO,	NO,		NO,	AMPR,	AT,	HASH,	PERC,	QUES,			CIRC,	RPRN,	RCBR,	RBRC,	PIPE,	NO,	NO,	NO,		NO,
NO,	NO,		NO,	MINUS,	ASTR,	EQUAL,	PLUS,	SLSH,			UNDS,	LPRN,	LCBR,	LBRC,	BSLS,	NO,	NO,			NO,
NO,	NO,		NO,	LT,	LALT,	LCTL,	EXLM,	TILDE,			GRAVE,	DLR,	LCTL,	LALT,	GT,	NO,			NO,	NO,
ADJST,	NO,		NO,	NO,	NO,	NO,		TRNS,			SPC,				ENTER,	NO,	NO,	NO,	NO,	NO
),
  [NAVIGATE] = LAYOUT_KC(
			NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,
NO,	NO,		NO,	NO,	NO,	NO,	NO,	NO,	NO,			F9,	F10,	F11,	F12,	BSPC,	NO,	NO,		NO,
NO,	NO,		NO,	TAB,	F1,	F2,	F3,	F4,			PGUP,	HOME,	UP,	END,	NO,	NO,	NO,	NO,		NO,
NO,	NO,		NO,	ESC,	F5,	F6,	F7,	F8,			PGDN,	LEFT,	DOWN,	RIGHT,	NO,	NO,	NO,			NO,
NO,	NO,		NO,	LGUI,	LALT,	LCTL,	LSFT,	X,			NO,	LSFT,	LCTL,	LALT,	LGUI,	NO,			NO,	NO,
ADJST,	NO,		NO,	NO,	NO,	TRNS,		NO,			BSPC,				DEL,	NO,	NO,	NO,	NO,	NO
),
  [MOUSE] = LAYOUT_KC(
			NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,
NO,	NO,		NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,		NO,
NO,	NO,		NO,	NO,	NO,	NO,	NO,	NO,			WH_U,	WH_L,	MS_U,	WH_R,	NO,	NO,	NO,	NO,		NO,
NO,	NO,		NO,	NO,	BTN1,	BTN3,	BTN2,	NO,			WH_D,	MS_L,	MS_D,	MS_R,	NO,	NO,	NO,		NO,
NO,	NO,		NO,	TRNS,	LCTL,	LALT,	LSFT,	NO,			NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,
ADJST,	NO,		NO,	NO,	NO,	NO,		NO,			BTN1,				BTN2,	NO,	NO,	NO,	NO,	NO
),
  [STENO1] = LAYOUT_KC(
			NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,
NO,	NO,		NO,	1,	2,	3,	4,	5,	6,			7,	8,	9,	0,	MINUS,	EQUAL,	NO,		NO,
NO,	NO,		NO,	Q,	W,	E,	R,	T,			Y,	U,	I,	O,	P,	LBRC,	NO,	NO,		NO,
NO,	NO,		NO,	A,	S,	D,	F,	G,			H,	J,	K,	L,	SCLN,	QUOT,	NO,			NO,
NO,	NO,		NO,	NO,	NO,	C,	V,	NO,			N,	M,	NO,	NO,	NO,	NO,			NO,	NO,
ADJST,	NO,		NO,	NO,	NO,	NO,		NO,			NO,				NO,	NO,	NO,	NO,	NO,	NO
),
  [STENO2] = LAYOUT_KC(
			NO,	Q,	W,	E,	R,	T,	NO,			Y,	U,	I,	O,	P,	LBRC,	NO,	NO,	NO,
NO,	NO,		NO,	A,	S,	D,	F,	G,	NO,			H,	J,	K,	L,	SCLN,	QUOT,	NO,		NO,
NO,	NO,		NO,	NO,	NO,	C,	V,	1,			1,	N,	M,	NO,	NO,	NO,	NO,	NO,		NO,
NO,	NO,		NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,
NO,	NO,		NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,
ADJST,	NO,		NO,	NO,	NO,	NO,		NO,			NO,				NO,	NO,	NO,	NO,	NO,	NO
),
  [ADJUST] = LAYOUT_KC(
			NO,	MUTE,	VOLD,	VOLU,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	BRIU,	BRID,	NO,	NO,	NO,
DVRK,	QWER,		NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,		NO,
CHORD,	NO,		NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,	NO,		NO,
NO,	NO,		NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,	NO,			NO,
STEN1,	STEN2,		NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,	NO,	NO,	NO,	NO,			NO,	NO,
TRNS,	RESET,		NO,	NO,	NO,	NO,		NO,			NO,				NO,	NO,	NO,	NO,	NO,	NO
),

};
