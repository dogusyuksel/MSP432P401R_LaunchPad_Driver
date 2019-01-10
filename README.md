# MSP432P401R_LaunchPad_Driver
This repo contains the specified MCU's pheripheral drivers.

Before Starting to the Project
-----------------------------------

1. Create a Keil project for MSP432P401R MCU
2. While creating, select CMSIS -> Core
3. Select Device -> Startup
4. Then project has been created and add "main.c" with this base
5. Lastly select "TI XDS Debugger" as debugger

```ruby
int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;  // Stop watchdog timer

    while(1);
}
```

GPIO
------------------
```ruby
/********************************************
This function is used for setting a pin as gpio output
port: port number (numeric)
pin:  pin  number (numeric)
eg: setAPinAsGPIOOutput(1, 0); //this is for P1.0
********************************************/
void setAPinAsGPIOOutput(uint16_t port, uint16_t pin);

/********************************************
This function is used for setting HIGH to a output pin
port: port number (numeric)
pin:  pin  number (numeric)
eg: setGPIOOutput(1, 0); //this is for P1.0
********************************************/
void setGPIOOutput(uint16_t port, uint16_t pin);

/********************************************
This function is used for setting LOW to a output pin
port: port number (numeric)
pin:  pin  number (numeric)
eg: resetGPIOOutput(1, 0); //this is for P1.0
********************************************/
void resetGPIOOutput(uint16_t port, uint16_t pin);

/********************************************
This function is used for setting TOGGLE to a output pin
port: port number (numeric)
pin:  pin  number (numeric)
eg: toggleGPIOOutput(1, 0); //this is for P1.0
********************************************/
void toggleGPIOOutput(uint16_t port, uint16_t pin);


/********************************************
This function is used for setting a pin as input
port: port number (numeric)
pin:  pin  number (numeric)
eg: setAPinAsGPIOInput(5, 0); //this is for P5.0
********************************************/
void setAPinAsGPIOInput(uint16_t port, uint16_t pin);

/********************************************
This function is used for setting a pin as input with internal resistor activated
port: port number (numeric)
pin:  pin  number (numeric)
isPulledUp: boolean-like for pull up or pull down (1 means pull up)
eg: setAPinAsGPIOInputWithPullUp(1, 1, 1); //this is for P1.1 with internal pull UP
********************************************/
void setAPinAsGPIOInputWithPullUp(uint16_t port, uint16_t pin, uint8_t isPulledUp);

/********************************************
This function is used for reading an input pin
port: port number (numeric)
pin:  pin  number (numeric)
return pin value (0 means low, else means high)
eg: readGPIOIntputPolling(5, 0); //this is for P5.0
********************************************/
uint8_t readGPIOIntputPolling(uint16_t port, uint16_t pin);
```

ADC
------------------

```ruby
/*************************************
This function sets A6 (P4.6) and A7 (P4. 6) pins as analog input
*************************************/
void ADC_Init(void);


/*************************************
This function gets A6 and A7 values when the function calles
*************************************/
void ADC_Read(uint32_t *ch6, uint32_t *ch7);
```
