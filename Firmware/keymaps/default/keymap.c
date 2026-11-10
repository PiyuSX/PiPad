// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───-┬───-┬──-─┐
     * │ F13│ F14│ F15│
     * ├───-┼───-┼──-─┤
     * │ F16│ F17│ F18│
     * ├───-┼───-┼──-─┤
     * │ F19│ F20│ F21│
     * └───-┴───-┴───-┘
     */
     //Profile 1
    [0] = LAYOUT_ortho_3x3(
        KC_F13,    KC_F14,    KC_F15,
        KC_F16,    KC_F17,    KC_F18,
        KC_F19,    KC_F20,    KC_F21
    ),
    //Profile 2
    [1] = LAYOUT_ortho_3x3(
        C(KC_F13),  C(KC_F14),  C(KC_F15),
        C(KC_F16),  C(KC_F17),  C(KC_F18),
        C(KC_F19),  C(KC_F20),  C(KC_F21)
    ),
    //Profile 3
    [2] = LAYOUT_ortho_3x3(
        S(KC_F13),  S(KC_F14),  S(KC_F15),
        S(KC_F16),  S(KC_F17),  S(KC_F18),
        S(KC_F19),  S(KC_F20),  S(KC_F21)
    ),
    //Profile 4
    [3] = LAYOUT_ortho_3x3(
        A(S(KC_F13)),  A(S(KC_F14)),  A(S(KC_F15)),
        A(S(KC_F16)),  A(S(KC_F17)),  A(S(KC_F18)),
        A(S(KC_F19)),  A(S(KC_F20)),  A(S(KC_F21))
    )

};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};

#endif


#define ENC_BTN_PIN GP3


void keyboard_post_init_user(void) {
    gpio_set_pin_input_high(ENC_BTN_PIN);
}

void housekeeping_task_user(void) {
    static bool was_pressed = false;
    static uint32_t last_change = 0;

    bool pressed = !gpio_read_pin(ENC_BTN_PIN);

    if (pressed != was_pressed && timer_elapsed32(last_change) > 30) {
        last_change = timer_read32();
        was_pressed = pressed;

        if (pressed) {
            uint8_t next = (get_highest_layer(layer_state) + 1) % 4;
            layer_move(next);
        }
    }
}

#ifdef OLED_ENABLE

// Used Ai here for the animation
#define CAP_COUNT     4
#define CAP_SLOT     32
#define CAP_X0        4
#define CAP_BASE     24
#define CAP_TOP_INSET 4
#define CAP_TOP_Y    10
#define CAP_BOT_Y    28
#define CAP_PRESS_Y  20
#define ANIM_MS     180


static void draw_h_line(int x0, int x1, int y) {
    if (y < 0 || y >= 32) {
        return;
    }

    if (x0 > x1) {
        int tmp = x0;
        x0 = x1;
        x1 = tmp;
    }
    if (x1 > 127) {
        x1 = 127;
    }

    for (int x = x0; x <= x1; x++) {
        oled_write_pixel((uint8_t)x, (uint8_t)y, true);
    }
}

static void fill_trap(int x_tl, int x_tr, int y_top, int x_bl, int x_br, int y_bot) {
    if (y_bot < y_top) {
        int tmp = y_bot;
        y_bot = y_top;
        y_top = tmp;
    }
    if (y_bot == y_top) {
        draw_h_line(x_bl < x_tl ? x_bl : x_tl, x_br > x_tr ? x_br : x_tr, y_top);
        return;
    }

    for (int y= y_top; y <= y_bot; y++) {
        int num = y - y_top;
        int den = y_bot - y_top;
        int xl = x_tl + (x_bl - x_tl) * num / den;
        int xr = x_tr + (x_br - x_tr)  * num / den;
        draw_h_line(xl, xr, y);
    }
}


/* press 0 = standing key, 255 = fully pressed bar */
static void draw_key(uint8_t index, uint8_t press) {
    int bx = CAP_X0 + (int)index * CAP_SLOT;

    int stand_tl = bx + CAP_TOP_INSET;
    int stand_tr = bx + CAP_BASE - CAP_TOP_INSET;
    int press_tl = bx;
    int press_tr = bx + CAP_BASE;

    int y_top = CAP_TOP_Y + ((CAP_PRESS_Y - CAP_TOP_Y) * (int)press) / 255;
    int x_tl  = stand_tl + ((press_tl - stand_tl) * (int)press) / 255;
    int x_tr  = stand_tr + ((press_tr - stand_tr) * (int)press) / 255;

    fill_trap(x_tl, x_tr, y_top, bx, bx + CAP_BASE, CAP_BOT_Y);
}

bool oled_task_user(void) {
    static uint8_t  last_layer = 0xFF;
    static uint8_t  anim_from  = 0;
    static uint32_t anim_start = 0;

    uint8_t current = get_highest_layer(layer_state);
    if (current > 3) {
        current = 3;
    }

    if (current != last_layer) {
        anim_from  = (last_layer == 0xFF) ? current : last_layer;
        anim_start = timer_read32();
        last_layer = current;
    }

    uint16_t elapsed  = timer_elapsed32(anim_start);
    uint8_t  progress = (elapsed >= ANIM_MS) ? 255 : (uint8_t)((elapsed * 255) / ANIM_MS);

    oled_clear();

    oled_set_cursor(0, 0);
    oled_write_P(PSTR("PiPad"), false);

    for (uint8_t i = 0; i < CAP_COUNT; i++) {
        uint8_t press = 0;
        if (anim_from == current) {
            press = (i == current) ? 255 : 0;
        } else if (elapsed >= ANIM_MS) {
            press = (i == current) ? 255 : 0;
        } else if (i == current) {
            press = progress;
        } else if (i == anim_from) {
            press = 255 - progress;
        }
        draw_key(i, press);
    }

    return false;
}

#endif