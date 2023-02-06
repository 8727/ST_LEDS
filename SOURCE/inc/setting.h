#ifndef _SETTING_H
#define _SETTING_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "main.h"
#include "ws2811.h"
#include "lighting.h"


/* Define --------------------------------------------------------------------*/




uint32_t GetTick(void);
void DelayMs(uint32_t ms);
void Setting(void);

#endif /* _SETTING_H */
