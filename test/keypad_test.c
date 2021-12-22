#include "unity.h"
#include "unity_fixture.h"
#include "stdio.h"
#include "runtime_error.h"
#include "keypad-nxn.h"

TEST_GROUP(keypad_driver);

keypad_t mykeypad;
extern const int rons_number;
extern const int cols_number;

extern void init_periph();
extern void deinit_periph();
extern void row_as_input(uint8_t row);
extern void row_as_output_low(uint8_t row);
extern uint8_t get_column_value(uint8_t column);
extern void delay_ms(int ms);

TEST_SETUP(keypad_driver)
{
    // Init peripherals asociated to the keypad:
    // all columns as "INPUT PULL_UP"
    // all rows as " FLOATING INPUT"
    init_periph();

    // Create a variable of type "keypad_t" and define each of its attributes
    mykeypad.rows = rons_number;
    mykeypad.columns = cols_number;
    mykeypad.row_as_Input = row_as_input;
    mykeypad.row_as_OutputLow = row_as_output_low;
    mykeypad.get_column_value = get_column_value;

    // Call "init_keypad" to initialize the keypad. In this case it does nothing
    init_keypad(&mykeypad);
}

TEST_TEAR_DOWN(keypad_driver)
{
    deinit_periph();

    // deinit keypad object
    mykeypad.rows = 0;
    mykeypad.columns = 0;
    mykeypad.row_as_Input = NULL;
    mykeypad.row_as_OutputLow = NULL;
    mykeypad.get_column_value = NULL;
}

TEST_GROUP_RUNNER(keypad_driver)
{
    RUN_TEST_CASE(keypad_driver, AllButtons_OneByOnePressedByUser);
}

TEST(keypad_driver, AllButtons_OneByOnePressedByUser)
{
    bool correct_button_pressed = true;
    uint8_t rows = mykeypad.rows;
    uint8_t columns = mykeypad.columns;

    for (uint8_t i = 1; i <= rows; i++)
    {
        for (uint8_t j = 1; j <= columns; j++)
        {
            printf("\nPRESS row:%i and column:%i for 5 seconds\n", i, j);
            delay_ms(3500);

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
            delay_ms(1500);
        }
        if (!correct_button_pressed)
            break;
    }

    TEST_ASSERT_EQUAL(true, correct_button_pressed);
}
