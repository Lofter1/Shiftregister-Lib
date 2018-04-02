#include <avr/io.h>
#include <util/delay.h>
#include "../Source/shift.h"

#define DELAY 1000
#define HIGH 1
#define LOW  0

int main(){
  //Setup
  uint8_t byteSchme1 = 0b01100110;
  uint8_t byteSchme2 = 0b10011001;
  uint8_t status;

  DDRB |= 0xFF;

  while(1){
    status = setShiftregister(byteSchme1);
    _delay_ms(DELAY);
    status = setShiftregister(byteSchme2);
    _delay_ms(DELAY);

    status = setShiftregisterPin(D0, LOW);
    _delay_ms(DELAY);
    status = setShiftregisterPin(D1, HIGH);
    _delay_ms(DELAY);
    status = setShiftregisterPin(D2, HIGH);
    _delay_ms(DELAY);
    status = setShiftregisterPin(D3, LOW);
    _delay_ms(DELAY);
    status = setShiftregisterPin(D4, LOW);
    _delay_ms(DELAY);
    status = setShiftregisterPin(D5, HIGH);
    _delay_ms(DELAY);
    status = setShiftregisterPin(D6, HIGH);
    _delay_ms(DELAY);
    status = setShiftregisterPin(D7, LOW);
    _delay_ms(DELAY);

  }

}
