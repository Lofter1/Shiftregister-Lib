#ifndef SHIFT_H
#define SHIFT_H

#include <avr/io.h>

//Define the Pins of the Shiftregister
#define SHIFT_D0 0
#define SHIFT_D1 1
#define SHIFT_D2 2
#define SHIFT_D3 3
#define SHIFT_D4 4
#define SHIFT_D5 5
#define SHIFT_D6 6
#define SHIFT_D7 7

//Define the connection of the Shiftregister
#ifndef SHIFTREGISTER_DDR
#define SHIFTREGISTER_DDR DDRB
#endif
#ifndef SHIFTREGISTER_PORT
#define SHIFTREGISTER_PORT PORTB
#endif
#ifndef SERIALDATA_PIN
#define SERIALDATA_PIN PB0
#endif
#ifndef SHIFTCLOCK_PIN
#define SHIFTCLOCK_PIN PB1
#endif
#ifndef STORAGECLOCK_PIN
#define STORAGECLOCK_PIN PB2
#endif

#define SHIFTREGISTER_LENGTH 8

extern uint8_t getShiftStatus();
extern uint8_t setPin (uint8_t pin, uint8_t pinStatus);
extern uint8_t byte2Shiftregister (uint8_t byte);

#define array2byte(array) ( (array[7]) \
                          + ((array[6]) << 1) \
                          + ((array[5]) << 2) \
                          + ((array[4]) << 3) \
                          + ((array[3]) << 4) \
                          + ((array[2]) << 5) \
                          + ((array[1]) << 6) \
                          + ((array[0]) << 7) )
#define array2Shiftregister(array) byte2Shiftregister(array2byte(array))

#endif
