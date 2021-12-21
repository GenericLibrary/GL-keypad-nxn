/* 
 * File:   software_tx.h
 * Author: bill_
 *
 * Created on December 20, 2021, 11:09 AM
 */

#ifndef SOFTWARE_TX_H
#define	SOFTWARE_TX_H

#include "util/delay.h"

#ifdef	__cplusplus
extern "C" {
#endif


const uint8_t bit_lenght = 8;
const uint8_t bittime_us = 104; // for 9600 bauds


#define set_low() tx_SetLow()
#define set_high() tx_SetHigh()
#define wait_bit_time() (_delay_us(bittime_us))

    void software_uart_print_char(char c) {
        uint8_t bits = bit_lenght;

        // start bit
        set_low();
        wait_bit_time();

        // data-bits
        do {
            if (c & 1) {
                set_high();
            } else {
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

    void software_uart_print_string( char* str) {
        while (*str != 0) {
            software_uart_print_char(*str);
            str++;
        }
    }



#ifdef	__cplusplus
}
#endif

#endif	/* SOFTWARE_TX_H */

