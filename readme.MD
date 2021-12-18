
# MAIN STRUCTURE

* keypad_t : Representation of a physical keypad

# MAIN STRUCTURE ATTRIBUTES

| Name| type | Description|
|------|------|------|
| rows | uint8_t | number of rows of the keypad|
| columns | uint8_t | number of columns of the keypad |
| row_as_Input | keypad_row_as_Input_fn | function to configure an specific row as input |
| row_as_OutputLow | keypad_row_as_OutputLow_fn | funtion to configure an specific row as output and in low state |
| get_column_value | keypad_get_column_value_fn | function to read logic state from an specific column |

# ADITIONAL STRUCTURES

| Name| Description|
|------|------|
| keypad_keyPos_t | Contains position (row and column) of an specific key |

# FUNCTIONS
| Name| Input| Output |Description|
|------|------|------|------|
| init_keypad | keypad : pointer to keypad_t | void | Initialize the keypad |
| scan_keypad | keypad : pointer to keypad_t | keypad_keyPos_t | Check if any key is pressed, stops when gets one. Then returns its position |

# HOW TO USE IT

* Init peripherals asociated to the keypad: all rows as " FLOATING INPUT" and all columns as "INPUT PULL_UP".
* Create a variable of type "keypad_t" and define each of its attributes.
* Call "init_keypad" to initialize the keypad. In this case it does nothing.
* Call "scan_keypad" to check if any key is pressed.

* NOTE : CHECK EXAMPLES FOR PRACTICAL USE
