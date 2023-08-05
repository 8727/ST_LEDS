#include "setting_animation.h"

struct settingAnimationInitTypeDef settingAnimation;

void Setings_Animation(void){
  Settings.Start_Power = 1;                                   // Время первого старта. сек 
  settingAnimation.Max_Brightness[0] = 255;                   // уовни яркости
  settingAnimation.Max_Brightness[1] = 192;                   // уовни яркости
  settingAnimation.Max_Brightness[2] = 128;                   // уовни яркости
}

/*
  animation = 0;                                              // номер анимации от 0 до 15
  SettingsAnimation[animation].Enable = True;                 // Анимация включена True, выключена False
  SettingsAnimation[animation].Channel = 0;                   // канал 0,1,.2
  SettingsAnimation[animation].Type_Animation = SKY;          // тип анимации SKY звездное небо, COMET комета
  SettingsAnimation[animation].Min_Start = 1;                 // минимальное время перед запуском анимации от 0 до 255 сек
  SettingsAnimation[animation].Max_Start = 10;                // максимальное время перед запуском анимации от 0 до 255 сек
  SettingsAnimation[animation].Star_Led = 0;                  // номер светодиода с которого начнеться анимация
	SettingsAnimation[animation].Stop_Led = 3;                  // номер светодиода на котором закончиться анимация
  SettingsAnimation[animation].Min_Brightness = 0;            // Минимальная яркость
  SettingsAnimation[animation].Speed_Min = 0;                 // Минимальная скорось загорания при SKY, Минимальная скорось полета при COMET
  SettingsAnimation[animation].Speed_Max = 10;                // Максимальная скорось загорания при SKY, Минимальная скорось полета при COMET
  JobAnimation[animation].Timer_Start = Settings.Start_Power; // Время первого старта.
*/

void Setings_Animations(void){
  uint8_t animation;
  
  animation = 0;
  SettingsAnimation[animation].Enable = True;
  SettingsAnimation[animation].Channel = 0;
  SettingsAnimation[animation].Type_Animation = COMET;
  SettingsAnimation[animation].Min_Start = 1;
  SettingsAnimation[animation].Max_Start = 10;
  SettingsAnimation[animation].Star_Led = 0;
  SettingsAnimation[animation].Stop_Led = 2;
  SettingsAnimation[animation].Min_Brightness = 0;
  SettingsAnimation[animation].Speed_Min = 1;
  SettingsAnimation[animation].Speed_Max = 5;
  JobAnimation[animation].Timer_Start = Settings.Start_Power;
  
//  animation = 1;
//  SettingsAnimation[animation].Enable = True;
//  SettingsAnimation[animation].Channel = 0;
//  SettingsAnimation[animation].Type_Animation = COMET;
//  SettingsAnimation[animation].Min_Start = 1;
//  SettingsAnimation[animation].Max_Start = 10;
//  SettingsAnimation[animation].Star_Led = 0;
//  SettingsAnimation[animation].Stop_Led = 2;
//  SettingsAnimation[animation].Min_Brightness = 0;
//  SettingsAnimation[animation].Speed_Min = 0;
//  SettingsAnimation[animation].Speed_Max = 10;
//  JobAnimation[animation].Timer_Start = Settings.Start_Power;
  
}
