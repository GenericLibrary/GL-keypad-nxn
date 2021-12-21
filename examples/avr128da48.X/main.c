
#include "mcc_generated_files/system/system.h"
#include "software_tx.h"
#include "util/delay.h"
#include <stdio.h>
#include "../../keypad-nxn.h"
#include "../../keypad-nxn.c"

#define ROWS_NUMBER 4
#define ROW1 a7
#define ROW2 a6
#define ROW3 a5
#define ROW4 a4
#define COLS_NUMBER 4
#define COL1 a3
#define COL2 a2
#define COL3 a1
#define COL4 a0

keypad_t mykeypad;

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

int main(void) {

    // Init peripherals asociated to the keypad:
    // all columns as "INPUT PULL_UP"
    // all rows as " FLOATING INPUT"
    SYSTEM_Initialize();

    // Create a variable of type "keypad_t" and define each of its attributes  
    mykeypad.rows = ROWS_NUMBER;
    mykeypad.columns = COLS_NUMBER;
    mykeypad.row_as_Input = row_as_input;
    mykeypad.row_as_OutputLow = row_as_output_low;
    mykeypad.get_column_value = get_column_value;

    // Call "init_keypad" to initialize the keypad. In this case it does nothing
    init_keypad(&mykeypad);

    char bufer[100] = {0};
    sprintf(bufer, "PRESS KEYS:\n\r");
    software_uart_print_string(bufer);

    while (1) {

        //Call "scan_keypad" to check if any key is pressed
        keypad_keyPos_t key = scan_keypad(&mykeypad);
        if (key.row != -1 && key.column != -1) {
            sprintf(bufer, "key pressed: r%i,c%i \n\r", key.row, key.column);
             software_uart_print_string(bufer);
        }
       
        _delay_ms(1000);
    }
}
