#include <avr/io.h>

void init_mcu(void)
{
    DDRB |= (1<<0);
    PORTB = 0x00;

    ADMUX  |= (1<<MUX1);
    ADCSRA |= (1<<ADEN)|(1<<ADATE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
    DIDR0  |= (1<<ADC2D)|(1<<ADC1D);
}