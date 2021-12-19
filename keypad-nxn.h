#ifndef _KEYPAD_NXN_H_
#define _KEYPAD_NXN_H_

#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        int row;
        int column;
    } keypad_keyPos_t;

    typedef void (*keypad_row_as_Input_fn)(uint8_t row);           //set by user
    typedef void (*keypad_row_as_OutputLow_fn)(uint8_t row);       //set by user
    typedef uint8_t (*keypad_get_column_value_fn)(uint8_t column); //set by user

    typedef struct
    {
        uint8_t rows;
        uint8_t columns;
        keypad_row_as_Input_fn row_as_Input;
        keypad_row_as_OutputLow_fn row_as_OutputLow;
        keypad_get_column_value_fn get_column_value;
    } keypad_t;

    void init_keypad(keypad_t *keypad);
    keypad_keyPos_t scan_keypad(keypad_t *keypad);

#ifdef __cplusplus
}
#endif

#endif /* _KEYPAD_NXN_H_ */