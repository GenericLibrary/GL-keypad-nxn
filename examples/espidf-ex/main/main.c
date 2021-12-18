#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <stdio.h>
#include "esp_system.h"
#include "keypad-nxn.h"

#define ROWS_NUMBER 4
#define ROW1 18
#define ROW2 19
#define ROW3 21
#define ROW4 22
#define COLS_NUMBER 4
#define COL1 15
#define COL2 23
#define COL3 4
#define COL4 5

void row_as_input(uint8_t row)
{
    switch (row)
    {
    case 1:
        gpio_set_direction(ROW1, GPIO_MODE_INPUT);
        break;
    case 2:
        gpio_set_direction(ROW2, GPIO_MODE_INPUT);
        break;
    case 3:
        gpio_set_direction(ROW3, GPIO_MODE_INPUT);
        break;
    case 4:
        gpio_set_direction(ROW4, GPIO_MODE_INPUT);
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
        gpio_set_direction(ROW1, GPIO_MODE_OUTPUT);
        gpio_set_level(ROW1, 0);
        break;
    case 2:
        gpio_set_direction(ROW2, GPIO_MODE_OUTPUT);
        gpio_set_level(ROW2, 0);
        break;
    case 3:
        gpio_set_direction(ROW3, GPIO_MODE_OUTPUT);
        gpio_set_level(ROW3, 0);
        break;
    case 4:
        gpio_set_direction(ROW4, GPIO_MODE_OUTPUT);
        gpio_set_level(ROW4, 0);
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
        return (uint8_t)gpio_get_level(COL1);
    case 2:
        return (uint8_t)gpio_get_level(COL2);
    case 3:
        return (uint8_t)gpio_get_level(COL3);
    case 4:
        return (uint8_t)gpio_get_level(COL4);
    default:
        return 0;
    }
}

void app_main(void)
{   
    // Init peripherals asociated to the keypad:
    // all columns as "INPUT PULL_UP"
    gpio_config_t io_conf;
    io_conf.pin_bit_mask = 1ULL << COL1;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << COL2;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << COL3;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << COL4;
    gpio_config(&io_conf);

    // all rows as " FLOATING INPUT"
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pin_bit_mask = 1ULL << ROW1;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << ROW2;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << ROW3;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << ROW4;
    gpio_config(&io_conf);

    // Create a variable of type "keypad_t" and define each of its attributes
    keypad_t mykeypad;
    mykeypad.rows = ROWS_NUMBER;
    mykeypad.columns = COLS_NUMBER;
    mykeypad.row_as_Input = row_as_input;
    mykeypad.row_as_OutputLow = row_as_output_low;
    mykeypad.get_column_value = get_column_value;

    // Call "init_keypad" to initialize the keypad. In this case it does nothing
    init_keypad(&mykeypad);

    printf("\nPRESS KEYS:\n");

    while (1)
    {
        //Call "scan_keypad" to check if any key is pressed
        keypad_keyPos_t key = scan_keypad(&mykeypad);
        if (key.row != -1 && key.column != -1)
        {
            printf("key pressed: %d, %d\n", key.row, key.column);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
