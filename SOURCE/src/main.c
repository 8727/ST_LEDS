#include "main.h"

int main(void){
  Start();
  Setting();
  
  while(0x01){
    
    DelayMs(100);
    WS2811_CH1[1] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH2[1] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH3[1] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH1[1] = 0;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH2[1] = 0;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH3[1] = 0;
    LEDS_Update();
    
    
    
    
    
    DelayMs(100);
    WS2811_CH1[4] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH2[4] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH3[4] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH1[4] = 0;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH2[4] = 0;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH3[4] = 0;
    LEDS_Update();
    
    
    
    
    DelayMs(100);
    WS2811_CH1[7] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH2[7] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH3[7] = 255;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH1[7] = 0;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH2[7] = 0;
    LEDS_Update();
    
    DelayMs(100);
    WS2811_CH3[7] = 0;
    LEDS_Update();
  }
}
