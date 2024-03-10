#include "main.h"

void eeprom_write(uint16_t add, uint8_t data){
    while(EECR & (1<<EEPE));    //Wait until EEPE becomes zero
    EEAR = add;
    EEDR = data;
    EECR |= 1<<EEMPE;   //EEMPE = 1
    EECR |= 1<<EEPE;    //EEPE = 1
}

uint8_t eeprom_read(uint16_t add){

while(EECR & (1<<EEPE));    //Wait for completion of previous write

EEAR = add;

EECR |= (1<<EERE);  //EERE = 1

return EEDR;
}

int main(void){
    eeprom_write(0,1);
    while(1){
        
        
    }
    return 0;
}