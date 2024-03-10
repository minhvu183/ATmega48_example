#include "main.h"

int main(void){
    TCCR0A = 0x00;  //non PWM, TOV flag set on max 0xff
    setHigh(TCCR0B,CS02);  //Clock source = osc/1024
    setHigh(TCCR0B,CS00);
    TCNT0 = 0x00;   //Timer register
    
    setHigh(DDRB,DDB5);    //PB0 la output
    while(1){
        while(checkPin(TIFR0, TOV0));
        TCNT0 = 0;
        togglePin(PORTB,PB5);
        setHigh(TIFR0, TOV0);
        
    }
    return 0;
}