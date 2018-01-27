#include <avr/io.h>
#include <util/delay.h>
#include <SN74HC595.h>

#define SHIFTREGISTER1_DS PB0
#define SHIFTREGISTER1_SHIFTCLOCK PB2
#define SHIFTREGISTER1_STORAGECLOCK PB1

#define DELAY 1000

int main(){
  //Setup
  uint8_t scheme1[SHIFTREGISTER_LENGTH] = {1,0,1,0,1,0,1,0};
  uint8_t scheme2[SHIFTREGISTER_LENGTH] = {0,1,0,1,0,1,0,1};
  uint8_t byteSchme1 = 0b01100110;
  uint8_t byteSchme2 = 0b10011001;
  struct shiftregister shiftregisterPORTB; //shiftregister on PORTB

  DDRB |= 0xFF;

  shiftregisterPORTB.serialDataPin = SHIFTREGISTER1_DS;
  shiftregisterPORTB.shiftClockPin = SHIFTREGISTER1_SHIFTCLOCK;
  shiftregisterPORTB.storageClockPin = SHIFTREGISTER1_STORAGECLOCK;

  while(1){
    array2Shiftregister(shiftregisterPORTB, scheme1);
    _delay_ms(DELAY);
    array2Shiftregister(shiftregisterPORTB, scheme2);
    _delay_ms(DELAY);
    byte2Shiftregister(shiftregisterPORTB, byteSchme1);
    _delay_ms(DELAY);
    byte2Shiftregister(shiftregisterPORTB, byteSchme2);
    _delay_ms(DELAY);
  }

}
