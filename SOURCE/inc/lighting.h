#ifndef _LIGHTING_H
#define _LIGHTING_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdlib.h>
#include "setting.h"
#include "ws2811.h"


/* Define --------------------------------------------------------------------*/
#define ANIMATIONS                         0x10              // количество анимаций

struct TimerAnimationInitTypeDef{
  uint16_t Sec;
  uint16_t Pwm;
};

struct JobAnimationInitTypeDef{
	uint8_t Channel;
	uint16_t Start;
	uint8_t Status;
	uint8_t Status_Led[LEDS];
	uint8_t Number_Led;
  uint8_t Min_Brightness;
  uint8_t Max_Brightness;
  uint8_t Speed_up_Brightness;
  uint8_t Speed_dw_Brightness;
	uint8_t Speed_comet;
	uint8_t Direction;
};


struct SettingsAnimationInitTypeDef{
  uint8_t Channel;
  uint8_t Type_Animation;
  uint8_t Min_Start;
  uint8_t Max_Start;
  uint8_t Star_Led;
  uint8_t Stop_Led;
  uint8_t Min_Brightness;
  uint8_t Max_Brightness;
  uint8_t Speed_Min;
  uint8_t Speed_Max;
};

extern struct TimerAnimationInitTypeDef TimerAnimation;
extern struct JobAnimationInitTypeDef JobAnimation[ANIMATIONS];
extern struct SettingsAnimationInitTypeDef SettingsAnimation[ANIMATIONS];


void AnimationPWM(void);
void AnimationTimer(void);

#endif /* _LIGHTING_H */
