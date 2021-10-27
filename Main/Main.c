#include <stdio.h>

void productPrint();

int main(int argc, char const *argv[])
{
    int code[] = {1, 2, 3, 4, 5, 6};
    char *name[7] = {"Apple", "Banana", "Cat", "Dog", "Elf", "Fish"};
    int quantity[] = {10,15,12,16,14,15};
    productPrint(sizeof(code) / 4, code, name, quantity);
    int num0;
    printf("Input Code:\n");
    scanf("%i", &num0);
    return 0;
}
void productPrint(int len, int code[], char *name[], int quantity[])
{
    printf("CODES\t\tPRODUCT NAMES\t\tQUANTITY\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%i\t\t%s\t\t\t%i\n", i, name[i], quantity[i]);
    }
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
    
}
