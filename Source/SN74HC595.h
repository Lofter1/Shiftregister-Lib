#ifndef SN74HC595_H
#define SN74HC595_H

#include <avr/io.h>

#define SHIFTREGISTER_LENGTH 8

#ifndef SHIFTREGISTER_DDR
  #define SHIFTREGISTER_DDR DDRB
#endif
#ifndef SHIFTREGISTER_PORT
  #define SHIFTREGISTER_PORT PORTB
#endif

struct shiftregister{
  uint8_t serialDataPin;
  uint8_t shiftClockPin;
  uint8_t storageClockPin;
//  char port;  //could be used to determine which port the shiftregister uses
};

extern void byte2Shiftregister( struct shiftregister *dataShiftregister,
                                      uint8_t byte);

#define array2byte(array) ( (array[7]) \
                          + ((array[6]) << 1) \
                          + ((array[5]) << 2) \
                          + ((array[4]) << 3) \
                          + ((array[3]) << 4) \
                          + ((array[2]) << 5) \
                          + ((array[1]) << 6) \
                          + ((array[0]) << 7) )

#define array2Shiftregister(s,a) byte2Shiftregister(s, array2byte(a))



#endif
