#include "project.h"
#include <stdio.h>
#define MACH 346.513 /* Mach 1.0 at 25.0 */
volatile uint16_t duration = 0 ;
volatile int echo_flag = 0 ;
char str[128] ; /* print buffer */
void print(char *str)
{
 UART_PutString(str);
}
void Timer_Int_Handler(void)
{
 NVIC_ClearPendingIRQ(isrTimer_cfg.intrSrc);
 NVIC_DisableIRQ((IRQn_Type)isrTimer_cfg.intrSrc);
 duration = Timer_Echo_GetCapture();
 Timer_Echo_SetCounter(0) ;
 PWM_Trigger_Disable() ;
 echo_flag = 1 ;
}
void init_hardware(void)
{
 Cy_SysInt_Init(&isrTimer_cfg, Timer_Int_Handler);
 __enable_irq(); /* Enable global interrupts. */
/* Enable CM4. CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is
changed. */
// Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR);
// we don't use CM4 this time
 UART_Start() ;
 Cy_SysInt_Init(&isrTimer_cfg, Timer_Int_Handler);
 NVIC_EnableIRQ((IRQn_Type)isrTimer_cfg.intrSrc);
 Timer_Echo_Start() ;
 PWM_Trigger_Start() ;
}
/**
* print_value
* Calculate distance from the duration
* Since the duration include both way of the trip
* to get the distance, the real duration is the half
* of the duration.
* distance = duration * MACH(m/s) * 100(cm) / (2 * 12000000(Hz)) ;
*
*/
void print_value(uint32_t duration)
{
 double distance = 0.0;
 distance = (double)(duration) * MACH / 240000.0;
 sprintf(str, "%d.%02dcm\n", (int)distance, (int)(100 * distance)%100);
 UART_PutString(str);
}
int main(void)
{
 init_hardware();
 sprintf(str, "HC-SR04 Test (%s %s)\n", __DATE__, __TIME__);
 print(str);
 for(;;)
 {
 if (echo_flag)
 {
 print_value(duration);
 echo_flag = 0;
 NVIC_EnableIRQ((IRQn_Type)isrTimer_cfg.intrSrc);
 PWM_Trigger_Start();
 }
 CyDelay(500);
 }
}