#include "SN74HC595.h"

#define BYTE_LENGTH 8

void byte2Shiftregister(struct shiftregister dataShiftregister,
                              uint8_t byte)
{
  uint8_t bytePosition;

  SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.storageClockPin);
  for(bytePosition = 0; bytePosition < BYTE_LENGTH; bytePosition++){
    SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.shiftClockPin);
    if( (byte & (0b00000001 << bytePosition)) != 0){
      SHIFTREGISTER_PORT |= (1 << dataShiftregister.serialDataPin);
    }
    else{
      SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.serialDataPin);
    }
    SHIFTREGISTER_PORT |= (1 << dataShiftregister.shiftClockPin);
  }
  SHIFTREGISTER_PORT |= (1 << dataShiftregister.storageClockPin);
  SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.storageClockPin);
}
