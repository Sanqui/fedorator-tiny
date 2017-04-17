DEVICE = m328p
DEVICE_LONG = atmega328p
CLOCK = 8000000
PROGRAMMER = arduino
BAUDRATE = 57600
PORT = /dev/ttyUSB0

OBJECTS = main.o

# ---

AVR_GCC = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE_LONG)

all: main.hex

.c.o:
	$(AVR_GCC) -c $< -o $@

main.elf: $(OBJECTS)
	$(AVR_GCC) -o main.elf $(OBJECTS)
	
main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

flash: all
	avrdude -c $(PROGRAMMER) -b $(BAUDRATE) -p $(DEVICE) -P /dev/ttyUSB0 -v -U flash:w:main.hex:i

clean:
	rm -f main.hex main.elf $(OBJECTS)
