/*
 * software_tx.h
 *
 * Created: 12/19/2021 6:32:28 PM
 *  Author: bill_
 */ 


#ifndef SOFTWARE_TX_H_
#define SOFTWARE_TX_H_


const uint8_t bit_lenght = 8;
const uint8_t bittime_us = 104; // for 9600 bauds

#define init_pin() (DDRD |= (1<<1))
#define set_low() (PORTD &= ~(1<<1))
#define set_high() (PORTD |= (1<<1))
#define wait_bit_time() (_delay_us(bittime_us))

void software_uart_init(){
	init_pin();
	set_high();
}
void software_uart_print_char(char c){
	uint8_t bits = bit_lenght;
	
	// start bit
	set_low();
	wait_bit_time();
	
	// data-bits
	do
	{
		if(c & 1)
		{
			set_high();
		}else
		{
			set_low();
		}
		wait_bit_time();
		c >>= 1;
	} while (--bits);
	
	// no parity-bit
	/*
	set_low();
	wait_bit_time();
	*/
	
	// stop-bit(s)
	set_high();
	wait_bit_time();
}
void software_uart_print_string(char* str){
	while (*str != 0)
	{
		software_uart_print_char(*str);
		str++;
	}
}




#endif /* SOFTWARE_TX_H_ */