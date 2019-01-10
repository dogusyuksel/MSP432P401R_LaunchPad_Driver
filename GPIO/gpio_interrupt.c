#include <stdint.h>
#include "msp.h"


volatile uint32_t isButton1Pressed, isButton2Pressed;

void InitGPIOInputsWithInterrupt(void){
  __disable_interrupt();
  
  isButton1Pressed = 0;                         
  isButton2Pressed = 0;
  
		//see msp432p401r.h
	  //PORT5_IRQn                  = 39,     /* 55 Port5 Interrupt           */
		//PORT6_IRQn                  = 40      /* 56 Port6 Interrupt           */
	
  P5->SEL0 	&= ~0x04;
  P5->SEL1 	&= ~0x04;                 	// configure P5.2 as GPIO
  P5->DIR 	&= ~0x04;                  	// make P5.2 in
  P5->IES 	&= ~0x04;                  	// P5.2 is rising edge event
  P5->IFG 	&= ~0x04;                  	// clear flag3 (reduce possibility of extra interrupt)
  P5->IE 		|=  0x04;                    		// arm interrupt on P5.2
  NVIC->IP[9] = (NVIC->IP[9] & 0x00FFFFFF)|0x40000000; // IPR9 is for Irq 36 to 39 Priority Register
  NVIC->ISER[1] = 0x00000080;         // enable interrupt 39 in NVIC, ISER1 for Irq 32 to 63 Set Enable Register
  
  P6->SEL0 	&= ~0x02;
  P6->SEL1 	&= ~0x02;                 	// configure P6.1 as GPIO
  P6->DIR 	&= ~0x02;                  	// make P6.1 in
  P6->IES 	&= ~0x02;                  	// P6.1 is rising edge event
  P6->IFG 	&= ~0x02;                  	// clear flag1 (reduce possibility of extra interrupt)
  P6->IE 		|=  0x02;                    		// arm interrupt on P6.1
  NVIC->IP[10] = (NVIC->IP[10] & 0xFFFFFF00)|0x00000040; // IPR10 is for Irq 40 to 43 Priority Register
  NVIC->ISER[1] = 0x00000100;         	// enable interrupt 40 in NVIC, ISER1 for Irq 32 to 63 Set Enable Register
  
   __enable_interrupt();
}

void PORT5_IRQHandler(void){
	uint16_t asd = P5->IFG & (0x0001 << 2);
  if(asd){              // poll P5.2
    P5->IFG &= ~(0x0001 << 2); //clear flag
    isButton1Pressed = 1;       
  }
}
void PORT6_IRQHandler(void){
	uint16_t asd = P6->IFG & (0x0001 << 1);
  if(asd){              // poll P6.1
    P6->IFG &= ~(0x0001 << 1); //clear flag
    isButton2Pressed = 1;       
  }
}


int main(void)
{
  InitGPIOInputsWithInterrupt(); 
	
  while(1)
	{
    if(isButton1Pressed)
		{
			isButton1Pressed = 0;
			//do sth
		}
		if(isButton2Pressed)
		{
			isButton2Pressed = 0;
			//do sth
		}
		if((isButton1Pressed != 1) && (isButton2Pressed != 1))
		{
			
		}
  }
}
