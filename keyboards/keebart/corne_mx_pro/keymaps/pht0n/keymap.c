#include QMK_KEYBOARD_H

// Combos carried over from the old keymap.
enum combo_events {
    CB_SELECT_ALL,
    CB_PRINT_SCREEN,
    CB_SHIFT_PRINT_SCREEN,
    CB_COPY,
    CB_PASTE,
    CB_CUT,
    CB_PARENS,
    CB_BRACKETS,
    CB_BRACES,
};

const uint16_t PROGMEM wf_combo[]  = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM fp_combo[]  = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM wp_combo[]  = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM xc_combo[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[]  = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM xd_combo[]  = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM prn_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM brc_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM cbr_combo[] = {KC_H, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CB_SELECT_ALL]         = COMBO_ACTION(wf_combo),
    [CB_PRINT_SCREEN]       = COMBO_ACTION(fp_combo),
    [CB_SHIFT_PRINT_SCREEN] = COMBO_ACTION(wp_combo),
    [CB_COPY]               = COMBO_ACTION(xc_combo),
    [CB_PASTE]              = COMBO_ACTION(cd_combo),
    [CB_CUT]                 = COMBO_ACTION(xd_combo),
    [CB_PARENS]              = COMBO_ACTION(prn_combo),
    [CB_BRACKETS]            = COMBO_ACTION(brc_combo),
    [CB_BRACES]              = COMBO_ACTION(cbr_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;
    switch (combo_index) {
        case CB_SELECT_ALL:         tap_code16(LCTL(KC_A)); break;
        case CB_PRINT_SCREEN:       tap_code16(KC_PSCR); break;
        case CB_SHIFT_PRINT_SCREEN: tap_code16(LSFT(KC_PSCR)); break;
        case CB_COPY:               tap_code16(LCTL(KC_C)); break;
        case CB_PASTE:              tap_code16(LCTL(KC_V)); break;
        case CB_CUT:                tap_code16(LCTL(KC_X)); break;
        case CB_PARENS:
            tap_code16(KC_LPRN); tap_code16(KC_RPRN); tap_code(KC_LEFT); break;
        case CB_BRACKETS:
            tap_code16(KC_LBRC); tap_code16(KC_RBRC); tap_code(KC_LEFT); break;
        case CB_BRACES:
            tap_code16(KC_LCBR); tap_code16(KC_RCBR); tap_code(KC_LEFT); break;
    }
}

enum layers { _BASE, _NUM, _SYM, _FUNCTION };

#define EX2_LAYOUT( \
    l00,l01,l02,l03,l04,l05, r05,r04,r03,r02,r01,r00, \
    l10,l11,l12,l13,l14,l15, r15,r14,r13,r12,r11,r10, \
    l20,l21,l22,l23,l24, r24,r23,r22,r21,r20, \
    t0,t1,t2,t3,t4,t5 \
) LAYOUT_split_3x5_3_ex2( \
    l00,l01,l02,l03,l04,l05, r05,r04,r03,r02,r01,r00, \
    l10,l11,l12,l13,l14,l15, r15,r14,r13,r12,r11,r10, \
    l20,l21,l22,l23,l24, r24,r23,r22,r21,r20, \
    t0,t1,t2,t3,t4,t5 \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Physical key layout for each layer:
     *
     * LEFT HALF (outer -> inner)                 RIGHT HALF (inner -> outer)
     * [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]       [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
     * [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]       [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
     * [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ]               [ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
     *
     *                         THUMBS
     *                 [ t0 ][ t1 ][ t2 ] [ t3 ][ t4 ][ t5 ]
     *
     * Keep each row's keycodes aligned with this diagram. The right half is
     * passed inner-to-outer, matching LAYOUT_split_3x5_3_ex2's argument order.
     */

    [_BASE] = EX2_LAYOUT(
        //                 LEFT HALF                                  RIGHT HALF
        //             outer ------------> inner                  inner ------------> outer
        // Top row:    [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,  RM_TOGG,    RM_NEXT, KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
        // Home row:   [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G, _______,    _______, KC_M, LSFT_T(KC_N), LALT_T(KC_E), LGUI_T(KC_I), LCTL_T(KC_O),
        // Bottom row: [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ]             [ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_Z, KC_X, KC_C, KC_D, KC_V,    KC_K, KC_H, KC_COMM, KC_DOT, KC_SCLN,
        // Thumb row:                         [ t0 ][ t1 ][ t2 ] [ t3 ][ t4 ][ t5 ]
                          LT(_FUNCTION, KC_ESC), LT(_NUM, KC_TAB), LT(_SYM, KC_ENT),    KC_SPC, OSM(MOD_LSFT), _______
    ),

    [_NUM] = EX2_LAYOUT(
        //                 LEFT HALF                                  RIGHT HALF
        // Top row:    [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_1, KC_2, KC_3, KC_4, KC_5, _______,    _______, KC_6, KC_7, KC_8, KC_9, KC_BSPC,
        // Home row:   [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_LCTL, KC_LGUI, KC_LALT, LSFT_T(KC_DEL), KC_UNDS, _______,    _______, KC_EQL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
        // Bottom row: [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ]             [ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_CIRC, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS,    KC_HOME, KC_END, KC_COMM, KC_DOT, KC_SCLN,
        // Thumb row:                         [ t0 ][ t1 ][ t2 ] [ t3 ][ t4 ][ t5 ]
                          _______, _______, _______,    KC_SPC, KC_0, _______
    ),

    [_SYM] = EX2_LAYOUT(
        //                 LEFT HALF                                  RIGHT HALF
        // Top row:    [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_AT, KC_HASH, KC_DLR, KC_PERC, RALT(KC_5), _______,    _______, RALT(KC_M), RALT(LSFT(KC_S)), RALT(KC_Y), KC_QUES, KC_BSPC,
        // Home row:   [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          RALT(KC_Q), KC_QUOT, RALT(KC_S), LCTL(KC_Z), LCTL(KC_Y), _______,    _______, KC_PGDN, KC_PGUP, KC_LCBR, KC_RCBR, RALT(KC_P),
        // Bottom row: [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ]             [ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_TILD, KC_BSLS, KC_AMPR, KC_PIPE, RALT(KC_COLN),    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_EXLM,
        // Thumb row:                         [ t0 ][ t1 ][ t2 ] [ t3 ][ t4 ][ t5 ]
                          _______, _______, _______,    KC_SPC, KC_LSFT, _______
    ),

    // Function, mouse, and media controls (legacy layer 3).
    // QK_BOOT remains on the outermost top-row key on the right half.
    [_FUNCTION] = EX2_LAYOUT(
        //                 LEFT HALF                                  RIGHT HALF
        // Top row:    [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,    _______, KC_F11, KC_F12, MS_WHLD, MS_WHLU, QK_BOOT,
        // Home row:   [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ][ L5 ]      [ R5 ][ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX, _______,    _______, XXXXXXX, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT,
        // Bottom row: [ L0 ][ L1 ][ L2 ][ L3 ][ L4 ]             [ R4 ][ R3 ][ R2 ][ R1 ][ R0 ]
                          KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,    KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
        // Thumb row:                         [ t0 ][ t1 ][ t2 ] [ t3 ][ t4 ][ t5 ]
                          _______, _______, _______,    MS_BTN1, MS_BTN2, MS_BTN3
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =
    {
        ENCODER_CCW_CW(RM_NEXT, RM_PREV),
        ENCODER_CCW_CW(RM_HUEU, RM_HUED),
        ENCODER_CCW_CW(RM_VALU, RM_VALD),
        ENCODER_CCW_CW(RM_SATU, RM_SATD),
    },
    [1] =
    {
        ENCODER_CCW_CW(RM_NEXT, RM_PREV),
        ENCODER_CCW_CW(RM_HUEU, RM_HUED),
        ENCODER_CCW_CW(RM_VALU, RM_VALD),
        ENCODER_CCW_CW(RM_SATU, RM_SATD),
    },
    [2] =
    {
        ENCODER_CCW_CW(RM_NEXT, RM_PREV),
        ENCODER_CCW_CW(RM_HUEU, RM_HUED),
        ENCODER_CCW_CW(RM_VALU, RM_VALD),
        ENCODER_CCW_CW(RM_SATU, RM_SATD),
    },
    [3] =
    {
        ENCODER_CCW_CW(RM_NEXT, RM_PREV),
        ENCODER_CCW_CW(RM_HUEU, RM_HUED),
        ENCODER_CCW_CW(RM_VALU, RM_VALD),
        ENCODER_CCW_CW(RM_SATU, RM_SATD),
    },
};
#endif

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUM, KC_TAB):
        case LT(_SYM, KC_ENT):
        case KC_LSFT:
        case LT(_FUNCTION, KC_ESC):
            return true;
        default: return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYM, KC_ENT): return 150;
        default: return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUM, KC_TAB):
        case LT(_SYM, KC_ENT):
        case LT(_FUNCTION, KC_ESC):
            return 0;
        default: return QUICK_TAP_TERM;
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GRV:
        case KC_COMM:
        case KC_DOT:
        case KC_SCLN: return true;
        default: return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    if (shifted) add_weak_mods(MOD_BIT(KC_LSFT));
    register_code16(IS_RETRO(keycode) ? keycode & 0xFF : keycode);
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    unregister_code16(IS_RETRO(keycode) ? keycode & 0xFF : keycode);
}
