#include "uart.h"
#include "timer.h"

spi_init(void){
    cli();
    PORTMUX.SPIROUTEA = PORTMUX_SPI0_ALT1_gc;
    PORTC.DIR |= (PIN0_bm | PIN2_bm);

    SPI0.CTRLA = SPI_MASTER_bm;
    SPI0.CTRLB = SPI_SSD_bm;
    SPI0.CTRLA |= SPI_ENABLE_bm;

    sei();

    PORTB.DIRSET = PIN5_bm;
    PORTA.DIRSET = PIN1_bm;
    PORTC.DIRSET = PIN0_bm;
    PORTC.DIRSET = PIN2_bm;;
  
}

spi_write(uint8_t b){
    SPI0.DATA = b;
    ///interrupt??
    
}