#include "setting.h"

static __IO uint32_t msTicks;

void SysTick_Handler(void){
  msTicks++;
  TimerAnimation.Sec++;
  if(TimerAnimation.Sec > 999){
    TimerAnimation.Sec = 0;
    AnimationTimer();
  }
  TimerAnimation.Pwm++;
  if(TimerAnimation.Pwm > 9){
    TimerAnimation.Pwm = 0;
    AnimationPWM();
  }
}

uint32_t GetTick(void){
  return msTicks;
}

void DelayMs(uint32_t ms){
  uint32_t tickstart = GetTick();
  while((GetTick() - tickstart) < ms){}
}

void Setting(void){
  SysTick_Config(SystemCoreClock / 1000);
  
  RCC->AHBENR |= RCC_AHBENR_DMA1EN;
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  
  
  WS2811Init();

}
