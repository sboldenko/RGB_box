
#define LEDS      24

#define RED       0x7F, 0x00, 0x00
#define GREEN     0x00, 0x7F, 0x00
#define BLUE      0x00, 0x00, 0x7F
#define TURQUOISE 0x00, 0x7F, 0x7F
#define VIOLET    0x7F, 0x00, 0x7F
#define WHITE     0x7F, 0x7F, 0x7F
#define ORANGE    0x7F, 0x7F, 0x00

#define LED_OFF   0x00, 0x00, 0x00

#include <avr/io.h>
#include <util/delay.h>
#include "init_mcu.h"
#include "ws2812.h"

uint8_t read_adc(void)
{
    ADCSRA |= (1 << ADSC);
    return ADCW;
}

uint8_t k = 0;
uint8_t color = 0;

void led_program(void)
{

        for(k = 0; k < LEDS; k++)
        {
            color++;

            if (color == 7)
                color = 0;

            switch(color)
            {
                case 0: 
                    ws2812_set_light(GREEN);
                    break;
                case 1: 
                    ws2812_set_light(VIOLET);
                    break;
                case 2: 
                    ws2812_set_light(BLUE);
                    break;
                case 3: 
                    ws2812_set_light(ORANGE);
                    break;  
                case 4: 
                    ws2812_set_light(TURQUOISE);
                    break;
                case 5: 
                    ws2812_set_light(RED);
                    break;      
                case 6: 
                    ws2812_set_light(LED_OFF);
                    break;                                      
                default:
                    ws2812_set_light(LED_OFF);  
            }
        }
        
        _delay_ms(200);
}

void main(void)
{
    uint16_t temp;

    init_mcu();
    ws2812_reset();

    while(1)
    {
        temp = read_adc();

        if(temp <= 22)
        {
            led_program();
            k = 0;
        }
        else
        {
            ws2812_reset();
            _delay_ms(500);
        }
    }
}