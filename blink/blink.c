/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

int main() {
    const uint LED_PIN_L = 15;
    const uint LED_PIN_R = 16;
    bool L_STATE = true;
    bool R_STATE = true;
    gpio_init(LED_PIN_L);
    gpio_set_dir(LED_PIN_L, GPIO_OUT);
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    while (true) {
        for (int i = 0; i < 3; i++) {
            if (i < 2) {
                gpio_put(LED_PIN_L, L_STATE);
                sleep_ms(500);
                L_STATE = !L_STATE;
                gpio_put(LED_PIN_L, L_STATE);
                sleep_ms(500);
                L_STATE = !L_STATE;
            } else {
                gpio_put(LED_PIN_R, R_STATE);
                sleep_ms(500);
                R_STATE = !R_STATE;
                gpio_put(LED_PIN_R, R_STATE);
                sleep_ms(500);
                R_STATE = !R_STATE;
            }
        }
    }
}
