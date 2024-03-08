#include "pico/stdlib.h"
#include <FreeRTOS.h>
#include <stdio.h>
#include <task.h>


#define LED_PIN 25

int main()
{
    stdio_init_all();

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }

    //xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    //vTaskStartScheduler();

    //while(1){};
}
