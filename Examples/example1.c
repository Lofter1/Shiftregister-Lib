#include <avr/io.h>
#include <util/delay.h>

#define SHIFTREGISTER_DDR DDRB
#define SHIFTREGISTER_PORT PORTB

#define SERIALDATA_PIN PB0
#define SHIFTCLOCK_PIN PB2
#define STORAGECLOCK_PIN PB1

#include "../Source/shift.h"

#define DELAY 1000
#define HIGH 1
#define LOW  0

int main(){
  //Setup
  uint8_t scheme1[SHIFTREGISTER_LENGTH] = {1,0,1,0,1,0,1,0};
  uint8_t scheme2[SHIFTREGISTER_LENGTH] = {0,1,0,1,0,1,0,1};
  uint8_t byteSchme1 = 0b01100110;
  uint8_t byteSchme2 = 0b10011001;
  uint8_t status;

  DDRB |= 0xFF;

  while(1){
    status = array2Shiftregister(scheme1);
    _delay_ms(DELAY);
    status = array2Shiftregister(scheme2);
    _delay_ms(DELAY);
    status = byte2Shiftregister(byteSchme1);
    _delay_ms(DELAY);
    status = byte2Shiftregister(byteSchme2);
    _delay_ms(DELAY);

    status = setPin(D0, LOW);
    _delay_ms(DELAY);
    status = setPin(D1, HIGH);
    _delay_ms(DELAY);
    status = setPin(D2, HIGH);
    _delay_ms(DELAY);
    status = setPin(D3, LOW);
    _delay_ms(DELAY);
    status = setPin(D4, LOW);
    _delay_ms(DELAY);
    status = setPin(D5, HIGH);
    _delay_ms(DELAY);
    status = setPin(D6, HIGH);
    _delay_ms(DELAY);
    status = setPin(D7, LOW);
    _delay_ms(DELAY);

  }

}
