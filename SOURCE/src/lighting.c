#include "lighting.h"

struct SettingsInitTypeDef Settings;
struct JobAnimationInitTypeDef JobAnimation[ANIMATIONS];
struct SettingsAnimationInitTypeDef SettingsAnimation[ANIMATIONS];

uint16_t Function_RAND(uint8_t min, uint8_t max){
  return min + rand() % ((max + 1) - min);
  }

void Tick_Animation(void){
  for(uint8_t a = 0; a < ANIMATIONS; a++){
    if(SettingsAnimation[a].Channel == 0){
      
      // Тип анимации
      if(SettingsAnimation[a].Type_Animation == 0){
        
        // Звездное небо
        for(uint8_t leds = 0; leds < LEDS; leds++){
          if(JobAnimation[a].Status_Sky[leds] == 1 && (WS2811_CH1[leds] <= JobAnimation[a].Max_Brightness - JobAnimation[a].Speed_up_Brightness)) WS2811_CH1[leds] += JobAnimation[a].Speed_up_Brightness;
          if(JobAnimation[a].Status_Sky[leds] == 2 && (WS2811_CH1[leds] >= SettingsAnimation[a].Min_Brightness + JobAnimation[a].Speed_dw_Brightness)) WS2811_CH1[leds] -= JobAnimation[a].Speed_dw_Brightness;
          
          if(JobAnimation[a].Status_Sky[leds] == 1 && (WS2811_CH1[leds] >= JobAnimation[a].Max_Brightness - JobAnimation[a].Speed_up_Brightness)) JobAnimation[a].Status_Sky[leds] = 2;
          if(JobAnimation[a].Status_Sky[leds] == 2 && (WS2811_CH1[leds] <= SettingsAnimation[a].Min_Brightness + JobAnimation[a].Speed_dw_Brightness)){
            JobAnimation[a].Status_Sky[leds] = 0;
            WS2811_CH1[leds] = SettingsAnimation[a].Min_Brightness;
          }
        }
        
      // Комета
      }else{
      
        if(JobAnimation[a].Direction == 1){
          WS2811_CH1[SettingsAnimation[a].Star_Led + JobAnimation[a].Comet_Led] = JobAnimation[a].Max_Brightness;
          
          
          
          
          
            pwm.brightness[i+5] = MAX_BRIGHTHESS;
            DelayMs(pwm.speed);
            pwm.brightness[i+5] = MIN_BRIGHTHESS;
          
        }
      }
    }
    if(SettingsAnimation[a].Channel == 1){
    
      
    }
    if(SettingsAnimation[a].Channel == 2){
    
      
    }
  }
  WS2811Update();
}

void Timer_Start_Animation(void){
  uint8_t led;
  uint8_t status;
  uint8_t jomp;
  uint16_t tick;
  for(uint8_t i = 0; i < ANIMATIONS; i++){
    
    // Проверяем таймер запуска анимации
    if(JobAnimation[i].Timer_Start != 0 && JobAnimation[i].Status_Comet == 0){ JobAnimation[i].Timer_Start--; }
      
    // Тип анимации
    if(SettingsAnimation[i].Type_Animation == 0){
      
      // Звездное небо
      if(JobAnimation[i].Timer_Start == 0){
      
        // Генерируем смучайную не светящюю звезду из диапазона
        tick = (TICK_LEDS);
        jomp = 0;
        do{
          led = Function_RAND(SettingsAnimation[i].Star_Led, SettingsAnimation[i].Stop_Led);
          status = JobAnimation[i].Status_Sky[led];
          
          // Выход по количеству попыток
          if(tick == 0){ status = 0; jomp = 1; }
          tick--;
        }while(status);
        
        if(jomp == 1){
          // Включаем светодиод
          JobAnimation[i].Status_Sky[led] = 1;
          
          // Генерируем максимальную яркость
          JobAnimation[i].Max_Brightness = Function_RAND(SettingsAnimation[i].Min_Brightness, Settings.Max_Brightness);
          
          // Генерируем скорость зажегания и угасания
          JobAnimation[i].Speed_up_Brightness = Function_RAND(SettingsAnimation[i].Speed_Min, SettingsAnimation[i].Speed_Max);
          JobAnimation[i].Speed_dw_Brightness = Function_RAND(SettingsAnimation[i].Speed_Min, SettingsAnimation[i].Speed_Max);
          
          // Генерируем время старта
          JobAnimation[i].Timer_Start = Function_RAND(SettingsAnimation[i].Min_Start, SettingsAnimation[i].Max_Start);
        }
      }
      
    // Комета  
    }else{
      
      // Ззапуска анимации
      if(JobAnimation[i].Timer_Start == 0 && JobAnimation[i].Status_Comet == 0){
        
        // Генерируем направление
        JobAnimation[i].Direction = Function_RAND(0, 1);
        
        // Количество светодиодов в комете
        JobAnimation[i].Comet_Leds = ((SettingsAnimation[i].Stop_Led - SettingsAnimation[i].Star_Led) + 1);
        JobAnimation[i].Comet_Led = 0;
        
        // Генерируем скорость кометы
        JobAnimation[i].Speed_comet = Function_RAND(SettingsAnimation[i].Speed_Min, SettingsAnimation[i].Speed_Max);
        JobAnimation[i].Status_Comet = 1;
        //JobAnimation[i].Status_Comet = JobAnimation[i].Status_Comet;
      }
      
      // Проверяем завершение анимации 
      if(JobAnimation[i].Timer_Start == 0 && JobAnimation[i].Status_Comet == 0xFF){ 
        JobAnimation[i].Status_Comet = 0;
        
        // Генерируем время старта
        JobAnimation[i].Timer_Start = Function_RAND(SettingsAnimation[i].Min_Start, SettingsAnimation[i].Max_Start);
      }
    }
  }
}
