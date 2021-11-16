#include <stdio.h>

int main()
{
    int l = 0, x;
    for (int k = 0; k < 4; k++)
    {
        x = 1;
        for (int i = 0; i < 2 + l; i++)
        {
            for (int j = 0; j < 5 - i - 1; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < x * 2 - 1; j++)
            {
                printf("%c", 164);
            }
            x++;
            printf("\n");
        }
        l++;
    }
    return 0;
}