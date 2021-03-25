#ifndef _WS2812_H
#define _WS2812_H 

void ws2812_set_light(uint8_t R, uint8_t G, uint8_t B);
void ws2812_reset(void);
void send_one(void);
void send_zero(void);

#endif