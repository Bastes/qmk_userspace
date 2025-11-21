// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0, // default layer
  _SYMBOLS,    // symbols
  _MEDIA,      // media keys
  _FRENCH,     // fucking french accented chars
  _FPS,        // fps-oriented layout
  _ARROWS,     // arrow layer
  _NUMBERS     // layer for manipulating numbers
};

// Aliases for readability
#define F_SYMS  LT(_SYMBOLS, KC_F)
#define J_SYMS  LT(_SYMBOLS, KC_J)
#define MEDIA   TT(_MEDIA)
#define G_FR    LT(_FRENCH, KC_G)
#define H_FR    LT(_FRENCH, KC_H)
#define ARROWS  TT(_ARROWS)
#define NUMBERS TT(_NUMBERS)
#define FPS     TT(_FPS)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define KC_LS KC_LSFT
#define KC_RS KC_RSFT
#define KC_C_UP LCTL(KC_UP)
#define NBSPC UC(NBSP)
#define ZWSPC UC(ZWSP)
#define UC_DEG UC(DEGREE)
#define UP_AC UP(ACIRCL, ACIRCU)
#define UP_AE UP(AELIGL, AELIGU)
#define UP_AG UP(AGRAVL, AGRAVU)
#define UP_AU UP(AUMLL, AUMLU)
#define UP_CC UP(CCEDL, CCEDU)
#define UP_EA UP(EACUTEL, EACUTEU)
#define UP_EC UP(ECIRCL, ECIRCU)
#define UP_EG UP(EGRAVL, EGRAVU)
#define UC_ELI UC(ELLIPS)
#define UP_EU UP(EUMLL, EUMLU)
#define UC_EUR UC(EURO)
#define UP_IC UP(ICIRCL, ICIRCU)
#define UP_IU UP(IUMLL, IUMLU)
#define UP_NT UP(NTLDL, NTLDU)
#define UP_OC UP(OCIRCL,OCIRCU)
#define UP_OE UP(OELIGL,OELIGU)
#define UP_OU UP(OUMLL, OUMLU)
#define UP_UC UP(UCIRCL, UCIRCU)
#define UP_UG UP(UGRAVL, UGRAVU)
#define UP_UU UP(UUMLL, UUMLU)
#define SNTAB LCTL(KC_PGDN)
#define SPTAB LCTL(KC_PGUP)
#define A_LSH LSFT_T(KC_A)
#define S_CTL LCTL_T(KC_S)
#define D_ALT LALT_T(KC_D)
#define K_ALT LALT_T(KC_K)
#define L_CTL RCTL_T(KC_L)
#define SC_RSH RSFT_T(KC_SCLN)

enum unicode_names {
  ACIRCL,
  ACIRCU,
  AELIGL,
  AELIGU,
  AGRAVL,
  AGRAVU,
  AUMLL,
  AUMLU,
  CCEDL,
  CCEDU,
  DEGREE,
  EACUTEL,
  EACUTEU,
  ECIRCL,
  ECIRCU,
  EGRAVL,
  EGRAVU,
  ELLIPS,
  EUMLL,
  EUMLU,
  EURO,
  ICIRCL,
  ICIRCU,
  IUMLL,
  IUMLU,
  NBSP,
  NTLDL,
  NTLDU,
  OCIRCL,
  OCIRCU,
  OELIGL,
  OELIGU,
  OUMLL,
  OUMLU,
  UCIRCL,
  UCIRCU,
  UGRAVL,
  UGRAVU,
  UUMLL,
  UUMLU,
  ZWSP
};

const uint32_t unicode_map[] PROGMEM = {
  [ACIRCL]  = 0x00E2,
  [ACIRCU]  = 0x00C2,
  [AELIGL]  = 0x00E6,
  [AELIGU]  = 0x00C6,
  [AGRAVL]  = 0x00E0,
  [AGRAVU]  = 0x00C0,
  [AUMLL]   = 0x00E4,
  [AUMLU]   = 0x00C4,
  [CCEDL]   = 0x00E7,
  [CCEDU]   = 0x00C7,
  [DEGREE]  = 0x00B0,
  [EACUTEL] = 0x00E9,
  [EACUTEU] = 0x00C9,
  [ECIRCL]  = 0x00EA,
  [ECIRCU]  = 0x00CA,
  [EGRAVL]  = 0x00E8,
  [EGRAVU]  = 0x00C8,
  [ELLIPS]  = 0x2026,
  [EUMLL]   = 0x00EB,
  [EUMLU]   = 0x00CB,
  [EURO]    = 0x20AC,
  [ICIRCL]  = 0x00EE,
  [ICIRCU]  = 0x00CE,
  [IUMLL]   = 0x00EF,
  [IUMLU]   = 0x00CF,
  [NBSP]    = 0x00A0,
  [NTLDL]   = 0x00F1,
  [NTLDU]   = 0x00D1,
  [OCIRCL]  = 0x00F4,
  [OCIRCU]  = 0x00D4,
  [OELIGL]  = 0x0153,
  [OELIGU]  = 0x0152,
  [OUMLL]   = 0x00F6,
  [OUMLU]   = 0x00D6,
  [UCIRCL]  = 0x00FB,
  [UCIRCU]  = 0x00DB,
  [UGRAVL]  = 0x00F9,
  [UGRAVU]  = 0x00D9,
  [UUMLL]   = 0x00FC,
  [UUMLU]   = 0x00DC,
  [ZWSP]    = 0x200B
};

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * 0 - QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Tab  |  Q   |  W   |  E   |  R   |  T   |                              |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    [   | A/LSh| S/Ctl| D/Alt| F/Sym| G/Acc|                              | H/Acc| J/Sym| K/Alt| L/Ctl|;:/RSh|  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    ]   |  Z   |  X   |  C   |  V   |  B   |  Esc |  Del |  | *Sym | CLck |   N  |   M  | ,  < | . >  | /  ? |    :   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | *L5  |  OS  | Space|BckSpc|  |  *L4 | Enter|  OS  | *L2  | Mute |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_QWERTY] = LAYOUT_split_3x6_5_hlc(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
      KC_LBRC,   A_LSH,   S_CTL,   D_ALT,  F_SYMS,    G_FR,                                        H_FR,  J_SYMS,   K_ALT,   L_CTL,  SC_RSH, KC_QUOT,
      KC_RBRC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,  KC_DEL, NUMBERS, KC_CAPS,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_COLN,
                                 _______,     FPS, KC_LGUI,  KC_SPC, KC_BSPC,  ARROWS,  KC_ENT, KC_LGUI,   MEDIA, KC_MUTE,
      KC_MUTE, _______, _______, _______, _______,                                                       KC_MUTE, _______, _______, _______, _______
    ),
/*
 * 1 - Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | PrtScr |   !  |   @  |   {  |   }  |   |  |                              |   &  |   7  |   8  |   9  |   *  | NumLck |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  ZwSpc |   #  |   $  |   (  |   )  |   `  |                              |   -  |   4  |   5  |   6  |   +  | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  NbSpc |   %  |   ^  |   [  |   ]  |   ~  |      |      |  |      |      |   _  |   1  |   2  |   3  |   =  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYMBOLS] = LAYOUT_split_3x6_5_hlc(
      KC_PSCR, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_PIPE,                                     KC_AMPR,    KC_7,    KC_8,    KC_9, KC_PAST,  KC_NUM,
        ZWSPC, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,                                     KC_MINS,    KC_4,    KC_5,    KC_6, KC_PPLS,  KC_INS,
        NBSPC, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_UNDS,    KC_1,    KC_2,    KC_3,  KC_EQL, _______,
                                 _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______,
      KC_MUTE, _______, _______, _______, _______,                                                       KC_MUTE, _______, _______, _______, _______
    ),
/*
 * 2 - Media & Mouse
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | MsWhL| MsUp |MsWhR |MsWhUp|                              |  F1  |  F2  |  F3  |  F4  |  F5  |   F6   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|MsWhDn|                              |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * |        | LCtl | LAlt |      |      |      |BBack | BFwd |  |      |      |      | Mute |VolDn |VolUp |      |        |
 * `----------------------+------+------+------+------|------|  |------+------+------+------+------+----------------------'
 *                        |      |      | MClk | LClk | RClk |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
     [_MEDIA] = LAYOUT_split_3x6_5_hlc(
       _______, _______, MS_WHLL,   MS_UP, MS_WHLR, MS_WHLU,                                       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                                       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
       _______, KC_LCTL, KC_LALT, _______, _______, _______, KC_WBAK, KC_WFWD, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
                                  _______, _______, MS_BTN3, MS_BTN1, MS_BTN2, _______, _______, _______, _______, _______,
       KC_MUTE, _______, _______, _______, _______,                                                       KC_MUTE, _______, _______, _______, _______
     ),
/*
 * 3 - Fucking french accented chars
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | Æ  æ | Ê  ê | É  é | È  è |   °  |                              | Û  û | Ù  ù | Î  î | Ô  ô | Œ  œ | Switch |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | À  à | Â  â | Ë  ë |    € |      |                              |      | Ü  ü | Ï  ï | Ö  ö |      |        |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * |        | Ä  ä |      | Ç  ç |      |      |      |      |  |      |      | Ñ  ñ |      |      |   …  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | ____ | ____ | _____ | ____ | ____ |                                              | ____ | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
     [_FRENCH] = LAYOUT_split_3x6_5_hlc(
       _______,   UP_AE,   UP_EC,   UP_EA,   UP_EG,  UC_DEG,                                       UP_UC,   UP_UG,   UP_IC,   UP_OC,   UP_OE, UC_NEXT,
       _______,   UP_AG,   UP_AC,   UP_EU,  UC_EUR, _______,                                     _______,   UP_UU,   UP_IU,   UP_OU, _______, _______,
       _______,   UP_AU, _______,   UP_CC, _______, _______, _______, _______, _______, _______,   UP_NT, _______, _______,  UC_ELI, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
     ),
/*
 * 4 - Arrows & Movements
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | Home |   ^  |  End | PgUp |                              | MOD> | Hue+ | Sat+ | Val+ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  <=  |   v  |  =>  | PgDn |                              | <MOD | Hue- | Sat- | Val- |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | <Tab |      | Tab> |      |  Esc |      |  |      |      | LEDs |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | ____ | ____ | _____ | ____ | ____ |                                              | ____ | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
     [_ARROWS] = LAYOUT_split_3x6_5_hlc(
       _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                                     UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, _______, _______,
       _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     UG_PREV, UG_HUED, UG_SATD, UG_VALD, _______, _______,
       _______, _______,   SPTAB, _______,   SNTAB, _______, _______, _______, _______, _______, UG_TOGG, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
     ),
/*
 * 5 - Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |  up  |   7  |   8  |   9  |   *  | NumLck |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |   1  |   2  |   3  |   =  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | ____ | ____ | _____ | ____ | ____ |                                              | ____ | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NUMBERS] = LAYOUT_split_3x6_5_hlc(
      _______, _______, _______, _______, _______, _______,                                       KC_UP,    KC_7,    KC_8,    KC_9, KC_PAST,  KC_NUM,
      _______, _______, _______, _______, _______, _______,                                     KC_DOWN,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3,  KC_EQL, _______,
                                 _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______,
      _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
/*
 * 6 - FPS (classic QWERTY)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CapsLk |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  Esc |  Del |  |      |      |   N  |   M  |  , < |  . > |  / ? | RShift |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 *                        |      |      | Lock | Space|Bckspc|  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | ____ | ____ | _____ | ____ | ____ |                                              | ____ | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
     [_FPS] = LAYOUT_split_3x6_5_hlc(
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
         KC_LS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,  KC_DEL, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RS,
                                  _______, _______, QK_LOCK,  KC_SPC, KC_BSPC, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
     ),
/*
 * Ideas for an emoji layer:
 * :wink:        U+1F609 😉
 * :thumbsup:    U+1F44D 👍
 * :thumbsdown:  U+1F44E 👎
 * :slightsmile: U+1F642 🙂
 */

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code16(KC_BRIGHTNESS_DOWN);
        } else {
            tap_code16(KC_BRIGHTNESS_UP);
        }
    } else if (index == 2) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return false;
}
#endif

// WoW combos
const uint16_t PROGMEM wow_shift_q[] = {KC_Q, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_w[] = {KC_W, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_e[] = {KC_E, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_r[] = {KC_R, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_t[] = {KC_T, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_a[] = {A_LSH, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_s[] = {S_CTL, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_d[] = {D_ALT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_f[] = {F_SYMS, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_g[] = {G_FR, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_z[] = {KC_Z, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_x[] = {KC_X, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_c[] = {KC_C, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_v[] = {KC_V, KC_BSPC, COMBO_END};
const uint16_t PROGMEM wow_shift_b[] = {KC_B, KC_BSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(wow_shift_q, LSFT(KC_Q)),
    COMBO(wow_shift_w, LSFT(KC_W)),
    COMBO(wow_shift_e, LSFT(KC_E)),
    COMBO(wow_shift_r, LSFT(KC_R)),
    COMBO(wow_shift_t, LSFT(KC_T)),
    COMBO(wow_shift_a, LSFT(KC_A)),
    COMBO(wow_shift_s, LSFT(KC_S)),
    COMBO(wow_shift_d, LSFT(KC_D)),
    COMBO(wow_shift_f, LSFT(KC_F)),
    COMBO(wow_shift_g, LSFT(KC_G)),
    COMBO(wow_shift_z, LSFT(KC_Z)),
    COMBO(wow_shift_x, LSFT(KC_X)),
    COMBO(wow_shift_c, LSFT(KC_C)),
    COMBO(wow_shift_v, LSFT(KC_V)),
    COMBO(wow_shift_b, LSFT(KC_B)),
};
