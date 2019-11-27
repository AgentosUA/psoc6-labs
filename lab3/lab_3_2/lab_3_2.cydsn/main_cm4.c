
#include "project.h"

#define PDL_PIN_CONFIGURATION   (0u)

#define GPIO_ISR_FLAG           (1u)
#define GPIO_ISR_MASKED         (1u)
#define PIN_DELAY               (0x00030000u)
#define INTCAUSE0_PORT0         (1u) 


#if PDL_PIN_CONFIGURATION
    /* This structure is used to initialize a single GPIO pin using PDL configuration. */
    const cy_stc_gpio_pin_config_t P0_4_Pin_Init =
    {
        .outVal     = 1u,                   /* Pin output state */
        .driveMode  = CY_GPIO_DM_PULLUP,    /* Drive mode */
        .hsiom      = HSIOM_SEL_GPIO,       /* HSIOM selection */
        .intEdge    = CY_GPIO_INTR_RISING,  /* Interrupt Edge type */
        .intMask    = CY_GPIO_INTR_EN_MASK << SW2_P0_4_NUM,  /* Interrupt enable mask */
        .vtrip      = CY_GPIO_VTRIP_CMOS,   /* Input buffer voltage trip type */
        .slewRate   = CY_GPIO_SLEW_FAST,    /* Output buffer slew rate */
        .driveSel   = CY_GPIO_DRIVE_FULL,   /* Drive strength */
        .vregEn     = 0u,                   /* SIO pair output buffer mode */
        .ibufMode   = 0u,                   /* SIO pair input buffer mode */
        .vtripSel   = 0u,                   /* SIO pair input buffer trip point */
        .vrefSel    = 0u,                   /* SIO pair reference voltage for input buffer trip point */
        .vohSel     = 0u                    /* SIO pair regulated voltage output level */
    };
        
    /* This structure is used to initialize a full GPIO Port using PDL configuration */
    const cy_stc_gpio_prt_config_t port5_Init =
    {
        .out        = 0x00000000u,  /* Initial output data for the IO pins in the port */
        .intrMask   = 0x00000000u,  /* Interrupt enable mask for the port interrupt */
        .intrCfg    = 0x00000000u,  /* Port interrupt edge detection configuration */
        .cfg        = 0x0EEEEEEEu,  /* Port drive modes and input buffer enable configuration */
        .cfgIn      = 0x00000000u,  /* Port input buffer configuration */
        .cfgOut     = 0x00000000u,  /* Port output buffer configuration */
        .cfgSIO     = 0x00000000u,  /* Port SIO configuration */
        .sel0Active = 0x00000000u,  /* HSIOM selection for port pins 0,1,2,3 */
        .sel1Active = 0x00000000u,  /* HSIOM selection for port pins 4,5,6,7 */
    };
#endif
uint32_t    pinState = 0ul;


void GPIO_Interrupt(void);

int main(void)
{
    volatile uint32_t pinReadValue = 0ul; /* Volatile to prevent compiler optimizing out examples */
    uint32_t portReadValue = 0ul;
    uint32_t portNumber = 0ul;
    uint32_t pinStateCounter = 0ul;
    
    __enable_irq(); /* Enable global interrupts. */

    
#if PDL_PIN_CONFIGURATION
   
    Cy_GPIO_Pin_FastInit(P0_3_PORT, P0_3_NUM, CY_GPIO_DM_STRONG, 1, HSIOM_SEL_GPIO);
    Cy_GPIO_Pin_FastInit(P11_1_PORT, P11_1_NUM, CY_GPIO_DM_STRONG, 1, HSIOM_SEL_GPIO);
    
   
    Cy_GPIO_Pin_Init(P0_4_PORT,P0_4_NUM, &P0_4_Pin_Init);
    Cy_GPIO_Port_Init(GPIO_PRT5, &port5_Init);
#else
    Cy_GPIO_SetHSIOM(SW2_P0_4_PORT, SW2_P0_4_NUM, (en_hsiom_sel_t)SW2_P0_4_INIT_MUXSEL);
    Cy_GPIO_SetDrivemode(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_DM_PULLUP);
    Cy_GPIO_SetVtrip(SW2_P0_4_PORT, SW2_P0_4_NUM, SW2_P0_4_THRESHOLD_LEVEL);
    Cy_GPIO_SetSlewRate(SW2_P0_4_PORT, SW2_P0_4_NUM, SW2_P0_4_SLEWRATE);
    Cy_GPIO_SetDriveSel(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_DRIVE_FULL);
#endif
    Cy_GPIO_SetInterruptEdge(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_INTR_RISING);
    Cy_GPIO_SetInterruptMask(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_INTR_EN_MASK);
    /* Configure CM4+ CPU GPIO interrupt vector for Port 0 */
    Cy_SysInt_Init(&SysInt_Port0_cfg, GPIO_Interrupt);
    NVIC_ClearPendingIRQ(SysInt_Port0_cfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)SysInt_Port0_cfg.intrSrc);
    
    for(;;)
    {
        
        pinReadValue = Cy_GPIO_Read(SW2_P0_4_PORT, SW2_P0_4_NUM);
        
       
        #define mySwPin_Port P0_4_PORT 
        #define mySwPin_Num  P0_4_NUM
        pinReadValue = Cy_GPIO_Read(mySwPin_Port, mySwPin_Num);
        pinReadValue = Cy_GPIO_Read(P0_4_PORT, P0_4_NUM);     
        pinReadValue = Cy_GPIO_Read(GPIO_PRT0, 4);
        portNumber = 0;
        pinReadValue = Cy_GPIO_Read(Cy_GPIO_PortToAddr(portNumber), 4);
        pinReadValue = (GPIO_PRT0->IN >> P0_4_NUM) & CY_GPIO_IN_MASK;
        Cy_GPIO_Write(LED_Red_P0_3_PORT, LED_Red_P0_3_NUM, pinReadValue);

        #define myLedPin_Port P0_3_PORT 
        #define myLedPin_Num  P0_3_NUM
        Cy_GPIO_Write(myLedPin_Port, myLedPin_Num, pinReadValue);
        Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, pinReadValue);
        Cy_GPIO_Write(GPIO_PRT0, 3, pinReadValue);
        portNumber = 0;
        Cy_GPIO_Write(Cy_GPIO_PortToAddr(portNumber), 3, pinReadValue);

        if(1u == pinReadValue)
        {
            Cy_GPIO_Set(LED_Red_P0_3_PORT, LED_Red_P0_3_NUM);
            Cy_GPIO_Clr(LED_Blue_P11_1_PORT,LED_Blue_P11_1_NUM);
        }
        else
        {
            Cy_GPIO_Clr(LED_Red_P0_3_PORT, LED_Red_P0_3_NUM);
            Cy_GPIO_Set(LED_Blue_P11_1_PORT,LED_Blue_P11_1_NUM);
        }
        Cy_GPIO_Inv(LED_Red_P0_3_PORT, LED_Red_P0_3_NUM);
        GPIO_PRT0->OUT_INV = CY_GPIO_OUT_MASK << P0_3_NUM; /* Equivalent to Cy_GPIO_Inv() function */
        portReadValue = GPIO_PRT5->IN;
        portReadValue++;
        GPIO_PRT5->OUT = portReadValue;
        if(GPIO_ISR_FLAG == pinState)
        {
            pinStateCounter++;
            if(PIN_DELAY > pinStateCounter)
            {
                Cy_GPIO_Clr(P11_1_PORT, P11_1_NUM); 
            }
            else
            {
                Cy_GPIO_Set(P11_1_PORT, P11_1_NUM);
                pinState = 0;
                pinStateCounter = 0;
            }
        }   
    }
}
void GPIO_Interrupt()
{
    uint32_t portIntrStatus;
    
    if((Cy_GPIO_GetInterruptCause0() & INTCAUSE0_PORT0) == INTCAUSE0_PORT0)
    {
        if(Cy_GPIO_GetInterruptStatus(SW2_P0_4_PORT, SW2_P0_4_NUM) == CY_GPIO_INTR_STATUS_MASK)
        {
            pinState = GPIO_ISR_FLAG;
        }
       
        portIntrStatus = SW2_P0_4_PORT->INTR;
        if(CY_GPIO_INTR_STATUS_MASK == ((portIntrStatus >> SW2_P0_4_NUM) & CY_GPIO_INTR_STATUS_MASK))
        {
            pinState = GPIO_ISR_FLAG;
        }
    }    
    
    Cy_GPIO_ClearInterrupt(SW2_P0_4_PORT, SW2_P0_4_NUM);
}