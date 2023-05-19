#include <avr/io.h>
#include <avr/interrupt.h>
#include "spi.h"

void timer_init() {
    cli();
    TCB0.CTRLB = TCB_CNTMODE_INT_gc;    // Configure TCB0 in periodic interrupt mode
    TCB0.CCMP = 3333;                   // Set interval for 1ms (3333 clocks @ 3.3 MHz)
    TCB0.INTCTRL = TCB_CAPT_bm;         // CAPT interrupt enable
    TCB0.CTRLA = TCB_ENABLE_bm;         // Enable
    sei(); 
}
//06
volatile int showLHS = 0;

ISR(TCB0_INT_vect) {

    

    static int  six = 0b10010000;
    // ABCDEG


    static int zero = 0b00001000;
    //ABCDEF

    if (showLHS == 0){
            spi_write(six);
            showLHS = 1;
    }else{
            spi_write(zero);
            showLHS = 0;
    }

    
    TCB0.INTFLAGS = TCB_CAPT_bm;
}