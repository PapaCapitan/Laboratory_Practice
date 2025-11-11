#include "../../CMSIS/Devices/STM32F4xx/Inc/stm32f4xx.h"
#include "../../CMSIS/Devices/STM32F4xx/Inc/STM32F411xE/stm32f411xe.h"

void Register_Init(void);
void Led_Init(void);
void delay_but(void);
void but(uint8_t led[][2]);
void delay(uint8_t a, uint8_t led[][2]);
void work(uint8_t led[][2]);