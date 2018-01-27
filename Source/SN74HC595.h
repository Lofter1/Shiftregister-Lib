#ifndef SN74HC595_H
#define SN74HC595_H

#define SHIFTREGISTER_LENGTH 8

#ifndef SHIFTREGISTER_PORT
  #define SHIFTREGISTER_PORT PORTB
#endif

struct shiftregister{
  uint8_t serialDataPin;
  uint8_t shiftClockPin;
  uint8_t storageClockPin;
//  char port;  //could be used to determine which port the shiftregister uses
};

extern void Array2Shiftregister(struct shiftregister dataShiftregister,
                                      uint8_t data[SHIFTREGISTER_LENGTH]);
extern void Byte2Shiftregister( struct shiftregister dataShiftregister,
                                      uint8_t byte);

#endif
