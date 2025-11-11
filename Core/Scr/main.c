#include "../Inc/init.h"

int main()
{
    uint8_t led[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            led[i][j] = 0;
        }
    }
    Register_Init();
    Led_Init();
    while(1)
    {
        but(led);
        work(led);
    }
}