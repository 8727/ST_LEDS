#include "ws2811.h"

uint8_t WS2811_CH1[LEDS_CH1];
uint8_t WS2811_CH2[LEDS_CH2];
uint8_t WS2811_CH3[LEDS_CH3];

uint8_t WS2811_DMA_CH1[LED_RESET + LEDS_CH1][0x08];
uint8_t WS2811_DMA_CH2[LED_RESET + LEDS_CH2][0x08];
uint8_t WS2811_DMA_CH3[LED_RESET + LEDS_CH3][0x08];

void LEDS_Update(void){
  uint8_t i, k;
  for(i = 0x00; i < (LEDS_CH1); i++){
    for(k = 0; k < 0x08; k++){
      WS2811_DMA_CH1[LED_RESET + i][k] = (WS2811_CH1[i] & (0x01 << (0x07 - k))) ? LED_HIGHT : LED_LOW;
    }
  }
  for(i = 0x00; i < (LEDS_CH2); i++){
    for(k = 0; k < 0x08; k++){
      WS2811_DMA_CH2[LED_RESET + i][k] = (WS2811_CH2[i] & (0x01 << (0x07 - k))) ? LED_HIGHT : LED_LOW;
    }
  }
  for(i = 0x00; i < (LEDS_CH3); i++){
    for(k = 0; k < 0x08; k++){
      WS2811_DMA_CH3[LED_RESET + i][k] = (WS2811_CH3[i] & (0x01 << (0x07 - k))) ? LED_HIGHT : LED_LOW;
    }
  }
}


void WS2811Init(void){
  GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_CNF1 | GPIO_CRL_CNF2);
  GPIOA->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE2;
  GPIOA->CRL |= GPIO_CRL_CNF0_1 | GPIO_CRL_CNF1_1 | GPIO_CRL_CNF2_1;
  
  //DMA
  RCC->AHBENR |= RCC_AHBENR_DMA1EN;
  DMA1_Channel5->CPAR = (uint32_t) (&TIM2->CCR1);
  DMA1_Channel5->CMAR = (uint32_t) (&WS2811_DMA_CH1);
  DMA1_Channel5->CNDTR = (LED_RESET + LEDS_CH1) * 0x08;
  DMA1_Channel5->CCR |= DMA_CCR5_MINC | DMA_CCR5_DIR | DMA_CCR5_PSIZE_0 | DMA_CCR5_CIRC;
  
  DMA1_Channel7->CPAR = (uint32_t) (&TIM2->CCR2);
  DMA1_Channel7->CMAR = (uint32_t) (&WS2811_DMA_CH2);
  DMA1_Channel7->CNDTR = (LED_RESET + LEDS_CH2) * 0x08;
  DMA1_Channel7->CCR |= DMA_CCR7_MINC | DMA_CCR7_DIR | DMA_CCR7_PSIZE_0 | DMA_CCR7_CIRC;
  
  DMA1_Channel1->CPAR = (uint32_t) (&TIM2->CCR3);
  DMA1_Channel1->CMAR = (uint32_t) (&WS2811_DMA_CH3);
  DMA1_Channel1->CNDTR = (LED_RESET + LEDS_CH3) * 0x08;
  DMA1_Channel1->CCR |= DMA_CCR3_MINC | DMA_CCR3_DIR | DMA_CCR3_PSIZE_0 | DMA_CCR3_CIRC;
  
  //TIM2
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  TIM2->PSC = 0x00;
  TIM2->ARR = LED_FR;
  TIM2->CCR1 = 0x00;
  TIM2->CCR2 = 0x00;
  TIM2->CCR3 = 0x00;
  TIM2->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE;
  TIM2->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE;
  TIM2->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE;
  TIM2->DIER = TIM_DIER_CC1DE | TIM_DIER_CC2DE | TIM_DIER_CC3DE;
  TIM2->CCER = TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E;
  
  uint8_t o;
  for(o = 0x00; o < LEDS_CH1; o++) WS2811_CH1[o] = 0;
  for(o = 0x00; o < LEDS_CH2; o++) WS2811_CH2[o] = 0;
  for(o = 0x00; o < LEDS_CH3; o++) WS2811_CH3[o] = 0;
  
  LEDS_Update();
  
  DMA1_Channel5->CCR |= DMA_CCR5_EN;
  DMA1_Channel7->CCR |= DMA_CCR7_EN;
  DMA1_Channel1->CCR |= DMA_CCR1_EN;
  
  TIM2->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
}






void ws2812b_init(void){
  flag_rdy = 0;
  
  //Разрешаем такирование переферии
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //Включаем тактирование порта GPIOA
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //таймера TIM2
  RCC->AHBENR |= RCC_AHBENR_DMA1EN;   //и DMA1
  
  /********* Настраиваем PA1 *********/
  //PA1 freq=10Mhz, AF output Push-pull
  GPIOA->CRL &= ~(GPIO_CRL_CNFx);
  GPIOA->CRL |= GPIO_CRL_CNFx_1 | GPIO_CRL_MODEx_1 | GPIO_CRL_MODEx_0;
  
  
  /********* Настойка таймера TIM2 *********/
  //Разрешаем таймеру управлять выводом PA1
  TIM2->CCER |= TIM_CCER_CCxE;    //Разрешаем
  
#ifdef WS2812B_OUTPUT_INVERSE
  TIM2->CCER |= TIM_CCER_CCxP;    //Вывод инверсный
#else
  TIM2->CCER &= ~(TIM_CCER_CCxP); //Вывод не инверсный
#endif
  
  TIM2->CCMRx &= ~(TIM_CCMRy_OCxM); //сбрасываем все биты OCxM
  
  //устанавливаем выход в неактивное состояние
  TIM2->CCMRx |= TIM_CCMRy_OCxM_2; 
  TIM2->CCMRx &= ~(TIM_CCMRy_OCxM_2);
    
  TIM2->CCMRx |= TIM_CCMRy_OCxM_2 | TIM_CCMRy_OCxM_1 | TIM_CCMRy_OCxPE; //режим ШИМ-а
  
  TIM2->CR1 |= TIM_CR1_ARPE;    //Регистры таймера с буферизацией
  TIM2->DIER |= TIM_DIER_CCxDE; //Разрешить запрос DMA
  
  //Настраиваем канал DMA
  DMA1_Channelx->CPAR = (uint32_t)(&TIM2->CCRx); //Куда пишем
  DMA1_Channelx->CMAR = (uint32_t)(led_array); //откуда берем
  
  DMA1_Channelx->CCR = DMA_CCR7_PSIZE_0 //регистр переферии 16 бит
    | DMA_CCR7_MINC //режим инкремента указателя памяти
    | DMA_CCR7_DIR; //напревление передачи из памяти в переферию
  
  //Разрешаем обработку прерываний
  NVIC_EnableIRQ(TIM2_IRQn); //от таймера
  NVIC_EnableIRQ(DMA1_Channelx_IRQn); //от DMA
  
  ws2812b_buff_clear();
  bus_retcode(); //сбрасываем шину
}



void ws2812b_buff_clear(void){
	int i;
  for(i = 0;i<WS2812B_NUM_LEDS-2; i++) led_array[i] = WS2812B_0_VAL;
  
  led_array[DATA_LEN-2] = 0;
  led_array[DATA_LEN-1] = 0;
}



int ws2812b_set(int pixn, uint8_t r, uint8_t g, uint8_t b){
  int offset = pixn*24;
  int i;
  uint8_t tmp;
  
  if(pixn > (WS2812B_NUM_LEDS - 1))
    return 1;
  
  //Green component
  tmp = g;
  for(i=0; i<8; i++){
    if(tmp & 0x80)
      led_array[offset + i] = WS2812B_1_VAL;
    else
      led_array[offset + i] = WS2812B_0_VAL;
    tmp<<=1;
  }
  
  //Red component
  tmp = r;
  for(i=0; i<8; i++){
    if(tmp & 0x80)
      led_array[offset + i + 8] = WS2812B_1_VAL;
    else
      led_array[offset + i + 8] = WS2812B_0_VAL;
    tmp<<=1;
  }
  
  //Blue component
  tmp = b;
  for(i=0; i<8; i++){
    if(tmp & 0x80)
      led_array[offset + i + 16] = WS2812B_1_VAL;
    else
      led_array[offset + i + 16] = WS2812B_0_VAL;
    tmp<<=1;
  }
  
  return 0;
}





int ws2812b_send(void){
  if(flag_rdy){ //Если сейчас ни чего не передается
    //Устанавливаем флаг занятости интерфейса
    flag_rdy = 0;
    
    //Настраиваем передачу данных
    DMA1_Channelx->CCR &= ~(DMA_CCR7_EN); //Отключаем канал DMA
    DMA1_Channelx->CNDTR = sizeof(led_array); //Устанавливаем количество данных
    
    //Таймер будет считать до WS2812B_TIMER_AAR, и
    //при данной частоте тактирования таймера
    //получается период ШИМ-сигнала, равный 1.25мкс
    TIM2->ARR = WS2812B_TIMER_AAR;
    TIM2->CCRx = 0x0000; //Устанавливаем ШИМ-регистр таймера в ноль
    TIM2->CNT = 0; //Очищаем счетный регистр
    TIM2->CR1 |= TIM_CR1_CEN; //Запускаем таймер
    //Так как значение ШИМ установили в ноль,то на шине будет установлен неактивный уровень
    //до момента запуска DMA  
    
    DMA1->IFCR = DMA_IFCR_CTEIFx | DMA_IFCR_CHTIFx | DMA_IFCR_CTCIFx | DMA_IFCR_CGIFx; //Очищаем все флаги прерываний DMA
    DMA1_Channelx->CCR |= DMA_CCRx_TCIE; //прерывание завершения передачи
    
    //Включаем канал DMA, тем самым начинаем передачу данных
    DMA1_Channelx->CCR |= DMA_CCRx_EN; 
    return 0;
  }else{
    return 1;
  }
}

int ws2812b_is_ready(void){
  return flag_rdy;
}

static void bus_retcode(void){
  TIM2->CR1 &= ~(TIM_CR1_CEN); //останавливаем таймер
  TIM2->ARR = WS2812B_TIMER_RET; //Устанавливаем период немного больше 50мкс
  TIM2->CNT = 0; //Очищаем счетный регистр
  TIM2->CCRx = 0x0000; //значение ШИМ-а ноль
  TIM2->SR &= ~(TIM_SR_UIF); //сбрасываем флаг прерывания
  TIM2->DIER |= TIM_DIER_UIE; //прерывание по обновлению
  TIM2->CR1 |= TIM_CR1_CEN; //Начинаем считать.
}

//Сюда заходим после завершения передачи данных
void DMA1_Channelx_IRQHandler(void){
  DMA1_Channelx->CCR &= ~(DMA_CCRx_EN); //Отключаем канал DMA
  DMA1->IFCR = DMA_IFCR_CTEIFx | DMA_IFCR_CHTIFx | DMA_IFCR_CTCIFx | DMA_IFCR_CGIFx; 
  //Сбрасываем все флаги прерываний
  //Так как последние 2 элемента массива равны нулю,то сейчас предпоследнее значение уже загружено
  //в теневой регистр сравненияи на шине установлено неактивное состояние.
  //Задача заключается в удержании шины в этом состоянии в течение 50мкс или более
  //перед установкой флага готовности интерфейса.
  
  bus_retcode();
}

//Сюда попадаем после завершения формирования сигнала RET шины ws2812b
void TIM2_IRQHandler(void){
  TIM2->SR = 0; //Сбрасываем все флаги прерываний  
  //Мы завершили формирование сигнала RET на шине и теперь можно сделать все завершающие операции 
  //и установить флаг готовности интерфейса к следующей передаче данных. 
  TIM2->CR1 &= ~(TIM_CR1_CEN); //останавливаем таймер
  TIM2->DIER &= ~(TIM_DIER_UIE); //запрещаем прерывание таймера
  flag_rdy = 1;
}


