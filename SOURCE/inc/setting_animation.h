#ifndef _SETTING_ANIMATION_H
#define _SETTING_ANIMATION_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"

/* Define --------------------------------------------------------------------*/


struct settingAnimationInitTypeDef{
  uint8_t Max_Brightness[3];
  
};

extern struct settingAnimationInitTypeDef settingAnimation;


void Setings_Animations(void);
#endif /* _SETTING_ANIMATION_H */
