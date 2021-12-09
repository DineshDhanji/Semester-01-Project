#include <stdio.h>
#include <windows.h>
int main(int argc, char const *argv[])
{
    system("Color 1A"); 
    for (int i = 0; i < 10; i++)
    {
        printf("i is at %d\n", i);
    }
    
    return 0;
}
