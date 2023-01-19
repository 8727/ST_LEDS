#include "lighting.h"

struct AnimationInitTypeDef Animation[ANIMATIONS];
struct SettingsAnimationInitTypeDef SettingsAnimation[ANIMATIONS];

void AnimationTimer(void){
  for(uint8_t i = 0; i < ANIMATIONS; i++){
    Animation[i].Start = 0;
    }


}
