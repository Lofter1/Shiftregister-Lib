#ifndef SN74HC595_H
#define SN74HC595_H

#include <avr/io.h>

#ifndef SHIFTREGISTER_LENGTH
  #define SHIFTREGISTER_LENGTH 8
#endif
#ifndef SHIFTREGISTER_DDR
  #define SHIFTREGISTER_DDR DDRB
#endif
#ifndef SHIFTREGISTER_PORT
  #define SHIFTREGISTER_PORT PORTB
#endif

extern void byte2Shiftregister(uint8_t byte);

#define array2byte(array) ( (array[7]) \
                          + ((array[6]) << 1) \
                          + ((array[5]) << 2) \
                          + ((array[4]) << 3) \
                          + ((array[3]) << 4) \
                          + ((array[2]) << 5) \
                          + ((array[1]) << 6) \
                          + ((array[0]) << 7) )

#define array2Shiftregister(a) byte2Shiftregister(array2byte(a))



#endif
