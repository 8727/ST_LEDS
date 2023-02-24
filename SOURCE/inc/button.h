#ifndef _BUTTON_H
#define _BUTTON_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"

/* Define --------------------------------------------------------------------*/
#define BUTTON                        (GPIOA->IDR & GPIO_IDR_IDR0)
#define LONG_BUTTON                   3000

struct ButtonInitTypeDef{
  uint8_t Flag_Button;
  uint8_t Long_Button;
  uint16_t Timer_Button;

  
};

extern struct ButtonInitTypeDef Button;

void Standby(void);

#endif /* _BUTTON_H */
