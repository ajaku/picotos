#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

void task_1(void *pvParameters) {
    while (true) {
        printf("Task 1 is running\n");
        vTaskDelay(100);
    }
}

void task_2(void *pvParameters) {
    while (true) {
        printf("Task 2 is running\n");
        vTaskDelay(100);
    }
}

int main()
{
    stdio_init_all();

    xTaskCreate(task_1, "Task_1", 256, NULL, 1, NULL);
    xTaskCreate(task_2, "Task_2", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}
