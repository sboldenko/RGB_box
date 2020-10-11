#define SET_BIT   PORTB |= (1<<0)
#define UNSET_BIT PORTB &= ~(1<<0)
#define LEDS      24
#define LED_OFF   0x00, 0x00, 0x00

#include <avr/io.h>
#include <avr/sfr_defs.h>

void send_zero(void)
{
	SET_BIT;
	asm("nop");
	asm("nop");
	asm("nop");
	UNSET_BIT;
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
}

void send_one(void)
{
	SET_BIT;
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	UNSET_BIT;
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
}

void ws2812_set_light(uint8_t R, uint8_t G, uint8_t B)
{
	uint8_t i=0;

	for(i=0; i<8; i++)
	{
		if(bit_is_set(G, i))
			send_one();
		else
			send_zero();
	}

	for(i=0; i<8; i++)
	{
		if(bit_is_set(R, i))
			send_one();
		else
			send_zero();
	}

	for(i=0; i<8; i++)
	{
		if(bit_is_set(B, i))
			send_one();
		else
			send_zero();
	}
}

void ws2812_reset(void)
{
	uint8_t n=0;

	while(n<LEDS)
	{
		ws2812_set_light(LED_OFF);
		n++;
	}
}	