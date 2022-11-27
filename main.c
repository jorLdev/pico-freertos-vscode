/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

void led_task( void * ptr )
{
    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(1000);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(500);
    }
}

int main() {
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("WiFi init failed");
        assert(1);
        return -1;
    }

    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);

    vTaskStartScheduler();
    
    while (true) {}
}