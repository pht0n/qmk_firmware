/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// combo variables
enum combo_events {
  CB_SLAL,
  CB_PRNT,
  CB_RPRNT,
  CB_COPY,
  CB_PASTE,
  CB_CUT,
  CB_NORBN,
  CB_PRN,
  CB_BRC,
  CB_CBR,
};

const uint16_t PROGMEM wf_combo[] = {KC_W,KC_F, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM wp_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM xd_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM PRN_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM BRC_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM CBR_combo[] = {KC_H, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CB_SLAL]  = COMBO_ACTION(wf_combo),
  [CB_PRNT]  = COMBO_ACTION(fp_combo),
  [CB_RPRNT] = COMBO_ACTION(wp_combo),
  [CB_COPY]  = COMBO_ACTION(xc_combo),
  [CB_PASTE] = COMBO_ACTION(cd_combo),
  [CB_CUT]   = COMBO_ACTION(xd_combo),
  [CB_PRN]   = COMBO_ACTION(PRN_combo),
  [CB_BRC]   = COMBO_ACTION(BRC_combo),
  [CB_CBR]   = COMBO_ACTION(CBR_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CB_SLAL:
      if (pressed) {
        tap_code16(LCTL(KC_A));
      }
      break;
    case CB_PRNT:
      if (pressed) {
        tap_code16(KC_PSCR);
      }
      break;
    case CB_RPRNT:
      if (pressed) {
        tap_code16(LSFT(KC_PSCR));
      }
      break;
    case CB_COPY:
      if (pressed) {
        tap_code16(LCTL(KC_C));
      }
      break;
    case CB_PASTE:
      if (pressed) {
        tap_code16(LCTL(KC_V));
      }
      break;
    case CB_CUT:
      if (pressed) {
        tap_code16(LCTL(KC_X));
      }
      break;
    case CB_PRN:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_LEFT);
      }
      break;
    case CB_BRC:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
        tap_code16(KC_LEFT);
      }
      break;
    case CB_CBR:
      if (pressed) {
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_LEFT);
      }
      break;
  }
}


// tapdance variables
enum {
  TD_RESET,
};

// key override for KC_ENT based on CTRL
//const key_override_t ENT_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_BTN1, KC_ENT, 1 << 0);

// This globally defines all key overrides to be used
//const key_override_t *key_overrides[] = {
//    &delete_key_override
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LCTL_T(KC_A),LGUI_T(KC_R),LALT_T(KC_S),LSFT_T(KC_T),KC_G,            KC_M,LSFT_T(KC_N),LALT_T(KC_E),LGUI_T(KC_I),LCTL_T(KC_O), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SCLN,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                           LT(3,KC_ESC), LT(1,KC_TAB), LT(2,KC_BTN1),     KC_SPC, OSM(MOD_LSFT), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9, KC_BSPC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, LSFT_T(KC_DEL), KC_UNDS,                        KC_EQL, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_CIRC, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS,                      KC_HOME,  KC_END, KC_COMM,  KC_DOT, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_SPC, KC_0, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_AT, KC_HASH, KC_DLR, KC_PERC, RALT(KC_5),                      RALT(KC_M), RALT(LSFT(KC_S)), RALT(KC_Y), KC_QUES, KC_BSPC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RALT(KC_Q), KC_QUOT, RALT(KC_S), LCTL(KC_Z), LCTL(KC_Y),          KC_PGDN, KC_PGUP, KC_LCBR, KC_RCBR, RALT(KC_P), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TILD, KC_BSLS, KC_AMPR, KC_PIPE, RALT(KC_COLN),                 KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_EXLM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_SPC, KC_LSFT, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F11,  KC_F12, KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,                      KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, TD(TD_RESET), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_BTN1, KC_BTN2, KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      XXXXXXX, KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_ESC, LALT_T(KC_TAB), LCTL_T(KC_ENT),    _______, _______,  _______
                                      //`--------------------------'  `--------------------------'
  )


};

void safe_reset(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_TAB):
            // Immediately select the hold action when another key is pressed.
            return true;
        case LT(2,KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        case KC_LSFT:
            // Immediately select the hold action when another key is pressed.
            return true;
        case LT(3,KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_ENT):
            return 150;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_TAB):
            return 0;
        case LT(2,KC_ENT):
            return 0;
        case LT(3,KC_ESC):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_GRV:
            return true;
        case KC_COMM:
            return true;
        case KC_DOT:
            return true;
        case KC_SCLN:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
