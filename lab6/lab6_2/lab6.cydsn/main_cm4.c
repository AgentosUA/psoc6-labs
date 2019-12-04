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

#define DELAY_SHORT (500)
#define DELAY_LONG (1000)
#define RED_LED_BLINK_COUNT (8)
#define BLUE_LED_BLINK_COUNT (4)
    
#define LED_ON (0)
#define LED_OFF (1)
    
#define SWITCH_INTR_PRIORITY (3u)
    
uint32_t interrupt_flag = false;


#define TIMER_PERIOD_MSEC 1000U /* Період таймера в мсек */

void Isr_switch(void)
{
   /* Очищення спрацьованого переривання виводу */
    Cy_GPIO_ClearInterrupt(KIT_BTN1_PORT, KIT_BTN1_NUM);
    //NVIC_ClearPendingIRQ(SysInt_Switch_cfg.intrSrc);
    /* Встановити прапорець переривання */
    interrupt_flag = true;
}

void TimerInterruptHandler(void)
    {
        /* Очистка переривання підрахунку терміналу */
        Cy_TCPWM_ClearInterrupt(Timer_HW, Timer_CNT_NUM,CY_TCPWM_INT_ON_TC);

        /* Переключення світлодіоду LED */
        Cy_GPIO_Inv(LED_Red_PORT, LED_Red_NUM);
    }

int main(void)
{
    
    
    //Cy_GPIO_Write(LED_Blue_PORT, LED_Blue_NUM, LED_OFF);
    uint32_t count = 0;
    uint32_t delayMs = DELAY_LONG;
    
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_SysInt_Init(&isrTimer_cfg, TimerInterruptHandler);
    NVIC_EnableIRQ(isrTimer_cfg.intrSrc); 
    
    void NVIC_ClearPendingIRQ (IRQn_Type IRQn);
    
    
    (void)Cy_TCPWM_Counter_Init(Timer_HW, Timer_CNT_NUM, &Timer_config);
    Cy_TCPWM_Enable_Multiple(Timer_HW, Timer_CNT_MASK); 
    
    Cy_TCPWM_Counter_SetPeriod(Timer_HW, Timer_CNT_NUM, TIMER_PERIOD_MSEC - 1);
    
    
    
    for(;;)
    {
         if(interrupt_flag)
        {
            interrupt_flag = false;
            if(DELAY_LONG == delayMs)
            {
                delayMs = DELAY_SHORT;
            }
            else
            {
                delayMs = DELAY_LONG;
            }
        }
        
        /* 
        for (count = 0; count < RED_LED_BLINK_COUNT; count++)
        {
            Cy_GPIO_Write(LED_Blue_PORT, LED_Blue_NUM, LED_ON);
            Cy_SysLib_Delay(delayMs);
            Cy_GPIO_Write(LED_Blue_PORT, LED_Blue_NUM, LED_OFF);
            Cy_SysLib_Delay(delayMs);
        }
        */
        Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
        Cy_TCPWM_TriggerStart(Timer_HW, Timer_CNT_MASK);
    }
    
}

/* [] END OF FILE */
