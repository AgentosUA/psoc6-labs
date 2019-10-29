/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

#define LEN_ON  (0)
#define LEN_OFF (1)

void UartInit(void);
void TimerInit(void);
void Isr_Timer(void);

bool LEDupdateFlag = false;



int main(void)
{
    UartInit();
    
    __enable_irq(); /* Enable global interrupts. */
    
    // Cy_SCB_UART_PutString(UART_HW, "\x1b[2J\x1b[;H");
    Cy_SCB_UART_PutString(UART_HW, "Hello world from PSoc 6! \r\n\n");
    
    Cy_SCB_UART_PutString(UART_HW, "Press enter key to start blinking the LED\r\n\n");
    
    while(Cy_SCB_UART_Get(UART_HW) != 'r');
    
    TimerInit();
    
    Cy_SCB_UART_PutString(UART_HW, "Observe the LED blinking on the kit!\r\n");

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(LEDupdateFlag)
        {
            LEDupdateFlag = false;
            
            Cy_GPIO_Inv(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM);
        }
    }
}

void UartInit(void)
{
    Cy_SCB_UART_Init(UART_HW, &UART_config, &UART_context);
    Cy_SCB_UART_Enable(UART_HW);
}

void TimerInit(void)
{
    Cy_TCPWM_Counter_Init(Timer_HW, Timer_CNT_NUM, &Timer_config);
    
    Cy_TCPWM_Counter_Enable(Timer_HW, Timer_CNT_NUM);
    
    Cy_TCPWM_TriggerStart(Timer_HW, Timer_CNT_MASK);
    
    Cy_SysInt_Init(&Isr_Timer_cfg, Isr_Timer);
    
    NVIC_EnableIRQ((IRQn_Type)Isr_Timer_cfg.intrSrc);
}

void Isr_Timer(void)
{
    Cy_TCPWM_ClearInterrupt(Timer_HW, Timer_CNT_NUM, CY_TCPWM_INT_ON_TC);
    
    NVIC_ClearPendingIRQ(Isr_Timer_cfg.intrSrc);
    LEDupdateFlag = true;
}



/* [] END OF FILE */