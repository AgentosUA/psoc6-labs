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
    
    /* The method to configure all attributes of a single pin is to use the */
    /* Cy_GPIO_Pin_Init() function and configuration structure. While easy to use, it generates */
    /* larger code than other methods. */
    Cy_GPIO_Pin_Init(P0_4_PORT,P0_4_NUM, &P0_4_Pin_Init);
    
    /* The most code efficient method to configure all attributes for a full port of pins */
    /* is to use the Cy_GPIO_Port_Init() API function and configuration structure. It packs all */
    /* the configuration data into direct register writes for the whole port. Its limitation */
    /* is that it must configure all pins in a port and the user must calculate the */
    /* combined register values for all pins or copy them from a configuration tool. */
    /* This is the method used by automated configuration tools. */
    Cy_GPIO_Port_Init(GPIO_PRT5, &port5_Init);
#else
    Cy_GPIO_SetHSIOM(SW2_P0_4_PORT, SW2_P0_4_NUM, (en_hsiom_sel_t)SW2_P0_4_INIT_MUXSEL);
    Cy_GPIO_SetDrivemode(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_DM_PULLUP);
    Cy_GPIO_SetVtrip(SW2_P0_4_PORT, SW2_P0_4_NUM, SW2_P0_4_THRESHOLD_LEVEL);
    Cy_GPIO_SetSlewRate(SW2_P0_4_PORT, SW2_P0_4_NUM, SW2_P0_4_SLEWRATE);
    Cy_GPIO_SetDriveSel(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_DRIVE_FULL);
#endif
        
    /* Pin Interrupts */
    /* Configure GPIO pin to generate interrupts */
    Cy_GPIO_SetInterruptEdge(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_INTR_RISING);
    Cy_GPIO_SetInterruptMask(SW2_P0_4_PORT, SW2_P0_4_NUM, CY_GPIO_INTR_EN_MASK);
    /* Configure CM4+ CPU GPIO interrupt vector for Port 0 */
    Cy_SysInt_Init(&SysInt_Port0_cfg, GPIO_Interrupt);
    NVIC_ClearPendingIRQ(SysInt_Port0_cfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)SysInt_Port0_cfg.intrSrc);
    
     Cy_TCPWM_PWM_Init(PWM_1_HW, PWM_1_CNT_NUM, &PWM_1_config);
    Cy_TCPWM_PWM_Enable(PWM_1_HW, PWM_1_CNT_NUM);
    
    Cy_TCPWM_PWM_Init(PWM_2_HW, PWM_2_CNT_NUM, &PWM_2_config);
    Cy_TCPWM_PWM_Enable(PWM_2_HW, PWM_2_CNT_NUM);
    
    Cy_TCPWM_PWM_Init(PWM_3_HW, PWM_3_CNT_NUM, &PWM_3_config);
    Cy_TCPWM_PWM_Enable(PWM_3_HW, PWM_3_CNT_NUM);
    
    
    for(;;)
    {
        
        pinReadValue = Cy_GPIO_Read(SW2_P0_4_PORT, SW2_P0_4_NUM);
        
        /* Pin read with user defined custom #define pin name. This is the preferred */
        /* method for direct PDL use without a configuration tool. #defines are typically */
        /* placed in .h file but included here for example simplicity and clarity */
        #define mySwPin_Port P0_4_PORT 
        #define mySwPin_Num  P0_4_NUM
        pinReadValue = Cy_GPIO_Read(mySwPin_Port, mySwPin_Num);
        
    
        pinReadValue = Cy_GPIO_Read(P0_4_PORT, P0_4_NUM);     
        
     
        pinReadValue = Cy_GPIO_Read(GPIO_PRT0, 4);
        

        portNumber = 0;
        pinReadValue = Cy_GPIO_Read(Cy_GPIO_PortToAddr(portNumber), 4);
        
        /* Direct port IN register read with mask and shift of desired pin data */
        pinReadValue = (GPIO_PRT0->IN >> P0_4_NUM) & CY_GPIO_IN_MASK;
        
        
        

        #define myLedPin_Port P0_3_PORT 
        #define myLedPin_Num  P0_3_NUM
        Cy_GPIO_Write(myLedPin_Port, myLedPin_Num, pinReadValue);
        
       
        Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, pinReadValue);
    
        Cy_GPIO_Write(GPIO_PRT0, 3, pinReadValue);
     
        portNumber = 0;
        Cy_GPIO_Write(Cy_GPIO_PortToAddr(portNumber), 3, pinReadValue);
                        
        int p = 1000;
        int i = 2000;
        
        if(1u == pinReadValue)
        {
            Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, 1u);
            Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 0u);
            Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 0u);
        
            Cy_TCPWM_TriggerStart(PWM_1_HW, PWM_1_CNT_MASK);
            CyDelay(p);
            Cy_TCPWM_TriggerStopOrKill(PWM_1_HW, PWM_1_CNT_NUM);
            Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, 0u);
        
            CyDelay(1000);
        
            Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 1u);
            Cy_TCPWM_TriggerStart(PWM_2_HW, PWM_2_CNT_MASK);
            CyDelay(p);
            Cy_TCPWM_TriggerStopOrKill(PWM_2_HW, PWM_2_CNT_NUM);
            Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 0u);
        
            CyDelay(1000);
        
            Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 1u);
            Cy_TCPWM_TriggerStart(PWM_3_HW, PWM_3_CNT_MASK);
            CyDelay(p);
            Cy_TCPWM_TriggerStopOrKill(PWM_3_HW, PWM_3_CNT_NUM);
            Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 0u);
            
            CyDelay(1000);
            
        }
        else
        {   
            
            Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, 1u);
            Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 0u);
            Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 0u);
        
            Cy_TCPWM_TriggerStart(PWM_1_HW, PWM_1_CNT_MASK);
            CyDelay(i);
            Cy_TCPWM_TriggerStopOrKill(PWM_1_HW, PWM_1_CNT_NUM);
            Cy_GPIO_Write(P0_3_PORT, P0_3_NUM, 0u);
        
            CyDelay(1000);
        
            Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 1u);
            Cy_TCPWM_TriggerStart(PWM_2_HW, PWM_2_CNT_MASK);
            CyDelay(i);
            Cy_TCPWM_TriggerStopOrKill(PWM_2_HW, PWM_2_CNT_NUM);
            Cy_GPIO_Write(P11_1_PORT, P11_1_NUM, 0u);
        
            CyDelay(1000);
        
            Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 1u);
            Cy_TCPWM_TriggerStart(PWM_3_HW, PWM_3_CNT_MASK);
            CyDelay(i);
            Cy_TCPWM_TriggerStopOrKill(PWM_3_HW, PWM_3_CNT_NUM);
            Cy_GPIO_Write(P1_1_PORT, P1_1_NUM, 0u);
            
            CyDelay(1000);
        }
        portReadValue = GPIO_PRT5->IN;
        portReadValue++;
        GPIO_PRT5->OUT = portReadValue;
        
        
        
        /* Service ISR flag */
        /*******************************************************************************/
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
        }     }
}

void GPIO_Interrupt()
{
    uint32_t portIntrStatus;
    
    /* Optional check to determine if correct Port generated interrupt. */
    /* Only used if a single interrupt vector is used for multiple Ports due to vector */
    /* limitations. Preferred method is to use unique interrupt vector for each Port. */
    if((Cy_GPIO_GetInterruptCause0() & INTCAUSE0_PORT0) == INTCAUSE0_PORT0)
    {
        /* Optional check to determine if one pin in the port generated interrupt. */
        if(Cy_GPIO_GetInterruptStatus(SW2_P0_4_PORT, SW2_P0_4_NUM) == CY_GPIO_INTR_STATUS_MASK)
        {
            pinState = GPIO_ISR_FLAG;
        }
        /* Alternate optional check to determine which pin(s) in the port generated interrupt. */
        portIntrStatus = SW2_P0_4_PORT->INTR;
        if(CY_GPIO_INTR_STATUS_MASK == ((portIntrStatus >> SW2_P0_4_NUM) & CY_GPIO_INTR_STATUS_MASK))
        {
            pinState = GPIO_ISR_FLAG;
        }
    }    

    Cy_GPIO_ClearInterrupt(SW2_P0_4_PORT, SW2_P0_4_NUM);
}
