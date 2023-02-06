#include "lighting.h"

struct TimerAnimationInitTypeDef TimerAnimation;
struct JobAnimationInitTypeDef JobAnimation[ANIMATIONS];
struct SettingsAnimationInitTypeDef SettingsAnimation[ANIMATIONS];

uint16_t Function_RAND(uint8_t min, uint8_t max){
	return min + rand() % ((max + 1) - min);
	}

void AnimationPWM(void){
	for(uint8_t i = 0; i < ANIMATIONS; i++){
		if(SettingsAnimation[i].Channel == 0){
			
			if(JobLed[i].Status != 0){
			// Тип анимации
			if(SettingsAnimation[i].Type_Animation == 0){
				
				// Звездное небо
				for(uint8_t led = 0; i < LEDS; i++){
					if(JobLed[i].Status_Led[led] == 1 && (WS2811_CH1[led] <= JobLed[i].Brightness - SettingsAnimation[i].Speed_up_Brightness)) WS2811_CH1[led] += SettingsAnimation[i].Speed_up_Brightness;
					if(JobLed[i].Status_Led[led] == 2 && (WS2811_CH1[led] >= JobLed[i].Min_Brightness + SettingsAnimation[i].Speed_dw_Brightness)) WS2811_CH1[led] -= SettingsAnimation[i].Speed_dw_Brightness;
					
					if(JobLed[i].Status_Led[led] == 1 && (WS2811_CH1[led] >= JobLed[i].Brightness - SettingsAnimation[i].Speed_up_Brightness)) SettingsAnimation[i].Status_Led[led] = 2;
					if(JobLed[i].Status_Led[led] == 2 && (WS2811_CH1[led] <= SettingsAnimation[i].Min_Brightness + SettingsAnimation[i].Speed_dw_Brightness)){
						JobLed[i].Status_Led[led] = 0;
						WS2811_CH1[led] = SettingsAnimation[i].Min_Brightness;
					}
				}
				
			// Комета
			}else{
			
			
			
			
			
				}
			}
		}
		if(SettingsAnimation[i].Channel == 1){
		
			
		}
		if(SettingsAnimation[i].Channel == 2){
		
			
		}
  }
	WS2811Update();
}

void AnimationTimer(void){
  for(uint8_t i = 0; i < ANIMATIONS; i++){
		// Проверяем таймер запуска анимации
    if(SettingsAnimation[i].Start != 0 && SettingsAnimation[i].Status == 0){ SettingsAnimation[i].Start--; }
		if(SettingsAnimation[i].Start == 0 && SettingsAnimation[i].Status == 0){ SettingsAnimation[i].Status = 1; }
			
		// Проверяем завершение анимации, генерируем время старта
		if(SettingsAnimation[i].Start == 0 && SettingsAnimation[i].Status == 0xFF){ 
			SettingsAnimation[i].Status = 0;
			SettingsAnimation[i].Start = Function_RAND(SettingsAnimation[i].Min_Start, SettingsAnimation[i].Max_Start);
			
			// Тип анимации
			if(SettingsAnimation[i].Type_Animation == 0){
			
				// Звездное небо
				// Генерируем смучайную не светящюю звезду из диапазона
				do{ SettingsAnimation[i].Number_Led = Function_RAND(SettingsAnimation[i].Stop_Led, SettingsAnimation[i].Star_Led);
				}while(SettingsAnimation[i].Status_Led[SettingsAnimation[i].Number_Led]);
				
				// Включаем светодиод
				SettingsAnimation[i].Status_Led[SettingsAnimation[i].Number_Led] = 1;
				
				// Генерируем максимальную яркость
				SettingsAnimation[i].Brightness = Function_RAND(SettingsAnimation[i].Min_Brightness, SettingsAnimation[i].Max_Brightness);
				
				// Генерируем скорость зажегания и угасания
				SettingsAnimation[i].Speed_up_Brightness = Function_RAND(SettingsAnimation[i].Speed_Min, SettingsAnimation[i].Speed_Max);
				SettingsAnimation[i].Speed_dw_Brightness = Function_RAND(SettingsAnimation[i].Speed_Min, SettingsAnimation[i].Speed_Max);
			
			// Комета	
			}else{
	
				// Генерируем направление
				SettingsAnimation[i].Direction = Function_RAND(0, 1);
				
				// Генерируем скорость кометы
				SettingsAnimation[i].Speed_comet = Function_RAND(SettingsAnimation[i].Speed_Min, SettingsAnimation[i].Speed_Max);
			}	
		} 
  }
}
