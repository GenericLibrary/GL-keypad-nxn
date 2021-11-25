#include "keypad-nxn.h"

void init_keypad(keypad_t *keypad)
{
    uint8_t rows = keypad->rows;
    for (uint8_t i = 1; i <= rows; i++)
    {
        keypad->row_as_Input(i);
    }
}

keypad_keyPos_t scan_keypad(keypad_t *keypad)
{
    keypad_keyPos_t result = {-1, -1};
    uint8_t rows = keypad->rows;
    uint8_t columns = keypad->columns;

    for (uint8_t i = 1; i <= rows; i++)
    {
        keypad->row_as_OutputLow(i);

        bool key_pressed = false;
        for (uint8_t j = 1; j <= columns; j++)
        {
            key_pressed = (keypad->get_column_value(j) == 0);
            if (key_pressed)
            {
                result.row = i;
                result.column = j;
                break;
            }
        }

        keypad->row_as_Input(i);

        if (key_pressed)
        {
            break;
        }
    }

    return result;
}