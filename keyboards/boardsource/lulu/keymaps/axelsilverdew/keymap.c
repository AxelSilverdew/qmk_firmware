// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK,
    _NAV,
    _NUMPAD,
    _MEDIA,
    _SYMBOLS,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  =   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |M/ESC |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------| HYPER |    | DEL   |------+------+------+------+------+------|
 * |(Shift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |Shift)|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | MO3  |Space | /BSPC   /       \BSPC4 \  |ENTER |MO2   | RSUP |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_EQUAL,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCOLON,    KC_BSLASH,
  MT(MOD_LGUI, KC_ESCAPE), KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOTE,
  KC_LSPO,  MT(MOD_LCTL, KC_Z),   KC_X,    KC_C,    KC_D,    KC_V, KC_HYPR,  KC_DELETE,  KC_K,    KC_H,    KC_COMM, KC_DOT,  MT(MOD_RCTL, KC_SLASH),  KC_RSPC,
                          KC_LALT,    MO(_MEDIA), KC_SPC, KC_BSPC,  LT(_SYMBOLS, KC_BSPC),   LT(_NAV, KC_ENTER),   MO(_NUMPAD), KC_RALT
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |                    |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |                    | REDO |  PST  | COPY | CUT  | UNDO |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |-------.    ,-------|  TR  | LEFT | DOWN |  UP  |RIGHT |  TR  |
 * |------+------+------+------+------+------|  TR   |    |  TR   |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |-------|    |-------|  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   TR   | TR   | TR | /  TR   /       \ TR   \  |  TR  |  TR  |  TR  |
 *                   |        |      |    |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NAV] = LAYOUT(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                   LCTL(LSFT(KC_Z)), KC_PASTE, KC_COPY, KC_CUT, KC_UNDO, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                   KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, KC_INSERT, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, KC_TRANSPARENT,
                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  TR  |  K7  |  K8  |  K9  |  /   |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |                    |  TR  |  K4  |  K5  |  K6  |  *   |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |-------.    ,-------|  TR  |  K1  |  K2  |  K3  |  +   |  TR  |
 * |------+------+------+------+------+------|  TR   |    |  TR   |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |-------|    |-------|  TR  |  K0  |  .   |  TR  |  -   |  TR  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   TR   | TR   | TR | /  TR   /       \ TR   \  |  TR  |  TR  |  TR  |
 *                   |        |      |    |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NUMPAD] = LAYOUT(
  KC_F1, KC_F2, KC_F3, F4, KC_F5, KC_F6,                                                                                            KC_PSCREEN, KC_KP_7, KC_KP_8, KC_KP_9, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                                                                                      KC_TRANSPARENT, KC_KP_4, KC_KP_5, KC_KP_6, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_KP_1, KC_KP_2, KC_KP_3, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_0, KC_DOT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
/* MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |                    |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  B+  |                    |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  B-  |-------.    ,-------|  TR  | MEDB | VOL- | VOL+ | MEDF |  TR  |
 * |------+------+------+------+------+------|  TR   |    |  TR   |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |-------|    |-------|  TR  | MUTE |  TR  |  TR  |  TR  |  TR  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   TR   | TR   | TR | /  TR   /       \ TR   \  |  TR  |  TR  |  TR  |
 *                   |        |      |    |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_MEDIA] = LAYOUT(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_UP,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,                                 KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |                    |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |                    |  TR  |  TR  |  TR  |  TR  |  TR  |  TR  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TR  |  TR  |  {   |  [   |  (   |  TR  |-------.    ,-------|  TR  |   )  |  ]   |  }   |  TR  |  TR  |
 * |------+------+------+------+------+------|  TR   |    |  TR   |------+------+------+------+------+------|
 * |  TR  |  TR  |  TR  |  TR  |  TR  |  `   |-------|    |-------|  |   |  TR  |  TR  |  TR  |  TR  |  TR  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   TR   | TR   | TR | /  TR   /       \ TR   \  |  TR  |  TR  |  TR  |
 *                   |        |      |    |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_SYMBOLS] = LAYOUT(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR, KC_LBRACKET, KC_LPRN, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RPRN, KC_RBRACKET, KC_RCBR, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE, KC_TRANSPARENT, KC_TRANSPARENT, KC_PIPE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  )
};
