
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
}
product[10] =
{
    {1, "Apple", 6, 100 },
    {2, "Banana", 7, 150},
    {3, "Cat", 12, 120},
    {4, "Dog", 14, 140},
    {5, "Elf" ,14, 140},
    {6, "Fish", 15, 150}
};
struct cart
{
    int inCode;
    char inName[30];
    int inQuantity;
    int inPrice;
};
struct cart cart[10];

int countproduct();
int countcart();
void message(int);

int main()
{
    int cur;
    while(1)
    {
        do
        {
            printf("\nEnter code: ");
            scanf("%i",&cart[cur].inCode);
            if(cart[cur].inCode > countproduct())
            {
                printf("The index you are trying to enter is out of our product codes\n");
            }
        }while(cart[cur].inCode > countproduct());
        for(int i = 0; i < countproduct(); i++)
        {
            if(product[i].code == cart[cur].inCode) 
            {
                cart[cur].inCode = product[i].code;
                strcpy(cart[cur].inName, product[i].name);
                do
                {
                    printf("Enter the quantity: ");
                    scanf("%i",&cart[cur].inQuantity);
                }while(cart[cur].inQuantity > product[i].quantity);
                product[i].quantity = product[i].quantity - cart[cur].inQuantity;
                cart[cur].inQuantity = cart[cur].inQuantity;
                cart[cur].inPrice = cart[cur].inQuantity * product[i].price;
                // cur++;
                break;
            }
        }
        // for(int i = 0; i < cur; i++)
        // {
        //     for(int j = 0; j < cur; j++)
        //     {
        //         if(cart[j].inCode == cart[j+1].inCode)
        //         {
        //             strcpy(cart[j].inName,cart[j+1].inName);
        //             cart[j].inPrice += cart[j+1].inPrice;
        //             cart[j].inQuantity += cart[j+1].inQuantity;
        //             cur--;
        //             break;
        //         }
        //     // printf("\n----------------\n%s %i, %i",cart[i].inName,cart[i].inQuantity,cart[i].inPrice);
        //     // if(cart[i].inCode == product[i].code)
        //     // {
        //     //     message(i);
        //     // }
        //     }
        //     if(cart[i].inQuantity == 0)
        //     {
        //         cur--;
        //     }
        // }
            for(int i = 0; i < cur; i++)
            {
                for(int j = 1; j < cur; j++)
                {
                    if(cart[cur].inCode == cart[cur+1].inCode)
                    {
                    int temp = cart[cur].inCode;
                    cart[cur].inCode = cart[cur+1].inCode;
                    cart[cur+1].inCode = temp;
                    
                    char *temp2;
                    strcpy(temp2,cart[cur].inName);
                    strcpy(cart[cur].inName,cart[cur+1].inName);
                    strcpy(cart[cur+1].inName,temp2);

                    int temp3 = cart[cur].inQuantity;
                    cart[cur].inQuantity = cart[cur+1].inQuantity;
                    cart[cur+1].inQuantity = temp3;

                    int temp4 = cart[cur].inPrice;
                    cart[cur].inPrice = cart[cur+1].inPrice;
                    cart[cur+1].inPrice = temp4;

                    cur--;
                    break;
                    }
            // printf("\n----------------\n%s %i, %i",cart[i].inName,cart[i].inQuantity,cart[i].inPrice);
            // if(cart[i].inCode == product[i].code)
            // {
            //     message(i);
            // }
                }
            // if(cart[i].inQuantity == 0)
            // {
            //     cur--;
            // }
        }
        for (int i  = 0; i < countproduct(); i++)
        {
            printf("\n%s %i",product[i].name,product[i].quantity);
        }
        for(int i = 0; i <= countcart(); i++)
        {
            printf("\n----------------\n%s %i, %i",cart[i].inName,cart[i].inQuantity,cart[i].inPrice);
            if(cart[i].inCode == product[i].code)
            {
                message(i);
            }
        }
        for(int i = 0; i < countcart(); i++)
        {
            printf("\n%i %s %i %i\n",cart[i].inCode,cart[i].inName,cart[i].inQuantity,cart[i].inPrice);
        }
        // message(cur);
        cur++;
    }
    return 0;
}

int countproduct()
{
    int c=0;
    while (product[c].code > 0)
    {
        c++;
    }
    return c;
    
}

int countcart()
{
    int c=0;
    while (cart[c].inCode > 0)
    {
        c++;
    }
    return c;
    
}

void message(int cur)
{
   if(product[cur].quantity == 0 && (product[cur].code == cart[cur].inCode))
    {
            printf("\nSorry! %s is out of stock\n",product[cur].name);
    }
    else if(product[cur].quantity > 0 && product[cur].quantity <= 5 && (product[cur].code == cart[cur].inCode))
    {
            printf("\nHurry Up! %s is becoming out of stock\n",cart[cur].inName);
    }
}

