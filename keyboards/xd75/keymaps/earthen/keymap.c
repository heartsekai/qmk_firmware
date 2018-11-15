/* Copyright 2017 Wunder
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
#include "xd75.h"
#include "keymap_extras/keymap_german_ch.h"

#define BASE 0 // default layer
#define GAME 1 // Game Layer
#define SYMB 2 // symbols
#define NUMB 3 // Numbers and F keys
#define WORK 4 // Work keys
#define _FN 5

#define CUTTIMER 150

#define COPYCUT M(1)
#define PASTE M(2)
#define DOUBLE0 M(3)
#define CLOSEFILE M(4)
#define MAILWORK M(5)
#define MAILPRIV M(6)
#define CHOME M(7)
#define MOVEWINDOW M(8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | MEH §  | 1      | 2      | 3      | 4      | 5      | Esc    |        |        | 6      | 7      | 8      | 9      | 0      |PrintScr|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |Tab/CODE| ü      | ;      | .      | P      | Y      | Del    |        | MEHTab | F      | G      | C      | T      | Z      | CODE   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | Tab/SMB| A      | O      | E      | I      | U      | CopyCut|        | RUN    | H      | D      | R      | N      | S      | L/SYMB |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | ä/Shift| ö      | Q      | J      | K      | X      | Paste  |        |        | B      | M      | W      | V      | -/AltGr| RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCtrl  | LAlt   | LGui   | Ctrl + | Alt +  | BACKSP | DEL    |        | ENTER  | SPACE  | SPACE  |        |        |        | RCTRL  |
 * | LCtrl  | LAlt   |        | Shift  | Shift  | WORK   | NUMB   |        | WORK   | NUMB   |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [BASE] = { /* QWERTY */
  { LCTL(CH_PARA),     CH_1,    CH_2,    CH_3,                     CH_4,                     CH_5,             KC_ESC,           XXXXXXX, XXXXXXX,          CH_6,             CH_7,     CH_8,    CH_9,    CH_0,    KC_PSCR          },
  { KC_TAB,   CH_UE,   CH_COMM, KC_DOT,                   CH_P,                     CH_Y,             KC_DELT,          XXXXXXX, HYPR(KC_TAB),     CH_F,             CH_G,     CH_C,    CH_T,    CH_Z,    KC_BSPC },
  { LT(SYMB, KC_TAB),  CH_A,    CH_O,    CH_E,                     CH_I,                     CH_U,             COPYCUT,        XXXXXXX, XXXXXXX,          CH_H,             CH_D,     CH_R,    CH_N,    CH_S,    LT(SYMB,CH_L)    },
  { SFT_T(CH_AE),      CH_OE,   CH_Q,    CH_J,                     CH_K,                     CH_X,             PASTE,            XXXXXXX, LGUI(CH_R),       CH_B,             CH_M,     CH_W,    CH_V,    KC_FN3,  KC_LSFT          },
  {  KC_LCTL,          KC_LALT, KC_LGUI, OSM(MOD_LCTL | MOD_LSFT), OSM(MOD_RALT | MOD_LSFT), LT(NUMB,KC_BSPC), LT(WORK,KC_DELT), XXXXXXX, LT(NUMB, KC_ENT), LT(WORK,KC_SPC),  KC_SPACE, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL          },
 },

/* SYMBOLS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   !    |   @    |   {    |   }    |   |    |        |        |        |    ç   |   "    |   '    |   §    |    *   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   #    |   $    |   (    |   )    |   `    |        |        |   C:\  |    ´   |   \    |   /    |   ?    |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   %    |   ^    |   [    |   ]    |   ~    |        |        |        |   &    |   <    |   >    |  =     |   -    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [SYMB] = { /* SYMBOLS */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, CH_EXLM, CH_AT,   CH_LCBR, CH_RCBR, CH_PIPE, _______, _______, _______, CH_CELA, CH_DQOT, CH_QUOT, CH_PARA, CH_PAST, _______  },
  { _______, CH_HASH, CH_DLR,  CH_LPRN, CH_RPRN, CH_GRV,  _______, _______, CHOME,   CH_ACUT, CH_BSLS, CH_SLSH, CH_QST,  CH_PLUS, _______  },
  { _______, CH_PERC, CH_CARR, CH_LBRC, CH_RBRC, CH_TILD, _______, _______, _______, CH_AMPR, CH_LESS, CH_MORE, CH_EQL,  CH_MINS, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

/* NUMBERS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F4   |   F3   |  F2    |  F1    |   0    |        |        |        |        |   7    |   8    |   9    |   *    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F8   |   F7   |  F6    |  F5    |   5    |        |        |        |   /    |   4    |   5    |   6    |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F12  |   F11  |  F10   |  F9    |   1    |        |        |        |   &    |   1    |   2    |   3    |   -    | NumLock|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |   0    |   00   |   .    |   =    |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [NUMB] = { /* NUMBERS */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_F4,   KC_F3,   KC_F2,   KC_F1,   CH_0,    _______, _______, _______, _______, CH_7,    CH_8,    CH_9,    KC_PAST, _______  },
  { _______, KC_F8,   KC_F7,   KC_F6,   KC_F5,   CH_5,    _______, _______, _______, KC_PSLS, CH_4,    CH_5,    CH_6,    KC_PPLS, _______  },
  { _______, KC_F12,  KC_F11,  KC_F10,  KC_F9,   CH_1,    _______, _______, _______, CH_AMPR, CH_1,    CH_2,    CH_3,    CH_MINS, KC_NLCK  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  CH_0,    DOUBLE0, KC_DOT,  CH_EQL,  _______  },
 },

/* WORK
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |  Lock  |WorkMail|PrivMail|WinClose|        |        |        |        | MovWin |  END   |   UP   |  HOME  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CrlShf |        |        | WinExpl| AddrBar|  LGui  |        |        |        |TaskView|  Left  |  Down  |  Right |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        | PrevTab| NextTab|        |        |        |        | NextWin|  Undo  |  Redo  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [WORK] = { /* WORK Layer */
  { _______,                  _______,    _______,  _______,            _______,      _______, _______, _______, _______, _______,      _______,    _______,    _______,  _______, _______  },
  { _______,                  LGUI(CH_L), MAILWORK, MAILPRIV,           LALT(KC_F4),  XXXXXXX, _______, _______, _______, MOVEWINDOW,   KC_HOME,    KC_UP,      KC_END,   XXXXXXX, _______  },
  { OSM(MOD_LCTL | MOD_LSFT), XXXXXXX,    XXXXXXX,  KC_MYCM,            LCTL(CH_L),   KC_LGUI, _______, _______, _______, LGUI(KC_TAB), KC_LEFT,    KC_DOWN,    KC_RIGHT, XXXXXXX, _______  },
  { KC_LSFT,                  XXXXXXX,    XXXXXXX,  LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), XXXXXXX, _______, _______, _______, LALT(KC_TAB), LCTL(CH_Z), LCTL(CH_Y), XXXXXXX,  XXXXXXX, _______  },
  { _______,                  _______,    _______,  _______,            _______,      _______, _______, _______, _______, _______,      _______,    _______,    _______,  _______, _______  },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12   },
  { KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS  },
  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______  },
  { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______  },
  { _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______  },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
        case 1: {
          // Copy for 150 ms press
          // Cut for long press
          // Paste for tap
          if (record->event.pressed) {
            key_timer = timer_read(); // if the key is being pressed, we start the timer.
          }
          else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
            if (timer_elapsed(key_timer) > CUTTIMER) { // the longest press ist a Cut
              key_timer = 0;
                return MACRO( D(LCTL), T(X), U(LCTL), END  );
            }
            else { // less than 150ms count as a tap and we do a copy.
              key_timer = 0;
                return MACRO( D(LCTL), T(C), U(LCTL), END  );
            }
          }
          break;
        }
        case 2: {
          if (record->event.pressed) {
            return MACRO( D(LCTL), T(V), U(LCTL), END  );
          }
          break;
        }
        case 3: { // add 00
          if (record->event.pressed) {
            return MACRO( I(25), T(P0), T(P0), END );
          }
          break;
        }
        case 4: { // CLOSEFILE
          if (record->event.pressed){
            return MACRO( D(LCTL), T(K), U(LCTL), T(W), END);
          }
          break;
        }
        case 5: {
          if (record->event.pressed)          {
            // SEND_STRING("joan.lustenberger");
            return MACRO(T(J),T(O),T(A),T(N),T(DOT),T(L),T(U),T(S),T(T),T(E),T(N),T(B),T(E),T(R),T(G),T(E),T(R),D(RALT),T(2),U(RALT),T(S),T(U),T(V),T(A),T(DOT),T(C),T(H),T(TAB),END);
          }
          break;
        }
        case 6: {
          if (record->event.pressed)          {
            // SEND_STRING("lustenberger.joan");
            return MACRO(T(L),T(U),T(S),T(T),T(E),T(N),T(B),T(E),T(R),T(G),T(E),T(R),T(DOT),T(J),T(O),T(A),T(N),D(RALT),T(2),U(RALT),T(O),T(U),T(T),T(L),T(O),T(O),T(K),T(DOT),T(C),T(O),T(M),T(TAB),END);
          }
          break;
        }
        case 7: {
          if (record->event.pressed)
            /* Send c:\ */
            return MACRO(T(C),D(LSFT),T(DOT),U(LSFT),D(RALT),T(NUBS),U(RALT),END);
        }
        case 8: {
          if (record->event.pressed)
            // send move Window
            return MACRO(D(LALT),T(SPACE),U(LALT),T(M),END);
        }
      }
    return MACRO_NONE;
};

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
  //   case LOWER:
  //   rgbsps_setall(0,255,0);
  //     break;
     case SYMB:
  //   case SYMBUS:
       rgbsps_setall(255,165,0); // yellow
       break;
  //   case RAISE:
  //     rgbsps_setall(0,0,255); //blue
  //     break;
  //   case CODE:
  //     rgbsps_setall(255,0,255); // lila
  //     break;
  //   case MOUSE:
  //     rgbsps_setall(160,50,0); //orange
  //     break;
  //   case ADJUST:
  //     rgbsps_setall(255,0,0); // red
  //     break;
  // case DESKTOP:
  //   rgbsps_setall(0,100,0); // green
  //   break;
  // case INTELLIJ:
  //   rgbsps_setall(0,206,209); // red
  //   break;
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
