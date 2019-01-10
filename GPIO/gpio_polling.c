
/*
PxDIR 	PxREN 	PxOUT 	I/O Configuration
0 			0 			x 			Input
0 			1 			0 			Input with pulldown resistor
0 			1 			1 			Input with pullup resistor
1 			x 			x 			Output
*/
//*****************************************************************************
//
// MSP432 main.c template
//
//*****************************************************************************

#include "msp.h"

#define RED_LED_PORT 			1
#define RED_LED_PIN_NUM 	0
#define RED2_LED_PORT 		2
#define RED2_LED_PIN_NUM 	0
#define GREEN_LED_PORT 		2
#define GREEN_LED_PIN_NUM 1
#define BLUE_LED_PORT 		2
#define BLUE_LED_PIN_NUM 	2

#define USER_BUTTON_1_PORT	1
#define USER_BUTTON_1_PIN		1
#define USER_BUTTON_2_PORT	1
#define USER_BUTTON_2_PIN		4

#define MY_BUTTON_PORT	5
#define MY_BUTTON_PIN		0

#define MY_BUTTON_2_PORT	1
#define MY_BUTTON_2_PIN		7

//functions for GPIO Output
void setAPinAsGPIOOutput(uint16_t port, uint16_t pin);
void setGPIOOutput(uint16_t port, uint16_t pin);
void resetGPIOOutput(uint16_t port, uint16_t pin);
void toggleGPIOOutput(uint16_t port, uint16_t pin);


//functions for GPIO Input
void setAPinAsGPIOInput(uint16_t port, uint16_t pin);
void setAPinAsGPIOInputWithPullUp(uint16_t port, uint16_t pin, uint8_t isPulledUp);
uint8_t readGPIOIntputPolling(uint16_t port, uint16_t pin);

int main(void)
{
    volatile uint32_t i;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;  // Stop watchdog timer

    setAPinAsGPIOOutput(RED_LED_PORT, RED_LED_PIN_NUM);
    setAPinAsGPIOOutput(BLUE_LED_PORT, BLUE_LED_PIN_NUM);
		setAPinAsGPIOInput(MY_BUTTON_PORT, MY_BUTTON_PIN);
		setAPinAsGPIOInputWithPullUp(USER_BUTTON_1_PORT, USER_BUTTON_1_PIN, 1);

	//__enable_interrupt();
    while(1)
    {
			if(readGPIOIntputPolling(MY_BUTTON_PORT, MY_BUTTON_PIN))
				setGPIOOutput(RED_LED_PORT, RED_LED_PIN_NUM);
			else
				resetGPIOOutput(RED_LED_PORT, RED_LED_PIN_NUM);
			
			
			if(readGPIOIntputPolling(USER_BUTTON_1_PORT, USER_BUTTON_1_PIN))
				setGPIOOutput(BLUE_LED_PORT, BLUE_LED_PIN_NUM);
			else
				resetGPIOOutput(BLUE_LED_PORT, BLUE_LED_PIN_NUM);
    }
}

void setAPinAsGPIOOutput(uint16_t port, uint16_t pin)
{
//	#define P1                               ((DIO_PORT_Odd_Interruptable_Type*)  (DIO_BASE + 0x0000))
//	#define P2                               ((DIO_PORT_Even_Interruptable_Type*) (DIO_BASE + 0x0000))
//	Since they points same location, we cannot use port data as pointer function input
	
	switch(port) 
	{
		 case 1:
				P1->SEL0 &= ~(0x0001 << pin);  //select P1 specified bit as alternate function gpio
				P1->SEL1 &= ~(0x0001 << pin);  //select P1 specified bit as alternate function gpio
				P1->DIR |= (0x0001 << pin);  //select P1 specified bit as gpio output pin
				break;
		 case 2:
				P2->SEL0 &= ~(0x0001 << pin); 
				P2->SEL1 &= ~(0x0001 << pin); 
				P2->DIR |= (0x0001 << pin); 
				break;
		 case 3:
				P3->SEL0 &= ~(0x0001 << pin); 
				P3->SEL1 &= ~(0x0001 << pin); 
				P3->DIR |= (0x0001 << pin); 
				break;
		 case 4:
				P4->SEL0 &= ~(0x0001 << pin); 
				P4->SEL1 &= ~(0x0001 << pin); 
				P4->DIR |= (0x0001 << pin); 
				break;
		 case 5:
				P5->SEL0 &= ~(0x0001 << pin); 
				P5->SEL1 &= ~(0x0001 << pin); 
				P5->DIR |= (0x0001 << pin); 
				break;
		 case 6:
				P6->SEL0 &= ~(0x0001 << pin); 
				P6->SEL1 &= ~(0x0001 << pin); 
				P6->DIR |= (0x0001 << pin); 
				break;
		 case 7:
				P7->SEL0 &= ~(0x0001 << pin); 
				P7->SEL1 &= ~(0x0001 << pin); 
				P7->DIR |= (0x0001 << pin); 
				break;
		 case 8:
				P8->SEL0 &= ~(0x0001 << pin); 
				P8->SEL1 &= ~(0x0001 << pin); 
				P8->DIR |= (0x0001 << pin); 
				break;
		 case 9:
				P9->SEL0 &= ~(0x0001 << pin); 
				P9->SEL1 &= ~(0x0001 << pin); 
				P9->DIR |= (0x0001 << pin); 
				break;
		 case 10:
				P10->SEL0 &= ~(0x0001 << pin); 
				P10->SEL1 &= ~(0x0001 << pin); 
				P10->DIR |= (0x0001 << pin); 
				break;
	}
}


void setGPIOOutput(uint16_t port, uint16_t pin)
{
	switch(port) 
	{ 
		 case 1:
				P1->OUT |= (0x0001 << pin); 
				break;
		 case 2:
				P2->OUT |= (0x0001 << pin); 
				break;
		 case 3:
				P3->OUT |= (0x0001 << pin); 
				break;
		 case 4:
				P4->OUT |= (0x0001 << pin); 
				break;
		 case 5:
				P5->OUT |= (0x0001 << pin); 
				break;
		 case 6:
				P6->OUT |= (0x0001 << pin); 
				break;
		 case 7:
				P7->OUT |= (0x0001 << pin); 
				break;
		 case 8:
				P8->OUT |= (0x0001 << pin); 
				break;
		 case 9:
				P9->OUT |= (0x0001 << pin); 
				break;
		 case 10:
				P10->OUT |= (0x0001 << pin); 
				break;
	}
}


void resetGPIOOutput(uint16_t port, uint16_t pin)
{
	switch(port) 
	{ 
		 case 1:
				P1->OUT &= ~(0x0001 << pin); 
				break;
		 case 2:
				P2->OUT &= ~(0x0001 << pin); 
				break;
		 case 3:
				P3->OUT &= ~(0x0001 << pin); 
				break;
		 case 4:
				P4->OUT &= ~(0x0001 << pin); 
				break;
		 case 5:
				P5->OUT &= ~(0x0001 << pin); 
				break;
		 case 6:
				P6->OUT &= ~(0x0001 << pin); 
				break;
		 case 7:
				P7->OUT &= ~(0x0001 << pin); 
				break;
		 case 8:
				P8->OUT &= ~(0x0001 << pin); 
				break;
		 case 9:
				P9->OUT &= ~(0x0001 << pin); 
				break;
		 case 10:
				P10->OUT &= ~(0x0001 << pin); 
				break;
	}
}
void toggleGPIOOutput(uint16_t port, uint16_t pin)
{
	switch(port) 
	{ 
		 case 1:
				P1->OUT ^= (0x0001 << pin); 
				break;
		 case 2:
				P2->OUT ^= (0x0001 << pin); 
				break;
		 case 3:
				P3->OUT ^= (0x0001 << pin); 
				break;
		 case 4:
				P4->OUT ^= (0x0001 << pin); 
				break;
		 case 5:
				P5->OUT ^= (0x0001 << pin); 
				break;
		 case 6:
				P6->OUT ^= (0x0001 << pin); 
				break;
		 case 7:
				P7->OUT ^= (0x0001 << pin); 
				break;
		 case 8:
				P8->OUT ^= (0x0001 << pin); 
				break;
		 case 9:
				P9->OUT ^= (0x0001 << pin); 
				break;
		 case 10:
				P10->OUT ^= (0x0001 << pin); 
				break;
	}
}


void setAPinAsGPIOInputWithPullUp(uint16_t port, uint16_t pin, uint8_t isPulledUp)
{
	setAPinAsGPIOInput(port, pin);
	switch(port) 
	{
		 case 1:
				P1->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P1->OUT |= (0x0001 << pin);
				else
					P1->OUT &= ~(0x0001 << pin);
				break;
		 case 2:
				P2->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P2->OUT |= (0x0001 << pin);
				else
					P2->OUT &= ~(0x0001 << pin);
				break;
		 case 3:
				P3->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P3->OUT |= (0x0001 << pin);
				else
					P3->OUT &= ~(0x0001 << pin);
				break;
		 case 4:
				P4->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P4->OUT |= (0x0001 << pin);
				else
					P4->OUT &= ~(0x0001 << pin);
				break;
		 case 5:
				P5->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P5->OUT |= (0x0001 << pin);
				else
					P5->OUT &= ~(0x0001 << pin);
				break;
		 case 6:
				P6->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P6->OUT |= (0x0001 << pin);
				else
					P6->OUT &= ~(0x0001 << pin);
				break;
		 case 7:
				P7->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P7->OUT |= (0x0001 << pin);
				else
					P7->OUT &= ~(0x0001 << pin);
				break;
		 case 8:
				P8->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P8->OUT |= (0x0001 << pin);
				else
					P8->OUT &= ~(0x0001 << pin);
				break;
		 case 9:
				P9->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P9->OUT |= (0x0001 << pin);
				else
					P9->OUT &= ~(0x0001 << pin);
				break;
		 case 10:
				P10->REN |= (0x0001 << pin);
				if(isPulledUp) //it is pull up
					P10->OUT |= (0x0001 << pin);
				else
					P10->OUT &= ~(0x0001 << pin);
				break;
	}
}


void setAPinAsGPIOInput(uint16_t port, uint16_t pin)
{
//	#define P1                               ((DIO_PORT_Odd_Interruptable_Type*)  (DIO_BASE + 0x0000))
//	#define P2                               ((DIO_PORT_Even_Interruptable_Type*) (DIO_BASE + 0x0000))
//	Since they points same location, we cannot use port data as pointer function input
	
	switch(port) 
	{
		 case 1:
				P1->SEL0 &= ~(0x0001 << pin);  //select P1 specified bit as alternate function gpio
				P1->SEL1 &= ~(0x0001 << pin);  //select P1 specified bit as alternate function gpio
				P1->DIR &= ~(0x0001 << pin);  //select P1 specified bit as gpio input pin
				break;
		 case 2:
				P2->SEL0 &= ~(0x0001 << pin); 
				P2->SEL1 &= ~(0x0001 << pin); 
				P2->DIR &= ~(0x0001 << pin); 
				break;
		 case 3:
				P3->SEL0 &= ~(0x0001 << pin); 
				P3->SEL1 &= ~(0x0001 << pin); 
				P3->DIR &= ~(0x0001 << pin); 
				break;
		 case 4:
				P4->SEL0 &= ~(0x0001 << pin); 
				P4->SEL1 &= ~(0x0001 << pin); 
				P4->DIR &= ~(0x0001 << pin); 
				break;
		 case 5:
				P5->SEL0 &= ~(0x0001 << pin); 
				P5->SEL1 &= ~(0x0001 << pin); 
				P5->DIR &= ~(0x0001 << pin); 
				break;
		 case 6:
				P6->SEL0 &= ~(0x0001 << pin); 
				P6->SEL1 &= ~(0x0001 << pin); 
				P6->DIR &= ~(0x0001 << pin); 
				break;
		 case 7:
				P7->SEL0 &= ~(0x0001 << pin); 
				P7->SEL1 &= ~(0x0001 << pin); 
				P7->DIR &= ~(0x0001 << pin); 
				break;
		 case 8:
				P8->SEL0 &= ~(0x0001 << pin); 
				P8->SEL1 &= ~(0x0001 << pin); 
				P8->DIR &= ~(0x0001 << pin); 
				break;
		 case 9:
				P9->SEL0 &= ~(0x0001 << pin); 
				P9->SEL1 &= ~(0x0001 << pin); 
				P9->DIR &= ~(0x0001 << pin); 
				break;
		 case 10:
				P10->SEL0 &= ~(0x0001 << pin); 
				P10->SEL1 &= ~(0x0001 << pin); 
				P10->DIR &= ~(0x0001 << pin); 
				break;
	}
}

uint8_t readGPIOIntputPolling(uint16_t port, uint16_t pin)
{
	uint8_t retVal = 0;
	switch(port) 
	{ 
		 case 1:
				retVal = ((P1->IN) & (0x0001 << pin)); 
				break;
		 case 2:
				retVal = (P2->IN & (0x0001 << pin)); 
				break;
		 case 3:
				retVal = (P3->IN & (0x0001 << pin)); 
				break;
		 case 4:
				retVal = (P4->IN & (0x0001 << pin)); 
				break;
		 case 5:
				retVal = (P5->IN & (0x0001 << pin)); 
				break;
		 case 6:
				retVal = (P6->IN & (0x0001 << pin)); 
				break;
		 case 7:
				retVal = (P7->IN & (0x0001 << pin)); 
				break;
		 case 8:
				retVal = (P8->IN & (0x0001 << pin)); 
				break;
		 case 9:
				retVal = (P9->IN & (0x0001 << pin)); 
				break;
		 case 10:
				retVal = (P10->IN & (0x0001 << pin)); 
				break;
	}
	return retVal;
}

