
#include <stdint.h>
#include "msp.h"


// P4.6 = A7
// P4.7 = A6
uint32_t ADC_Val_Ch6, ADC_Val_Ch7; //these are adc values for A6 and A7


//function prototypes
void ADC_Init(void);
void ADC_Read(uint32_t *ch6, uint32_t *ch7);


int main(void)
{
  ADC_Init();        // initialize ADC sample P4.7/A6 and P4.6/A7
		
  __enable_interrupt();
	
  while(1)
	{
    ADC_Read(&ADC_Val_Ch6, &ADC_Val_Ch7);
  }
}

void ADC_Init(void)
{
  while(REFCTL0&0x0400){};         // wait for the reference to be idle before reconfiguring (see REF4 in errata)
  REFCTL0 = 0x0039;                // configure reference for static 2.5V
  while((REFCTL0&0x1000) == 0){};  // wait for the reference to stabilize before continuing (optional, see REF8 in errata)
		
	ADC14->CTL0 &= ADC14_CTL0_ENC;	//to allow configuration

	while(ADC14->CTL0 & ADC14_CTL0_BUSY){};   // wait for BUSY to be zero
		
	// 4) single, SMCLK, on, disabled, /1, 32 SHM, actual value 0x04223390
  ADC14->CTL0 = ADC14_CTL0_SSEL__SMCLK 	| ADC14_CTL0_SHP 		| \
								ADC14_CTL0_CONSEQ_1 		| ADC14_CTL0_SHT1_3 | \
								ADC14_CTL0_SHT0_3 			| ADC14_CTL0_MSC 		| \
								ADC14_CTL0_MSC 					| ADC14_CTL0_ON;          
		
  ADC14->CTL1 = ADC14_CTL1_RES_3;          // 5) ADC14MEM0, 14-bit, ref on, regular power, actual value 0x00000030
		
	//since MCTL[0] for channel 6 then we will read MEM[0] for channel 6
  ADC14->MCTL[0] = ADC14_MCTLN_INCH_6 | ADC14_MCTLN_VRSEL0;         // 6a) 0 to 2.5V, channel 6, actual value 0x00000106
	//since MCTL[1] for channel 7 then we will read MEM[1] for channel 7, THIS IS ALSO LABELLED AS End Of Sequence
	ADC14->MCTL[1] = ADC14_MCTLN_INCH_7 | ADC14_MCTLN_VRSEL0 | ADC14_MCTLN_EOS;         // 6b) 0 to 2.5V, channel 7, actual value 0x00000187
		
  ADC14->IER0 = 0; // 7) no interrupts
  ADC14->IER1 = 0; // no interrupts
		
  P4SEL1 |= (BIT7 | BIT6); //0xC0;                  // 8) analog mode on P4.7/A6 and P4.6/A7 selected alternate function
  P4SEL0 |= (BIT7 | BIT6); //0xC0;
  ADC14->CTL0 |= ADC14_CTL0_ENC;         // 9) enable, 0x00000002
}


void ADC_Read(uint32_t *ch6, uint32_t *ch7)
{
  while(ADC14->CTL0 & ADC14_CTL0_BUSY){};    	// 1) wait for BUSY to be zero
  ADC14->CTL0 |= ADC14_CTL0_SC;          			// 2) start single conversion, start sample and conversation, 0x00000001
  while((ADC14->IFGR0 & ADC14_IFGR0_IFG1) == 0){};  			// 3) wait for ADC14IFG1, it waits for MEM1 conversation, 0x02
  *ch6 = ADC14->MEM[0];                 			// 4) P4.7/A6 result 0 to 0x3FFF
  *ch7 = ADC14->MEM[1];                 			// P4.6/A7 result 0 to 0x3FFF
}

