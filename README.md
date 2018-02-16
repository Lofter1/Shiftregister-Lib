# Shiftregister-Lib
An ATmega328P-Library for the use of Shiftregisters like the SN74HC595

<<<<<<< HEAD
## SN74HC595.h
=======
### Macros
    SHIFTREGISTER_LENGTH = 8  
    SHIFTREGISTER_PORT PORTB  //will only be defined if not already defined
    SHIFTREGISTER_DDR  DDRB   //will only be defined if not already defined
>>>>>>> master

### Macros

    SHIFTREGISTER_DDR		  the data directory, by default ddrb  
    SHIFTREGISTER_PORT  	the port of the shiftregiser, by default portb  
    SHIFTREGISTER_DP  		the dataport pin  
    SHIFTREGISTER_STCP		the storageclock pin  
    SHIFTREGISTER_SHCP		the shiftclock pin

Remember that, if you want to change the values, you need to define the macros before including the header-file or instead change the values in the header itself.


### Functions

**Array2Shiftregister**

    void array2Shiftregister(uint8_t data[SHIFTREGISTER_LENGTH]);


Description  
Writes the array into the shiftregister (array[0] = Q0, array[1] = Q1, ...)  
Actually, array2Shiftregister is a macro, that calculates a byte out of the array and uses byte2Shiftregister to write the calculated byte to the shiftregister.

**Byte2Shiftregister**  

    void byte2Shiftregister(uint8_t byte);

Description  
Writes the byte (the uint8_t) into the shiftregister, starting with the right bit (Q7) going to the left bit (Q0)
