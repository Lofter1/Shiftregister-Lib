#include "shift.h"

#define BYTE_LENGTH 8

#define setShiftPin_High(pin) shiftStatus |= (1 << pin);
#define setShiftPin_Low(pin) shiftStatus &= ~(1 << pin);

static uint8_t shiftStatus;

static void sendData()
{
  uint8_t position;

  SHIFTREGISTER_PORT &= ~(1 << STORAGECLOCK_PIN);
  for(position = 0; position < BYTE_LENGTH; position++){
    SHIFTREGISTER_PORT &= ~(1 << SHIFTCLOCK_PIN);
    if( (shiftStatus & (0b00000001 << position)) != 0){
      SHIFTREGISTER_PORT |= (1 << SERIALDATA_PIN);
    }
    else{
      SHIFTREGISTER_PORT &= ~(1 << SERIALDATA_PIN);
    }
    SHIFTREGISTER_PORT |= (1 << SHIFTCLOCK_PIN);
  }
  SHIFTREGISTER_PORT |= (1 << STORAGECLOCK_PIN);
  SHIFTREGISTER_PORT &= ~(1 << STORAGECLOCK_PIN);
}

uint8_t setShiftregister (uint8_t data)
{
  shiftStatus = data;
  sendData();

  return shiftStatus;
}

uint8_t setShiftregisterPin (uint8_t pin, uint8_t pinStatus)
{
  if(pinStatus){
    setShiftPin_High(pin);
  }
  else {
    setShiftPin_Low(pin);
  }
  sendData();

  return shiftStatus;
}

uint8_t getShiftStatus()
{
  return shiftStatus;
}
