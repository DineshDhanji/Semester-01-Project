#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// STRUCTURES
struct items
{
    int code;
    char name[30];
    int quantity;
    int price;
};

// FUNCTIONS
void printing();
int greeting();

// MAIN
int main(int argc, char const *argv[])
{
    // To clean previous lines.
    system("cls");

    int DidYouGreet = 0;
    while (1)
    {
        if (DidYouGreet == 0)
        {
            DidYouGreet = greeting();
        }
        if (DidYouGreet == 1)
        {
            system("cls");
            printing();
            // Temporary work to stop screen
                printf("\n");
                while (getchar() != '\n');
                getchar();
        }
    }
    return 0;
}
int greeting()
{
    int num;
    printf("\t\t\t\t\tWELCOME TO MAAD MART\n\n\t\t\t\tSelect the respective option:\n\t\t\tRequest Report Generator\t\t0\n\t\t\tGo To Cart\t\t\t\t1\n\t\t\tInput: ");
    scanf(" %d", &num);
    switch (num)
    {
    case 0:
        // Temporary work
            printf("\t\t\t\tReport Generated `\\(O w O)/`\n");
            sleep(1);
            system("cls");
            return 1;
            // reportGeneration();    to be create
        break;
    case 1:
        // Temporary work
            printf("\t\t\t\t\tOk `\\(^ o ^)/`\n");
            sleep(1);
            system("cls");
            return 1;
            // reportGeneration();    to be create
        break;

    default:
        printf("\t\t\t\t  Invalid input ! (@ . @)\n");
        sleep(1);
        system("cls");
        return 0;
        // break;
    }
}
void printing()
{
    // Opening Product Data file for updating data.
    FILE *ptr;
    ptr = fopen("Products Data.txt", "r+");
    if (ptr == NULL)
    {
        printf("ERROR\n");
        // return 1;
        exit(1);
    }

    // Accessing new data. 
    int code, quantity, price;
    char name[20];
    struct items product[10];
    for (int i = 0; fscanf(ptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF; i++)
    {
        product[i].code = code;
        strcpy(product[i].name, name);
        product[i].quantity = quantity;
        product[i].price = price;
    }

    // Design printing
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

    // Printing Products
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

    // Closing file
    fclose(ptr);
    
    
    // Work to be decided
    // // Cart's DATA
    // int cart_len = 2;
    // int cart_code[6] = {4, 2};
    // // char *cart_name[] = {"Apple", "Banana", "Cat", "Dog", "Elf", "Fish"};
    // // int cart_code[] = {1, 2, 3, 4, 5, 6};
    // char *cart_name[6] = {"Dog", "Banana"};
    // // int cart_quantity[] = {10,15,12,16,14,15};
    // int cart_quantity[6] = {2, 8};
    // int cart_prices[6] = {280, 1200};
    // Printing
}