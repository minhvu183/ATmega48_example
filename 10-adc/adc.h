#ifndef ADC_H
#define ADC_H

#include "main.h"

#define set_adc(pin) setLow(DDRC,pin)
void adc_init(void);
uint16_t value_adc(uint8_t pin);

#endif