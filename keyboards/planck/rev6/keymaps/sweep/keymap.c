#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _SYM,
  _EXT,
  _ADJUST
};

enum planck_keycodes {
  BACKLIT,
};

const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
  COMBO(we_combo, KC_ESC),
  COMBO(io_combo, KC_BACKSPACE)
};

#define SYM MO(_SYM)
#define EXT MO(_EXT)

#define MOD_A LGUI_T(KC_A)
#define MOD_S LALT_T(KC_S)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)
#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L RALT_T(KC_L)
#define MOD_SC RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *   Gui    Alt    Ctl    Sft
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+----------------+------+------+------+----
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+---------+------+------+------+------+----
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Symbol|Shift |Space |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
       KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,  XXXXXXX, XXXXXXX,   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,
      MOD_A,   MOD_S,   MOD_D, MOD_F,    KC_G,  XXXXXXX, XXXXXXX,   KC_H, MOD_J,   MOD_K,   MOD_L,  MOD_SC,
       KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,  XXXXXXX, XXXXXXX,   KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,
    XXXXXXX, XXXXXXX, XXXXXXX,   SYM, KC_LSFT,  XXXXXXX, XXXXXXX, KC_SPC, EXT, XXXXXXX, XXXXXXX,  XXXXXXX
),

#define MOD_TAB LGUI_T(KC_TAB)
#define MOD_UNS LALT_T(KC_UNDS)
#define MOD_SLS LCTL_T(KC_SLSH)
#define MOD_EQL LSFT_T(KC_EQL)
#define MOD_LPN RSFT_T(KC_LPRN)
#define MOD_RPN RCTL_T(KC_RPRN)
#define MOD_DQU RALT_T(KC_DQUO)
#define MOD_ENT RGUI_T(KC_ENT)

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |  `   |  <   |  >   |  -   |  |   |      |      |  ^   |  {   |  }   |  $   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  _   |  /   |   =  |  &   |      |      |  #   |  (   |  )   |   "  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ~   |  +   |  [   |  ]   |  %   |      |      |  @   | (???)|  \   |  '   |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_GRV, KC_LT, KC_GT, KC_MINS, KC_PIPE,  _______, _______, KC_CIRC,  KC_LCBR, KC_RCBR, KC_DLR, KC_BSPC,
    MOD_TAB, MOD_UNS, MOD_SLS, MOD_EQL, KC_AMPR, _______, _______, KC_HASH,    MOD_LPN,   MOD_RPN, MOD_DQU, MOD_ENT,
    KC_TILD, KC_PLUS,   KC_LBRC,   KC_RBRC,   KC_PERC,  _______,  _______,  KC_AT, _______, KC_BSLS, KC_QUOT,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  7   |  8   |  9   |      |      |      | PrSc |Shift | Ctrl |  Al  | Gui  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  4   |  5   |  6   |      |      |      |      | <-   |  V   |  ^   | ->   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  0   |      |      | Pgu  | PgD  | Home | End  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXT] = LAYOUT_planck_grid(
    _______, KC_7, KC_8, KC_9, _______, _______, _______, KC_PSCR, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    _______, KC_4, KC_5, KC_6, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    _______, KC_1, KC_2, KC_3, KC_0, _______, _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_INS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Debug | RGB  |RGBMOD|      |      |      | F1   | F2   | F3   | F4   |      |
 * |------+------+------+------+------+------+------+------+------+------|------|------|
 * |BRGTH+| SAT+ | HUE+ |DT_UP |      |      |      | F5   | F6   | F7   | F8   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BRGTH-| SAT- | HUE- |DT_DN |      |      |      | F9   | F10  | F11  | F12  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |DT_Prn|      |      |      |      |Sft   | Ctrl | Alt  | Gui  | (Oneshot mods)
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, _______,
    UG_VALU, UG_SATU, UG_HUEU, DT_UP, _______, _______, _______, KC_F5, KC_F6, KC_F7, KC_F8, _______,
    UG_VALD, UG_SATD, UG_HUED, DT_DOWN,   _______,  _______, _______, KC_F9,  KC_F10, KC_F11, KC_F12,  _______,
    _______, _______, _______, DT_PRNT, _______, _______, _______, _______, OS_RSFT, OS_RCTL, OS_RALT, OS_RGUI
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _EXT, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          gpio_write_pin_low(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          gpio_write_pin_high(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}
