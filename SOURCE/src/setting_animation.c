#include "setting_animation.h"

struct settingAnimationInitTypeDef settingAnimation;

void Setings_Animations(void){
  settingAnimation.Max_Brightness[0] = 255;
  settingAnimation.Max_Brightness[1] = 192;
  settingAnimation.Max_Brightness[2] = 128;
  
  SettingsAnimation[0].Channel = 0;
  SettingsAnimation[0].Type_Animation = 0;
  SettingsAnimation[0].Min_Start = 1;
  SettingsAnimation[0].Max_Start = 10;
  SettingsAnimation[0].Star_Led = 0;
  SettingsAnimation[0].Stop_Led = 3;
  SettingsAnimation[0].Min_Brightness = 0;
  SettingsAnimation[0].Speed_Min = 0;
  SettingsAnimation[0].Speed_Max = 10;
  
  
  
  
  
  
  
  
  
  
  
  JobAnimation[0].Timer_Start = 1;
}
