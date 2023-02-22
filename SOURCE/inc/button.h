#ifndef _BUTTON_H
#define _BUTTON_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"

/* Define --------------------------------------------------------------------*/
#define BUTTON												(GPIOA->IDR & GPIO_IDR_IDR0)

struct ButtonInitTypeDef{
  uint8_t Status_Button;
	uint16_t Timer_Button;

  
};

extern struct ButtonInitTypeDef Button;

#endif /* _BUTTON_H */
