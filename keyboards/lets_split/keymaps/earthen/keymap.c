#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_extras/keymap_german_ch.h"
#include "ws2812.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define QWERTY 1
#define JOAN 2
#define MARC 0
#define SYMB 3
#define SYMBUS 4
#define LOWER 5
#define RAISE 6
#define CODE 7
#define ADJUST 8
#define MOUSE 9
#define DESKTOP 10
#define INTELLIJ 11


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// leds status
bool RGB_LIGHT_STATUS = true;

// Macros
#define CLOSEFILE M(0)
#define COPYPATH M(1)
#define REVEAL M(2)
#define WORKINGFILES M(3)
#define MARK M(4)
#define DELETEMARK M(5)
#define SELECTOMARK M(6)

// Tap Dance declarations
enum {
  TD_Y_COPY = 0,
  TD_F_PASTE,
  TD_M_WIN1,
  TD_W_WIN2,
  TD_V_WIN3,
  TD_WIN4_LEFT,
  TD_WIN5_DOWN,
  TD_WIN6_RIGHT,
  TD_G_WIN7,
  TD_WIN8_UP,
  TD_R_WIN9
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LT(LOWER,KC_SPC),   LT(RAISE,KC_BSPC),  LT(LOWER,KC_DELT),  LT(RAISE,KC_ENT),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* JOAN
 * ,---------------------------------------------------------------------------------------.
 * | § /CODE|   ü  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   T  |   Z  |PtS/Code|
 * |--------+------+------+------+------+-------------+------+------+------+------+--------|
 * |Tab/SYMB|   A  |   O  |   E  |   I  |   U  |   H  |   D  |   R  |   N  |   S  |L/SYMB  |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |ä/Shift |   ö  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   -  |Shift/ESC|
 * |--------+------+------+------+------+------+------+------+------+------+------+--------|
 * | Ctrl   | Alt  | GUI  |MOUSE |Space/| Bksp/| Del/ |Enter/| Up   | Down | Left |Right   |
 * |        |      |      |      | RAISE| LOWER| RAISE| LOWER|      |      |      |        |
 * `---------------------------------------------------------------------------------------'
 */

[JOAN] = KEYMAP( \
  LT(CODE,CH_PARA),   CH_UE,          CH_COMM, CH_DOT,  CH_P,               TD(TD_Y_COPY),      TD(TD_F_PASTE),     CH_G,               CH_C,    CH_T,    CH_Z,    LT(CODE,KC_PSCR), \
  LT(SYMB, KC_TAB),  SFT_T(CH_A),    CH_O,    CH_E,    CH_I,               CH_U,               CH_H,               CH_D,               CH_R,    CH_N,    SFT_T(CH_S),    LT(SYMB,CH_L), \
  SFT_T(CH_AE),      CH_OE,          CH_Q,    CH_J,    CH_K,               CH_X,               CH_B,               CH_M,               CH_W,    CH_V,    CH_MINS, SFT_T(KC_ESC) , \
  KC_LCTL,           KC_LALT,        KC_LGUI, TT(MOUSE), LT(RAISE,KC_BSPC),  LT(LOWER,KC_SPC),  LT(RAISE,KC_ENT),  LT(LOWER,KC_DELT),   LT(MOUSE,KC_UP), KC_DOWN, RGB_TOG,   RCTL_T(KC_CAPS) \
),

/* Marc
 * ,--------------------------------------------------------------------------------------------.
 * | Esc/CODE |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | - /INTELIJ|
 * |----------+------+------+------+------+-------------+------+------+------+------+-----------|
 * | TAB/SYMB |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  / /SYMB  |
 * |----------+------+------+------+------+------|------+------+------+------+------+-----------|
 * | Shift    |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Shift     |
 * |----------+------+------+------+------+------+------+------+------+------+------+-----------|
 * | Ctrl     | GUI  | Alt  |Mouse |Bksp/ |Delete|Enter/|SPACE/| DESK | Alt  |  GUI |BMayus     |
 * |          |      |      |      |LOWER |/RAISE|RAISE |LOWER | TOP  |      |      |/ Ctrl     |
 * `--------------------------------------------------------------------------------------------'
 */

[MARC] = KEYMAP ( \
  LT(INTELLIJ, KC_ESC),  KC_QUOT, KC_COMM, KC_DOT,             KC_P,              KC_Y,             KC_F,         KC_G,         KC_C,    KC_R,    KC_L,    LT(INTELLIJ,KC_MINS),\
  LT(SYMBUS,KC_TAB), KC_A,    KC_O,    KC_E,               KC_U,              KC_I,             KC_D,         KC_H,         KC_T,    KC_N,    KC_S,    LT(SYMBUS,KC_SLSH), \
  OSM(MOD_LSFT), KC_SCLN, KC_Q,    KC_J,               KC_K,              KC_X,             KC_B,             KC_M,         KC_W,    KC_V,    KC_Z,   OSM(MOD_LSFT), \
  LCTL_T(KC_CAPS),   KC_RGUI, KC_LALT, TT(MOUSE), LT(LOWER,KC_BSPC), LT(RAISE,KC_SPC), LT(RAISE,KC_SPC), LT(LOWER,KC_DELT), OSL(DESKTOP),   KC_LALT, KC_RGUI, RCTL_T(KC_ENT) \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |ADJUST|     |      |      |  ESC  |COPY  |MOUSE1| HOME |  UP  |  END |  *   |      |
 * |------+-----+------+------+----- -+-------------+------+------+------+------+------|
 * |      |     |      |MOUSE2| MOUSE1|CUT   |      | LEFT | DOWN | RIGHT|   +  |      |
 * |------+-----+------+------+----- -+------|------+------+------+------+------+------|
 * |      |      |      |DELETE| ENTER| PASTE|      |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[MOUSE] = KEYMAP( \
                 TG(ADJUST),  XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC, LCTL(KC_C), KC_BTN1, KC_WH_U,    KC_MS_UP, KC_WH_D,XXXXXXX,_______, \
                 _______, XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1, LCTL(KC_X), KC_WH_L, KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT, KC_WH_R, _______, \
                 _______, XXXXXXX, XXXXXXX, KC_DELT, KC_ENT, LCTL(KC_V), XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, _______, \
                 _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______ \
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   {  |   }  |   |  |   ç  |   "  |   '  |   &   |  *   |     |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |  ´   |   \  |   /  |   ?  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |   §  |   <  |   >  |      |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SYMB] = KEYMAP( \
  _______, CH_EXLM,CH_AT,  CH_LCBR,CH_RCBR,CH_PIPE, CH_CELA,   CH_DQOT,   CH_QUOT,    CH_AMPR,    CH_PAST, _______, \
  _______,  CH_HASH,CH_DLR, CH_LPRN,CH_RPRN,CH_GRV,  CH_ACUT, CH_BSLS,   CH_SLSH,    CH_QST,    KC_PPLS,  _______, \
  _______, CH_PERC,CH_CARR,CH_LBRC,CH_RBRC,CH_TILD, CH_PARA, CH_LESS,   CH_MORE,    CH_PLUS,    KC_PSLS,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______ \
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   {  |   }  |   |  |   $  |   @  |   '  |   &   |  *   |  =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |  ´   |   \  |   /  |   *  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |   =  |   <  |   >  |  =   |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SYMBUS] = KEYMAP( \
  _______, KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE, LSFT(KC_4),   LSFT(KC_2),   KC_QUOT,    KC_AMPR,    KC_ASTR, KC_EQL, \
  _______,  KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV, ALGR(KC_MINS), KC_BSLS,   KC_SLSH,    KC_PAST,    KC_PPLS,  _______, \
  _______, KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD, KC_EQL, LSFT(KC_COMMA), LSFT(KC_DOT) ,    KC_EQL,    KC_PSLS,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______ \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F4 |  F3  |   F2 |  F1   |      |  DEL |   7  |   8  |   9  |  *   | BSPC |
 * |------+-----+------+------+----- -+-------------+------+------+------+------+------|
 * |      |  F8 |   F7 |   F6 |   F5  |      |  =   |   4  |   5  |   6  |   +  |  -   |
 * |------+-----+------+------+----- -+------|------+------+------+------+------+------|
 * |      |  12  | F11  |  F10 |  F9  |      |   0  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  ,   |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER] = KEYMAP( \
                 _______, KC_F4,   KC_F3,   KC_F2,   KC_F1,   _______,   KC_DELT, KC_7,    KC_8,    KC_9,   KC_PAST, KC_BSPC, \
                 _______, KC_F8,   KC_F7,   KC_F6,   KC_F5,   _______,   KC_EQL, KC_4,    KC_5,    KC_6,   KC_PPLS, KC_PMNS, \
                 _______, KC_F12,  KC_F11,  KC_F10,  KC_F9,   _______,    KC_0,    KC_1,    KC_2,    KC_3,   KC_PSLS, _______, \
                 _______, _______, _______, _______, _______, _______, _______, _______, KC_PCMM, KC_DOT, _______,  _______ \
                  ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |ADJUST| Lock|      |      |WinCls |      |INSERT| HOME |  UP  |  END |      |      |
 * |------+-----+------+------+----- -+-------------+------+------+------+------+------|
 * |      |     | Run  |WinExp|AdrBar |      |TaskVw| LEFT | DOWN | RIGHT|      |      |
 * |------+-----+------+------+----- -+------|------+------+------+------+------+------|
 * |      |      |      |PrvTab|NexTab|      |NexWin| Undo | Redo |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE] = KEYMAP( \
  TG(ADJUST), LGUI(CH_L), XXXXXXX, XXXXXXX,            LALT(KC_F4),  XXXXXXX, KC_INS,       KC_HOME,    KC_UP,      KC_END,   XXXXXXX, _______, \
  _______,    XXXXXXX,    LGUI(KC_R), KC_MYCM,            LCTL(CH_L),   XXXXXXX, LGUI(KC_TAB), KC_LEFT,    KC_DOWN,    KC_RIGHT, XXXXXXX, _______, \
  _______,    XXXXXXX,    XXXXXXX, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), XXXXXXX, LALT(KC_TAB), LCTL(CH_Z), LCTL(CH_Y), XXXXXXX,  XXXXXXX, _______, \
  _______,    _______,    _______,            _______, _______,      _______, _______,      _______,    _______,    _______,  _______, _______ \
),

/* CODE	 
 * ,-----------------------------------------------------------------------------------.
 * |      |UnfolA|FoldA |UnfolS|FoldS |CloseF|Coment|F_Prev| Find |F_Next|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |SeltoM|DelMark| Mark |JFunc| LProj|G_Symb|G_File|LWorkF|G_Line|PeekDef|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Reveal|CopyPh|DeLine|S_Srnk|S_Expd| MCase| MWord|MRegex|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[CODE] =  KEYMAP( \
  _______, LCTL(LSFT(LALT(KC_A))),   LCTL(LSFT(LALT(KC_O))), LCTL(LSFT(LALT(KC_E))), LCTL(LSFT(LALT(KC_I))), CLOSEFILE, LCTL(CH_PARA), LSFT(KC_F3), LCTL(CH_F), KC_F3, XXXXXXX, _______, \
  _______, XXXXXXX, SELECTOMARK, DELETEMARK,   MARK,  LCTL(CH_M), LCTL(LALT(CH_P)),    LCTL(CH_R),          LCTL(KC_P),    WORKINGFILES,  LCTL(KC_G),      LALT(KC_F12), \
  _______, XXXXXXX, XXXXXXX, REVEAL,        COPYPATH,      LCTL(LSFT(CH_K)), LSFT(LALT(KC_LEFT)), LSFT(LALT(KC_RIGHT)),LALT(CH_C),    LALT(CH_W),    LALT(CH_R), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Exit |Restart|Reload|workSl|workSr|fullsc|  7   | 8-UP |  9   |resize|      |
 * |------+------+-------+------+------+-------------+------+------+------+------+------|
 * |      |      |stackin|togSpl|tabbed|      | menu |4-LEFT|5-DOWN|6-RIGH|vertic|horitz|
 * |------+------+-------+------+------+------|------+------+------+------+------+------|
 * |      | KILL | mute  |voldow|volup | LOCK |  0   |  1   |  2   |  3   |      |      |
 * |------+------+-------+------+------+------+------+------+------+------+------+------|
 * |      | stop | bakc  | play | next |floati focus |      |      |      |      |consol|
 * `------------------------------------------------------------------------------------'
 */

[DESKTOP] =  KEYMAP( \
                    _______, LGUI(LSFT(KC_E)), LGUI(LSFT(KC_R)), LGUI(LSFT(KC_C)), LGUI(LALT(KC_LEFT)), LGUI(LALT(KC_RIGHT)), LGUI(KC_F), LGUI(KC_7), TD(TD_WIN8_UP), LGUI(KC_9), LGUI(KC_R), _______, \
                    _______, _______, LGUI(KC_S), LGUI(KC_E), LGUI(KC_W), _______, LGUI(KC_D), TD(TD_WIN4_LEFT), TD(TD_WIN5_DOWN), TD(TD_WIN6_RIGHT), LGUI(KC_V), LGUI(KC_H), \
                    _______, LGUI(LSFT(KC_Q)), KC__MUTE, KC__VOLDOWN, KC__VOLUP, LGUI(LSFT(KC_X)), LGUI(KC_0), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______, \
                    _______, KC_STOP, KC_MPRV, KC_MPLY, KC_MNXT, LGUI(LSFT(KC_SPC)), LGUI(KC_SPC), _______, _______, _______, _______, LGUI(KC_ENT) \
                     ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |refact|altIns|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |goBack|      |goFord|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |altEnt|
 * `-----------------------------------------------------------------------------------'
 */
[INTELLIJ] =  KEYMAP( \
                     _______, LCTL(LALT(LSFT(KC_T))), LALT(KC_INS), _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, LCTL(LALT(KC_LEFT)), _______, LCTL(LALT(KC_RIGHT)), _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LSFT(KC_LSFT), \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LALT(KC_ENT) \
                     ),

/*
  Name 	Description
  RGB_TOG 	toggle on/off
  RGB_MOD 	cycle through modes
  RGB_HUI 	hue increase
  RGB_HUD 	hue decrease
  RGB_SAI 	saturation increase
  RGB_SAD 	saturation decrease
  RGB_VAI 	value increase
  RGB_VAD 	value decrease
*/
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      | led- | led+ |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST] =  KEYMAP( \
  _______, RESET , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, KC_DEL, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, TO(QWERTY),  XXXXXXX, DF(MARC),  XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(JOAN), XXXXXXX, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_M_WIN1] = ACTION_TAP_DANCE_DOUBLE(KC_M, LGUI(KC_1)),
  [TD_W_WIN2] = ACTION_TAP_DANCE_DOUBLE(KC_W, LGUI(KC_2)),
  [TD_V_WIN3] = ACTION_TAP_DANCE_DOUBLE(KC_V, LGUI(KC_3)),
  [TD_WIN4_LEFT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_4), LGUI(KC_LEFT)),
  [TD_WIN5_DOWN] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_5), LGUI(KC_DOWN)),
  [TD_WIN6_RIGHT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_6), LGUI(KC_RIGHT)),
  [TD_G_WIN7] = ACTION_TAP_DANCE_DOUBLE(KC_G, LGUI(KC_7)),
  [TD_WIN8_UP] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_8), LGUI(KC_UP)),
  [TD_R_WIN9] = ACTION_TAP_DANCE_DOUBLE(KC_R, LGUI(KC_9)),

  [TD_M_WIN1] = ACTION_TAP_DANCE_DOUBLE(CH_Y, LCTL(CH_C)),
  [TD_Y_COPY] = ACTION_TAP_DANCE_DOUBLE(CH_Y, LCTL(CH_C)),
  [TD_F_PASTE] = ACTION_TAP_DANCE_DOUBLE(CH_F, LCTL(CH_V))
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0: { // CLOSEFILE
      if (record->event.pressed){
        return MACRO( D(LCTL), T(K), U(LCTL), T(W), END);
      }
      break;
    }
    case 1: { // Copy Path of Active File
      if (record->event.pressed){
        return MACRO( D(LCTL), T(K), U(LCTL), T(P), END);
      }
      break;
    }
    case 2: { // Reveal Active File in Windows
      if (record->event.pressed){
        return MACRO( D(LCTL), T(K), U(LCTL), T(R), END);
      }
      break;
    }
    case 3: { // List Working Files
      if (record->event.pressed){
        return MACRO( D(LCTL), T(K), T(P), U(LCTL), END);
      }
      break;
    }
    case 4: { // Set Mark
      if (record->event.pressed){
        return MACRO( D(LCTL), T(K), T(SPC), U(LCTL), END);
      }
      break;
    }
    case 5: { // Remove Mark
      if (record->event.pressed){
        return MACRO( D(LCTL), T(K), T(G), U(LCTL), END);
      }
      break;
    }
    case 6: { // Mark til mark
      if (record->event.pressed){
        return MACRO( D(LCTL), T(K), T(A), U(LCTL), END);
      }
      break;
    }
  }
  return MACRO_NONE;
};

// this runs on key pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_TOG: {
      // capture one press, otherway it will enter here multiple times
      if (record->event.pressed) {
        RGB_LIGHT_STATUS = RGB_LIGHT_STATUS ? false : true;
      }
      break;
    }
  }
  return true;
}

struct cRGB led[RGBLED_NUM];
void rgbsps_set(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
  led[index].r = r;
  led[index].g = g;
  led[index].b = b;
}
void rgbsps_setall(uint8_t r, uint8_t g, uint8_t b) {
  for (uint16_t i = 0; i < RGBLED_NUM; i++) {
    rgbsps_set(i, r, g, b);
  }
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  switch (layer) {
    case LOWER:
    rgbsps_setall(0,255,0);
      break;
    case SYMB:
    case SYMBUS:
      rgbsps_setall(255,165,0); // yellow
      break;
    case RAISE:
      rgbsps_setall(0,0,255); //blue
      break;
    case CODE:
      rgbsps_setall(255,0,255); // lila
      break;
    case MOUSE:
      rgbsps_setall(160,50,0); //orange
      break;
    case ADJUST:
      rgbsps_setall(255,0,0); // red
      break;
  case DESKTOP:
    rgbsps_setall(0,100,0); // green
    break;
  case INTELLIJ:
    rgbsps_setall(0,206,209); // red
    break;
  default:
    //      if (RGB_LIGHT_STATUS)
    // {
    //    rgbsps_setall(255,255,255); // white
    //  }
    //  else {
        rgbsps_setall(0,0,0); // none
        //  }
      break;
  }
  ws2812_setleds(led, RGBLED_NUM);
};
