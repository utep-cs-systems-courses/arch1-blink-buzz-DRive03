#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char buzzer_count = 0;
  if (++blink_count == 249) {
    state_advance();
    blink_count = 0;
  }

  if(++buzzer_count == 35){
    buzzer_state_advance();
    buzzer_count = 0;
  }
}
