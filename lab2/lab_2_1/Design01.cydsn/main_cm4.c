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

#define LED_ON (uint8_t) (0x00u)
#define LED_OFF (uint8_t) (0x01u)

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        Cy_GPIO_Write(P1_1_PORT, P1_1_NUM ,LED_ON);
        CyDelay(350);
        Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, LED_OFF);
        CyDelay(650);
        
        Cy_GPIO_Write(P11_1_PORT, P11_1_NUM ,LED_ON);
        CyDelay(350);
        Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, LED_OFF);
        CyDelay(650);
    }
}

/* [] END OF FILE */
