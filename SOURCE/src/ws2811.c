#include "ws2811.h"

uint8_t ws2811W[LEDS];
uint8_t ws2811wDMA[LEDS + 0x06][0x08];

void Ws2811WUpdate(void){
  for(uint8_t i = 0x00; i < LEDS; i++){
    for(uint8_t k = 0; k < 0x08; k++){
      ws2811wDMA[i + 0x06][k] = (ws2811W[i] & (0x01 << (0x07 - k))) ? LED_HIGHT : LED_LOW;
    }
  }
}

void Ws2811Init(void){
  GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_CNF1 | GPIO_CRL_CNF2 | GPIO_CRL_CNF3);
  GPIOA->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE2 | GPIO_CRL_MODE3;
  GPIOA->CRL |= GPIO_CRL_CNF0_1 | GPIO_CRL_CNF1_1 | GPIO_CRL_CNF2_1 | GPIO_CRL_CNF3_1;
  
  RCC->AHBENR |= RCC_AHBENR_DMA1EN;
  DMA1_Channel7->CPAR = (uint32_t) &TIM2->CCR2;
  DMA1_Channel7->CMAR = (uint32_t) &ws2811wDMA[0x00];
  DMA1_Channel7->CNDTR = (LEDS + 0x06) * 0x08;
  DMA1_Channel7->CCR |= DMA_CCR1_MINC | DMA_CCR1_DIR | DMA_CCR1_PSIZE_0 |DMA_CCR1_CIRC;
  
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  TIM2->PSC = 0x00;
  TIM2->ARR = 0x63;
  TIM2->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE;
  TIM2->DIER = TIM_DIER_CC2DE;
  TIM2->CCER = TIM_CCER_CC2E;
  
  for(uint8_t i = 0x00; i < LEDS; i++){
    ws2811W[i] = 0;
  }
  Ws2811WUpdate();
  
  DMA1_Channel7->CCR |= DMA_CCR2_EN;
  TIM2->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
}
