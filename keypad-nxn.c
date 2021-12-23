#include "keypad-nxn.h"

keypad_error_t init_keypad(keypad_t *keypad)
{
    bool res = keypad->init_periph();
    if (res == false)
        return KEYPAD_INIT_PERIPH_ERR;

    return KEYPAD_OK;
}

keypad_error_t deinit_keypad(keypad_t *keypad)
{
    bool res = keypad->deinit_periph();
    if (res == false)
        return KEYPAD_DEINIT_PERIPH_ERR;

    return KEYPAD_OK;
}

keypad_error_t scan_keypad(keypad_t *keypad, keypad_keyPos_t *keyPos)
{
    keyPos->row = -1;
    keyPos->column = -1;
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
                keyPos->row = i;
                keyPos->column = j;
                break;
            }
        }

        keypad->row_as_Input(i);

        if (key_pressed)
        {
            break;
        }
    }

    return KEYPAD_OK;
}