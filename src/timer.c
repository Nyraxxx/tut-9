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

    

    static int  one1 = 0b01101011;
    // ABCDEG


    static int one = 0b11101011;
    //ABCDEF

    if (showLHS == 0){
            spi_write(one1);
            showLHS = 1;
    }else{
            spi_write(one);
            showLHS = 0;
    }

    
    TCB0.INTFLAGS = TCB_CAPT_bm;
}