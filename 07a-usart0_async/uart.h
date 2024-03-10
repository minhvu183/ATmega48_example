#ifndef UART_H
#define UART_H

 
#include "main.h"

void uart_init(uint32_t baudrate, uint8_t high_speed);
void uart_tx(uint8_t data);
uint8_t uart_rx( void );
void uart_tx_string(const char *str);
void uart_tx_number(uint32_t number);

#endif