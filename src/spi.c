#include "uart.h"
#include "timer.h"

void spi_init(void){
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
    PORTC.DIRSET = PIN2_bm;
  
  //latch stuff

    PORTA.OUTCLR = PIN1_bm;
    PORTC.OUTCLR = PIN0_bm;
    PORTC.OUTCLR = PIN2_bm;

}

int spi_write(uint8_t b){
    SPI0.DATA = b;
    ///interrupt??
    
    
}

ISR(SPI0_INT_vect) {

    
    PORTC.OUTSET = PIN2_bm;
        TCB0.INTFLAGS = TCB_CAPT_bm;

        
        
    }
