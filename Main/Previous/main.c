#include <stdio.h>

void printing();
int main(int argc, char const *argv[])
{

    // while (1)
    // {
    printing();
    // }
    return 0;
}
void printing()
{
    // Welcome design
    for (int i = 0; i < 15; i++)
    {
        printf("--------");
    }
    printf("\n");
    printf("\t\t\t\t\tWELCOME TO MAAD MART\n");
    for (int i = 0; i < 15; i++)
    {
        printf("--------");
    }
    printf("\n");

    // Product's DATA
    int product_len = 6;
    int product_code[6] = {1, 2, 3, 4, 5, 6};
    char *product_name[6] = {"Apple", "Banana", "Cat", "Dog", "Elf", "Fish"};
    int product_quantity[6] = {10, 7, 12, 14, 14, 15};
    int product_prices[6] = {100, 150, 120, 140, 140, 150};

    // Cart's DATA
    int cart_len = 2;
    int cart_code[6] = {4, 2};
    // char *cart_name[] = {"Apple", "Banana", "Cat", "Dog", "Elf", "Fish"};
    // int cart_code[] = {1, 2, 3, 4, 5, 6};
    char *cart_name[6] = {"Dog", "Banana"};
    // int cart_quantity[] = {10,15,12,16,14,15};
    int cart_quantity[6] = {2, 8};
    int cart_prices[6] = {280, 1200};

    // Printing
    printf("\t\t\tPRODUCTS\t\t\t\t\t\tCART\nCODES\tPRODUCT NAMES\tQUANTITY\tPRICES   |   CODES\tPRODUCT NAMES\tQUANTITY\tPRICES\n");
    for (int i = 0; i < product_len; i++)
    {
        printf("%i\t%s\t\t%i\t\t%i\t |", product_code[i], product_name[i], product_quantity[i], product_prices[i]);
        if (cart_len > i)
        {
            printf("   %i\t\t%s\t\t%i\t\t%i\n", cart_code[i], cart_name[i], cart_quantity[i], cart_prices[i]);
        }
        else
        {
            printf("\n");
        }
    }
    for (int i = 0; i < 15; i++)
    {
        printf("--------");
    }
    printf("\n");
}