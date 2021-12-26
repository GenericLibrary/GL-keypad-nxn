#include "mcc_generated_files/system/system.h"
#include "software_tx.h"
#include "util/delay.h"
#include <stdio.h>
#include "../../keypad-nxn.h"
#include "../../keypad-nxn.c"

#define TEST_PROJECT
//#define APP_PROJECT

#ifdef TEST_PROJECT
int mainTest(void);
#endif

#define ROW1 a7
#define ROW2 a6
#define ROW3 a5
#define ROW4 a4
#define COL1 a3
#define COL2 a2
#define COL3 a1
#define COL4 a0

keypad_t mykeypad;
const uint8_t keypad_rows_number = 4;
const uint8_t keypad_cols_number = 4;
bool keypad_init_periph() {
    // all columns as "INPUT PULL_UP"
    /*
    C1_SetDigitalInput();
    C1_SetPullUp();
    C2_SetDigitalInput();
    C2_SetPullUp();
    C3_SetDigitalInput();
    C3_SetPullUp();
    C4_SetDigitalInput();
    C4_SetPullUp();

    // all rows as " FLOATING INPUT"
    R1_SetDigitalInput();
    R2_SetDigitalInput();
    R3_SetDigitalInput();
    R4_SetDigitalInput();
*/
    return true;
}
bool keypad_deinit_periph() {/*
    C1_ResetPullUp();
    C2_ResetPullUp();
    C3_ResetPullUp();
    C4_ResetPullUp();
    R1_SetDigitalInput();
    R2_SetDigitalInput();
    R3_SetDigitalInput();
    R4_SetDigitalInput();*/
    return true;
}
void row_as_input(uint8_t row) {
    switch (row) {
        case 1:
            R1_SetDigitalInput();
            break;
        case 2:
            R2_SetDigitalInput();
            break;
        case 3:
            R3_SetDigitalInput();
            break;
        case 4:
            R4_SetDigitalInput();
            break;
        default:
            break;
    }
}
void row_as_output_low(uint8_t row) {
    switch (row) {
        case 1:
            R1_SetDigitalOutput();
            R1_SetLow();
            break;
        case 2:
            R2_SetDigitalOutput();
            R2_SetLow();
            break;
        case 3:
            R3_SetDigitalOutput();
            R3_SetLow();
            break;
        case 4:
            R4_SetDigitalOutput();
            R4_SetLow();
            break;
        default:
            break;
    }
}
uint8_t get_column_value(uint8_t column) {
    switch (column) {
        case 1:
            return (uint8_t) C1_GetValue();
        case 2:
            return (uint8_t) C2_GetValue();
        case 3:
            return (uint8_t) C3_GetValue();
        case 4:
            return (uint8_t) C4_GetValue();
        default:
            return 0;
    }
}
void keypad_delay_ms(int ms) {
    for (int i = 0; i < ms; i++)
        _delay_ms(1);
}

int main(void) {

    // Init peripherals asociated to the keypad:
    // all columns as "INPUT PULL_UP"
    // all rows as " FLOATING INPUT"
    SYSTEM_Initialize();

    // Create a variable of type "keypad_t" and define each of its attributes  
    mykeypad.rows = keypad_rows_number;
    mykeypad.columns = keypad_cols_number;
    mykeypad.init_periph = keypad_init_periph;
    mykeypad.deinit_periph = keypad_deinit_periph;
    mykeypad.row_as_Input = row_as_input;
    mykeypad.row_as_OutputLow = row_as_output_low;
    mykeypad.get_column_value = get_column_value;
    mykeypad.delay_ms = keypad_delay_ms;

    // Call "init_keypad" to initialize the keypad. In this case it does nothing
    init_keypad(&mykeypad);

#ifdef APP_PROJECT
    char bufer[100] = {0};
    sprintf(bufer, "PRESS KEYS:\n\r");
    software_uart_print_string(bufer);
#endif
#ifdef TEST_PROJECT  
    return mainTest();
#endif

    while (1) {
#ifdef APP_PROJECT
        //Call "scan_keypad" to check if any key is pressed
        keypad_keyPos_t key;
        scan_keypad(&mykeypad, &key);
        if (key.row != -1 && key.column != -1) {
            sprintf(bufer, "key pressed: r%i,c%i \n\r", key.row, key.column);
            software_uart_print_string(bufer);
        }

        _delay_ms(1000);
#endif
    }
}
