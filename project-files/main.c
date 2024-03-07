#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

#define GPIO_ON  1
#define GPIO_OFF 0
#define LED_PIN  25

void loop();

void my_gpio_put(int pin, int val) {
    gpio_put(pin, val);
    return;
}

int main(int argc, char **argv) {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, GPIO_ON);
    loop();
}
