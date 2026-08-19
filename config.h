/* wmenu-caos configuration — flat Dracula launcher (matches dwl bar) */

/* standalone launcher colors — flat dark like dwl bar, purple selection */
static const unsigned int bar_bg     = 0x222222ee; /* dwl SchemeNorm dark */
static const unsigned int bar_fg     = 0xeeeeeeff; /* light text */
static const unsigned int bar_sel_bg = 0xbd93f9dd; /* purple selection */
static const unsigned int bar_sel_fg = 0x1e1e2eff; /* dark text on selection */
static const unsigned int bar_border = 0x222222ee; /* same as bg → flat, no visible frame */

/* on-bar pill colors (dwl IPC bar_geometry active) — flat dark, purple selection */
static const unsigned int bar_pill_bg     = 0x222222ee;
static const unsigned int bar_pill_fg     = 0xeeeeeeff;
static const unsigned int bar_pill_sel_bg = 0xbd93f9dd;
static const unsigned int bar_pill_sel_fg = 0x1e1e2eff;

/* centered launcher box width (-t), floats over the middle of the bar */
static const unsigned int wmenu_width = 720;
