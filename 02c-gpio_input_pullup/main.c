#include "main.h"

int main(void){
    
    setLow(DDRB,DDB0);     //PB0 la input
    setHigh(DDRB,DDB5);    //PB1 la output
    
    setHigh(PORTB,PB0);     //PB0 pullup 
    while(1){
        if(checkPin(PINB,PINB0))
            setHigh(PORTB,PB5);
        else
            setLow(PORTB,PB5);
    }
    return 0;
}