#include "shift.h"

#define setShiftPin_High(pin) shiftStatus |= (1 << pin);
#define setShiftPin_Low(pin) shiftStatus &= ~(1 << pin);

static uint8_t shiftStatus;

uint8_t byte2Shiftregister (uint8_t byte)
{
  uint8_t bytePosition;

  SHIFTREGISTER_PORT &= ~(1 << STORAGECLOCK_PIN);
  for(bytePosition = 0; bytePosition < BYTE_LENGTH; bytePosition++){
    SHIFTREGISTER_PORT &= ~(1 << SHIFTCLOCK_PIN);
    if( (byte & (0b00000001 << bytePosition)) != 0){
      SHIFTREGISTER_PORT |= (1 << SERIALDATA_PIN);
    }
    else{
      SHIFTREGISTER_PORT &= ~(1 << SERIALDATA_PIN);
    }
    SHIFTREGISTER_PORT |= (1 << SHIFTCLOCK_PIN);
  }
  SHIFTREGISTER_PORT |= (1 << STORAGECLOCK_PIN);
  SHIFTREGISTER_PORT &= ~(1 << STORAGECLOCK_PIN);

  shiftStatus = byte;

  return shiftStatus;
}

uint8_t setPin (uint8_t pin, uint8_t pinStatus){
  if(pinStatus){
    setShiftPin_High(pin);
  }
  else {
    setShiftPin_Low(pin);
  }
  byte2Shiftregister(shiftStatus);

  return shiftStatus;
}

uint8_t getShiftStatus(){
  return shiftStatus;
}
