#include "main.h"

int main(void){
  Setting();
  
  while(True){
    if(Settings.Flag_Timer_Tick == True) Tick_Animation();
    if(Settings.Flag_Timer_Sec == True) Timer_Start_Animation();
    
  }
}
