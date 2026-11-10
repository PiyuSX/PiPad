# pipad

Wired 3x3 macropad for the Seeed XIAO RP2040.

* Keyboard Maintainer: [Piyush Rajbanshi](https://github.com/PiyuSX)
* Hardware Supported: Seeed XIAO RP2040, 9 MX switches, EC11 encoder, 128x32 SSD1306 OLED
* Hardware Availability: private project, not for sale

QMK **0.34.7**

    qmk compile -kb pipad -km default

Flash by holding BOOT on the XIAO, then copy `pipad_default.uf2` onto the RPI-RP2 drive.

## Bootloader

* **Bootmagic reset**: hold the top-left key and plug in USB
* **Physical reset**: hold the BOOT button on the XIAO and plug in USB
* **Keycode**: `QK_BOOT` is not on the keymap