#include "pico/stdlib.h"


#define LED_PIN 25

<<<<<<< Updated upstream
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
=======
int main() { 
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (1) {
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
    }
}
>>>>>>> Stashed changes
