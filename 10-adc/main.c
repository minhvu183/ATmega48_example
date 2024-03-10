#include "main.h"

int main(void){
    adc_init();
    
    uart_init(19200, 1);
    uart_tx_string("ok\n");
    
    while(1){
        uart_tx_number(value_adc(0));
        uart_tx_string(" \n");
        _delay_ms(200);
        
    }
    return 0;
}