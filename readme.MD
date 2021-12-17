
# MAIN STRUCTURE

* keypad_t: Representation of a physical keypad

# MAIN STRUCTURE ATTRIBUTES

| attribute| type | Description|
|------|------|------|
| rows | uint8_t | number of rows |
| columns | uint8_t | number of columns |
| row_as_Input | keypad_row_as_Input_fn | function to configure an specific row as input |
| row_as_OutputLow | keypad_row_as_OutputLow_fn | funtion to configure an specific row as output and in low state |
| get_column_value | keypad_get_column_value_fn | function to read logic state from an specific column |

# ADITIONAL STRUCTURES