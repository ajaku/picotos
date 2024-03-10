// This was inspired by Cooper Union's existing ember tasking system
#include <FreeRTOS.h> 
#include <task.h> 
#include <semphr.h> 
#include <stdio.h> 
#include <timers.h>
#include "pico/stdlib.h"

#define WAIT_TIME 100 // in ms 

static SemaphoreHandle_t xSemph_10Hz  = NULL;
static SemaphoreHandle_t xSemph_1Hz   = NULL;

TimerHandle_t timer_handle;

void timer_callback(TimerHandle_t t) {
	static int counter = 0;	
	counter++;

	if (counter %1 == 0) {
		xSemaphoreGiveFromISR(xSemph_10Hz, NULL);
	}

	if (counter %10 == 0) {
		xSemaphoreGiveFromISR(xSemph_1Hz, NULL);
		counter = 0;
	}
}

static void task_10Hz() {
	for (;;) {
		if (xSemaphoreTake(xSemph_10Hz, portMAX_DELAY ) == pdTRUE) {
			printf("10Hz\n");	
			// add more functions here
		}
	}
}

static void task_1Hz() {
	for (;;) {
		if (xSemaphoreTake(xSemph_1Hz, portMAX_DELAY ) == pdTRUE) {
			printf("1Hz\n");	
			// add more functions here
		}
	}
}

// Create the tasks and semaphores for each task
int main() {
	stdio_init_all();

	xSemph_10Hz = xSemaphoreCreateBinary();
	if (xSemph_10Hz == NULL) { return 1; }

	xSemph_1Hz = xSemaphoreCreateBinary();
	if (xSemph_1Hz == NULL) { return 1; }

	static TaskHandle_t task_10Hz_h;
	static TaskHandle_t task_1Hz_h;

	xTaskCreate(task_10Hz,  "10Hz Task",  1024, NULL, 3, &task_10Hz_h); 
	xTaskCreate(task_1Hz,   "1Hz Task",   1024, NULL, 4, &task_1Hz_h); 

	timer_handle = xTimerCreate("Rate function timer",
								pdMS_TO_TICKS(WAIT_TIME),
								pdTRUE,
								0,
								timer_callback);

	if (timer_handle == NULL) { 
		printf("Couldn't create timer\n");
		return 1; 
	}

	if (xTimerStart(timer_handle, 0) != pdTRUE) { 
		printf("Couldn't start timer\n");
		return 1; 
	}

	// Now that the tasks have been created we need to give them and take them
	vTaskStartScheduler();

	// Shouldn't, get here
	for(;;);
}
