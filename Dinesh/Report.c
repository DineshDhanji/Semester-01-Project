#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct items
{
    int code;
    char name[30];
    int quantity;
    int price;
};
// #include <windows.h>
int main(int argc, char const *argv[])
{






    
    system("cls");
    printf("\x1B[1;%dm", 29);
    printf("\t\t\t\t<--- SALE REPORT --->\n\n");
    FILE *fileptr;
    fileptr = fopen("./Products.txt", "r");
    if (fileptr == NULL)
    {
        printf("\t\t\t\tCould not open the file. (! . !)\n");
        exit(1);
    }

    int code, quantity, price, productQuantity;
    char name[20];
    fscanf(fileptr, "%d", &productQuantity);

    int *OpeningStock;
    float *Profits;
    struct items *ClosingStock;
    OpeningStock = (int *)calloc(productQuantity, sizeof(int));
    ClosingStock = (struct items *)calloc(productQuantity, sizeof(struct items));
    Profits = (float *)calloc(productQuantity, sizeof(float));

    int i = 0;
    while (fscanf(fileptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF)
    {
        OpeningStock[i] = quantity;
        i++;
    }
    fclose(fileptr);

    // FILE *fileptr;
    fileptr = fopen("./Products Data.txt", "r");
    if (fileptr == NULL)
    {
        printf("\t\t\t\tCould not open the file. (! . !)\n");
        exit(1);
    }

    i = 0;
    while (fscanf(fileptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF)
    {
        ClosingStock[i].code = code;
        strcpy(ClosingStock[i].name, name);
        ClosingStock[i].quantity = quantity;
        ClosingStock[i].price = price;
        i++;
    }

    float TotalSaleInAmount = 0, TotalCost = 0, TotalMarUp = 0;
    // printf("Product Name\t\tSale Per Unit\tSale in Amount\tCost\t\tMarkup/Profit\n");
    for (int i = 0; i < productQuantity; i++)
    {
        int SaleInAmount = ClosingStock[i].price * (OpeningStock[i] - ClosingStock[i].quantity);
        float Cost = SaleInAmount / 1.2;
        float MarkUp = SaleInAmount - Cost;
        // printf("%s\t\t\t%d\t\t%d\t\t%.2f\t\t%.2f\n", ClosingStock[i].name, ClosingStock[i].price, SaleInAmount, Cost, MarkUp);
        TotalSaleInAmount += SaleInAmount;
        TotalCost += Cost;
        TotalMarUp += MarkUp;
        Profits[i] = round(MarkUp);
    }
    // printf("\nTOTAL:\t\t\t\t\t%.2f\t\t%.2f\t\t%.2f\n", TotalSaleInAmount, TotalCost, TotalMarUp);

    for (int i = 0; i < productQuantity; i++)
    {
        printf("%f\n", Profits[i] );
    }

    // fileptr = fopen("./Products Info.txt", "r");
    // if (fileptr == NULL)
    // {
    //     printf("\t\t\t\tCould not open the file. (! . !)\n");
    //     exit(1);
    // }

    // while (fscanf(fileptr, "%d %s %d %d", &code, name ,&quantity,&price) != EOF)
    // {
    //     /* code */
    // }

    for (int i = 0; i < productQuantity; i++)
    {
        for (int j = i; j < productQuantity; j++)
        {
            if (Profits[i] < Profits[j])
            {
                float temp = Profits[j];
                Profits[j] = Profits[i];
                Profits[i] = temp;
            }
        }
    }

    for (int i = 0; i < productQuantity; i++)
    {
        printf("%f\n", Profits[i] );
    }
    

    // int a[] = {40, 10, 25, 10, 4, 2};

    for (int i = 100; i >= 0; i-=2)
    {
        if (i <= Profits[0]+2)
        {
            // printf("i:%d\n",i);
            printf("\x1B[0;%dm", 29);
            printf("\t\t%d\t", i);
            for (int j = 0; j < 6; j++)
            {
                printf("\x1B[0;%dm", 30 + j);
                if (Profits[j] >= i)
                {
                    printf("\t%c", 219);
                }
                else
                {
                    printf("\t%c", 0);
                }
            }
            printf("\n");
        }
        
            // printf("ouyt:%d\n",i);
        // if (i <= (a[0] + 2) / 2)
        // {
            // printf("i:%d\n",i);
        //     // printf("\x1B[0;%dm", 29);
        //     printf("  %d\t", per);
        //     for (int j = 0; j < len; j++)
        //     {
        //         printf("\x1B[0;%dm", 30 + j);
        //         if (a[j] >= per)
        //         {
        //             printf("\t%c", 219);
        //         }
        //         else
        //         {
        //             printf("\t%c", 0);
        //         }
        //     }
        //     per -= 2;
        //     printf("\n");
        // }
    }
    printf("\t");
    printf("\x1B[0;%dm", 29);
    for (int i = 0; i < 9; i++)
    {
        printf("________");
    }

    return 0;
}