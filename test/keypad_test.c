#if defined(ESP_PLATFORM)
#include "unity.h"
#include "unity_fixture.h"
#endif
#include "stdio.h"

TEST_GROUP(keypad_driver);

keypad_t *testkeypad;

TEST_SETUP(keypad_driver) {
    init_keypad(testkeypad);
}

TEST_TEAR_DOWN(keypad_driver) {
    deinit_keypad(testkeypad);
}

TEST(keypad_driver, AllButtons_OneByOnePressedByUser) {

    bool correct_button_pressed = true;
    uint8_t rows = testkeypad->rows;
    uint8_t columns = testkeypad->columns;

    for (uint8_t i = 1; i <= rows; i++) {
        for (uint8_t j = 1; j <= columns; j++) {
            UNITY_PRINT_EOL();
            UnityPrint("PRESS row :");
            UnityPrintNumber(i);
            UnityPrint(" and column:");
            UnityPrintNumber(j);
            UnityPrint(" for 5 seconds");
            UNITY_PRINT_EOL();
            testkeypad->delay_ms(5500);

            keypad_keyPos_t keypos;
            scan_keypad(testkeypad, &keypos);

            if ((keypos.row != i) || (keypos.column != j)) {
                UnityPrint("expected i= ");
                UnityPrintNumber(i);
                UnityPrint(" j=");
                UnityPrintNumber(j);
                UNITY_PRINT_EOL();

                UnityPrint("pressed i= ");
                UnityPrintNumber(keypos.row);
                UnityPrint(" j=");
                UnityPrintNumber(keypos.column);
                UNITY_PRINT_EOL();
                correct_button_pressed = false;
                break;
            }

            UnityPrint("BUTTON DETECTED. RELEASE BUTTON");
            UNITY_PRINT_EOL();
            testkeypad->delay_ms(1500);
        }
        if (!correct_button_pressed)
            break;
    }

    TEST_ASSERT_EQUAL(true, correct_button_pressed);
}

TEST_GROUP_RUNNER(keypad_driver) {
    RUN_TEST_CASE(keypad_driver, AllButtons_OneByOnePressedByUser);
}
