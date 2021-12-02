#include <stdio.h>
#include <string.h>
struct items {
    int code;
    char name[30];
    int quantity;
    int price;
};
int printing();
int main(int argc, char const *argv[])
{
    

    // while (1)
    // {
    printing();
    // }
    return 0;
}
int printing()
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
    // int product_len = 6;
    // int product_code[6] = {1, 2, 3, 4, 5, 6};
    // char *product_name[6] = {"Apple", "Banana", "Cat", "Dog", "Elf", "Fish"};
    // int product_quantity[6] = {10, 7, 12, 14, 14, 15};
    // int product_prices[6] = {100, 150, 120, 140, 140, 150};

    // // Cart's DATA
    // int cart_len = 2;
    // int cart_code[6] = {4, 2};
    // // char *cart_name[] = {"Apple", "Banana", "Cat", "Dog", "Elf", "Fish"};
    // // int cart_code[] = {1, 2, 3, 4, 5, 6};
    // char *cart_name[6] = {"Dog", "Banana"};
    // // int cart_quantity[] = {10,15,12,16,14,15};
    // int cart_quantity[6] = {2, 8};
    // int cart_prices[6] = {280, 1200};
    
    FILE *ptr;
    ptr = fopen("Products.txt", "r");
    if (ptr == NULL)
    {
        printf("ERROR\n");
        return 1;
    }
    
    int code, quantity, price;
    char name[20];
    struct items product[10]; 
    for (int i = 0;fscanf(ptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF; i++)
    {
        product[i].code = code; 
        strcpy(product[i].name , name); 
        product[i].quantity = quantity; 
        product[i].price = price; 
          
    }
    // Printing
    printf("\t\t\tPRODUCTS\t\t\t\t\tCART\nCODES\tPRODUCT NAMES\tQUANTITY\tPRICES   |   CODES\tPRODUCT NAMES\tQUANTITY\tPRICES\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%i\t%s\t\t%i\t\t%i\t |", product[i].code, product[i].name, product[i].quantity, product[i].price);
        // if (cart_len > i)
        // {
        //     printf("   %i\t\t%s\t\t%i\t\t%i\n", cart_code[i], cart_name[i], cart_quantity[i], cart_prices[i]);
        // }
    //     else
    //     {
            printf("\n");
    //     }
    }
    for (int i = 0; i < 15; i++)
    {
        printf("--------");
    }
    for (int i = 0; i <= 5; i++)
    {
        printf("Code: %d\nName: %s\nQuantity: %d \nPrice: %d\n\n", product[i].code,  product[i].name,  product[i].quantity,  product[i].price);
    }
    printf("\n");
}
