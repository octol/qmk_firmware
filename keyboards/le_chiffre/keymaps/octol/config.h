/* Copyright 2020 keyboard-magpie
 * Copyright 2020 Jon Häggblad
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

#pragma once

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 14
#    define COMBO_TERM 30
#endif

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// NOTES: no PERMISSIVE_HOLD and TAPPING_TERM 150, or PERMISSIVE_HOLD and TAPPING_TERM 200

// If you press a dual-function modifier key (such as "Ctrl when held, Z when tapped"),
// press another key (such as "X"), release the modifier key, and then release the normal
// key, it would normally output the modded key ("Ctrl+X" in this case)... [Ignore mod
// tap] makes sure that both keys are sent (eg "zx") unless both keys are held for the
// Tapping Term.
#define IGNORE_MOD_TAP_INTERRUPT

// Normally if you press a Mod Tap key, tap another key (press and release) and then release the
// Mod Tap key, all within the tapping term, it will output the tapping function for both
// keys. This changes it to output the mod.
#define PERMISSIVE_HOLD

// When the user holds a key after tapping it, the tapping function is repeated by
// default, rather than activating the hold function. This allows keeping the ability to
// auto-repeat the tapping function of a dual-role key. TAPPING_FORCE_HOLD removes that
// ability to let the user activate the hold function instead, in the case of holding the
// dual-role key after having tapped it.
//#define TAPPING_FORCE_HOLD

// Holding and releasing a dual function key without pressing another key will result in
// nothing happening. With retro tapping enabled, releasing the key without pressing
// another will send the original keycode even if it is outside the tapping term.
//#define RETRO_TAPPING
