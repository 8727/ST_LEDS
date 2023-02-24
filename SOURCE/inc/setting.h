#ifndef _SETTING_H
#define _SETTING_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "main.h"
#include "ws2811.h"
#include "lighting.h"
#include "button.h"
#include "setting_animation.h"



/* Define --------------------------------------------------------------------*/

#define TIMER_ON                   10

struct SettingsInitTypeDef{
  uint8_t Start_Power;
  
  uint8_t Flag_Power;
  uint8_t Timer_Power;
  uint8_t Number_Brightness;
  
  uint8_t Flag_Timer_Sec;
  uint8_t Flag_Timer_Tick;
  uint16_t Timer_Sec;
  uint16_t Timer_Tick;
  uint8_t Max_Brightness;
  
  
};


extern struct SettingsInitTypeDef Settings;

uint32_t GetTick(void);
void DelayMs(uint32_t ms);
void Setting(void);

#endif /* _SETTING_H */
