#ifndef _WS2811_H
#define _WS2811_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"

/* Define --------------------------------------------------------------------*/

#define WS2811_LED_FR           0x5A
#define WS2811_LED_LOW          WS2811_LED_FR / 3
#define WS2811_LED_HIGHT        WS2811_LED_LOW * 2
#define WS2811_RESET            0x1A


extern uint8_t WS2811_CH1[];
extern uint8_t WS2811_CH2[];
extern uint8_t WS2811_CH3[];

void WS2811Reset(void);
void WS2811Init(void);

#endif /* _WS2811_H */
