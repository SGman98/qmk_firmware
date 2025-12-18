#include QMK_KEYBOARD_H

enum layer_number {
    _COLEMAK = 0,
    _QWERTY,
    _NUMS,
    _SYMS,
    _NAV,
    _CONFIG
};

const uint16_t MO_SYMS = LT(_SYMS, KC_ENT);
const uint16_t MO_NUMS = LT(_NUMS, KC_ESC);
const uint16_t MO_NAV1 = LT(_NAV, KC_INS);
const uint16_t MO_NAV2 = LT(_NAV, KC_DEL);

const uint16_t TG_QWER = TG(_QWERTY);

enum tap_dance_number {
    _1F1,
    _2F2,
    _3F3,
    _4F4,
    _5F5,
    _6F6,
    _7F7,
    _8F8,
    _9F9,
    _0F0, // F10*
};

tap_dance_action_t tap_dance_actions[] = {
    [_1F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [_2F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [_3F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [_4F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [_5F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [_6F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [_7F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [_8F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [_9F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [_0F0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
};

const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);

const key_override_t *key_overrides[] = {
    &comma_key_override,
    &dot_key_override,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* COLEMAK
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |QWERTY|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |PrtSc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   K  |   L  |   U  |   Y  | ARpt |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |RShift|
     * |------+------+------+------+------+------|  Ins  |    |  Del  |------+------+------+------+------+------|
     * |LCtrl |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   J  |   H  |  ,   |   .  |  Rpt |RCtrl |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |  Esc | /Space  /       \BackSP\  |Enter | RAlt | RGUI |
     *                   |      |      | NUMS |/       /         \      \ | SYMS |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_COLEMAK] = LAYOUT(
        TG_QWER,TD(_1F1),TD(_2F2),TD(_3F3),TD(_4F4),TD(_5F5),                  TD(_6F6),TD(_7F7),TD(_8F8),TD(_9F9),TD(_0F0), KC_PSCR,
         KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_K,    KC_L,    KC_U,    KC_Y, QK_AREP, _______,
        KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_RSFT,
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, MO_NAV1, MO_NAV2,    KC_J,    KC_H, KC_COMM,  KC_DOT,  QK_REP, KC_RCTL,
                                   KC_LGUI, KC_LALT, MO_NUMS,  KC_SPC, KC_BSPC, MO_SYMS, KC_RALT, KC_RGUI
    ),

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | COLE |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |   S  |   D  |   F  |      |-------.    ,-------|   H  |   J  |   K  |   L  |  Up  |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |   V  |   B  |-------|    |-------|   N  |   M  |      | Left | Down |Right |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_QWERTY] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
        _______, _______,    KC_S,    KC_D,    KC_F, _______,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_UP,  KC_DOT,
        _______, _______, _______, _______,    KC_V,    KC_B, _______, _______,    KC_N,    KC_M, _______, KC_LEFT, KC_DOWN, KC_RGHT,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* NUMS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | F12  | F10  |  F9  |  F8  |  F7  |  F6  |                    |  F5  |  F4  |  F3  |  F2  |  F1  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |  F7  |  F5  |  F3  |  F1  |  F9  |                    |  F8  | F10  |  F2  |  F4  |  F6  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |  7   |  5   |  3   |  1   |  9   |-------.    ,-------|  8   |  0   |  2   |  4   |  6   |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |  _   |  (   |  )   | F11  |Space |-------|    |-------|      | F12  |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |CONFIG|      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_NUMS] = LAYOUT(
         KC_F12,TD(_0F0),TD(_9F9),TD(_8F8),TD(_7F7),TD(_6F6),                  TD(_5F5),TD(_4F4),TD(_3F3),TD(_2F2),TD(_1F1), KC_F11,
        _______,   KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                     KC_F8,  KC_F10,   KC_F2,   KC_F4,   KC_F6, _______,
        _______,    KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                      KC_8,    KC_0,    KC_2,    KC_4,    KC_6, _______,
        _______, KC_UNDS, KC_LPRN, KC_RPRN,  KC_F11,  KC_SPC, _______, _______, _______,  KC_F12, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* SYMS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |  `   |  '   |  "   |  %   |                    |  #   |  ^   |  *   |  $   |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |  @   |  [   |  ]   |  _   |  |   |-------.    ,-------|  !   |  -   |  (   |  )   |  =   |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |  \   |  {   |  }   |  ~   |  &   |-------|    |-------|  ?   |  +   |  <   |  >   |  /   |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |CONFIG| /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_SYMS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  KC_GRV, KC_QUOT, KC_DQUO, KC_PERC,                   KC_HASH, KC_CIRC, KC_ASTR,  KC_DLR, XXXXXXX, XXXXXXX,
        _______,   KC_AT, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE,                   KC_EXLM, KC_MINS, KC_LPRN, KC_RPRN,  KC_EQL, _______,
        _______, KC_NUHS, KC_LCBR, KC_RCBR, KC_TILD, KC_AMPR, XXXXXXX, XXXXXXX, KC_QUES, KC_PLUS,   KC_LT,   KC_GT, KC_SLSH, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* NAV
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | WHLU | WHLL | MUP  | WHLR |      |                    | Vol+ | Home |  UP  |  End | PgUp |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | WHLD |MLEFT |MDOWN |MRGHT |      |-------.    ,-------| Vol- | LEFT | DOWN | RGHT | PgDn |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      | LNG1 | BTN1 | BTN2 | BTN3 |      |-------|    |-------| Mute | Prev | Play | Next | LNG2 |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, MS_WHLU, MS_WHLL,   MS_UP, MS_WHLR, XXXXXXX,                   KC_VOLU, KC_HOME,   KC_UP,  KC_END, KC_PGUP, XXXXXXX,
        _______, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,                   KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, KC_LNG1, MS_BTN2, MS_BTN3, MS_BTN1, XXXXXXX, _______, _______, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_LNG2, XXXXXXX,
                                   _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______
    ),

    /* CONFIG
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |RESET |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_CONFIG] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUMS, _SYMS, _CONFIG);
}

#ifdef OLED_ENABLE
#include <oled.c>
#endif // OLED_ENABLE
