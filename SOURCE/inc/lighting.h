#ifndef _LIGHTING_H
#define _LIGHTING_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdlib.h>
#include "setting.h"
#include "ws2811.h"


/* Define --------------------------------------------------------------------*/
#define LEDS                               33
#define TICK_LEDS                          LEDS * 3
#define ANIMATIONS                         16              // количество анимаций

struct JobAnimationInitTypeDef{
  uint16_t Timer_Start;
  uint8_t Status_Comet;
  uint8_t Status_Sky[LEDS];
  uint8_t Max_Brightness;
  uint8_t Speed_up_Brightness;
  uint8_t Speed_dw_Brightness;
  uint8_t Speed_comet;
  uint8_t Direction;
  uint8_t Comet_Tick;
  uint8_t Comet_Leds;
  uint8_t Comet_Led;
  
};

struct SettingsAnimationInitTypeDef{
  uint8_t Enable;
  uint8_t Channel;
  uint8_t Type_Animation;
  uint8_t Min_Start;
  uint8_t Max_Start;
  uint8_t Star_Led;
  uint8_t Stop_Led;
  uint8_t Min_Brightness;
  uint8_t Speed_Min;
  uint8_t Speed_Max;
  
};

extern struct JobAnimationInitTypeDef JobAnimation[ANIMATIONS];
extern struct SettingsAnimationInitTypeDef SettingsAnimation[ANIMATIONS];

void Tick_Animation(void);
void Timer_Start_Animation(void);

#endif /* _LIGHTING_H */
