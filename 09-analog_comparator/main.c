#include "main.h"

int main(void){
    setHigh(DDRB,DDB0);
    
  
  
    while(1){
        if(checkPin(ACSR,ACO))
            setHigh(PORTB,PB0);
        else
            setLow(PORTB,PB0);
        
    }
    return 0;
}