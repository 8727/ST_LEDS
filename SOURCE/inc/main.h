#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"


/* Define --------------------------------------------------------------------*/
#define ANIMATION_1_CHANNEL               0                                       // Канал 0, 1, 2
#define ANIMATION_1_ANIMATION             SKY                                     // SKY звездное небо, COMET комета
#define ANIMATION_1_MIN_START             50                                      // 50 сек
#define ANIMATION_1_START_LED             0                                       // 
#define ANIMATION_1_STOP_LED              10                                      // 
#define ANIMATION_1_BRIGHTNESS_MIN        0                                       // Минимальная яркость
#define ANIMATION_1_BRIGHTNESS_MAX        255                                     // Максимальная яркость
#define ANIMATION_1_BRIGHTNESS_SPEED      255                                     // Скорось яркости

#define ANIMATION_2_CHANNEL               1                                       // Канал 0, 1, 2
#define ANIMATION_2_ANIMATION             COMET                                   // SKY звездное небо, COMET комета
#define ANIMATION_2_MIN_START             50                                      // 50 сек
#define ANIMATION_2_START_LED             0                                       // 
#define ANIMATION_2_STOP_LED              10                                      // 
#define ANIMATION_2_BRIGHTNESS_MIN        0                                       // Минимальная яркость
#define ANIMATION_2_BRIGHTNESS_MAX        255                                     // Максимальная яркость
#define ANIMATION_2_BRIGHTNESS_SPEED      255                                     // Скорось яркости


#endif /* __MAIN_H */
