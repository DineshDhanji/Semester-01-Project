#include <stdio.h>

int main()
{
    for (int i = 0; i < 14; i++)
    {
        if (i ==0)
        {
            printf("*\n");
        }
        for (int j = 0; j <= i + 1 && i % 2 != 0; j += 2)
        {
            if (j % 2 == 0 && j != 0)
            {
                printf("%d", j);
            }
            printf("*");
        }
        for (int j = 1; j <= i + 2 && i % 2 == 0; j += 2)
        {
            if (j % 2 != 0)
            {
                printf("%d", j);
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}