#include "main.h"

int main(void){
  Start();
  Setting();
  
  while(0x01){
    
    DelayMs(1000);
    ws2811W[0] = 255;
    Ws2811WUpdate();
    
    DelayMs(1000);
    ws2811W[0] = 0;
    Ws2811WUpdate();
    
    DelayMs(1000);
    ws2811W[1] = 255;
    Ws2811WUpdate();
    
    DelayMs(1000);
    ws2811W[1] = 0;
    Ws2811WUpdate();
    
    DelayMs(1000);
    ws2811W[2] = 255;
    Ws2811WUpdate();
    
    DelayMs(1000);
    ws2811W[2] = 0;
    Ws2811WUpdate();
  }
}
