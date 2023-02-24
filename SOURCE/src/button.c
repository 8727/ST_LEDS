#include "button.h"

struct ButtonInitTypeDef Button;

void Standby(void){
  
  WS2811Clear();
  WS2811Update();
  DelayMs(500);
  
  RCC->APB1ENR |= RCC_APB1ENR_PWREN;
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; 
  PWR->CR |= PWR_CR_PDDS;
  PWR->CR |= PWR_CR_CWUF ; 
  PWR->CSR |= PWR_CSR_EWUP; 
  __WFI();  // или WFE, кому что нужно
}

void Status_Button(void){
  if(BUTTON == True){
    
    // Переключение яркости 
    if(Button.Flag_Button == True && Button.Timer_Button > LONG_BUTTON){
      Button.Timer_Button = 0;
      Settings.Max_Brightness = settingAnimation.Max_Brightness[Settings.Number_Brightness];
      Button.Long_Button = True;
    }
    
    Button.Flag_Button = True;
  }else{
    
    // Выключение
    if(Button.Flag_Button == True && Button.Long_Button == False && Settings.Flag_Power == False) Standby();
    
    Button.Flag_Button = False;
    Button.Long_Button = False;
  }
}
