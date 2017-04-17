#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

#include <stdlib.h>

#define LED      PB5
#define LED_DDR  DDRB
#define LED_PORT PORTB

#define set_bit(sfr, bit)     (_SFR_BYTE(sfr) |= (1 << bit))
#define clear_bit(sfr, bit)   (_SFR_BYTE(sfr) &= ~(1 << bit))
#define toggle_bit(sfr, bit)  (_SFR_BYTE(sfr) ^= (1 << bit))

