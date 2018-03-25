# Shiftregister-Lib
An ATmega328P-Library for the use of Shiftregisters like the SN74HC595


## SN74HC595.h

### Macros

Shiftregister wiring

    SHIFTREGISTER_DDR       the data directory, by default ddrb  
    SHIFTREGISTER_PORT      the port of the shiftregiser, by default portb  
    SERIALDATA_PIN          the dataport pin, by default PB0
    SHIFTCLOCK_PIN          the shiftclock pin, by default PB1
    STORAGECLOCK_PIN        the storageclock pin, by default PB2

Shiftregister output-pins

    SHIFT_D0        1. outputpin (Q0)
    SHIFT_D1        2. outputpin (Q1)
    SHIFT_D2        3. outputpin (Q2)
    SHIFT_D3        4. outputpin (Q3)
    SHIFT_D4        5. outputpin (Q4)
    SHIFT_D5        6. outputpin (Q5)
    SHIFT_D6        7. outputpin (Q6)
    SHIFT_D7        8. outputpin (Q7)


### Functions

**Array2Shiftregister**

    uint8_t array2Shiftregister(uint8_t data[SHIFTREGISTER_LENGTH]);


Description  
Writes the array into the shiftregister (array[0] = Q0, array[1] = Q1, ...)  
Actually, array2Shiftregister is a macro, that calculates a byte out of the array and uses byte2Shiftregister to write the calculated byte to and return the status from the shiftregister (see GetShiftStatus).

**Byte2Shiftregister**  

    uint8_t byte2Shiftregister(uint8_t byte);

Description  
Writes the byte (the uint8_t) into the shiftregister, starting with the right bit (Q7) going to the left bit (Q0) and returns the status of the shiftregister (see GetShiftStatus).

**GetShiftStatus**

    uint8_t getShiftStatus();
    
Description
Returns you the current status of the shiftregister as a byte (uint8_t), where the left bit is Q0 and the right bit Q7.

**SetPin**

    uint8_t setPin(uint8_t pin, uint8_t pinStatus);
    
Description
In the status-variable of the shiftregister the pin is set to pinStatus (1 or 0) and the function then calls byte2shiftregister with the new status as the parameter. Finally, the function returns the new status (see GetShiftStatus).
