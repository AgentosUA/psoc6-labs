#include "project.h"

void UartInit(void);
void TimerInit(void);
void Isr_Timer(void);
   

uint32 status = 0 ;
uint32 freq = 100;

void Isr_switch(void) 
{  
    if (freq == 500 ) 
        freq = 100;
        
    else
        freq += 200;
    
    Cy_GPIO_ClearInterrupt(SW2_P0_4_PORT, SW2_P0_4_NUM); 
    NVIC_ClearPendingIRQ(SysInt_Switch_cfg.intrSrc);   
} 
int main(void)
{
    UartInit();
    
    __enable_irq(); /* Enable global interrupts. */
    Cy_SysInt_Init(&SysInt_Switch_cfg, Isr_switch);
    NVIC_ClearPendingIRQ(SysInt_Switch_cfg.intrSrc);
    NVIC_EnableIRQ(SysInt_Switch_cfg.intrSrc); 
    
    Cy_SCB_UART_PutString(UART_HW, "Stepaniuk Oleg, FES-31, Lab #7 \r\n\n");
    Cy_SCB_UART_PutString(UART_HW, "Press r, b or g key to start blinking the LED! \r\n\n");
    TimerInit();

    for(;;)
    {

        switch(Cy_SCB_UART_Get(UART_HW))
        {
            case 'r':
                status = 1;
                break;
            case 'g':
                status = 2 ;
                break;
            case 'b':
                status = 3;
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
    switch(status)
    {
        case 1:
            Timer_SetPeriod(freq);
            if(freq == 300) Cy_SCB_UART_PutString(UART_HW,"Red Led, Freq: 300 \r\n\n");
            if(freq == 100) Cy_SCB_UART_PutString(UART_HW,"Red Led, Freq: 100 \r\n\n");
            if(freq == 500) Cy_SCB_UART_PutString(UART_HW,"Red Led, Freq: 500 \r\n\n");
            Cy_GPIO_Set(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM);
            Cy_GPIO_Set(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM);
            Cy_GPIO_Inv(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM);
            break;
        case 2:
            Timer_SetPeriod(freq);
            if(freq == 300) Cy_SCB_UART_PutString(UART_HW,"Green Led, Freq: 300 \r\n\n");
            if(freq == 100) Cy_SCB_UART_PutString(UART_HW,"Green Led, Freq: 100 \r\n\n");
            if(freq == 500) Cy_SCB_UART_PutString(UART_HW,"Green Led, Freq: 500 \r\n\n");
            Cy_GPIO_Set(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM);
            Cy_GPIO_Set(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM);
            Cy_GPIO_Inv(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM);
            break;
        case 3:
            Timer_SetPeriod(freq);
            if(freq == 300) Cy_SCB_UART_PutString(UART_HW,"Blue Led, Freq: 300 \r\n\n");
            if(freq == 100) Cy_SCB_UART_PutString(UART_HW,"Blue Led, Freq: 100 \r\n\n");
            if(freq == 500) Cy_SCB_UART_PutString(UART_HW,"Blue Led, Freq: 500 \r\n\n");
            Cy_GPIO_Set(Pin_RedLED_0_PORT, Pin_RedLED_0_NUM);
            Cy_GPIO_Set(Pin_GreenLED_0_PORT, Pin_GreenLED_0_NUM);
            Cy_GPIO_Inv(Pin_BlueLED_0_PORT, Pin_BlueLED_0_NUM);
            break;
    }
}