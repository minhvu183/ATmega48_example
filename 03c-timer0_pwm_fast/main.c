#include "main.h"

int main(void){
    uint8_t duty_cycle=0;
    
    setHigh(DDRD,DDD6); //PD6 la output
    
    setHigh(TCCR0A,WGM01);  //fast PWM
    setHigh(TCCR0A,WGM00);
    
    setHigh(TCCR0A,COM0A1); //non-inverting 
    
    OCR0A = 20;    //duty cycle
    
    setHigh(TCCR0B,CS00);   //clock = osc

    while(1){
        for(duty_cycle=0; duty_cycle<250; duty_cycle++){
            OCR0A = duty_cycle;
            _delay_ms(5);
        }
        _delay_ms(200);
        
        for(duty_cycle=255; duty_cycle>5; duty_cycle--){
            OCR0A = duty_cycle;
            _delay_ms(5);
        }
        _delay_ms(200);
    }
    return 0;
}