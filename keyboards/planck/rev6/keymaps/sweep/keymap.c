#include "keycodes.h"
#include QMK_KEYBOARD_H

enum planck_layers { _QWERTY, _GALLIUM, _SYM, _EXT, _ADJUST, _SETTINGS };

enum planck_keycodes { TOGG_LO = SAFE_RANGE, VIM_SAVE };

#define SYM MO(_SYM)
#define EXT LT(_EXT, KC_ESC)
#define SETT MO(_SETTINGS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *   Gui    Alt    Ctl    Sft
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  ||     |     ||   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  ||     |     ||   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  ||     |     ||   N  |   M  |   ,  |   .  |   ;  |
 * |======+======+======+======+======+======+======+======+======+======+======+======|
 * |Settin|      |      |     || Shift|Symbol| Ext  | Space||     |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                            ^Esc (tap)
 */

#define MOD_A LGUI_T(KC_A)
#define MOD_S LALT_T(KC_S)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)
#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L RALT_T(KC_L)
#define MOD_QUOT RGUI_T(KC_QUOT)

    [_QWERTY] = LAYOUT_planck_grid(
        KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX, XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P,
        MOD_A, MOD_S, MOD_D, MOD_F, KC_G, XXXXXXX, XXXXXXX, KC_H, MOD_J, MOD_K, MOD_L, MOD_QUOT,
        KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SCLN,
        SETT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, SYM, EXT, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

/* Gallium
 *   Gui    Alt    Ctl    Sft            (homerow)            Gui   Alt     Ctl    Sft
 * ,----------------------------------------------------------------------------------.
 * |   B  |   L  |   D  |   C  |   V  ||     |     ||   J  |   Y  |   O  |   U  |   ,  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   N  |   R  |   T  |   S  |   G  ||     |     ||   P  |   H  |   A  |   E  |   I  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   X  |   Q  |   M  |   W  |   Z  ||     |     ||   K  |   F  |  '   |   ;  |   .  |
 * |======+======+======+======+======+======+======+======+======+======+======+======|
 * |SETTIN|      |      |     || Shift|Symbol| Ext  | Space||     |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                            ^Esc (tap)
 */

#define MOD_N LGUI_T(KC_N)
#define MOD_R LALT_T(KC_R)
#define MOD_T LCTL_T(KC_T)
#define MOD_SS LSFT_T(KC_S)
#define MOD_H RSFT_T(KC_H)
#define MOD_AA RCTL_T(KC_A)
#define MOD_E RALT_T(KC_E)
#define MOD_I RGUI_T(KC_I)

    [_GALLIUM] = LAYOUT_planck_grid(
        KC_B, KC_L, KC_D, KC_C, KC_V, XXXXXXX, XXXXXXX, KC_J, KC_Y, KC_O, KC_U, KC_COMM,
        MOD_N, MOD_R, MOD_T, MOD_SS, KC_G, XXXXXXX, XXXXXXX, KC_P, MOD_H, MOD_AA, MOD_E, MOD_I,
        KC_X, KC_Q, KC_M, KC_W, KC_Z, XXXXXXX, XXXXXXX, KC_K, KC_F, KC_QUOT, KC_SCLN, KC_DOT,
        SETT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, SYM, EXT, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/* Symbol
 *   Gui    Alt    Ctl    Sft            (homerow)            Gui   Alt     Ctl    Sft
 * ,-----------------------------------------------------------------------------------.
 * |  *   |  -   |   <  |  >   |  |   ||     |     ||  ^   |  {   |  }   |  $   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  !   |  _   |  /   |[ =  ]|  &   ||     |     ||  #   |[ (  ]|  )   |  ?   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ~   |  +   |  [   |  ]   |  %   ||     |     ||  @   |  `   |  \   |      |  Del |
 * |======+======+======+======+======+======+======+======+======+======+======+======|
 * |      |      |      |     ||      |<HOLD>|      | Enter||     |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

#define MOD_EXLM LGUI_T(KC_EXLM)
#define MOD_UNS LALT_T(KC_UNDS)
#define MOD_SLS LCTL_T(KC_SLSH)
#define MOD_EQL LSFT_T(KC_EQL)
#define MOD_LPN RSFT_T(KC_LPRN)
#define MOD_RPN RCTL_T(KC_RPRN)
#define MOD_QUES RALT_T(KC_QUES)
#define MOD_ENT RGUI_T(KC_ENT)

    [_SYM] = LAYOUT_planck_grid(
        KC_ASTR, KC_MINS, KC_LT, KC_GT, KC_PIPE, _______, _______, KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR, KC_BSPC,
        MOD_EXLM, MOD_UNS, MOD_SLS, MOD_EQL, KC_AMPR, _______, _______, KC_HASH, MOD_LPN, MOD_RPN, MOD_QUES, MOD_ENT,
        KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC, _______, _______, KC_AT, KC_GRV, KC_BSLS, XXXXXXX, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, KC_ENT, _______, _______, _______, _______
    ),

/* Ext
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |  7   |  8   |  9   |Vim Sv||     |     || Pgu  | PgD  | Home | End  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc |  4   |  5   |[ 6  ]|  0   ||     |     ||  <-  |  V   |  ^   | ->   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |      ||     |     || PrSc |[Shif]| Ctrl |  Al  | Gui  |
 * |======+======+======+======+======+------+------+======+======+======+======+======|
 * |      |      |      |     ||BkSp  |      |<HOLD>|      ||     |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
#define MOD_ESC LGUI_T(KC_ESC)
#define MOD_4 LALT_T(KC_4)
#define MOD_5 LCTL_T(KC_5)
#define MOD_6 LSFT_T(KC_6)

    [_EXT] = LAYOUT_planck_grid(
        KC_TAB, KC_7, KC_8, KC_9, VIM_SAVE, _______, _______, KC_PSCR, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        MOD_ESC, MOD_4, MOD_5, MOD_6, KC_0, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX,
        XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, _______, _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_INS,
        _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______, _______, _______
    ),

/* Adjust
* ,-----------------------------------------------------------------------------------.
* | CapT |ToggLO|      |PrtSc |      ||     |     || F1   | F2   | F3   | F4   | Ctrl |
* |------+------+------+------+------+------+------+------+------+------|------|------|
* | M<-  | Mv   | M^   | M->  |      ||     |     || F5   |[F6  ]| F7   | F8   | Alt  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |Reset |Debug | ML   | MR   ||     |     || F9   | F10  | F11  | F12  | Gui  |
* |======+======+======+======+======+------+------+======+======+======+======+======|
* |      |      |      |      |      |<HOLD>|<HOLD>|      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/

    [_ADJUST] = LAYOUT_planck_grid(
        CW_TOGG, TOGG_LO, XXXXXXX, KC_PSCR, XXXXXXX, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, OS_RCTL,
        MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX, _______, _______, KC_F5, KC_F6, KC_F7, KC_F8, OS_RALT,
        XXXXXXX, QK_BOOT, DB_TOGG, MS_BTN1, MS_BTN2, _______, _______, KC_F9, KC_F10, KC_F11, KC_F12, OS_RGUI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* Settings
* ,-----------------------------------------------------------------------------------.
* |RGB   |RGBMOD|      |DT_U  |      ||     |     ||      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------|------|------|
* |BRGTH+| SAT+ | HUE+ |DT_D  |      ||     |     ||      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |BRGTH-| SAT- | HUE- |DT_Prn|      ||     |     ||      |      |      |      |      |
* |======+======+======+======+======+------+------+======+======+======+======+======|
* |<HOLD>|      |      |      |      |      |      |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/

    [_SETTINGS] = LAYOUT_planck_grid(
        UG_TOGG, UG_NEXT, XXXXXXX, DT_UP, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        UG_VALU, UG_SATU, UG_HUEU, DT_DOWN, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        UG_VALD, UG_SATD, UG_HUED, DT_PRNT, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
