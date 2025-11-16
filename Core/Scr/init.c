#include "../Inc/init.h"

void Register_Init(void)
{
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOEEN);
}
void Led_Init(void)
{
    // First Led (green)
    GPIO_B_MODER |= GPIO_B_MODE_PB0_OUT;
    GPIO_B_OTYPER |= GPIO_B_OTYPE_PB0_PP;
    GPIO_B_OSPEEDR |= GPIO_B_OSPEED_PB0_MID;
    GPIO_B_PUPDR |= GPIO_B_PUPDR_PB0_NOPUPD;
    // Second Led (blue)
    *(uint32_t*)(0x40020400UL + 0x00UL) |= 0x4000;
    *(uint32_t*)(0x40020400UL + 0x04UL) |= 0x00;
    *(uint32_t*)(0x40020400UL + 0x08UL) |= 0x4000;
    *(uint32_t*)(0x40020400UL + 0x0CUL) |= 0x00;
    // Third Led (red)
    SET_BIT(GPIOB->MODER, GPIO_MODER_MODE14_0);
    CLEAR_BIT(GPIOB->OTYPER, GPIO_OTYPER_OT_14);
    SET_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDR_OSPEED14_0);
    CLEAR_BIT(GPIOB->PUPDR, GPIO_PUPDR_PUPDR14_0);
}
void All_Ports_Input(void)
{
    // First Port
    GPIO_E_MODER &= CL_DEL_E;
    GPIO_E_OSPEEDR &= CL_DEL_E;
    Res_BIT(GPIO_B_BSRR, GPIO_B_BSRR_PB0_SET);
    // Second Port
    *(uint32_t*)(0x40020C00UL + 0x00UL) &= 0x00;
    *(uint32_t*)(0x40020C00UL + 0x08UL) &= 0x00;
    *(uint32_t*)(0x40020400UL + 0x18UL) |= 0x800000;
    // Third Port
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE8_0);
    CLEAR_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDR_OSPEED8_0);
    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR14);
}
void All_Ports_Output(void)
{
    // First Port
    GPIO_E_MODER |= GPIO_E_MODE_PE0_OUT;
    GPIO_E_OTYPER |= GPIO_E_OTYPE_PE0_PP;
    GPIO_E_OSPEEDR |= GPIO_E_OSPEED_PE0_MID;
    GPIO_E_PUPDR |= GPIO_E_PUPDR_PE0_NOPUPD;
    S_BIT(GPIO_E_BSRR, GPIO_E_BSRR_PE0_SET);
    // Second Port
    *(uint32_t*)(0x40020C00UL + 0x00UL) |= 0x4000;
    *(uint32_t*)(0x40020C00UL + 0x04UL) |= 0x00;
    *(uint32_t*)(0x40020C00UL + 0x08UL) |= 0x4000;
    *(uint32_t*)(0x40020C00UL + 0x0CUL) |= 0x00;
    *(uint32_t*)(0x40020C00UL + 0x18UL) |= 0x80;
    // Third Port
    SET_BIT(GPIOC->MODER, GPIO_MODER_MODE8_0);
    CLEAR_BIT(GPIOC->OTYPER, GPIO_OTYPER_OT_8);
    SET_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDR_OSPEED8_0);
    CLEAR_BIT(GPIOC->PUPDR, GPIO_PUPDR_PUPDR8_0);
    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS8);
}
void First_Port_Output(void)
{
    // First Port
    GPIO_E_MODER |= GPIO_E_MODE_PE0_OUT;
    GPIO_E_OTYPER |= GPIO_E_OTYPE_PE0_PP;
    GPIO_E_OSPEEDR |= GPIO_E_OSPEED_PE0_MID;
    GPIO_E_PUPDR |= GPIO_E_PUPDR_PE0_NOPUPD;
    S_BIT(GPIO_E_BSRR, GPIO_E_BSRR_PE0_SET);
    // Second Port
    *(uint32_t*)(0x40020C00UL + 0x00UL) &= 0x00;
    *(uint32_t*)(0x40020C00UL + 0x08UL) &= 0x00;
    // Third Port
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE8_0);
    CLEAR_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDR_OSPEED8_0);
}
void Second_Port_Output(void)
{
    // First Port
    GPIO_E_MODER &= CL_DEL_E;
    GPIO_E_OSPEEDR &= CL_DEL_E;
    // Second Port
    *(uint32_t*)(0x40020C00UL + 0x00UL) |= 0x4000;
    *(uint32_t*)(0x40020C00UL + 0x04UL) |= 0x00;
    *(uint32_t*)(0x40020C00UL + 0x08UL) |= 0x4000;
    *(uint32_t*)(0x40020C00UL + 0x0CUL) |= 0x00;
    *(uint32_t*)(0x40020C00UL + 0x18UL) |= 0x80;
    // Third Port
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE8_0);
    CLEAR_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDR_OSPEED8_0);
}
void Third_Port_Output(void)
{
    // First Port
    GPIO_E_MODER &= CL_DEL_E;
    GPIO_E_OSPEEDR &= CL_DEL_E;
    // Second Port
    *(uint32_t*)(0x40020C00UL + 0x00UL) &= 0x00;
    *(uint32_t*)(0x40020C00UL + 0x08UL) &= 0x00;
    // Third Port
    SET_BIT(GPIOC->MODER, GPIO_MODER_MODE8_0);
    CLEAR_BIT(GPIOC->OTYPER, GPIO_OTYPER_OT_8);
    SET_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDR_OSPEED8_0);
    CLEAR_BIT(GPIOC->PUPDR, GPIO_PUPDR_PUPDR8_0);
    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS8);
}
void delay(void)
{
    int count = 0;
    for (int i = 0; i <= 900000; i++)
    {
        count++;
    }
}