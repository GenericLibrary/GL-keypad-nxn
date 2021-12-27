#define TEST_PROJECT
//#define APP_PROJECT

#define F_CPU 16000000UL
#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>
#include "software_uart.h"
#include "../../../keypad-nxn.h"
#include "../../../keypad-nxn.c"

#ifdef TEST_PROJECT
int mainTest(void);
#endif

#define ROW1 d7
#define ROW2 d6
#define ROW3 d5
#define ROW4 d4
#define COL1 d3
#define COL2 d2
#define COL3 b1
#define COL4 b0

keypad_t mykeypad;
const uint8_t keypad_rows_number = 4;
const uint8_t keypad_cols_number = 4;
bool keypad_init_periph()
{
	// all columns as "INPUT PULL_UP"
	c1_set_dir(PORT_DIR_IN);
	c1_set_pull_mode(PORT_PULL_UP);
	c2_set_dir(PORT_DIR_IN);
	c2_set_pull_mode(PORT_PULL_UP);
	c3_set_dir(PORT_DIR_IN);
	c3_set_pull_mode(PORT_PULL_UP);
	c4_set_dir(PORT_DIR_IN);
	c4_set_pull_mode(PORT_PULL_UP);

	// all rows as " FLOATING INPUT"
	r1_set_dir(PORT_DIR_IN);
	r2_set_dir(PORT_DIR_IN);
	r3_set_dir(PORT_DIR_IN);
	r4_set_dir(PORT_DIR_IN);
	return true;
}
bool keypad_deinit_periph()
{
	c1_set_dir(PORT_DIR_IN);
	c1_set_pull_mode(PORT_PULL_OFF);
	c2_set_dir(PORT_DIR_IN);
	c2_set_pull_mode(PORT_PULL_OFF);
	c3_set_dir(PORT_DIR_IN);
	c3_set_pull_mode(PORT_PULL_OFF);
	c4_set_dir(PORT_DIR_IN);
	c4_set_pull_mode(PORT_PULL_OFF);

	r1_set_dir(PORT_DIR_IN);
	r2_set_dir(PORT_DIR_IN);
	r3_set_dir(PORT_DIR_IN);
	r4_set_dir(PORT_DIR_IN);
	return true;
}
void row_as_input(uint8_t row)
{
	switch (row)
	{
		case 1:
		r1_set_dir(PORT_DIR_IN);
		break;
		case 2:
		r2_set_dir(PORT_DIR_IN);
		break;
		case 3:
		r3_set_dir(PORT_DIR_IN);
		break;
		case 4:
		r4_set_dir(PORT_DIR_IN);
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
		r1_set_dir(PORT_DIR_OUT);
		r1_set_level(0);
		break;
		case 2:
		r2_set_dir(PORT_DIR_OUT);
		r2_set_level(0);
		break;
		case 3:
		r3_set_dir(PORT_DIR_OUT);
		r3_set_level(0);
		break;
		case 4:
		r4_set_dir(PORT_DIR_OUT);
		r4_set_level(0);
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
		return (uint8_t)c1_get_level();
		case 2:
		return (uint8_t)c2_get_level();
		case 3:
		return (uint8_t)c3_get_level();
		case 4:
		return (uint8_t)c4_get_level();
		default:
		return 0;
	}
}
void keypad_delay_ms(int ms)
{
	for (int i = 0; i < ms; i++)
	_delay_ms(1);
}
int main(void)
{
	// Init peripherals asociated to the keypad:
	// all columns as "INPUT PULL_UP"
	// all rows as " FLOATING INPUT"
	atmel_start_init();

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

	software_uart_init();
	
	
	#ifdef APP_PROJECT
	software_uart_print_string("PRESS KEYS:\n");
	#endif

	#ifdef TEST_PROJECT
	return mainTest();
	#endif
	
	while (1) {
		
		//Call "scan_keypad" to check if any key is pressed
		#ifdef APP_PROJECT
		keypad_keyPos_t key ;
		scan_keypad(&mykeypad, &key);
		if (key.row != -1 && key.column != -1)
		{
			char bufer[50]={0};
			sprintf(bufer, "key pressed: r%i,c%i\n\r", key.row, key.column);
			software_uart_print_string(bufer);
		}
		_delay_ms(1000);
		#endif
		

	}
}
