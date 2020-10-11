#Makefile for AVR attiny13_ws2812 

MCU=attiny13
F_CPU=9600000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-mmcu=${MCU} -DF_CPU=${F_CPU} -Os 
TARGET=main
SRC=main.c
SRC+=ws2812.c init_mcu.c

#AVRDUDE 
PROGRAMMER=avrisp2
AVRDUDE_MCU=t13 

#FUSE BITS
LFUSE=0x7a
HFUSE=0xff

all:
	${CC} ${CFLAGS} -o ${TARGET}.o ${SRC}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex	

signature:
	avrdude -c ${PROGRAMMER} -P usb -p ${AVRDUDE_MCU} 

fuse:
	avrdude -c ${PROGRAMMER} -P usb -p ${AVRDUDE_MCU} -U lfuse:w:${LFUSE}:m -U hfuse:w:${HFUSE}:m 

flash:
	avrdude -c ${PROGRAMMER} -P usb -p ${AVRDUDE_MCU} -U flash:w:${TARGET}.hex 

clean:
	rm -f *.o *.hex
