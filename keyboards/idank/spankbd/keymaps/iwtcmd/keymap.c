#include QMK_KEYBOARD_H

enum {
    _MAIN,
    _NUMSYM1,
    _NUMSYM2,
    _NAVSPEC,
    _HOTKEYS
};

enum {
    TD_DQUO_QUOT,
    TD_QUES_SLSH,
    TD_PIPE_BSLS,
    TD_TILD_GRV,
    TD_ESC_CAPS
};

enum custom_keycodes {
    SS_YAML_VAR = SAFE_RANGE,
};


#define KC_CTL_A  MT(MOD_LCTL, KC_A)     // Tap for A, hold for Control
#define KC_CTL_CL MT(MOD_LCTL, KC_SCLN)  // Tap for colon, hold for Control
#define KC_SFT_Z  MT(MOD_RSFT, KC_Z)     // Tap for Z, hold for Shift
#define KC_SFT_SL MT(MOD_RSFT, KC_SLSH)  // Tap for slash, hold for Shift

#define KC_GUI_ESC MT(MOD_LGUI, KC_ESC)  // Tap for Esc, hold for GUI (Meta, Command, Win)
#define KC_ALT_ENT MT(MOD_LALT, KC_ENT)  // Tap for Enter, hold for Alt (Option)
#define KC_SPE_SPC LT(_SPECIAL, KC_SPC)  // Tap for Space, hold for Special layer
#define KC_NUM_SPC LT(_NUMBERS, KC_SPC)  // Tap for Space, hold for Numbers layer


#define KC_SFT_OSM OSM(MOD_LSFT | MOD_RSFT)  // Tap for OneShot shift, hold for shift
#define KC_DESKTOP_L LGUI(LCTL(KC_LEFT))
#define KC_DESKTOP_R LGUI(LCTL(KC_RGHT))

tap_dance_action_t tap_dance_actions[] = {
    [TD_DQUO_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_DQUO, KC_QUOT),
    [TD_QUES_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_SLSH),
    [TD_PIPE_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_PIPE, KC_BSLS),
    [TD_TILD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_TILD, KC_GRV),
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x5_3(
         KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,
         KC_A,     KC_S,   KC_D,   KC_F,   KC_G,          KC_H,   KC_J,   KC_K,     KC_L,   KC_COLN,
         KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,          KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SFT_OSM,
             QK_REP, OSL(_NUMSYM1), KC_SPC,                  KC_ENT, OSL(_NAVSPEC), OSL(_NUMSYM2)),


    [_NUMSYM1] = LAYOUT_split_3x5_3(
         KC_1,    KC_2,    KC_3,    KC_4,   KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
         KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
         KC_TILD, KC_PIPE, KC_PLUS, KC_EQL, KC_MINS,          KC_UNDS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,
                  KC_BSPC, TO(_MAIN), TO(_NUMSYM1),           KC_ENT, OSL(_NUMSYM2), KC_DEL),

   
    [_NUMSYM2] = LAYOUT_split_3x5_3(
         KC_CAPS,    KC_PSCR,   KC_D,      KC_LT,      KC_GT,        LCTL(KC_BSPC),LCTL(KC_DEL),  LCTL(KC_LEFT), LCTL(KC_RGHT), SS_YAML_VAR,
         KC_QUOT,    KC_DQUO,   KC_QUES,   KC_SCLN,    KC_PERC,      KC_1,         KC_2,          KC_3,          KC_4,          KC_5,
         KC_QUES,    KC_SLSH,   KC_PLUS,   KC_MS_L,    KC_MS_R,      KC_6,         KC_7,          KC_8,          KC_9,          KC_0,
                     LGUI(KC_L),      TO(_MAIN), KC_DOT,             TO(_NUMSYM2), OSL(_HOTKEYS), KC_ESC),

    
    [_NAVSPEC] = LAYOUT_split_3x5_3(
         OSM(MOD_LCTL),  OSM(MOD_LALT),  LCTL(KC_LEFT),  LCTL(KC_RGHT),  KC_ESC,            KC_HOME,       KC_PGDN,        KC_PGUP,     KC_END,        KC_F2,
         LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_N),     LCTL(KC_F),     LSFT(KC_TAB),      KC_LEFT,       KC_DOWN,        KC_UP,       KC_RGHT,       KC_LGUI,
         LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     KC_TAB,            LGUI(KC_LEFT), LGUI(KC_DOWN),  LGUI(KC_UP), LGUI(KC_RGHT), LALT(KC_TAB),
                         KC_DESKTOP_L,   TO(_MAIN),      KC_LALT,                           TO(_NAVSPEC),  OSL(_HOTKEYS),  KC_DESKTOP_R),

   
    [_HOTKEYS] = LAYOUT_split_3x5_3(
         KC_CAPS,  KC_2,  KC_3,  KC_4,  KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
                    KC_F11, TO(_MAIN), KC_TRNS,         KC_TRNS,  TO(_NAVSPEC),  KC_MNXT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SS_YAML_VAR:
        if (record->event.pressed) {
            SEND_STRING("{{ " SS_TAP(X_LEFT));
        } else {
        }
        break;
    }
    return true;
};
