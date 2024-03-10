#include "main.h"

int main(void){
    TCCR1A = 0x00;  //non PWM, TOV flag set on max 0xff
    setHigh(TCCR1B,CS11);  //External clock
    setHigh(TCCR1B,CS12);
    TCNT1 = 65530;   //Timer register
    
    DDRB = 0xff;    //PORTB la output
    setLow(DDRD,DDD5);      //PD5 la input
    while(1){
        if(!checkPin(TIFR1, TOV1)){
            TCNT1 = 0;
            setHigh(TIFR1, TOV1);
        }
        PORTB = TCNT1L;
        
    }
    return 0;
}