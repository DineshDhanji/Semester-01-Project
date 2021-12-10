
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// STRUCTURES
struct items
{
    int code;
    char name[30];
    int quantity;
    int price;
} product[10] =
    {
        {1, "Apple", 6, 100},
        {2, "Banana", 7, 150},
        {3, "Cat", 12, 120},
        {4, "Dog", 14, 140},
        {5, "Elf", 14, 140},
        {6, "Fish", 15, 150}},
  cart[10];

// int countproduct();
// int countcart();
// void message(int);

int main()
{
    int userCode, userQuantity, quantity = 6, checkCode = 0, cont;
    while (1)
    {
        system("cls");
        printf("Code\tName\tQuantity\tprice\n\n");

        for (int i = 0; i < quantity; i++)
        {
            // printf("%d\t", product[i].code);
            // if (product[i].quantity == 0)
            // {
            //     printf("Out Of Stock");
            // }
            // else
            // {
            //     printf("%s", product[i].name);
            // }
            // printf("\t%d\t\t%c%d\n",product[i].quantity, 36, product[i].price);

            printf("%d\t%s\t%d\t\t%c%d\n", product[i].code, product[i].name, product[i].quantity, 36, product[i].price);
        }
        printf("Cart is Down Here (^-^)\n");
        for (int i = 0; i < countcart(); i++)
        {
            printf("%d\t%s\t%d\t\t%c%d\n", cart[i].code, cart[i].name, cart[i].quantity, 36, cart[i].price);
        }
        printf("\nInput: ");
        scanf(" %d", &userCode);

        if (userCode == 0)
        {
            printf("SPECIAL TOOLS OPEN\n");
        }
        else
        {
            for (int i = 0; i < quantity; i++)
            {
                if (userCode == product[i].code)
                {
                    checkCode = 1;
                    do
                    {
                        cont = 0;
                        printf("Input the quantity: ");
                        scanf(" %d", &userQuantity);
                        if (userQuantity > product[i].quantity || userQuantity < 1)
                        {
                            cont = 1;
                            printf("Given quantity is invalid (o_O)\n");
                        }
                    } while (cont);
                    int present = -1;
                    for (int j = 0; j < quantity; j++)
                    {
                        if (product[i].code == cart[j].code)
                        {
                            printf("x");
                            present = j;
                            break;
                        }
                    }
                    if (present >  -1)
                    {
                        // cart[present] = product.
                        // strcpy(cart[present].name, p[present].name);
                        // cart[present].code = product[i].code;
                        cart[present].quantity += userQuantity;
                        cart[present].price += userQuantity * product[i].price;
                        product[i].quantity -= userQuantity;
                    }
                    else
                    {
                        int count = 0;
                        while (cart[count].code > 0)
                        {
                            count++;
                        }

                        strcpy(cart[count].name, product[i].name);
                        cart[count].code = product[i].code;
                        cart[count].quantity = userQuantity;
                        cart[count].price = userQuantity * product[i].price;
                        product[i].quantity -= userQuantity;
                    }

                    break;
                }
            }
            if (checkCode == 0)
            {
                printf("Given code is invalid (o_O)\n");
            }
        }
        
        
    }
    return 0;
}

// /*
// int countproduct()
// {
//     int c=0;
//     while (product[c].code > 0)
//     {
//         c++;
//     }
//     return c;
    
// }


int countcart()
{
    int c=0;
    while (cart[c].code > 0)
    {
        c++;
    }
    return c;
    
}

// void message(int cur)
// {
//    if(product[cur].quantity == 0 && (product[cur].code == cart[cur].inCode))
//     {
//             printf("\nSorry! %s is out of stock\n",product[cur].name);
//     }
//     else if(product[cur].quantity > 0 && product[cur].quantity <= 5 && (product[cur].code == cart[cur].inCode))
//     {
//             printf("\nHurry Up! %s is becoming out of stock\n",cart[cur].inName);
//     }
// }

// */