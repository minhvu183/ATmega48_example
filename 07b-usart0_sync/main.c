#include "main.h"
#define osc 8000000

void uart_init(uint16_t baudrate){

    UBRR0 = F_CPU/16/baudrate-1;    //Set baud rate  
    
    setHigh(UCSR0B,RXEN0);  //Enable receiver and transmitter
    setHigh(UCSR0B,TXEN0);

    setHigh(UCSR0C,UCSZ00); //Set frame format: 8data
    setHigh(UCSR0C,UCSZ01);
    
    setHigh(UCSR0C,UMSEL00);    //Synchronous USART
    
//    setHigh(UCSR0C,UCPOL0);
}

void uart_tx(uint8_t data){
    while ( !checkPin(UCSR0A,UDRE0));   //Wait for empty transmit buffer
    UDR0 = data;    //Put data into buffer, sends the data
}

uint8_t uart_rx( void ){
    while ( !checkPin(UCSR0A,RXC0)); //Wait for data to be received
    return UDR0;
}

int main(void){
    setHigh(DDRD, DDD2);
    setHigh(DDRD, DDD4);
    setHigh(PORTD,PD2);
    uart_init(1200);
    uart_tx(0xaa);
    
    setLow(PORTD,PD2);
    _delay_ms(1);
    setHigh(PORTD,PD2);
    while(1){
       
        
    }
    return 0;
}