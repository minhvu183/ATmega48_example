#include "main.h"

int main(void){
    
    setHigh(EICRA, ISC01);  //The falling edge of INT0
    
    setHigh(EIMSK, INT0);  //External Interrupt Request 0 Enable
    
    setHigh(SREG, SREG_I);   //Global Interrupt Enable
    
    setHigh(DDRB,DDB0);
    setHigh(DDRB,DDB1);
    setLow(DDRD,DDD2);
    setHigh(PORTD,PD2);
    while(1){
        togglePin(PORTB,PB0);
        _delay_ms(300);
    }
    return 0;
}

ISR (INT0_vect){
    togglePin(PORTB,PB1);
}