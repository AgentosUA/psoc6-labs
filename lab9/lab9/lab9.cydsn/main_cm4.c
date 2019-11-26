#include "project.h"
#include "ctdac/cy_ctdac.h"
#include "dma/cy_dma.h"
/* This project assumes a configuration tool will automatically configure system
*/
/* Для демонстрація того, як драйвери PDL використовуються для ручної настройки
 VDAC, потрібно встановити для PDL_CONFIGURATION в #define значення 1 */
#define PDL_CONFIGURATION (0u)
/* Число точок таблиці синусоїди */
#define NUM_POINTS (100u)
/* Таблиця значень синусоїди в без знаковому форматі. */
uint32_t sineWaveLUT[] = {0x7FF, 0xF9A, 0xF9A, 0xCB2, 0x7FF, 0x34C, 0x064, 0x064, 0x34C};


/* {0x7FF, 0x880, 0x900, 0x97F, 0x9FC, 0xA78, 0xAF1, 0xB67, 0xBD9, 0xC48,
 0xCB2, 0xD18, 0xD79, 0xDD4, 0xE29, 0xE77, 0xEC0, 0xF01, 0xF3C, 0xF6F,
0xF9A, 0xFBE, 0xFDA, 0xFEE, 0xFFA, 0xFFF, 0xFFA, 0xFEE, 0xFDA, 0xFBE,
 0xF9A, 0xF6F, 0xF3C, 0xF01, 0xEC0, 0xE77, 0xE29, 0xDD4, 0xD79, 0xD18,
 0xCB2, 0xC48, 0xBD9, 0xB67, 0xAF1, 0xA78, 0x9FC, 0x97F, 0x900, 0x880,
0x7FF, 0x77E, 0x6FE, 0x67F, 0x602, 0x586, 0x50D, 0x497, 0x425, 0x3B6,
0x34C, 0x2E6, 0x285, 0x22A, 0x1D5, 0x187, 0x13E, 0x0FD, 0x0C2, 0x08F,
0x064, 0x040, 0x024, 0x010, 0x004, 0x000, 0x004, 0x010, 0x024, 0x040,
0x064, 0x08F, 0x0C2, 0x0FD, 0x13E, 0x187, 0x1D5, 0x22A, 0x285, 0x2E6,
0x34C, 0x3B6, 0x425, 0x497, 0x50D, 0x586, 0x602, 0x67F, 0x6FE, 0x77E};
*/
/* В головній функції main виконуються наступні дії:
 1. Ініціалізуються компоненти VDAC та DMA
 2. DMA постійно оновлює значення VDAC з таблиці синусів */
int main(void)
{
 /* Дозвіл глобальних переривань. */
 __enable_irq();
#if PDL_CONFIGURATION
 /* Configure VDAC for VDDA reference and unbuffered output.
 * FastInit will configure the VDAC for unsigned mode and buffered updates
 * with a 500 kHz clock by default. */
 Cy_CTDAC_FastInit(CTDAC0, &Cy_CTDAC_Fast_VddaRef_UnbufferedOut);
 /* Configure Trigger Mux to route VDAC trigger output to DMA input trigger
*/
 (void)Cy_TrigMux_Connect(TRIG14_IN_PASS_TR_CTDAC_EMPTY,
TRIG14_OUT_TR_GROUP0_INPUT50, CY_TR_MUX_TR_INV_DISABLE,
TRIGGER_TYPE_PASS_TR_CTDAC_EMPTY);
 (void)Cy_TrigMux_Connect(TRIG1_IN_TR_GROUP14_OUTPUT7,
TRIG1_OUT_CPUSS_DW1_TR_IN0, CY_TR_MUX_TR_INV_DISABLE,
TRIGGER_TYPE_TR_GROUP_OUTPUT__LEVEL);
 /* Enable CTDAC hardware blocks */
 Cy_CTDAC_Enable(CTDAC0);
 DMA_1_Start(sineWaveLUT, &CTDAC0->CTDAC_VAL_NXT);
#else
 VDAC_1_Start();
 DMA_1_Start(sineWaveLUT, (uint32_t *)&(CTDAC0->CTDAC_VAL_NXT));
#endif
 /* Жодні операції з процесором не потрібні, так як в проекті
використовується DMA для всіх передач пам'яті. */
 for(;;)
 {
 }
}
/* [] END OF FILE */