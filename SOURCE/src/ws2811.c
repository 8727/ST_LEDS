#include "ws2811.h"

uint8_t WS2811_CH1[LEDS_CH1];
uint8_t WS2811_CH2[LEDS_CH2];
uint8_t WS2811_CH3[LEDS_CH3];

uint8_t WS2811_DMA_CH1[WS2811_DMA_LEDS_CH1][0x08];
uint8_t WS2811_DMA_CH2[WS2811_DMA_LEDS_CH2][0x08];
uint8_t WS2811_DMA_CH3[WS2811_DMA_LEDS_CH3][0x08];

void WS2811Clear(void){
  uint8_t l, i;
  for(l=0; l < WS2811_DMA_LEDS_CH1; l++){ for(i=0; i<8; i++){ WS2811_DMA_CH1[l][i] = WS2811_LED_LOW;} }
  for(l=0; l < WS2811_DMA_LEDS_CH2; l++){ for(i=0; i<8; i++){ WS2811_DMA_CH1[l][i] = WS2811_LED_LOW;} }
  for(l=0; l < WS2811_DMA_LEDS_CH3; l++){ for(i=0; i<8; i++){ WS2811_DMA_CH1[l][i] = WS2811_LED_LOW;} }
}

void WS2811Update(void){
  uint8_t i, k;
  for(i = 0x00; i < (LEDS_CH1); i++){
    for(k = 0; k < 0x08; k++){
      WS2811_DMA_CH1[WS2811_RESET + i][k] = (WS2811_CH1[i] & (0x01 << (0x07 - k))) ? WS2811_LED_HIGHT : WS2811_LED_LOW;
    }
  }
  for(i = 0x00; i < (LEDS_CH2); i++){
    for(k = 0; k < 0x08; k++){
      WS2811_DMA_CH2[WS2811_RESET + i][k] = (WS2811_CH2[i] & (0x01 << (0x07 - k))) ? WS2811_LED_HIGHT : WS2811_LED_LOW;
    }
  }
  for(i = 0x00; i < (LEDS_CH3); i++){
    for(k = 0; k < 0x08; k++){
      WS2811_DMA_CH3[WS2811_RESET + i][k] = (WS2811_CH3[i] & (0x01 << (0x07 - k))) ? WS2811_LED_HIGHT : WS2811_LED_LOW;
    }
  }
}


void WS2811Init(void){
  GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_CNF1 | GPIO_CRL_CNF2);
  GPIOA->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE2;
  GPIOA->CRL |= GPIO_CRL_CNF0_1 | GPIO_CRL_CNF1_1 | GPIO_CRL_CNF2_1;
  
  DMA1_Channel5->CPAR = (uint32_t) (&TIM2->CCR1);
  DMA1_Channel5->CMAR = (uint32_t) (&WS2811_DMA_CH1);
  DMA1_Channel5->CNDTR = WS2811_DMA_LEDS_CH1 * 0x08;
  DMA1_Channel5->CCR |= DMA_CCR5_MINC | DMA_CCR5_DIR | DMA_CCR5_PSIZE_0 | DMA_CCR5_CIRC;
  
  DMA1_Channel7->CPAR = (uint32_t) (&TIM2->CCR2);
  DMA1_Channel7->CMAR = (uint32_t) (&WS2811_DMA_CH2);
  DMA1_Channel7->CNDTR = WS2811_DMA_LEDS_CH2 * 0x08;
  DMA1_Channel7->CCR |= DMA_CCR7_MINC | DMA_CCR7_DIR | DMA_CCR7_PSIZE_0 | DMA_CCR7_CIRC;
  
  DMA1_Channel1->CPAR = (uint32_t) (&TIM2->CCR3);
  DMA1_Channel1->CMAR = (uint32_t) (&WS2811_DMA_CH3);
  DMA1_Channel1->CNDTR = WS2811_DMA_LEDS_CH3 * 0x08;
  DMA1_Channel1->CCR |= DMA_CCR3_MINC | DMA_CCR3_DIR | DMA_CCR3_PSIZE_0 | DMA_CCR3_CIRC;
  
  TIM2->PSC = 0x00;
  TIM2->ARR = WS2811_LED_FR;
  TIM2->CCR1 = 0x00;
  TIM2->CCR2 = 0x00;
  TIM2->CCR3 = 0x00;
  TIM2->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE;
  TIM2->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE;
  TIM2->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE;
  TIM2->DIER = TIM_DIER_CC1DE | TIM_DIER_CC2DE | TIM_DIER_CC3DE;
  TIM2->CCER = TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E;
  
  WS2811Clear();
  
  DMA1_Channel5->CCR |= DMA_CCR5_EN;
  DMA1_Channel7->CCR |= DMA_CCR7_EN;
  DMA1_Channel1->CCR |= DMA_CCR1_EN;
  
  TIM2->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
}



