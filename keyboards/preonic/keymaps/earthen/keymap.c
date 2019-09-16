/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_extras/keymap_german_ch.h"

enum preonic_layers {
  _BASE,
  _SYMB,
  _NUMB,
  _WORK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  NUMB,
  WORK,
  QWERTY,
  LOWER,
  RAISE,
  BACKLIT
};

#define CUTTIMER 150

#define COPYCUT M(1)
#define PASTE M(2)
#define DOUBLE0 M(3)
#define CLOSEFILE M(4)
#define MAILWORK M(5)
#define MAILPRIV M(6)
#define CHOME M(7)
#define MOVEWINDOW M(8)
#define MAILGOGL M(9)

#define NextDesk LGUI(LCTL(KC_RIGHT))
#define PrevDesk LGUI(LCTL(KC_LEFT))
#define ShowWindows LCTL(LALT(KC_TAB))

#define FN_LIB LCTL(LALT(KC_1))
#define FN_DEV LCTL(LALT(KC_2))
#define FN_BOOK LCTL(LALT(KC_4))
#define FN_DIM LCTL(LSFT(KC_L)) // Lights Out
#define FN_UNDO LCTL(KC_Z)
#define FN_REDO LCTL(KC_Y)
#define FN_PAINT LCTL(LALT(KC_K))
#define FN_COPY LCTL(LSFT(KC_C)) // Copy Settings
#define FN_PAST LCTL(LSFT(KC_V)) // Paste Settings
//Targeted Adjustment Tool
#define FN_TAT LCTL(LALT(LSFT(KC_N))) // Deselect Targeted Adjustemt Tool
#define FN_TONE LCTL(LALT(LSFT(KC_T))) // Tone Curve
#define FN_HUE LCTL(LALT(LSFT(KC_H))) // HUE
#define FN_SAT LCTL(LALT(LSFT(KC_S))) // Saturation
#define FN_LUM LCTL(LALT(LSFT(KC_L))) // Lumination
#define FN_BWMIX LCTL(LALT(LSFT(KC_G))) // Black & White Mix


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * .-----------------------------------------------------------------------------------------------------------.
 * | ESC    | 0      | 1      | 2      | 3      | 4      | 5      | Library| Develop| Book   | 0      | MEH §  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | ,      | .      | Copy   | Paste  |        |        |        | Grid   |AdjustBr|        |        |Mayu/Alt|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |Flagged |Unflaged|Regected|LEFT    | RIGHT  |        |        | Loupe  |SpotRem |        |        |  L/SYMB|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | Undo   | Redo   |Bevor   |Clipping|LightOut|  B & W |        | Info   |Croping |Aspect  |        | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+-----------------+--------+--------|
 * | LCtrl  | Alt    | LShift | Tone   | Hue    | Sat    | Lumin  |B& W Mix|DeselTAT|  DOWN  | LEFT   | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------'
 */

 [_BASE] = LAYOUT_preonic_grid( /* QWERTY */ \
  KC_ESC,  CH_0,    CH_1,    CH_2,    CH_3,      CH_4,   CH_5,     FN_LIB,    FN_DEV,   FN_BOOK, KC_0,    KC_ESC, \
  CH_COMM, KC_DOT,  FN_COPY, FN_PAST, KC_0,      KC_0,   CH_0,     CH_G,      CH_K,     KC_0,    KC_0,    KC_0,   \
  CH_U,    CH_P,    CH_X,    KC_LEFT, KC_RIGHT,  KC_0,   KC_0,     CH_E,      CH_Q,     KC_0,    KC_0,    KC_0,   \
  FN_UNDO, FN_REDO, CH_Y,    CH_J,    FN_DIM,    CH_V,   KC_0,     CH_I,      CH_R,     CH_A,    KC_0,    KC_DEL, \
  KC_LCTL, KC_LALT, KC_LSFT, FN_TONE, FN_HUE,    FN_SAT, FN_LUM,   FN_BWMIX,  FN_TAT, KC_DOWN, KC_LEFT, KC_RIGHT  \
 ),
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),
/* SYMBOLS
 * .-----------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   !    |   @    |   {    |   }    |   |    |    ç   |   "    |   '    |   §    |    *   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   #    |   $    |   (    |   )    |   `    |    ´   |   \    |   /    |   ?    |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   %    |   ^    |   [    |   ]    |   ~    |   &    |   <    |   >    |  =     |   -    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */

 [_SYMB] = LAYOUT_preonic_grid( /* SYMBOLS */ \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  , \
  _______, CH_EXLM, CH_AT,   CH_LCBR, CH_RCBR, CH_PIPE, CH_CELA, CH_DQOT, CH_QUOT, CH_PARA, CH_PAST, _______  , \
  _______, CH_HASH, CH_DLR,  CH_LPRN, CH_RPRN, CH_GRV,  CH_ACUT, CH_BSLS, CH_SLSH, CH_QST,  CH_PLUS, _______  , \
  _______, CH_PERC, CH_CARR, CH_LBRC, CH_RBRC, CH_TILD, CH_AMPR, CH_LESS, CH_MORE, CH_EQL,  CH_MINS, _______  , \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______   \
 ),

 /* NUMBERS
 * .-----------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F4   |   F3   |  F2    |  F1    |   0    |        |   7    |   8    |   9    |   *    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F8   |   F7   |  F6    |  F5    |   5    |   /    |   4    |   5    |   6    |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F12  |   F11  |  F10   |  F9    |   1    |   &    |   1    |   2    |   3    |   -    | NumLock|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |    0   |  Space |   00   |   .    |   =    |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */

 [_NUMB] = LAYOUT_preonic_grid( /* NUMBERS */ \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  , \
  _______, KC_F4,   KC_F3,   KC_F2,   KC_F1,   CH_0,    _______, CH_7,    CH_8,    CH_9,    KC_PAST, _______  , \
  _______, KC_F8,   KC_F7,   KC_F6,   KC_F5,   CH_5,    KC_PSLS, CH_4,    CH_5,    CH_6,    KC_PPLS, _______  , \
  _______, KC_F12,  KC_F11,  KC_F10,  KC_F9,   CH_1,    CH_AMPR, CH_1,    CH_2,    CH_3,    CH_MINS, KC_NLCK  , \
  _______, _______, _______, _______, _______, _______, CH_0,    KC_SPC,  DOUBLE0, KC_DOT,  CH_EQL,  _______   \
 ),
/* WORK
 * .-----------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |MailGogl|WorkMail|PrivMail|WinClose|        | MovWin |  END   |   UP   |  HOME  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CrlShf |  Lock  |        | WinExpl| AddrBar|  LGui  |ShowWin |  Left  |  Down  |  Right |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        | PrevTab| NextTab|        | NextWin|  Undo  |  Redo  |PrevDesk|NextDesk|        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */

 [_WORK] = LAYOUT_preonic_grid( /* WORK Layer */ \
  _______,                  _______,    _______,  _______,            _______,      _______, _______,      _______,    _______,    _______,  _______,  _______  , \
  OSM(MOD_LCTL | MOD_LALT), MAILGOGL, MAILWORK, MAILPRIV,           LALT(KC_F4),  XXXXXXX, MOVEWINDOW,   KC_HOME,    KC_UP,      KC_END,   XXXXXXX,  _______  , \
  OSM(MOD_LCTL | MOD_LSFT), LGUI(CH_L),    XXXXXXX,  LGUI(CH_E),            LCTL(CH_L),   KC_LGUI, ShowWindows,  KC_LEFT,    KC_DOWN,    KC_RIGHT, XXXXXXX,  _______  , \
  KC_LSFT,                  XXXXXXX,    XXXXXXX,  LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), XXXXXXX, LALT(KC_TAB), LCTL(CH_Z), LCTL(CH_Y), PrevDesk, NextDesk, _______  , \
  _______,                  _______,    _______,  _______,            _______,      _______, _______,      _______,    _______,    _______,  _______,  _______   \
 ),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (clockwise) {
      register_code(KC_PPLS);
      unregister_code(KC_PPLS);
    } else {
      register_code(KC_PMNS);
      unregister_code(KC_PMNS);
    }

}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

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
        case 9: {
          if (record->event.pressed)          {
            // SEND_STRING("joan.badiac@gmail.com");
            return MACRO(T(J),T(O),T(A),T(N),T(DOT),T(B),T(A),T(D),T(I),T(A),T(C),D(RALT),T(2),U(RALT),T(G),T(M),T(A),T(I),T(L),T(DOT),T(C),T(O),T(M),T(TAB),END);
          }
          break;
        }
      }
    return MACRO_NONE;
};

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
