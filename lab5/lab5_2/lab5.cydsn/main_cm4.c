#include "project.h"

#define DELAY_SHORT (500)
#define DELAY_LONG (1000)
#define RED_LED_BLINK_COUNT (8)
#define BLUE_LED_BLINK_COUNT (4)
    
#define LED_ON (0)
#define LED_OFF (1)
    
#define SWITCH_INTR_PRIORITY (3u)
    
uint32_t interrupt_flag = false;
   
void Isr_switch(void)
{
   /* Очищення спрацьованого переривання виводу */
    Cy_GPIO_ClearInterrupt(KIT_BTN1_PORT, KIT_BTN1_NUM);
    NVIC_ClearPendingIRQ(SysInt_Switch_cfg.intrSrc);
    /* Встановити прапорець переривання */
    interrupt_flag = true;
}


int main(void)
{
    
    Cy_GPIO_Write(KIT_LED_BLUE_PORT, KIT_LED_BLUE_NUM, LED_OFF);
    uint32_t count = 0;
    uint32_t delayMs = DELAY_LONG;
 
    /* Глобальний дозвіл переривань */
    
    __enable_irq(); /* Enable global interrupts. */
    
    Cy_SysInt_Init(&SysInt_Switch_cfg, Isr_switch);
    NVIC_ClearPendingIRQ(SysInt_Switch_cfg.intrSrc);
    NVIC_EnableIRQ(SysInt_Switch_cfg.intrSrc);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

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
        
        
        for (count = 0; count < RED_LED_BLINK_COUNT; count++)
        {
            Cy_GPIO_Write(KIT_LED_RED_PORT, KIT_LED_RED_NUM, LED_ON);
            Cy_SysLib_Delay(delayMs);
            Cy_GPIO_Write(KIT_LED_RED_PORT, KIT_LED_RED_NUM, LED_OFF);
            Cy_SysLib_Delay(delayMs);
        }
        
        Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
        
        for (count = 0; count < BLUE_LED_BLINK_COUNT; count++)
        {
            Cy_GPIO_Write(KIT_LED_BLUE_PORT, KIT_LED_BLUE_NUM, LED_ON);
            Cy_SysLib_Delay(delayMs);
            Cy_GPIO_Write(KIT_LED_BLUE_PORT, KIT_LED_BLUE_NUM, LED_OFF);
            Cy_SysLib_Delay(delayMs);
        }
        /* Перехід в режим ″глибокого сну″ */
        Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
    }
}

/* [] END OF FILE */
