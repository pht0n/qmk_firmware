#pragma once

// Preserve the new keyboard's Vial identity and unlock chord.
#define VIAL_KEYBOARD_UID {0x89, 0x36, 0x2A, 0xC7, 0xFA, 0xD8, 0x89, 0x45}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {1, 2}

// Old keymap behavior.
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define COMBO_COUNT 9
#define COMBO_TERM 30
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL
#define ONESHOT_TIMEOUT 1000
