#ifndef _SETTING_H
#define _SETTING_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "main.h"
#include "ws2811.h"
#include "lighting.h"



/* Define --------------------------------------------------------------------*/
#define LEDS                  0x09

struct settingsInitTypeDef{
  uint8_t brightnessW[LEDS];
  uint8_t effect;
  
};
extern struct settingsInitTypeDef settings;

uint32_t GetTick(void);
void DelayMs(uint32_t ms);

void Start(void);
void Setting(void);

#endif /* _SETTING_H */
