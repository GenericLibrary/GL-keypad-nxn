/*
 * unity_port.c
 *
 *  Created on: Dec 23, 2021
 *      Author: bill_
 */

#include <string.h>
#include <stdint.h>
#include "main.h"

static uint32_t s_test_start, s_test_stop;
extern UART_HandleTypeDef hlpuart1;
void unity_putc(int c) {
	if (c == '\n') {
		HAL_UART_Transmit(&hlpuart1, (uint8_t*) "\r\n", 2, 1000);

	} else if (c == '\r') {
	} else {
		uint8_t data = (uint8_t) c;
		HAL_UART_Transmit(&hlpuart1, &data, 1, 1000);
	}
}

void unity_flush(void) {

}

void unity_exec_time_start(void) {
	s_test_start = HAL_GetTick();
}

void unity_exec_time_stop(void) {
	s_test_stop = HAL_GetTick();
}

uint32_t unity_exec_time_get_ms(void) {
	return (s_test_stop - s_test_start);
}
