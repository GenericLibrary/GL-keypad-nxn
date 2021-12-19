#include "keypad-nxn.h"

#define ROWS_NUMBER 4
#define ROW1 22
#define ROW2 24
#define ROW3 26
#define ROW4 28
#define COLS_NUMBER 4
#define COL1 30
#define COL2 32
#define COL3 34
#define COL4 36

keypad_t mykeypad;

void row_as_input(uint8_t row)
{
  switch (row)
  {
  case 1:
    pinMode(ROW1, INPUT);
    break;
  case 2:
    pinMode(ROW2, INPUT);
    break;
  case 3:
    pinMode(ROW3, INPUT);
    break;
  case 4:
    pinMode(ROW4, INPUT);
    break;
  default:
    break;
  }
}
void row_as_output_low(uint8_t row)
{
  switch (row)
  {
  case 1:
    pinMode(ROW1, OUTPUT);
    digitalWrite(ROW1, LOW);
    break;
  case 2:
    pinMode(ROW2, OUTPUT);
    digitalWrite(ROW2, LOW);
    break;
  case 3:
    pinMode(ROW3, OUTPUT);
    digitalWrite(ROW3, LOW);
    break;
  case 4:
    pinMode(ROW4, OUTPUT);
    digitalWrite(ROW4, LOW);
    break;
  default:
    break;
  }
}
uint8_t get_column_value(uint8_t column)
{
  switch (column)
  {
  case 1:
    return (uint8_t)digitalRead(COL1);
  case 2:
    return (uint8_t)digitalRead(COL2);
  case 3:
    return (uint8_t)digitalRead(COL3);
  case 4:
    return (uint8_t)digitalRead(COL4);
  default:
    return 0;
  }
}

void setup()
{
  // Init peripherals asociated to the keypad:
  // all columns as "INPUT PULL_UP"
  pinMode(COL1, INPUT_PULLUP);
  pinMode(COL2, INPUT_PULLUP);
  pinMode(COL3, INPUT_PULLUP);
  pinMode(COL4, INPUT_PULLUP);

  // all rows as " FLOATING INPUT"
  pinMode(ROW1, INPUT);
  pinMode(ROW2, INPUT);
  pinMode(ROW3, INPUT);
  pinMode(ROW4, INPUT);

  // Create a variable of type "keypad_t" and define each of its attributes  
  mykeypad.rows = ROWS_NUMBER;
  mykeypad.columns = COLS_NUMBER;
  mykeypad.row_as_Input = row_as_input;
  mykeypad.row_as_OutputLow = row_as_output_low;
  mykeypad.get_column_value = get_column_value;

  // Call "init_keypad" to initialize the keypad. In this case it does nothing
  init_keypad(&mykeypad);

  printf("\nPRESS KEYS:\n");
}

void loop()
{
  //Call "scan_keypad" to check if any key is pressed
  keypad_keyPos_t key = scan_keypad(&mykeypad);
  if (key.row != -1 && key.column != -1)
  {
    printf("key pressed: %d, %d\n", key.row, key.column);
  }
  delay(1000);
}
