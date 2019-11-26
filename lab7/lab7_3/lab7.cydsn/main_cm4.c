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
int i = 0;

int main(void)
{
    UartInit();
    
    __enable_irq(); /* Enable global interrupts. */
    
    Cy_SCB_UART_PutString(UART_HW, "FES-31, Stepaniuk Oleg \r\n\n");
    
    Cy_SCB_UART_PutString(UART_HW, "Press enter r for red, b for blue and g for green blinking!\r\n\n");
  
    TimerInit();
    
    for(;;)
    {
        
        
        switch(Cy_SCB_UART_Get(UART_HW))
        {
            case 'r':
            
                i = 1;
                Cy_GPIO_Write(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM,1);
                Cy_GPIO_Write(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM,1);   
                Cy_GPIO_Write(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM,1);
                while (i == 1)
                {    
                    CyDelay(500);
                    Cy_GPIO_Write(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM,0);
                    CyDelay(500);
                    Cy_GPIO_Write(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM,1); 
                    switch(Cy_SCB_UART_Get(UART_HW))
                    {
                        case 'r':
                            i = 0;
                            break;
                        case 'g':
                            i = 0;
                            break;
                        case 'b':
                            i = 0;
                            break;
                        case '\r':
                            i = 0;
                            break;
                        default:
                            break;        
                    }
                }
                break;
                
            case 'g':
                i = 1;
                Cy_GPIO_Write(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM,1);
                Cy_GPIO_Write(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM,1);   
                Cy_GPIO_Write(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM,1);
                while (i == 1)
                {    
                    CyDelay(1000);
                    Cy_GPIO_Write(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM,0);
                    CyDelay(1000);
                    Cy_GPIO_Write(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM,1); 
                    switch(Cy_SCB_UART_Get(UART_HW))
                    {
                        case 'r':
                            i = 0;
                            break;
                        case 'g':
                            i = 0;
                            break;
                        case 'b':
                            i = 0;
                            break;
                        case '\r':
                            i = 0;
                            break;
                        default:
                            break;        
                    }
                }
                break;
                
            case 'b':
                i = 1;
                Cy_GPIO_Write(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM,1);
                Cy_GPIO_Write(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM,1);   
                Cy_GPIO_Write(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM,1);
                while (i == 1)
                {    
                    CyDelay(300);
                    Cy_GPIO_Write(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM,0);
                    CyDelay(300);
                    Cy_GPIO_Write(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM,1); 
                    switch(Cy_SCB_UART_Get(UART_HW))
                    {
                        case 'r':
                            i = 0;
                            break;
                        case 'g':
                            i = 0;
                            break;
                        case 'b':
                            i = 0;
                            break;
                        case '\r':
                            i = 0;
                            break;
                        default:
                            break;        
                    }
                }
                break;
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
