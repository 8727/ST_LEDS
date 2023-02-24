#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"


/* Define --------------------------------------------------------------------*/
#define True                                0x01
#define False                               0x00





#define ANIMATION_1_CHANNEL               0                                       // Канал 0, 1, 2
#define ANIMATION_1_ANIMATION             SKY                                     // SKY звездное небо, COMET комета
#define ANIMATION_1_TIMER_MIN_START       0                                       // минимальное время перед запуском анимации 50 сек
#define ANIMATION_1_TIMER_MAX_START       255                                     // максимальное время перед запуском анимации 50 сек
#define ANIMATION_1_START_LED             0                                       // номер светодиода с которого начнеться анимация
#define ANIMATION_1_STOP_LED              255                                     // номер светодиода на котором начнеться анимация
#define ANIMATION_1_BRIGHTNESS_MIN        0                                       // Минимальная яркость
#define ANIMATION_1_BRIGHTNESS_MAX        255                                     // Максимальная яркость
#define ANIMATION_1_BRIGHTNESS_SPEED_UP   0                                       // Скорось загорания
#define ANIMATION_1_BRIGHTNESS_SPEED_DW   255                                     // Скорось затухания
#define ANIMATION_1_COMET_SPEED_MIN       0                                       // Минимальная скорось полета
#define ANIMATION_1_COMET_SPEED_MAX       255                                     // Максимальная скорось полета

#define ANIMATION_2_CHANNEL               0                                       // Канал 0, 1, 2
#define ANIMATION_2_ANIMATION             COMET                                   // SKY звездное небо, COMET комета
#define ANIMATION_2_TIMER_MIN_START       0                                       // минимальное время перед запуском анимации 50 сек
#define ANIMATION_2_TIMER_MAX_START       255                                     // максимальное время перед запуском анимации 50 сек
#define ANIMATION_2_START_LED             0                                       // номер светодиода с которого начнеться анимация
#define ANIMATION_2_STOP_LED              255                                     // номер светодиода на котором начнеться анимация
#define ANIMATION_2_BRIGHTNESS_MIN        0                                       // Минимальная яркость
#define ANIMATION_2_BRIGHTNESS_MAX        255                                     // Максимальная яркость
#define ANIMATION_2_BRIGHTNESS_SPEED_UP   0                                       // Скорось загорания
#define ANIMATION_2_BRIGHTNESS_SPEED_DW   255                                     // Скорось затухания
#define ANIMATION_2_COMET_SPEED_MIN       0                                       // Минимальная скорось полета
#define ANIMATION_2_COMET_SPEED_MAX       255                                     // Максимальная скорось полета

#define ANIMATION_3_CHANNEL               0                                       // Канал 0, 1, 2
#define ANIMATION_3_ANIMATION             SKY                                     // SKY звездное небо, COMET комета
#define ANIMATION_3_TIMER_MIN_START       0                                       // минимальное время перед запуском анимации 50 сек
#define ANIMATION_3_TIMER_MAX_START       255                                     // максимальное время перед запуском анимации 50 сек
#define ANIMATION_3_START_LED             0                                       // номер светодиода с которого начнеться анимация
#define ANIMATION_3_STOP_LED              255                                     // номер светодиода на котором начнеться анимация
#define ANIMATION_3_BRIGHTNESS_MIN        0                                       // Минимальная яркость
#define ANIMATION_3_BRIGHTNESS_MAX        255                                     // Максимальная яркость
#define ANIMATION_3_BRIGHTNESS_SPEED_UP   0                                       // Скорось загорания
#define ANIMATION_3_BRIGHTNESS_SPEED_DW   255                                     // Скорось затухания
#define ANIMATION_3_COMET_SPEED_MIN       0                                       // Минимальная скорось полета
#define ANIMATION_3_COMET_SPEED_MAX       255                                     // Максимальная скорось полета

#define ANIMATION_4_CHANNEL               0                                       // Канал 0, 1, 2
#define ANIMATION_4_ANIMATION             SKY                                     // SKY звездное небо, COMET комета
#define ANIMATION_4_TIMER_MIN_START       0                                       // минимальное время перед запуском анимации 50 сек
#define ANIMATION_4_TIMER_MAX_START       255                                     // максимальное время перед запуском анимации 50 сек
#define ANIMATION_4_START_LED             0                                       // номер светодиода с которого начнеться анимация
#define ANIMATION_4_STOP_LED              255                                     // номер светодиода на котором начнеться анимация
#define ANIMATION_4_BRIGHTNESS_MIN        0                                       // Минимальная яркость
#define ANIMATION_4_BRIGHTNESS_MAX        255                                     // Максимальная яркость
#define ANIMATION_4_BRIGHTNESS_SPEED_UP   0                                       // Скорось загорания
#define ANIMATION_4_BRIGHTNESS_SPEED_DW   255                                     // Скорось затухания
#define ANIMATION_4_COMET_SPEED_MIN       0                                       // Минимальная скорось полета
#define ANIMATION_4_COMET_SPEED_MAX       255                                     // Максимальная скорось полета


#endif /* __MAIN_H */
