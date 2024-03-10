#include "main.h"

int main(void){
    TCCR1A = 0x00;  //non PWM, TOV flag set on max 0xff
    setHigh(TCCR1B,CS11);  //Clock source = osc
    TCNT1 = 15535;   //Timer register
    
    setHigh(DDRB,DDB5);    //PB0 la output
    while(1){
        while(checkPin(TIFR1, TOV1));
        TCNT1 = 15535;
        togglePin(PORTB,PB5);
        setHigh(TIFR1, TOV1);
        
    }
    return 0;
}