#include "lighting.h"

struct AnimationInitTypeDef Animation[ANIMATIONS];
struct SettingsAnimationInitTypeDef SettingsAnimation[ANIMATIONS];

void AnimationPWM(void){
  for(uint8_t i = 0; i < 10; i++){
    if(led.status[i] == 1 && (pwm.brightness[i] <= pwm.brhMax[i] - pwm.speed_p[i])) pwm.brightness[i] += pwm.speed_p[i];
    if(led.status[i] == 2 && (pwm.brightness[i] >= MIN_BRIGHTHESS + pwm.speed_m[i])) pwm.brightness[i] -= pwm.speed_m[i];
    
    if(led.status[i] == 1 && (pwm.brightness[i] >= pwm.brhMax[i] - pwm.speed_p[i])) led.status[i] = 2;
    if(led.status[i] == 2 && (pwm.brightness[i] <= MIN_BRIGHTHESS + pwm.speed_m[i])){
      led.status[i] = 0;
      pwm.brightness[i] = MIN_BRIGHTHESS;
    }
  }
}


void AnimationTimer(void){
  for(uint8_t i = 0; i < ANIMATIONS; i++){
    if(Animation[i].Start == 0){
      Animation[i].Start = rand() % (SettingsAnimation[i].Max_Start - SettingsAnimation[i].Min_Start) + SettingsAnimation[i].Min_Start;
      
    } 
      
    
  }
}
