#include "main.h"

void uart_spi_init(uint16_t baud){
    UBRR0 = 0;
    /* Setting the XCKn port pin as output, enables master
    mode. */
    setHigh(DDRD,PD4);
    setLow(DDRD,PD0);
    
    /* Set MSPI mode of operation and SPI data mode 0. */
    setHigh(UCSR0C,UMSEL01);
    setHigh(UCSR0C,UMSEL00);
    
    setLow(UCSR0C,UDORD0);
    setLow(UCSR0C,UCPHA0);
    
    /* Enable receiver and transmitter. */
    setHigh(UCSR0B,RXEN0);
    setHigh(UCSR0B,TXEN0);
    
    /* Set baud rate. */
    /* IMPORTANT: The Baud Rate must be set after the
    transmitter is enabled */
    UBRR0 = baud;
}

uint8_t uart_spi_send(uint8_t data){   
    setHigh(UCSR0A,TXC0);
    UDR0 = data; 
    while (!checkPin(UCSR0A,RXC0));
    return UDR0;
}

int main(void){
    
    DDRB = 0xff;
    setHigh(DDRD,DDD2);
    setHigh(PORTD,PD2);
    uart_spi_init(0);
    
//    setLow(PORTD,PD2);
//    uart_spi_send(0x06);
//    setHigh(PORTD,PD2);
//    _delay_ms(1);
    
    setLow(PORTD,PD2);
    uart_spi_send(0x03);
    uart_spi_send(0);
    uart_spi_send(0);
    PORTB = uart_spi_send(0);
    setHigh(PORTD,PD2);
    
    while(1){
        
        
    }
    return 0;
}