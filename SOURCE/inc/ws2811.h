#ifndef _WS2811_H
#define _WS2811_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "setting.h"

/* Define --------------------------------------------------------------------*/

#define LED_FR           0x5A
#define LED_LOW          LED_FR / 3
#define LED_HIGHT        LED_LOW * 2

#define LED_RESET        0x1A



#if (WS2812B_OUTPUT_PAx==0)

  #define GPIO_CRL_CNFx           GPIO_CRL_CNF0
  #define GPIO_CRL_CNFx_1         GPIO_CRL_CNF0_1
  #define GPIO_CRL_MODEx_1        GPIO_CRL_MODE0_1
  #define GPIO_CRL_MODEx_0        GPIO_CRL_MODE0_0

  #define TIM_CCER_CCxE           TIM_CCER_CC1E
  #define TIM_CCER_CCxP           TIM_CCER_CC1P

  #define CCMRx                   CCMR1
  #define TIM_CCMRy_OCxM          TIM_CCMR1_OC1M
  #define TIM_CCMRy_OCxM_2        TIM_CCMR1_OC1M_2
  #define TIM_CCMRy_OCxM_1        TIM_CCMR1_OC1M_1
  #define TIM_CCMRy_OCxPE         TIM_CCMR1_OC1PE
  #define TIM_DIER_CCxDE          TIM_DIER_CC1DE
  #define CCRx                    CCR1

  #define DMA1_Channelx           DMA1_Channel5
  #define DMA1_Channelx_IRQn      DMA1_Channel5_IRQn
  #define DMA1_Channelx_IRQHandler        DMA1_Channel5_IRQHandler

  #define DMA_CCRx_EN             DMA_CCR5_EN
  #define DMA_CCRx_TCIE           DMA_CCR5_TCIE

  #define DMA_IFCR_CTEIFx         DMA_IFCR_CTEIF5
  #define DMA_IFCR_CHTIFx         DMA_IFCR_CHTIF5
  #define DMA_IFCR_CTCIFx         DMA_IFCR_CTCIF5
  #define DMA_IFCR_CGIFx          DMA_IFCR_CGIF5

#elif (WS2812B_OUTPUT_PAx==1)

  #define GPIO_CRL_CNFx           GPIO_CRL_CNF1
  #define GPIO_CRL_CNFx_1         GPIO_CRL_CNF1_1
  #define GPIO_CRL_MODEx_1        GPIO_CRL_MODE1_1
  #define GPIO_CRL_MODEx_0        GPIO_CRL_MODE1_0

  #define TIM_CCER_CCxE           TIM_CCER_CC2E
  #define TIM_CCER_CCxP           TIM_CCER_CC2P

  #define CCMRx                   CCMR1
  #define TIM_CCMRy_OCxM          TIM_CCMR1_OC2M
  #define TIM_CCMRy_OCxM_2        TIM_CCMR1_OC2M_2
  #define TIM_CCMRy_OCxM_1        TIM_CCMR1_OC2M_1
  #define TIM_CCMRy_OCxPE         TIM_CCMR1_OC2PE
  #define TIM_DIER_CCxDE          TIM_DIER_CC2DE
  #define CCRx                    CCR2

  #define DMA1_Channelx           DMA1_Channel7
  #define DMA1_Channelx_IRQn      DMA1_Channel7_IRQn
  #define DMA1_Channelx_IRQHandler        DMA1_Channel7_IRQHandler

  #define DMA_CCRx_EN             DMA_CCR7_EN
  #define DMA_CCRx_TCIE           DMA_CCR7_TCIE

  #define DMA_IFCR_CTEIFx         DMA_IFCR_CTEIF7
  #define DMA_IFCR_CHTIFx         DMA_IFCR_CHTIF7
  #define DMA_IFCR_CTCIFx         DMA_IFCR_CTCIF7
  #define DMA_IFCR_CGIFx          DMA_IFCR_CGIF7


#elif (WS2812B_OUTPUT_PAx==2)

  #define GPIO_CRL_CNFx           GPIO_CRL_CNF2
  #define GPIO_CRL_CNFx_1         GPIO_CRL_CNF2_1
  #define GPIO_CRL_MODEx_1        GPIO_CRL_MODE2_1
  #define GPIO_CRL_MODEx_0        GPIO_CRL_MODE2_0

  #define TIM_CCER_CCxE           TIM_CCER_CC3E
  #define TIM_CCER_CCxP           TIM_CCER_CC3P

  #define CCMRx                   CCMR2
  #define TIM_CCMRy_OCxM          TIM_CCMR2_OC3M
  #define TIM_CCMRy_OCxM_2        TIM_CCMR2_OC3M_2
  #define TIM_CCMRy_OCxM_1        TIM_CCMR2_OC3M_1
  #define TIM_CCMRy_OCxPE         TIM_CCMR2_OC3PE
  #define TIM_DIER_CCxDE          TIM_DIER_CC3DE
  #define CCRx                    CCR3

  #define DMA1_Channelx           DMA1_Channel1
  #define DMA1_Channelx_IRQn      DMA1_Channel1_IRQn
  #define DMA1_Channelx_IRQHandler        DMA1_Channel1_IRQHandler

  #define DMA_CCRx_EN             DMA_CCR1_EN
  #define DMA_CCRx_TCIE           DMA_CCR1_TCIE

  #define DMA_IFCR_CTEIFx         DMA_IFCR_CTEIF1
  #define DMA_IFCR_CHTIFx         DMA_IFCR_CHTIF1
  #define DMA_IFCR_CTCIFx         DMA_IFCR_CTCIF1
  #define DMA_IFCR_CGIFx          DMA_IFCR_CGIF1

#elif (WS2812B_OUTPUT_PAx==3)

#define GPIO_CRL_CNFx           GPIO_CRL_CNF3
#define GPIO_CRL_CNFx_1         GPIO_CRL_CNF3_1
#define GPIO_CRL_MODEx_1        GPIO_CRL_MODE3_1
#define GPIO_CRL_MODEx_0        GPIO_CRL_MODE3_0

#define TIM_CCER_CCxE           TIM_CCER_CC4E
#define TIM_CCER_CCxP           TIM_CCER_CC4P

#define CCMRx                   CCMR2
#define TIM_CCMRy_OCxM          TIM_CCMR2_OC4M
#define TIM_CCMRy_OCxM_2        TIM_CCMR2_OC4M_2
#define TIM_CCMRy_OCxM_1        TIM_CCMR2_OC4M_1
#define TIM_CCMRy_OCxPE         TIM_CCMR2_OC4PE
#define TIM_DIER_CCxDE          TIM_DIER_CC4DE
#define CCRx                    CCR4

#define DMA1_Channelx           DMA1_Channel7
#define DMA1_Channelx_IRQn      DMA1_Channel7_IRQn
#define DMA1_Channelx_IRQHandler        DMA1_Channel7_IRQHandler

#define DMA_CCRx_EN             DMA_CCR7_EN
#define DMA_CCRx_TCIE           DMA_CCR7_TCIE

#define DMA_IFCR_CTEIFx         DMA_IFCR_CTEIF7
#define DMA_IFCR_CHTIFx         DMA_IFCR_CHTIF7
#define DMA_IFCR_CTCIFx         DMA_IFCR_CTCIF7
#define DMA_IFCR_CGIFx          DMA_IFCR_CGIF7

#endif

extern uint8_t WS2811_CH1[];
extern uint8_t WS2811_CH2[];
extern uint8_t WS2811_CH3[];

void LEDS_Update(void);
void WS2811Init(void);

#endif /* _WS2811_H */
