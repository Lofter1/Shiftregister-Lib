#ifndef SN74HC595_H
#define SN74HC595_H

#define SHIFTREGISTER_LENGTH 8

#ifndef SHIFTREGISTER_PORT
  #define SHIFTREGISTER_PORT PORTB
#endif


#define array2byte(array) ((array[7]) \
                        + ((array[6]) << 1) \
                        + ((array[5]) << 2) \
                        + ((array[4]) << 3) \
                        + ((array[3]) << 4) \
                        + ((array[2]) << 5) \
                        + ((array[1]) << 6) \
                        + ((array[0]) << 7) )

#define array2Shiftregister(shiftregiser, array) \
                    byte2Shiftregister((shiftregister), array2byte((array)) )


struct shiftregister{
  uint8_t serialDataPin;
  uint8_t shiftClockPin;
  uint8_t storageClockPin;
//  char port;  //could be used to determine which port the shiftregister uses
};

/*extern void array2Shiftregister(struct shiftregister dataShiftregister,
                                      uint8_t data[SHIFTREGISTER_LENGTH]);*/
extern void byte2Shiftregister( struct shiftregister dataShiftregister,
                                      uint8_t byte);

#endif
