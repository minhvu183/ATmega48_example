#include "main.h"

int main(void){
    
    setHigh(DDRB,DDB5);   //PORTB5 la output

    while(1){
        togglePin(PORTB,PB5); //PORTB0 = 0
        _delay_ms(1000);
    
    }
    return 0;
}