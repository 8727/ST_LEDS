#include "setting.h"

struct SettingsInitTypeDef Settings;

static __IO uint32_t msTicks;

void SysTick_Handler(void){
  msTicks++;
  Settings.Timer_Sec++;
  if(Settings.Timer_Sec > 999){
    Settings.Timer_Sec = 0;
    Settings.Flag_Timer_Sec = True;
    if(Settings.Flag_Power == True && (Settings.Timer_Power > 0)) Settings.Timer_Power--;
    if(Settings.Flag_Power == True && (Settings.Timer_Power == 0)) Settings.Flag_Power = False;
  }
  Settings.Timer_Tick++;
  if(Settings.Timer_Tick > 9){
    Settings.Timer_Tick = 0;
    Settings.Flag_Timer_Tick = True;
    if(Button.Flag_Button == True) Button.Timer_Button++;
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
  Settings.Timer_Power = TIMER_ON;
  Settings.Flag_Power = True;
  
  SysTick_Config(SystemCoreClock / 1000);
  
  RCC->AHBENR |= RCC_AHBENR_DMA1EN;
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
  
  WS2811Init();
  
  Setings_Animation();
  Setings_Animations();
}
