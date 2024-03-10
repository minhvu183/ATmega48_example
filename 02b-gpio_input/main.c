#include "main.h"

int main(void){
    
    setLow(DDRB,DDB0);     //PB0 la input
    setHigh(DDRB,DDB5);    //PB1 la output
    setLow(PORTB,PB0);     //PB0 pullup off 
    while(1){
        if(checkPin(PINB,PINB0))
            setHigh(PORTB,PB5);
        else
            setLow(PORTB,PB5);
    }
    return 0;
}