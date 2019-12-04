#include "project.h"
#define TIMER_PERIOD_MSEC 1000U /* Період таймера в мсек */
uint32 status = 0 ;
uint32 i = 0 ;
uint32 p = 16 ; 

void Isr_switch(void) {  
    Cy_GPIO_ClearInterrupt(SW2_P0_4_PORT, SW2_P0_4_NUM); 
    NVIC_ClearPendingIRQ(SysInt_Switch_cfg.intrSrc);   

    status = 1 -  status ;
}  

void TimerInterruptHandler(void)
    {
        Cy_TCPWM_ClearInterrupt(Timer_HW, Timer_CNT_NUM,CY_TCPWM_INT_ON_TC);
        /* Очистка переривання підрахунку терміналу */

        if(status)
        {
            Cy_GPIO_Set(KIT_LED_RED_PORT, KIT_LED_RED_NUM); 
            Timer_SetPeriod(500);
            p = 8;
            Cy_GPIO_Inv(KIT_LED_BLUE_PORT, KIT_LED_BLUE_NUM);
        }
        else
        {
            Cy_GPIO_Set(KIT_LED_BLUE_PORT, KIT_LED_BLUE_NUM);
            Timer_SetPeriod(1000);
            p = 16;
            Cy_GPIO_Inv(KIT_LED_RED_PORT, KIT_LED_RED_NUM);
        }
        i++;
    }
  
int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_SysInt_Init(&isrTimer_cfg, TimerInterruptHandler);
    NVIC_EnableIRQ(isrTimer_cfg.intrSrc); 
    
    void NVIC_ClearPendingIRQ (IRQn_Type IRQn);
    
    Cy_SysInt_Init(&SysInt_Switch_cfg, Isr_switch);
    NVIC_ClearPendingIRQ(SysInt_Switch_cfg.intrSrc);
    NVIC_EnableIRQ(SysInt_Switch_cfg.intrSrc); 
    
    (void)Cy_TCPWM_Counter_Init(Timer_HW, Timer_CNT_NUM, &Timer_config);
    Cy_TCPWM_Enable_Multiple(Timer_HW, Timer_CNT_MASK); 
    
    Cy_TCPWM_Counter_SetPeriod(Timer_HW, Timer_CNT_NUM, TIMER_PERIOD_MSEC - 1);
    
    Cy_TCPWM_TriggerStart(Timer_HW, Timer_CNT_MASK);
   
    for(;;)
    {   
        if (i == p)
        {
            i = 0;
            CyDelay(100);
            Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);  
        }    
    }
}