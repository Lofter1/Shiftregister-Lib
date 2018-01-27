# Shiftregister-Lib
An ATmega328P-Library for the use of Shiftregisters like the SN74HC595

### Defines
    SHIFTREGISTER_LENGTH = 8  
    SHIFTREGISTER_PORT PORTB  
    -> will only be defined if it is not already defined  


### Structs

**shiftregister**

    uint8_t serialDataPin  
    uint8_t shiftClockPin  
    uint8_t storageClockPin  

### Functions

**Array2Shiftregister**
Returntype

    void  
Arguments

    struct shiftregister  
    uint8_t array  
Description  
Writes the array into the shiftregister (array[0] = Q0, array[1] = Q1, ...)  

**Byte2Shiftregister**  
Returntype

    void  
Arguments

    struct shiftregister  
    uint8_t  
Description  
Writes the byte (the uint8_t) into the shiftregister, starting with the right bit (Q7) going to the left bit (Q0)
