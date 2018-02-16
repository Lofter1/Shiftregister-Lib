#include <avr/io.h>
#include <util/delay.h>
#include "../Source/SN74HC595.h"

#define SHIFTREGISTER_DP PB0
#define SHIFTREGISTER_SHCP PB2
#define SHIFTREGISTER_STCP PB1

#define DELAY 1000

int main(){
  //Setup
  uint8_t scheme1[SHIFTREGISTER_LENGTH] = {1,0,1,0,1,0,1,0};
  uint8_t scheme2[SHIFTREGISTER_LENGTH] = {0,1,0,1,0,1,0,1};
  uint8_t byteSchme1 = 0b01100110;
  uint8_t byteSchme2 = 0b10011001;

  DDRB |= 0xFF;

  while(1){
    array2Shiftregister(scheme1);
    _delay_ms(DELAY);
    array2Shiftregister(scheme2);
    _delay_ms(DELAY);
    byte2Shiftregister(byteSchme1);
    _delay_ms(DELAY);
    byte2Shiftregister(byteSchme2);
    _delay_ms(DELAY);
  }

}
