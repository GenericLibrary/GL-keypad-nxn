#include "unity.h"
#include "unity_fixture.h"
#include "esp_system.h"
#include "stdio.h"
#include "runtime_error.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "keypad-nxn.h"

TEST_GROUP(keypad_driver);

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

TEST_SETUP(keypad_driver)
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
}

TEST_TEAR_DOWN(keypad_driver)
{
    gpio_reset_pin(15);
    gpio_reset_pin(2);
    gpio_reset_pin(4);
    gpio_reset_pin(5);
    gpio_reset_pin(18);
    gpio_reset_pin(19);
    gpio_reset_pin(21);
    gpio_reset_pin(22);

    mykeypad.rows = 0;
    mykeypad.columns = 0;
    mykeypad.row_as_Input = NULL;
    mykeypad.row_as_OutputLow = NULL;
    mykeypad.get_column_value = NULL;
}

TEST_GROUP_RUNNER(keypad_driver)
{
    RUN_TEST_CASE(keypad_driver, AllButtons_Works_OnceAtATime);
}

TEST(keypad_driver, AllButtons_Works_OnceAtATime)
{
    bool correct_button_pressed = true;
    uint8_t rows = mykeypad.rows;
    uint8_t columns = mykeypad.columns;

    for (uint8_t i = 1; i <= rows; i++)
    {
        for (uint8_t j = 1; j <= columns; j++)
        {
            printf("\nPRESS row:%i and column:%i for 5 seconds\n", i, j);
            vTaskDelay(pdMS_TO_TICKS(3500));

            keypad_keyPos_t result = {-1, -1};
            result = scan_keypad(&mykeypad);

            if ((result.row != i) || (result.column != j))
            {
                printf("i = %i, j = %i\n", i, j);
                printf("result i = %i, result j = %i\n", result.row, result.column);
                correct_button_pressed = false;
                break;
            }
            
            printf("BUTTON DETECTED. FREE BUTTON\n\n");
            vTaskDelay(pdMS_TO_TICKS(1500));
        }
        if (!correct_button_pressed)
            break;
    }

    TEST_ASSERT_EQUAL(true, correct_button_pressed);
}
