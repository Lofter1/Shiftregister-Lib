#include "SN74HC595.h"

#define BYTE_LENGTH 8

void byte2Shiftregister(uint8_t byte){
  uint8_t bytePosition;

  SHIFTREGISTER_PORT &= ~(1 << SHIFTREGISTER_STCP);
  for(bytePosition = 0; bytePosition < BYTE_LENGTH; bytePosition++){
    SHIFTREGISTER_PORT &= ~(1 << SHIFTREGISTER_SHCP);
    if( (byte & (0b00000001 << bytePosition)) != 0){
      SHIFTREGISTER_PORT |= (1 << SHIFTREGISTER_DP);
    }
    else{
      SHIFTREGISTER_PORT &= ~(1 << SHIFTREGISTER_DP);
    }
    SHIFTREGISTER_PORT |= (1 << SHIFTREGISTER_SHCP);
  }
  SHIFTREGISTER_PORT |= (1 << SHIFTREGISTER_STCP);
  SHIFTREGISTER_PORT &= ~(1 << SHIFTREGISTER_STCP);
}
