#include "keypad-nxn.h"

#include "unity/unity_config.h"
#include "unity/unity.h"
#include "unity/unity.c"
#include "unity/unity_fixture.h"
#include "unity/unity_fixture.c"

#include "test/keypad_test.c"

// Uncommend just one
//#define TEST_PROJECT
#define APP_PROJECT

const uint8_t keypad_rows_number = 4;
const uint8_t keypad_cols_number = 4;

#define ROW1 22
#define ROW2 24
#define ROW3 26
#define ROW4 28

#define COL1 30
#define COL2 32
#define COL3 34
#define COL4 36

keypad_t mykeypad;
bool keypad_init_periph()
{
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
  return true;
}
bool keypad_deinit_periph()
{
  pinMode(COL1, INPUT);
  pinMode(COL2, INPUT);
  pinMode(COL3, INPUT);
  pinMode(COL4, INPUT);
  pinMode(ROW1, INPUT);
  pinMode(ROW2, INPUT);
  pinMode(ROW3, INPUT);
  pinMode(ROW4, INPUT);
  return true;
}
void keypad_row_as_input(uint8_t row)
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
void keypad_row_as_output_low(uint8_t row)
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
uint8_t keypad_get_column_value(uint8_t column)
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
void keypad_delay_ms(int ms)
{
  for (int i = 0; i < ms; i++)
    delay(1);
}

static void runAllTests(void)
{
 // RUN_TEST_GROUP(keypad_driver);
}

void setup()
{
#ifdef APP_PROJECT

  // Create a variable of type "keypad_t" and define each of its attributes
  mykeypad.rows = keypad_rows_number;
  mykeypad.columns = keypad_cols_number;
  mykeypad.init_periph = keypad_init_periph;
  mykeypad.deinit_periph = keypad_deinit_periph;
  mykeypad.row_as_Input = keypad_row_as_input;
  mykeypad.row_as_OutputLow = keypad_row_as_output_low;
  mykeypad.get_column_value = keypad_get_column_value;
  mykeypad.delay_ms = keypad_delay_ms;

  // Call "init_keypad" to initialize the keypad. In this case it does nothing
  init_keypad(&mykeypad);

  Serial.begin(9600);
  Serial.println("PRESS KEYS:");
#endif

#ifdef TEST_PROJECT
  testkeypad = &mykeypad;

  //const char *args[] = {"main_test.c", "-v", "", "-g", "", "-n", "", "-r", ""};
  const char *args[] = {"main_test.c", "-v", "-g", "keypad_driver", "-r", "1"};

  UnityMain(sizeof(args) / sizeof(char *), args, runAllTests);
  return;
#endif
}

void loop()
{
#ifdef APP_PROJECT

  //Call "scan_keypad" to check if any key is pressed
  keypad_keyPos_t key = scan_keypad(&mykeypad);
  if (key.row != -1 && key.column != -1)
  {
    Serial.print("key pressed:");
    Serial.print(key.row);
    Serial.print(",");
    Serial.println(key.column);
  }
  delay(1000);

#endif

#ifdef TEST_PROJECT

#endif
}
