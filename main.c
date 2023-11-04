#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN     4
#define SWITCH_PIN  2

void app_main() {
    // Configure LED GPIO
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_PIN, 0); // Turn off the LED initially

    // Configure Switch GPIO
    gpio_pad_select_gpio(SWITCH_PIN);
    gpio_set_direction(SWITCH_PIN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(SWITCH_PIN, GPIO_PULLUP_ONLY);

    while (1) {
        // Read the state of the switch
        int switch_state = gpio_get_level(SWITCH_PIN);

        // Update the LED state based on the switch state
        gpio_set_level(LED_PIN, switch_state);

        vTaskDelay(100 / portTICK_PERIOD_MS); // Optional delay for smoother operation
    }
}
