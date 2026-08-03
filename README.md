# wmenu-dwlb

Fork of [wmenu](https://git.sr.ht/~adnano/wmenu), a Wayland-native dmenu replacement, optimized for `dwl` and `dwlb`.

## Core Features

### 1. Integrated Positioning Modes
- **Title Bar Mode (`-t`)**: Positions the menu seamlessly inside the `dwlb` status bar by reading coordinates from `/tmp/dwlb-geometry`.
- **Centered Mode (`-c`)**: Creates a centered floating popup with a fixed minimum width (800px) and dynamic height, ideal for clipboard pickers and app launchers.

### 2. Image Preview Protocol (Cairo Rendering)
This fork introduces a native Cairo-based PNG rendering engine. It allows inline image thumbnails within the menu items.

**Protocol**: `[img:/path/to/image.png] Item Text`
- If an item starts with `[img:path]`, `wmenu-dwlb` renders the image as a 96x96 thumbnail.
- The `[img:path]` prefix is stripped before the selection is outputted to stdout.

### 3. Dynamic Height Calculation
To prevent items from being cut off (especially when mixing images and text), the menu dynamically calculates its surface height based on the number of items and their type (thumbnail vs. text), capped at 15 entries.

## Configuration (`config.h`)
Colors and bar dimensions are defined at compile-time to ensure a consistent theme without bloated runtime flags.

```c
static const unsigned int dwlb_middle_bg  = 0xbd93f9ff; /* Bar background */
static const unsigned int dwlb_middle_fg  = 0xf8f8f2ff; /* Bar foreground */
static const unsigned int dwlb_bar_height = 30;
```

## Installation
```bash
cp config.h.example config.h
# edit config.h to match your theme
rm -rf build
meson setup build
ninja -C build
sudo ninja -C build install
```

## Example Usage: Clipboard Picker
Combine with `kapc` (text) and `cclip` (images) for a powerful clipboard manager:

```bash
# Example integrated pipeline (see contrib/clipboard-pick.sh)
{
    kapc search "" -L
    # Imagine loop generating [img:/tmp/kt/id.png] id
} | wmenu -c -l 15 -p "clip:"
```
