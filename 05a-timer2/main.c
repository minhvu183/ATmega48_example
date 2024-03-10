#include "main.h"

int main(void){
    TCCR2A = 0x00;  //non PWM, TOV flag set on max 0xff
    setHigh(TCCR2B,CS21);  //Clock source = osc/1024
    setHigh(TCCR2B,CS22);
    setHigh(TCCR2B,CS20);
    TCNT2 = 0x00;   //Timer register
    
    setHigh(DDRB,DDB5);    //PB0 la output
    while(1){
        while(checkPin(TIFR2, TOV2));   //wait flag
        TCNT2 = 0;              ////Timer register
        togglePin(PORTB,PB5);
        setHigh(TIFR2, TOV2);   //clear flag
        
    }
    return 0;
}