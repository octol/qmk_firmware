#pragma once

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 16
#    define COMBO_TERM 30
#endif

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD
