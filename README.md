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


**setShiftregister**  

    uint8_t setShiftregister(uint8_t data);

Description

Writes the byte (the uint8_t) into the shiftregister, starting with the right bit (Q7) going to the left bit (Q0) and returns the status of the shiftregister (see getShiftStatus).

**getShiftStatus**

    uint8_t getShiftStatus();

Description

Returns the current status of the shiftregister as a byte (uint8_t), where the left bit is Q0 and the right bit Q7.

**setPin**

    uint8_t setPin(uint8_t pin, uint8_t pinStatus);

Description

Sets the pin of the shiftregister to high (pinStatus = 1) or low (pinStatus = 0) and returns the current state of the shiftregister as a byte (see getShiftStatus)
