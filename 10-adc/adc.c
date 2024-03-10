#include "adc.h"

void adc_init(void){
    setHigh(ADMUX,REFS0);   //Vref = Vcc
       
    setHigh(ADCSRA,ADEN);   //ADC enable
    
    setHigh(ADCSRA,ADPS2);   //clock = osc/64
    setHigh(ADCSRA,ADPS1);
}

uint16_t value_adc(uint8_t pin){
    uint16_t result;
    ADMUX &= 0xf0;
    ADMUX |= pin;
    setHigh(ADCSRA,ADSC);
    while(!checkPin(ADCSRA,ADIF));
    setHigh(ADCSRA,ADIF);
    result = ADCL;
    result |= ADCH<<8;
    return result;
}