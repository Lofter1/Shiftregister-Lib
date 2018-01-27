# Shiftregister-Lib
An ATmega328P-Library for the use of Shiftregisters like the SN74HC595

### Defines
    SHIFTREGISTER_LENGTH = 8  
    SHIFTREGISTER_PORT PORTB  //will only be defined if not already defined


### Structs

**shiftregister**

    struct shiftregister{
      uint8_t serialDataPin;
      uint8_t shiftClockPin;
      uint8_t storageClockPin;
    };

### Functions

**Array2Shiftregister**
   
    void Array2Shiftregister(struct shiftregister dataShiftregister, uint8_t data[SHIFTREGISTER_LENGTH]);

Description  
Writes the array into the shiftregister (array[0] = Q0, array[1] = Q1, ...)  

**Byte2Shiftregister**  

    void Byte2Shiftregister( struct shiftregister dataShiftregister, uint8_t byte);

Description  
Writes the byte (the uint8_t) into the shiftregister, starting with the right bit (Q7) going to the left bit (Q0)
