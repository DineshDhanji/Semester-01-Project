#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #include <windows.h>
struct items
{
    int code;
    char name[30];
    int quantity;
    int price;
} cart[4] = {
    {1, "Apple", 2, 6},
    {2, "Banana", 2, 8},
    {3, "Elf", 1, 14},
    {4, "Fish", 1, 5}};

struct user
{
    int code;
    char name[30];
}customer;

int countcart(struct items *cart)
{
    int c = 0;
    while (cart[c].code > 0)
    {
        c++;
    }
    return c;
}

// int id = 1003;
int main(int argc, char const *argv[])
{
    customer.code = 1003;
    strcpy(customer.name, "Venom");
    printf("CHECK OUT\n");
    // fflush(stdin);
    // getchar();
    FILE *fileptr;
    fileptr = fopen("Customer Data.txt", "r+");
    if (fileptr == NULL)
    {
        printf("\t\t\t\tCould not open the file. (! . !)\n");
        exit(1);
    }
    int Customer_Number, found = 0;
    char name[30];
    while (fscanf(fileptr, "%d %s ", &Customer_Number, name) != EOF)
    {
        found = 0;
        if (Customer_Number == customer.code)
        {
            found = 1;
            // fseek(fileptr, 0, SEEK_SET);
            printf("ELSE\n");
            fprintf(fileptr,"45");
            break;
        }
    }
    if (found == 0)
    {
        fseek(fileptr, 0, SEEK_END);
        fprintf(fileptr, "%d %s\n", customer.code, customer.name);
        for (int i = 0; i < 6; i++)
        {
            fprintf(fileptr, "---");
        }
        for (int i = 0; i < countcart(cart); i++)
        {
            fprintf(fileptr, "\n%d\t%s\t%d\t%d", cart[i].code, cart[i].name, cart[i].quantity, cart[i].price);

        }        
    }
    else
    {
        
        // for (int i = 0; i < 6; i++)
        // {
        //     fprintf(fileptr, "---");
        // }
        // for (int i = 0; i < countcart(cart); i++)
        // {
        //     fprintf(fileptr, "\n%d\t%s\t%d\t%d", cart[i].code, cart[i].name, cart[i].quantity, cart[i].price);

        // }    
    }
    

    // for (i = 0; i < productQuantity; i++)
    // {
    //     fprintf(fileptr, "%d %s %d %d\n", product[i].code, product[i].name, product[i].quantity, product[i].price);
    // }
    fclose(fileptr);

    // Cleaning Cart for next iteration
    // for (int i = 0; i < countcart(cart); i++)
    // {
    //     printf("%d\t%s\t%d\t%d\n", cart[i].code, cart[i].name, cart[i].quantity, cart[i].price);
    //     // strcpy(cart[i].name, "");
    //     // cart[i].code = NULL;
    //     // cart[i].quantity = NULL;
    //     // cart[i].price = NULL;
    // }
    return 0;
}
