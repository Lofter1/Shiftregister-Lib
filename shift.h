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
#define SHIFTREGISTER_DDR DDRB
#define SHIFTREGISTER_PORT PORTB
#define SERIALDATA_PIN PB0
#define SHIFTCLOCK_PIN PB2
#define STORAGECLOCK_PIN PB1

#define SHIFTREGISTER_LENGTH 8

//Functions
extern uint8_t getShiftStatus();
extern uint8_t setShiftregisterPin (uint8_t pin, uint8_t pinStatus);
extern uint8_t setShiftregister (uint8_t byte);

/*
//Still needed?
#define array2byte(array) ( (array[7]) \
                          + ((array[6]) << 1) \
                          + ((array[5]) << 2) \
                          + ((array[4]) << 3) \
                          + ((array[3]) << 4) \
                          + ((array[2]) << 5) \
                          + ((array[1]) << 6) \
                          + ((array[0]) << 7) )
#define array2Shiftregister(array) setShiftregister(array2byte(array))
*/

#endif
