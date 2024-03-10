#include "uart.h"

void uart_init(uint32_t baudrate, uint8_t high_speed){
    if(high_speed){
        setHigh(UCSR0A,U2X0);    //Double Speed off
        UBRR0 = F_CPU/8/baudrate-1;    //Set baud rate
    }
    else
        UBRR0 = F_CPU/16/baudrate-1;    //Set baud rate
    
    setHigh(UCSR0B,RXEN0);  //Enable receiver and transmitter
    setHigh(UCSR0B,TXEN0);

    setHigh(UCSR0C,UCSZ00); //Set frame format: 8data
    setHigh(UCSR0C,UCSZ01);
}

void uart_tx(uint8_t data){
    while ( !checkPin(UCSR0A,UDRE0));   //Wait for empty transmit buffer
    UDR0 = data;    //Put data into buffer, sends the data
}

uint8_t uart_rx( void ){
    while ( !checkPin(UCSR0A,RXC0)); //Wait for data to be received
    return UDR0;
}

void uart_tx_string(const char *str){
    while(*str){
        uart_tx(*str);
        str++;
	}
}

void uart_tx_number(uint32_t number){
    uint32_t reverse = 0;
    while(number){
        reverse = reverse*10 + number%10;
        number /= 10;
    }
    if(!reverse)
        uart_tx('0');
    while(reverse){
        uart_tx(reverse%10 + 48);
        reverse /= 10;
    }
}