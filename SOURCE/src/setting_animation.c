#include "setting_animation.h"

struct settingAnimationInitTypeDef settingAnimation;

void Setings_Animations(void){
  uint8_t animation;
  
  Settings.Start_Power = 1;
  settingAnimation.Max_Brightness[0] = 255;
  settingAnimation.Max_Brightness[1] = 192;
  settingAnimation.Max_Brightness[2] = 128;
  
  animation = 0;
  SettingsAnimation[animation].Channel = 0;
  SettingsAnimation[animation].Type_Animation = 0;
  SettingsAnimation[animation].Min_Start = 1;
  SettingsAnimation[animation].Max_Start = 10;
  SettingsAnimation[animation].Star_Led = 0;
  SettingsAnimation[animation].Stop_Led = 3;
  SettingsAnimation[animation].Min_Brightness = 0;
  SettingsAnimation[animation].Speed_Min = 0;
  SettingsAnimation[animation].Speed_Max = 10;
  SettingsAnimation[animation].Enable = True;
  JobAnimation[animation].Timer_Start = Settings.Start_Power;
  
  animation = 1;
  SettingsAnimation[animation].Channel = 0;
  SettingsAnimation[animation].Type_Animation = 1;
  SettingsAnimation[animation].Min_Start = 1;
  SettingsAnimation[animation].Max_Start = 10;
  SettingsAnimation[animation].Star_Led = 0;
  SettingsAnimation[animation].Stop_Led = 3;
  SettingsAnimation[animation].Min_Brightness = 0;
  SettingsAnimation[animation].Speed_Min = 0;
  SettingsAnimation[animation].Speed_Max = 10;
  SettingsAnimation[animation].Enable = True;
  JobAnimation[animation].Timer_Start = Settings.Start_Power;
  
}
