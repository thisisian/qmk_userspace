#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "bit-c_led.h"

void matrix_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

enum layers { _QWERTY, _GALLIUM, _SYM, _EXT, _ADJUST, _MOUSE };

enum keycodes { TOGG_LO = SAFE_RANGE, VIM_SAVE };

#define SYM MO(_SYM)
#define EXT LT(_EXT, KC_ESC)
#define MOUSE TG(_MOUSE)
#define SETT MO(_SETTINGS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------.             ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   '  |
 * |(Gui) |(Alt) |(Ctl) |(Shft)|      |             |      |(Shft)|(Ctl) |(Alt) |(Gui) |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   ;  |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *                      |Symbol|Shift |             |Space |  Ext |
 *                      `-------------'             `-------------'
 *                                                          ^Esc (tap)
 */

#define MOD_A LGUI_T(KC_A)
#define MOD_S LALT_T(KC_S)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)
#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L RALT_T(KC_L)
#define MOD_QUOT RGUI_T(KC_QUOT)

    [_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P,
        MOD_A, MOD_S, MOD_D, MOD_F, KC_G,                   KC_H, MOD_J, MOD_K, MOD_L, MOD_QUOT,
        KC_Z, KC_X, KC_C, KC_V, KC_B,                   KC_N, KC_M, KC_COMM, KC_DOT, KC_SCLN,
                                         SYM, KC_LSFT, KC_SPC,  EXT),

/* Gallium
 * ,----------------------------------.             ,----------------------------------.
 * |   B  |   L  |   D  |   C  |   V  |             |   J  |   Y  |   O  |   U  |   ,  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   N  |   R  |   T  |   S  |   G  |             |   P  |   H  |   A  |   E  |   I  |
 * |(Gui) |(Alt) |(Ctl) |(Shft)|      |             |      |(Shft)|(Ctl) |(Alt) |(Gui) |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |   X  |   Q  |   M  |   W  |   Z  |             |   K  |   F  |  '   |   ;  |   .  |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *                      |Symbol|Shift |             |Space |  Ext |
 *                      `-------------'             `-------------'
 *                                                            ^Esc (tap)
 */

#define MOD_N LGUI_T(KC_N)
#define MOD_R LALT_T(KC_R)
#define MOD_T LCTL_T(KC_T)
#define MOD_SS LSFT_T(KC_S)
#define MOD_H RSFT_T(KC_H)
#define MOD_AA RCTL_T(KC_A)
#define MOD_E RALT_T(KC_E)
#define MOD_I RGUI_T(KC_I)

    [_GALLIUM] = LAYOUT(
        KC_B, KC_L, KC_D, KC_C, KC_V,                   KC_J, KC_Y, KC_O, KC_U, KC_COMM,
        MOD_N, MOD_R, MOD_T, MOD_SS, KC_G,                   KC_P, MOD_H, MOD_AA, MOD_E, MOD_I,
        KC_X, KC_Q, KC_M, KC_W, KC_Z,                   KC_K, KC_F, KC_QUOT, KC_SCLN, KC_DOT,
                                         SYM, KC_LSFT, KC_SPC, EXT
    ),

/* Symbol
 * ,----------------------------------.             ,----------------------------------.
 * |  *   |  -   |   <  |  >   |  |   |             |  ^   |  {   |  }   |  $   | Del  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  !   |  _   |  /   |  =   |  &   |             |  #   |  (   |  )   |  ?   |      |
 * |(Gui) |(Alt) |(Ctl) |(Shft)|      |             |      |(Shft)|(Ctl) |(Alt) |(Gui) |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  ~   |  +   |  [   |  ]   |  %   |             |  @   |  `   |  \   |      |      |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *                      |<HOLD>|      |             |Enter |      |
 *                      `-------------'             `-------------'
 */

#define MOD_EXLM LGUI_T(KC_EXLM)
#define MOD_UNS LALT_T(KC_UNDS)
#define MOD_SLS LCTL_T(KC_SLSH)
#define MOD_EQL LSFT_T(KC_EQL)
#define MOD_LPN RSFT_T(KC_LPRN)
#define MOD_RPN RCTL_T(KC_RPRN)
#define MOD_QUES RALT_T(KC_QUES)
#define MOD_ENT RGUI_T(KC_ENT)

    [_SYM] = LAYOUT(
        KC_ASTR, KC_MINS, KC_LT, KC_GT, KC_PIPE,                   KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR, KC_DEL,
        MOD_EXLM, MOD_UNS, MOD_SLS, MOD_EQL, KC_AMPR,                   KC_HASH, MOD_LPN, MOD_RPN, MOD_QUES, XXXXXXX,
        KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                   KC_AT, KC_GRV, KC_BSLS, XXXXXXX, XXXXXXX,
                                            _______, _______, KC_ENT, _______
    ),

/* Ext
 * ,----------------------------------.             ,----------------------------------.
 * |  Tab |  7   |  8   |  9   |Vim Sv|             | End  | PgD  | PgU  | Home | Ins  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |  4   |  5   |  6   |  0   |             |  <-  |  V   |  ^   | ->   |      |
 * |(Gui) |(Alt) |(Ctl) |(Shft)|      |             |      |      |      |      |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |  1   |  2   |  3   |      |             | Mouse| Shft | Ctrl |  Al  | Gui  |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *                      |      |BkSp  |             |      |<Hold>|
 *                      `-------------'             `-------------'
 */
#define MOD_ESC LGUI_T(KC_ESC)
#define MOD_4 LALT_T(KC_4)
#define MOD_5 LCTL_T(KC_5)
#define MOD_6 LSFT_T(KC_6)

    [_EXT] = LAYOUT(
        KC_TAB, KC_7, KC_8, KC_9, VIM_SAVE,                   KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_INS,
        KC_LGUI, MOD_4, MOD_5, MOD_6, KC_0,                   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX,
        XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX,                   MOUSE, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
                                            _______, KC_BSPC, _______, _______
    ),


/* Adjust
 * ,----------------------------------.             ,----------------------------------.
 * |      | F7   | F8   | F9   | F10  |             |PrtSc | CapT |      |      |      |
 * |------+------+------+------+------+             +------+------+------|------|------|
 * |      | F4   | F5   | F6   | F11  |             |      | Shft | Ctl  | Alt  | Gui  |
 * |(Gui) |(Alt) |(Ctl) |(Shft)|      |             |      |      |      |      |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      | F1   | F2   | F3   | F12  |             |      |      |ToggLO|Debug |Reset |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *                      |<Hold>|      |             |      |<Hold>|
 *                      `-------------'             `-------------'
 */

#define MOD_F4 LALT_T(KC_F4)
#define MOD_F5 LCTL_T(KC_F5)
#define MOD_F6 LSFT_T(KC_F6)

    [_ADJUST] = LAYOUT(
        XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10,                   KC_PSCR, CW_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI, MOD_F4, MOD_F5, MOD_F6, KC_F11,                   XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12,                   XXXXXXX, XXXXXXX, TOGG_LO, DB_TOGG, QK_BOOT,
                          _______, _______,                   _______, _______
    ),

/* Mouse
 * ,----------------------------------.             ,----------------------------------.
 * |      |      |      |      |      |             |MsWLft|MsWDwn|MsWUp |MsWRit|      |
 * |------+------+------+------+------+             +------+------+------|------|------|
 * | Gui  | Alt  | Ctl  | Shft |      |             |MsLeft|MsDown|MsUp  |MsRght|      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      |      |      |             |Mouse |MsAcc1|MsAcc2|MsAcc3|      |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *                      |Mouse |Mouse |             | Ms1  | Ms2  |
 *                      `-------------'             `-------------'
 */

    [_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   MOUSE, MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX,
                                            MOUSE, MOUSE, MS_BTN1, MS_BTN2
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _EXT, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // fixes for tap-mod with shifted keys
        case MOD_EXLM:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EXLM);
                return false;
            }
            break;
        case MOD_UNS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case MOD_LPN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case MOD_RPN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case MOD_QUES:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUES);
                return false;
            }
            break;
        case VIM_SAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) ":w" SS_TAP(X_ENTER));
                return false;
            }
            break;
        case TOGG_LO:
            if (record->event.pressed) {
                uint8_t current = get_highest_layer(default_layer_state);
                if (current == _QWERTY) {
                    set_single_persistent_default_layer(_GALLIUM);
                } else {
                    set_single_persistent_default_layer(_QWERTY);
                }
            }
            return false;
            break;
    }
    return true;
}
