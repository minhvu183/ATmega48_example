#include "main.h"

void spi_master_init(void){
    setHigh(DDRB,DDB3); //MOSI output
    setHigh(DDRB,DDB5); //SCK output
    setLow(DDRB,DDB4);  //MISO input

    setHigh(SPCR,MSTR); // Set as Master
    setHigh(SPCR,SPR0); //clock =osc / 16
    setHigh(SPCR,SPE);  // Enable SPI   
}

uint8_t spi_send(uint8_t data){
    SPDR = data;                   // send the data
    while(!checkPin(SPSR,SPIF));  // wait until transmission is complete 
    return SPDR;
}

int main (void){
   
    setHigh(DDRB,DDB2); //SS output
    setHigh(PORTB,PB2);
    DDRC = 0xff;
    
    spi_master_init();
    
//    setLow(PORTB,PB2);
//    spi_send(0x06);
//    setHigh(PORTB,PB2);
//    _delay_ms(1);   
//    setLow(PORTB,PB2);
//    spi_send(0x02);
//    spi_send(0x00);
//    spi_send(0x00);
//    spi_send('a');
//    setHigh(PORTB,PB2);
    
    setLow(PORTB,PB2);
    spi_send(0x03);
    spi_send(0x00);
    spi_send(0x00);
    PORTC = spi_send(0);
    setHigh(PORTB,PB2);

    
    while(1)
    {


       
    }
}