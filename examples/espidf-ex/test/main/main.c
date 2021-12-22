#include <stdio.h>
#include <string.h>
#include "unity_fixture.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

const uint8_t rons_number = 4;
const uint8_t cols_number = 4;

void init_periph()
{
    // Init peripherals asociated to the keypad:
    // all columns as "INPUT PULL_UP"
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

    // all rows as " FLOATING INPUT"
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pin_bit_mask = 1ULL << 18;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 19;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 21;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = 1ULL << 22;
    gpio_config(&io_conf);
}
void deinit_periph()
{
    gpio_reset_pin(15);
    gpio_reset_pin(2);
    gpio_reset_pin(4);
    gpio_reset_pin(5);
    gpio_reset_pin(18);
    gpio_reset_pin(19);
    gpio_reset_pin(21);
    gpio_reset_pin(22);
}
void delay_ms(int ms)
{
    vTaskDelay(pdMS_TO_TICKS(ms));
}

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

static void runAllTests(void)
{
    RUN_TEST_GROUP(keypad_driver);
}

void app_main(void)
{
    //const char *args[] = {"main_test.c", "-v", "", "-g", "", "-n", "", "-r", ""};
    const char *args[] = {"main_test.c", "-v", "-g", "keypad_driver", "-r", "1"};

    UnityMain(sizeof(args) / sizeof(char *), args, runAllTests);
    return;
}