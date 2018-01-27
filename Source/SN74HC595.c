#include "SN74HC595.h"

#define BYTE_LENGTH 8

void Array2Shiftregister(struct shiftregister dataShiftregister,
                                uint8_t data[SHIFTREGISTER_LENGTH])
{
  int8_t position;

  SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.storageClockPin);

  for(position = SHIFTREGISTER_LENGTH - 1; position >= 0; position--){
    SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.shiftClockPin);

    if(data[position] == 1){
      SHIFTREGISTER_PORT |= (1 << dataShiftregister.serialDataPin);
    }
    else if(data[position] == 0){
      SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.serialDataPin);
    }

    SHIFTREGISTER_PORT |= (1 << dataShiftregister.shiftClockPin);
  }

  SHIFTREGISTER_PORT |= (1 << dataShiftregister.storageClockPin);
  SHIFTREGISTER_PORT &= ~(1 << dataShiftregister.storageClockPin);
}

void Byte2Shiftregister(struct shiftregister dataShiftregister,
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
