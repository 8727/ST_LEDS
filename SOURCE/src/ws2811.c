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
  GPIOA->CRL &= ~(GPIO_CRL_CNF6);
  GPIOA->CRL |= GPIO_CRL_MODE6;
  GPIOA->CRL |= GPIO_CRL_CNF6_1;
  
  GPIOB->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_CNF1);
  GPIOB->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1;
  GPIOB->CRL |= GPIO_CRL_CNF0_1 | GPIO_CRL_CNF1_1;
  
  DMA1_Channel6->CPAR = (uint32_t) (&TIM3->CCR1);
  DMA1_Channel6->CMAR = (uint32_t) (&WS2811_DMA_CH1);
  DMA1_Channel6->CNDTR = WS2811_DMA_LEDS_CH1 * 0x08;
  DMA1_Channel6->CCR |= DMA_CCR6_MINC | DMA_CCR6_DIR | DMA_CCR6_PSIZE_0 | DMA_CCR6_CIRC;
  
  DMA1_Channel2->CPAR = (uint32_t) (&TIM3->CCR3);
  DMA1_Channel2->CMAR = (uint32_t) (&WS2811_DMA_CH2);
  DMA1_Channel2->CNDTR = WS2811_DMA_LEDS_CH2 * 0x08;
  DMA1_Channel2->CCR |= DMA_CCR2_MINC | DMA_CCR2_DIR | DMA_CCR2_PSIZE_0 | DMA_CCR2_CIRC;
  
  DMA1_Channel3->CPAR = (uint32_t) (&TIM3->CCR4);
  DMA1_Channel3->CMAR = (uint32_t) (&WS2811_DMA_CH3);
  DMA1_Channel3->CNDTR = WS2811_DMA_LEDS_CH3 * 0x08;
  DMA1_Channel3->CCR |= DMA_CCR3_MINC | DMA_CCR3_DIR | DMA_CCR3_PSIZE_0 | DMA_CCR3_CIRC;
  
  TIM3->PSC = 0x00;
  TIM3->ARR = WS2811_LED_FR;
  TIM3->CCR1 = 0x00;
  TIM3->CCR3 = 0x00;
  TIM3->CCR4 = 0x00;
  TIM3->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE;
  TIM3->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE;
  TIM3->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE;
  TIM3->DIER = TIM_DIER_CC1DE | TIM_DIER_CC3DE | TIM_DIER_CC4DE;
  TIM3->CCER = TIM_CCER_CC1E | TIM_CCER_CC3E | TIM_CCER_CC4E;
  
  WS2811Clear();
  
  DMA1_Channel6->CCR |= DMA_CCR6_EN;
  DMA1_Channel2->CCR |= DMA_CCR2_EN;
  DMA1_Channel3->CCR |= DMA_CCR3_EN;
  
  TIM3->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
}



