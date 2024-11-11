
 /* Copyright 2021 Dane Evans
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

//This is used to help replace the V in HSV with the indicator brightness
#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override

#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

#define RIGHT_ZERO 36

#define LEFT_ZERO 0

#define HSV_ENGRAMMER HSV_PURPLE

#define HSV_QWERTY HSV_TEAL

#define HSV_NUMPAD HSV_BLUE

#define HSV_RAISE HSV_CORAL

#define HSV_LOWER HSV_GOLDENROD

#define HSV_ADJUST HSV_ORANGE

/*
 * KEY ID
 * ,-----------------------------------------.                    ,--------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    | 33  |32| 23  |22|  13 |12|
 * |------+------+------+------+------+------|                    |-----+--+-----+--+-----+--|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |34(4)|31|24(3)|21|14(2)|11|
 * |------+------+------+------+------+------|                    |-----+--+-----+--+-----+--|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|  35 |30| 25  |20|  15 |10|
 * |------+------+------+------+------+------| MUTE  |    | 0     |-----+--+-----+--+-----+--|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|  35 |29| 26  |19|  16 | 9|
 * `-----------------------------------------/       /     \      \--------------------------'
 *            | OS   | L_ALT|LOWER | TAB  | / SPACE /       \ 28(5)\|27 |18|(6)|17 | 8 |(7)
 *            `----------------------------------'           '------''-----------------------'
 */


// Light combinations
#define SET_INDICATORS(hsv) \
    {LEFT_ZERO, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {RIGHT_ZERO, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}
#define SET_UNDERGLOW(hsv) \
	{LEFT_ZERO+1, 6, hsv}, \
    {RIGHT_ZERO+1, 6,hsv}

// These are keys 17, 19, 20, 21, 24,25,26, 29, 30, 31 on the right hand
#define SET_NUMPAD(hsv)     \
	{RIGHT_ZERO+16, 1, hsv},\
	{RIGHT_ZERO+18, 3, hsv},\
	{RIGHT_ZERO+23, 3, hsv},\
	{RIGHT_ZERO+28, 3, hsv}
//These are 13, 22, 23, 32, 33 on the left and the same on the right
#define SET_NUMROW(hsv) \
	{LEFT_ZERO+12, 1, hsv}, \
    {LEFT_ZERO+21, 2, hsv}, \
    {LEFT_ZERO+31, 2, hsv}, \
    {RIGHT_ZERO+12, 2, hsv}, \
    {RIGHT_ZERO+21, 2, hsv}, \
    {RIGHT_ZERO+31, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}
//These are 9, 10, 11, 12
#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
//These are 27 and 28
#define SET_THUMB_CLUSTER(hsv) 	\
	{LEFT_ZERO+26, 2, hsv}, \
	{RIGHT_ZERO+26, 2, hsv}

#define SET_LAYER_ID(hsv) 	\
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+1, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _ENGRAMMER,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _SWITCH,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_ENGRAMMER,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_D_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GRV  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  |   '  |                    |   ;  |   Y  |   U  |   I  |   O  |  P   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   ,  |-------.    ,-------|   .  |   G  |   H  |   J  |   K  |  L   |
 * |------+------+------+------+------+------| MUTE  |    |PAUSE  |------+------+------+------+------+------|
 * | SHFT |   Z  |   X  |   C  |   V  |   -  |-------|    |-------|   /  |   B  |   N  |   M  |   \  |RShift|
 * `-----------------------------------------/       /    \      \-----------------------------------------'
 *            | TAB  | L_ALT|LOWER | SPACE| / L_CMD /      \ BKSP \ | ENTER|RAISE | ALTGR | RCTR |
 *            |      |      |      |      |/       /        \      \|      |      |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_QWERTY] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,   KC_5,             LT(_SWITCH,KC_6),   KC_7,   KC_8,    KC_9,    KC_0,    KC_EQL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   KC_Q,     KC_W,   KC_E,    KC_R,    KC_T,  KC_QUOT,                    KC_SCLN,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,   KC_COMM,                     KC_DOT,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,   KC_MINS,  KC_MUTE,  KC_MPLY, KC_SLSH,    KC_B,   KC_N,    KC_M,  KC_BSLS,  KC_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TAB, KC_LOPT, KC_LOWER, KC_SPC,  KC_LCMD ,     KC_BSPC, KC_ENT , KC_RAISE, KC_ROPT, KC_RCTL
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * ENGRAMMER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GRV  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   \  |   B  |   Y  |   O  |   U  |   '  |                    |   ;  |   L  |   D  |   W  |   V  |  Z   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   C  |   I  |   E  |   A  |   ,  |-------.    ,-------|   .  |   H  |   T  |   S  |   N  |  Q   |
 * |------+------+------+------+------+------| MUTE  |    |PAUSE  |------+------+------+------+------+------|
 * | SHFT |   G  |   X  |   J  |   K  |   -  |-------|    |-------|   /  |   R  |   M  |   F  |   V  |RShift|
 * `-----------------------------------------/       /    \      \-----------------------------------------'
 *            | TAB  | L_ALT|LOWER | SPACE| / L_CMD /      \ BKSP \ | ENTER|RAISE | ALTGR | RCTR |
 *            |      |      |      |      |/       /        \      \|      |      |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ENGRAMMER] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,   KC_5,             LT(_SWITCH,KC_6),   KC_7,   KC_8,    KC_9,    KC_0,    KC_EQL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_BSLS  ,KC_B,   KC_Y,     KC_O,    KC_U,   KC_QUOT,                    KC_SCLN,   KC_L,   KC_D,    KC_W,    KC_V,    KC_Z ,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_CAPS,  KC_C,   KC_I,    KC_E,    KC_A,   KC_COMM,                     KC_DOT,    KC_H,   KC_T,    KC_S,    KC_N,    KC_Q,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_G,   KC_X,    KC_J,    KC_K,   KC_MINS,  KC_MUTE,  KC_MPLY, KC_SLSH,    KC_R,   KC_M,    KC_F,   KC_P,   KC_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TAB, KC_LOPT, KC_LOWER, KC_SPC,  KC_LCMD ,     KC_BSPC, KC_ENT , KC_RAISE, KC_ROPT, KC_RCTL
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|  NO  |  NO  |  NO  |  @   |  (   |                    |   )  |   "  |  NO  |  NO  |  NO  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|  NO  |   NO |  NO  |   \  |   {  |-------.    ,-------|   }  |   /  |  NO  | NO   |  NO  |trans |
 * |------+------+------+------+------+------|  MUTE |    | PAUSE |------+------+------+------+------+------|
 * | trans | NO  |  NO  | NO   |  #   |   [  |-------|    |-------|   ]  |   %  |  NO  |  NO  |  NO  | trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |trans | trans| trans| trans| / trans /       \ trans\  |DEL   | trans| trans | trans|
 *            |      |      |      |      |/       /         \      \ |      |      |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                        KC_F6,    KC_F7,    KC_F8,  KC_F9, KC_F10, KC_F11 ,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_AT, KC_LPRN,                   KC_RPRN, KC_DQT ,  XXXXXXX,  XXXXXXX,    XXXXXXX,   KC_F12,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_LCBR,                   KC_RCBR, KC_SLSH , XXXXXXX,  XXXXXXX,   XXXXXXX,   _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_HASH, KC_LBRC,_______,    _______,KC_RBRC, KC_PERC, XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, KC_DEL, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo | Redo | Cut  | Copy | Paste|-------|    |-------|      | LStr |      | LEnd |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, _______ , _______,  _______ , _______ , _______,               _______,  _______  , _______,  _______, _______ ,_______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX,                    XXXXXXX, ROPT(KC_LEFT), KC_UP, ROPT(KC_RIGHT), XXXXXXX, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                  XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______,LCMD(KC_Z),RSFT(LCMD(KC_Z)),LCMD(KC_X),LCMD(KC_C),LCMD(KC_V),_______,    _______,XXXXXXX, RCMD(KC_LEFT),XXXXXXX, RCMD(KC_RIGHT), XXXXXXX, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |UG_TOGG|hue^ |sat ^ | bri ^|      |      |-------.    ,-------|      | PREV | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn| ENGR |QWERTY|-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \ |      |      |      |      |
 *            |      |      |      |      |/       /         \      \|      |      |      |      |
 *            `----------------------------------'            '----------------------------------'
 */
  [_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  QK_BOOT, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  UG_TOGG, UG_HUEU,UG_SATU, UG_VALU, XXXXXXX,XXXXXXX,                     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  UG_NEXT, UG_HUED,UG_SATD, UG_VALD, KC_ENGRAMMER,KC_QWERTY,_______,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | TRANS|  0   | .    |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
              _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  _______, KC_P0,   KC_PDOT
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |KB_RBT| qwer | ENGR |      |      | Lock |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |DEF(Q)|DEF(E)|      |      |      |                    |numpad| low  | raise| adj  |      |QK_BOOT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EE_CLR|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  QK_RBT, KC_QWERTY, KC_ENGRAMMER, XXXXXXX, XXXXXXX, LCTL(LCMD(KC_Q)),             XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, TO(_QWERTY),TO(_ENGRAMMER), XXXXXXX, XXXXXXX, XXXXXXX,         TO(_NUMPAD),TO(_LOWER),TO(_RAISE), TO(_ADJUST), XXXXXXX, QK_BOOT,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_SYSTEM_SLEEP,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/

	),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_QWERTY),
  SET_THUMB_CLUSTER(HSV_QWERTY)

);

//ENGRAMMER
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_engrammer_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_ENGRAMMER),
  SET_THUMB_CLUSTER(HSV_ENGRAMMER)

);

// _LOWER,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_lower_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_LOWER)

);
// _RAISE,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_raise_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	//SET_LAYER_ID(HSV_BLUE)
    SET_LAYER_ID(HSV_RAISE)
    );
// _ADJUST,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_adjust_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_ADJUST)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_NUMPAD),
    SET_UNDERGLOW(HSV_NUMPAD),
	SET_NUMPAD(HSV_BLUE)
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	//SET_LAYER_ID(HSV_GREEN),
	SET_LAYER_ID(HSV_YELLOW),
	{LEFT_ZERO+12, 2, HSV_QWERTY},
	{LEFT_ZERO+20, 2, HSV_ENGRAMMER},
	{RIGHT_ZERO+33, 1, HSV_NUMPAD},
	{RIGHT_ZERO+30, 1, HSV_LOWER},
	{RIGHT_ZERO+23, 1, HSV_RAISE},
	{RIGHT_ZERO+20, 1, HSV_ADJUST}
);

//There must be a layer of RGB defined for each layer, otherwise layer switching crashes.
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_engrammer_lights,
	layer_lower_lights,
	layer_raise_lights,
    layer_adjust_lights,
	layer_numpad_lights,
	layer_switcher_lights  // Overrides other layers

);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
   	rgblight_set_layer_state(1, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_ENGRAMMER));

	rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(5, layer_state_cmp(state, _NUMPAD));
	rgblight_set_layer_state(6, layer_state_cmp(state, _SWITCH));

    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
//    static const char PROGMEM qmk_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//    };
//
//    oled_write_P(qmk_logo, false);

    static const char PROGMEM persimmon_logo[] = {
        0,  0,  0,  0,  0,  0,192,192,176,176, 12, 12, 12,130,194, 98, 98, 34,  2,  2,  6,  4, 12,  8, 16, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24, 28,238,183,  3,  3,  3,131,198,124,  0,128,128,128,128,128,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0, 48, 96, 48,  0,  0,  0,128,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,240, 16,254, 35, 32,225, 63,112, 64,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7,248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,127, 15,  3,  1,  1,  1,  0,120,255,145,153,  8, 12,133,199, 70,  0,131,254, 15,  3,  1,  1,  3,  6, 96,198,135,  9,  9,153,243, 98,  0,128,249, 15,  0,128,240, 62,  7,  3, 14, 24,  6,  3, 63,192,  0,128,240, 62,  7,  3, 14, 24,  6,  3,127,192,  0, 56,254,131,  1,  1,  1,129,195,126, 24,  0,195,126,  6,  3,  1,  1,  3,142,252,  0,  0,  0,  0,  0,
        0,  0,  0,  1,  1, 63,227,193, 51, 62,  6,  4,  5,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 96, 56, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0, 48,120,205,133,133,133,132,140, 28, 25, 49,  0,  0,  1,128,192, 64, 64, 64,192,128,  0,  0,  1,128,193,  0,  0,  0,  0,128,192,  0,  0,128,  1,  0,192,120, 29,  5, 13, 13,153,128, 64,240,124, 29,  0,  0,  0,128,192,192, 65, 64,192,128,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  7,  7, 24, 16, 32, 32, 32, 32, 32, 32, 32, 48, 24,  8, 12,  6,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8, 48, 48, 96, 64, 64, 64, 64, 97, 51, 62, 28,  0,  0, 63, 99, 64, 64, 64, 64, 48, 31,  7,  0, 12, 63, 97, 96, 96, 32, 48,127, 99, 64, 64,  1,  3,122, 63,  2,  2,  3,  1,  1,  1, 56,127, 67, 96, 96, 48, 16, 28, 63,104, 76, 68, 70, 98, 51, 17,  0,  0,
    };

    oled_write_raw_P(persimmon_logo, sizeof(persimmon_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Persimmon\n"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _ENGRAMMER:
            oled_write_ln_P(PSTR("ENGR"), false); //Only 4 characters or the line overruns and text positioning gets weird
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwrt\n"), false);
            break;
        case _ENGRAMMER:
            oled_write_P(PSTR("ENGR\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    else{
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                //layer_move(_QWERTY);
            }
            return false;
        case KC_ENGRAMMER:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ENGRAMMER);
                //layer_move(_ENGRAMMER);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {
			case _RAISE:
			case _LOWER:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_LEFT);
					} else {
						tap_code(KC_RIGHT);
					}
				break;
		}
    }
    return true;
}

#endif
