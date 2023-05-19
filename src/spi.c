#include "uart.h"
#include "timer.h"

void spi_init(void){
    cli();
    PORTMUX.SPIROUTEA = PORTMUX_SPI0_ALT1_gc;

    PORTA.OUTCLR = PIN1_bm;
    PORTA.DIRSET = PIN1_bm;


    PORTC.DIRSET = (PIN0_bm | PIN2_bm);

    SPI0.CTRLA = SPI_MASTER_bm;
    SPI0.CTRLB = SPI_SSD_bm;

    SPI0.INTCTRL = SPI_IE_bm;

    SPI0.CTRLA |= SPI_ENABLE_bm;

    sei();

 
}

void spi_write(uint8_t b){
    SPI0.DATA = b;
    ///interrupt??
    
    
}

ISR(SPI0_INT_vect) {
    PORTA.OUTCLR = PIN1_bm;
    PORTA.OUTSET = PIN1_bm;

    PORTC.OUTSET = PIN2_bm;
    SPI0.INTFLAGS |= SPI_RXCIF_bm;

        
        
    }
