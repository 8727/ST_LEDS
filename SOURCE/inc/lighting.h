#ifndef _LIGHTING_H
#define _LIGHTING_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"
#include "ws2811.h"


/* Define --------------------------------------------------------------------*/
#define ANIMATIONS                         0x08              // количество анимаций


struct AnimationInitTypeDef{
  uint16_t Start;

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
  uint8_t Speed_up_Brightness;
  uint8_t Speed_dw_Brightness;
  uint8_t Comet_Speed_Min;
  uint8_t Comet_Speed_Max;
};

extern struct AnimationInitTypeDef Animation[ANIMATIONS];
extern struct SettingsAnimationInitTypeDef SettingsAnimation[ANIMATIONS];

#endif /* _LIGHTING_H */
