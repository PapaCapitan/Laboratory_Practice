#include "../Inc/init.h"

static uint8_t i = 0;
uint16_t flag = 0;
uint16_t flag1 = 0;

void Register_Init(void)
{
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN);
}
void Led_Init(void)
{
    // First Led (green)
    SET_BIT(GPIOA->MODER, GPIO_MODER_MODE4_0);
    CLEAR_BIT(GPIOA->OTYPER, GPIO_OTYPER_OT_4);
    SET_BIT(GPIOA->OSPEEDR, GPIO_OSPEEDR_OSPEED4_0);
    CLEAR_BIT(GPIOA->PUPDR, GPIO_PUPDR_PUPDR4_0);
    // Second Led (blue)
    SET_BIT(GPIOB->MODER, GPIO_MODER_MODE0_0);
    CLEAR_BIT(GPIOB->OTYPER, GPIO_OTYPER_OT_0);
    SET_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDR_OSPEED0_0);
    CLEAR_BIT(GPIOB->PUPDR, GPIO_PUPDR_PUPDR0_0);
    // Third Led (red)
    SET_BIT(GPIOC->MODER, GPIO_MODER_MODE1_0);
    CLEAR_BIT(GPIOC->OTYPER, GPIO_OTYPER_OT_1);
    SET_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDR_OSPEED1_0);
    CLEAR_BIT(GPIOC->PUPDR, GPIO_PUPDR_PUPDR1_0);
}
void but(uint8_t led[3][2])
{
    uint64_t count = 0;
    if (READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_8) != 0)
    {
        while (count < 400000)
        {
            count++;
        }
        if (led[i][0] == 0)
        {
            led[i][0] = 1;
        }
        else
        {
            led[i][0] = 0;
        }
    }
    if (READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_6) != 0)
    {
        while (count < 500000)
        {
            count++;
        }
        if (led[i][1] == 0)
        {
            led[i][1] = 1;
        }
        else if (led[i][1] == 1)
        {
            led[i][1] = 2;
        }
        else if (led[i][1] == 2)
        {
            led[i][1] = 0;
        }
    }
    if (READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_5) != 0)
    {
        while (count < 500000)
        {
            count++;
        }
        if (i == 0)
        {
            i = 1;
        }
        else if (i == 1)
        {
            i = 2;
        }
        else if (i == 2)
        {
            i = 0;
        }
    }
}
void delay(uint8_t a, uint8_t led[3][2])
{
    if (a == 0)
    {
        for (int j = 0; j < 100000; j++)
        {
            but(led);
        }
    }
    else if (a == 1)
    {
        for (int j = 0; j < 700000; j++)
        {
            but(led);
        }
    }
    else
    {
        for (int j = 0; j < 2000000; j++)
        {
            but(led);
        }
    }
}
void work(uint8_t led[3][2])
{
    if (led[0][0] == 1)
    {
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS4);
        delay(led[0][1], led);
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR4);
        if (led[1][0] != 0 || led[2][0] != 0)
        {
        }
        else
        {
            delay(led[0][1], led);
        }
    }
    if (led[1][0] == 1)
    {
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0);
        delay(led[1][1], led);
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR0);
        if (led[0][0] != 0 || led[2][0] != 0)
        {
        }
        else
        {
            delay(led[1][1], led);
        }
    }
    if (led[2][0] == 1)
    {
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS1);
        delay(led[2][1], led);
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR1);
        if (led[1][0] != 0 || led[0][0] != 0)
        {
        }
        else
        {
            delay(led[2][1], led);
        }
    }
}