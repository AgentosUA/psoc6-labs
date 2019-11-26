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

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_TCPWM_PWM_Init(PWM_1_HW, PWM_1_CNT_NUM, &PWM_1_config);
    Cy_TCPWM_PWM_Enable(PWM_1_HW, PWM_1_CNT_NUM);
    
    Cy_TCPWM_PWM_Init(PWM_2_HW, PWM_2_CNT_NUM, &PWM_2_config);
    Cy_TCPWM_PWM_Enable(PWM_2_HW, PWM_2_CNT_NUM);
    
    Cy_TCPWM_PWM_Init(PWM_3_HW, PWM_3_CNT_NUM, &PWM_3_config);
    Cy_TCPWM_PWM_Enable(PWM_3_HW, PWM_3_CNT_NUM);
    
    
    
    for(;;)
    {
        
        Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, 1u);
        Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 0u);
        Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 0u);
        
        Cy_TCPWM_TriggerStart(PWM_1_HW, PWM_1_CNT_MASK);
        CyDelay(4050);
        Cy_TCPWM_TriggerStopOrKill(PWM_1_HW, PWM_1_CNT_NUM);
        Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, 0u);
        
        CyDelay(1000);
        
        Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 1u);
        Cy_TCPWM_TriggerStart(PWM_2_HW, PWM_2_CNT_MASK);
        CyDelay(4050);
        Cy_TCPWM_TriggerStopOrKill(PWM_2_HW, PWM_2_CNT_NUM);
        Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 0u);
        
        CyDelay(1000);
        
        Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 1u);
        Cy_TCPWM_TriggerStart(PWM_3_HW, PWM_3_CNT_MASK);
        CyDelay(4050);
        Cy_TCPWM_TriggerStopOrKill(PWM_3_HW, PWM_3_CNT_NUM);
        Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 0u);
        
        CyDelay(1000);
        
        
    }
}

/* [] END OF FILE */
