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
