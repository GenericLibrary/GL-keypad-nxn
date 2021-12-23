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

    typedef enum
    {
        KEYPAD_OK,
        KEYPAD_INIT_PERIPH_ERR,
        KEYPAD_DEINIT_PERIPH_ERR,
    } keypad_error_t;

    typedef bool (*keypad_init_periph_fn)(void);                   //set by user (mandatory)
    typedef bool (*keypad_deinit_periph_fn)(void);                 //set by user (mandatory)
    typedef void (*keypad_row_as_Input_fn)(uint8_t row);           //set by user (mandatory)
    typedef void (*keypad_row_as_OutputLow_fn)(uint8_t row);       //set by user (mandatory)
    typedef uint8_t (*keypad_get_column_value_fn)(uint8_t column); //set by user (mandatory)
    typedef void (*keypad_delay_ms_fn)(int ms);                    //set by user (optional for test)

    typedef struct
    {
        uint8_t rows;
        uint8_t columns;
        keypad_init_periph_fn init_periph;
        keypad_deinit_periph_fn deinit_periph;
        keypad_row_as_Input_fn row_as_Input;
        keypad_row_as_OutputLow_fn row_as_OutputLow;
        keypad_get_column_value_fn get_column_value;
        keypad_delay_ms_fn delay_ms;
    } keypad_t;

    keypad_error_t init_keypad(keypad_t *keypad);
    keypad_error_t deinit_keypad(keypad_t *keypad);
    keypad_error_t scan_keypad(keypad_t *keypad, keypad_keyPos_t *keyPos);

#ifdef __cplusplus
}
#endif

#endif /* _KEYPAD_NXN_H_ */