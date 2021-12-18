#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <stdio.h>
#include "esp_system.h"
#include "keypad-nxn.h"

keypad_t mykeypad;

void row_as_input(uint8_t row)
{
    switch (row)
    {
    case 1:
        gpio_set_direction(18, GPIO_MODE_INPUT);
        break;
    case 2:
        gpio_set_direction(19, GPIO_MODE_INPUT);
        break;
    case 3:
        gpio_set_direction(21, GPIO_MODE_INPUT);
        break;
    case 4:
        gpio_set_direction(22, GPIO_MODE_INPUT);
        break;
    default:
        break;
    }
}
void row_as_output_low(uint8_t row)
{
    switch (row)
    {
    case 1:
        gpio_set_direction(18, GPIO_MODE_OUTPUT);
        gpio_set_level(18, 0);
        break;
    case 2:
        gpio_set_direction(19, GPIO_MODE_OUTPUT);
        gpio_set_level(19, 0);
        break;
    case 3:
        gpio_set_direction(21, GPIO_MODE_OUTPUT);
        gpio_set_level(21, 0);
        break;
    case 4:
        gpio_set_direction(22, GPIO_MODE_OUTPUT);
        gpio_set_level(22, 0);
        break;
    default:
        break;
    }
}
uint8_t get_column_value(uint8_t column)
{
    switch (column)
    {
    case 1:
        return (uint8_t)gpio_get_level(15);
    case 2:
        return (uint8_t)gpio_get_level(23);
    case 3:
        return (uint8_t)gpio_get_level(4);
    case 4:
        return (uint8_t)gpio_get_level(5);
    default:
        return 0;
    }
}

void app_main(void)
{
    // columns
    gpio_config_t io_conf;
    io_conf.pin_bit_mask = 1ULL << 15;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 23;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 4;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 5;
    gpio_config(&io_conf);

    // rows
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pin_bit_mask = 1ULL << 18;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 19;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 21;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 22;
    gpio_config(&io_conf);

    // keypad object
    mykeypad.rows = 4;
    mykeypad.columns = 4;
    mykeypad.row_as_Input = row_as_input;
    mykeypad.row_as_OutputLow = row_as_output_low;
    mykeypad.get_column_value = get_column_value;
    init_keypad(&mykeypad);

    printf("\nPRESS KEYS:\n");

    while (1)
    {
        keypad_keyPos_t key = scan_keypad(&mykeypad);
        if (key.row != -1 && key.column != -1)
        {
            printf("key pressed: %d, %d\n", key.row, key.column);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
