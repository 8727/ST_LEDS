#ifndef _WS2811_H
#define _WS2811_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"

/* Define --------------------------------------------------------------------*/
#define LED_FR           0x5A
#define LED_LOW          LED_FR / 3
#define LED_HIGHT        LED_LOW * 2

#define LED_RESET        0x1A

extern uint8_t WS2811_CH1[];
extern uint8_t WS2811_CH2[];
extern uint8_t WS2811_CH3[];

void LEDS_Update(void);
void WS2811Init(void);

#endif /* _WS2811_H */
