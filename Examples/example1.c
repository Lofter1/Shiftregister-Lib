#include <avr/io.h>
#include <util/delay.h>
#include "../Source/shift.h"

#define DELAY 1000
#define HIGH 1
#define LOW  0

int main(){
  //Setup
  uint8_t byteSchme1 = 0b11111111;
  uint8_t byteSchme2 = 0b10011001;

  DDRB |= 0xFF;

  while(1){
     setShiftregister(byteSchme1);
    _delay_ms(DELAY);
     setShiftregister(byteSchme2);
    _delay_ms(DELAY);

     setShiftregisterPin(SHIFT_D0, LOW);
    _delay_ms(DELAY);
     setShiftregisterPin(SHIFT_D1, HIGH);
    _delay_ms(DELAY);
     setShiftregisterPin(SHIFT_D2, HIGH);
    _delay_ms(DELAY);
     setShiftregisterPin(SHIFT_D3, LOW);
    _delay_ms(DELAY);
     setShiftregisterPin(SHIFT_D4, LOW);
    _delay_ms(DELAY);
     setShiftregisterPin(SHIFT_D5, HIGH);
    _delay_ms(DELAY);
     setShiftregisterPin(SHIFT_D6, HIGH);
    _delay_ms(DELAY);
     setShiftregisterPin(SHIFT_D7, LOW);
    _delay_ms(DELAY);

  }

}
