#include "main.h"

int main(void){
    uint16_t duty_cycle;
    setHigh(DDRB,DDB1);    //PB1 la output
        
    ICR1 = 0xffff;  // pwm 16bit
    
    OCR1A = 0x6fff; //duty cycle
    
    setHigh(TCCR1A,COM1A1); //non-inverting
    
    setHigh(TCCR1A,WGM11);  //Fast PWM, ICR1 as TOP
    setHigh(TCCR1B,WGM12);
    setHigh(TCCR1B,WGM13);
   
    setHigh(TCCR1B,CS10);  //clock source = osc
    
    while(1){
        for(duty_cycle=0; duty_cycle<0xff00; duty_cycle+=25){
            OCR1A = duty_cycle;
            _delay_ms(2);
        }
        _delay_ms(400);
        
        for(duty_cycle=0xfff0; duty_cycle>5; duty_cycle-=25){
            OCR1A = duty_cycle;
            _delay_ms(2);
        }
        _delay_ms(400);        
        
    }
    return 0;
}
