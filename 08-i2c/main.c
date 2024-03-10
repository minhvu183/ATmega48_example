#include "main.h"

#define i2c_status (TWSR&0xf8)
#define error 0;
void i2c_init(uint32_t bitrate, uint8_t pre){
    if(pre == 64)
        TWSR |= _BV(TWPS1)|_BV(TWPS0);
    else if(pre == 16)
        TWSR |= _BV(TWPS1);
    else if(pre == 4)
        TWSR |= _BV(TWPS0);
    else
        TWSR &= 0xfc;
        
    TWBR = (F_CPU/bitrate-16)/(2*pre);
}
void i2c_init_pullup(uint32_t bitrate,uint8_t pre){
    setHigh(PORTC,PC4);
    setHigh(PORTC,PC5);
    i2c_init(bitrate, pre);
}
uint8_t i2c_start(void){ 
    TWCR |= _BV(TWSTA)|_BV(TWINT)|_BV(TWEN);
    setLow(TWCR,TWSTA);
    while(!checkPin(TWCR,TWINT)); 
    if(i2c_status != 0x08)
        return error;
    return 1;
}

uint8_t i2c_restart(){ 
    TWCR |= _BV(TWSTA)|_BV(TWINT)|_BV(TWEN);
    while(!checkPin(TWCR,TWINT)); 
    if(i2c_status != 0x10)
        return error;
    return 1;
}

uint8_t i2c_add_w(uint8_t add){
    TWDR = add<<1;
    setHigh(TWCR,TWINT);
    while(!checkPin(TWCR,TWINT));
    if(i2c_status != 0x18)
        return error;
    return 1;
}

uint8_t i2c_add_r(uint8_t add){
    TWDR = (add<<1)|1;
    setHigh(TWCR,TWINT);
    while(!checkPin(TWCR,TWINT));
    if(i2c_status != 0x40)
        return error;
    return 1;
}

uint8_t i2c_write(uint8_t data){
    TWDR = data;
    setHigh(TWCR,TWINT);
    while(!checkPin(TWCR,TWINT));
    if(i2c_status != 0x28)
        return error;
    return 1;
}

uint8_t i2c_read(uint8_t nack){
    if(!nack)
        TWCR |= _BV(TWINT)|_BV(TWEA);
    else
        setHigh(TWCR,TWINT);
    while(!checkPin(TWCR,TWINT));
    if((i2c_status != 0x50) || (i2c_status != 0x58))
        return TWDR;
    return error;
}

void i2c_stop(void){
    TWCR |= _BV(TWSTO)|_BV(TWINT)|_BV(TWEN);
    while(checkPin(TWCR,TWSTO));
}

int main(void){
    uint8_t i;
    setHigh(DDRC,DDC0);
    
    i2c_init(50000,4);
    _delay_ms(500);
    i2c_start();
    i2c_add_w(0x27);
//    _delay_ms(1);
    

    while(1){
        i2c_write(0);
//        _delay_ms(1000);
        i2c_write(0xff);
//        _delay_ms(1000);
    }
    return 0;
}