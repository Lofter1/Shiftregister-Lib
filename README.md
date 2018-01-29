# Shiftregister-Lib
An ATmega328P-Library for the use of Shiftregisters like the SN74HC595

### Macros
    SHIFTREGISTER_LENGTH = 8  
    SHIFTREGISTER_PORT PORTB  //will only be defined if not already defined
    SHIFTREGISTER_DDR  DDRB   //will only be defined if not already defined


### Structs

**shiftregister**constants and macros

    struct shiftregister{
      uint8_t serialDataPin;
      uint8_t shiftClockPin;
      uint8_t storageClockPin;
    };

### Functions

**Array2Shiftregister**

    void array2Shiftregister(struct shiftregister *dataShiftregister, uint8_t data[SHIFTREGISTER_LENGTH]);


Description  
Writes the array into the shiftregister (array[0] = Q0, array[1] = Q1, ...)  
Actually, array2Shiftregister is a macro, that calculates a byte out of the array and uses byte2Shiftregister to write the calculated byte to the shiftregister.

**Byte2Shiftregister**  

    void byte2Shiftregister( struct shiftregister *dataShiftregister, uint8_t byte);

Description  
Writes the byte (the uint8_t) into the shiftregister, starting with the right bit (Q7) going to the left bit (Q0)
