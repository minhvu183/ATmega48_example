#include "main.h"

int main(void){
    TCCR0A = 0x00;  //non PWM, TOV flag set on max 0xff
    setHigh(TCCR0B,CS01);  //External clock source on T0 pin. Clock on falling edge
    setHigh(TCCR0B,CS02);
    TCNT0 = 0xfa;   //Timer register
    
    DDRB = 0xff;    //PORTB la output
//    setLow(DDRD,DDD4);
    while(1){
        if(!checkPin(TIFR0, TOV0)){
        TCNT0 = 0;
        setHigh(TIFR0, TOV0);
        }
        PORTB = TCNT0;
        
    }
    return 0;
}