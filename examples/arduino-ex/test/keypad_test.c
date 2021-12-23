#include "../unity/unity_config.h"
#include "../unity/unity.h"
#include "../unity/unity_fixture.h"
#include "stdio.h"
#include "keypad-nxn.h"

TEST_GROUP(keypad_driver);

keypad_t *testkeypad;

TEST_SETUP(keypad_driver)
{
    init_keypad(testkeypad);
}

TEST_TEAR_DOWN(keypad_driver)
{
    deinit_keypad(testkeypad);
}

TEST_GROUP_RUNNER(keypad_driver)
{
    RUN_TEST_CASE(keypad_driver, AllButtons_OneByOnePressedByUser);
}

TEST(keypad_driver, AllButtons_OneByOnePressedByUser)
{
    bool correct_button_pressed = true;
    uint8_t rows = testkeypad->rows;
    uint8_t columns = testkeypad->columns;

    for (uint8_t i = 1; i <= rows; i++)
    {
        for (uint8_t j = 1; j <= columns; j++)
        {
            TEST_PRINTF("\nPRESS row:%i and column:%i for 5 seconds\n", i, j);
            testkeypad->delay_ms(3500);

            keypad_keyPos_t keypos;
            scan_keypad(testkeypad, &keypos);

            if ((keypos.row != i) || (keypos.column != j))
            {
                TEST_PRINTF("expected i = %i, j = %i\n", i, j);
                TEST_PRINTF("pressed i = %i, j = %i\n", keypos.row, keypos.column);
                correct_button_pressed = false;
                break;
            }

            TEST_PRINTF("BUTTON DETECTED. RELEASE BUTTON\n\n");
            testkeypad->delay_ms(1500);
        }
        if (!correct_button_pressed)
            break;
    }

    TEST_ASSERT_EQUAL(true, correct_button_pressed);
}
