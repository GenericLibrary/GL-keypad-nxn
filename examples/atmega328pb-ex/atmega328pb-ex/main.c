#define F_CPU 16000000UL
#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>
#include "software_uart.h"
#include "../../../keypad-nxn.h"
#include "../../../keypad-nxn.c"

#define ROWS_NUMBER 4
#define ROW1 d7
#define ROW2 d6
#define ROW3 d5
#define ROW4 d4
#define COLS_NUMBER 4
#define COL1 d3
#define COL2 d2
#define COL3 d1
#define COL4 d0

keypad_t mykeypad;

void row_as_input(uint8_t row)
{
	switch (row)
	{
		case 1:
		DDRD &= ~(1<<7);
		break;
		case 2:
		DDRD &= ~(1<<6);
		break;
		case 3:
		DDRD &= ~(1<<5);
		break;
		case 4:
		DDRD &= ~(1<<4);
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
		DDRD |= (1<<7);
		PORTD &= ~(1<<7);
		break;
		case 2:
		DDRD |= (1<<6);
		PORTD &= ~(1<<6);
		break;
		case 3:
		DDRD |= (1<<5);
		PORTD &= ~(1<<5);
		break;
		case 4:
		DDRD |= (1<<4);
		PORTD &= ~(1<<4);
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
		return (uint8_t)(PIND & (1<<3) ? 1:0 );
		case 2:
		return (uint8_t)(PIND & (1<<2) ? 1:0 );
		case 3:
		return (uint8_t)(PIND & (1<<1) ? 1:0 );
		case 4:
		return (uint8_t)(PIND & (1<<0) ? 1:0 );
		default:
		return 0;
	}
}

int main(void)
{
	// Init peripherals asociated to the keypad:
	// all columns as "INPUT PULL_UP"
	// all rows as " FLOATING INPUT"
	atmel_start_init();

	// Create a variable of type "keypad_t" and define each of its attributes
	mykeypad.rows = ROWS_NUMBER;
	mykeypad.columns = COLS_NUMBER;
	mykeypad.row_as_Input = row_as_input;
	mykeypad.row_as_OutputLow = row_as_output_low;
	mykeypad.get_column_value = get_column_value;

	// Call "init_keypad" to initialize the keypad. In this case it does nothing
	init_keypad(&mykeypad);

	software_uart_init();
	software_uart_print_string("PRESS KEYS:\n");
	
	while (1) {
		
		//Call "scan_keypad" to check if any key is pressed
		keypad_keyPos_t key = scan_keypad(&mykeypad);
		if (key.row != -1 && key.column != -1)
		{
			char bufer[50]={0};
			sprintf(bufer, "key pressed: r%i,c%i\n\r", key.row, key.column);
			software_uart_print_string(bufer);			
		}
		_delay_ms(1000);

	}
}
