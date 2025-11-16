#include "../Inc/init.h"

int main()
{
    uint8_t mode = 1;
    Register_Init();
    Led_Init();
    while(1)
    {
        if (READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_13) != 0)
        {
            delay();
            if (mode < 5)
            mode = mode + 1;
            else
            {
                mode = 1;
            }
        }
        switch (mode)
        {
            case 1: All_Ports_Input(); break;
            case 2: First_Port_Output(); break;
            case 3: Second_Port_Output(); break;
            case 4: Third_Port_Output(); break;
            case 5: All_Ports_Output(); break;
        }
        if ((READ_BIT(GPIOE->IDR, GPIO_IDR_IDR_0) != 0) && mode !=5 && mode != 2)
        {
            S_BIT(GPIO_B_BSRR, GPIO_B_BSRR_PB0_SET);
        }
        else
        {
            S_BIT(GPIO_B_BSRR, GPIO_B_BSRR_PB0_RESET);
        }
        if ((READ_BIT(GPIOD->IDR, GPIO_IDR_IDR_7) != 0) && mode != 5 && mode != 3)
        {
            *(uint32_t*)(0x40020400UL + 0x18UL) |= 0x80;
        }
        else
        {
            *(uint32_t*)(0x40020400UL + 0x18UL) |= 0x800000;
        }
        if (READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_8) != 0 && mode != 5 && mode != 4)
        {
            SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14);
        }
        else
        {
            SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR14);
        }
    }
}