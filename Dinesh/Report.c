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
    struct pro
    {
        char name[20];
        float profit;
    };

    system("cls");
    printf("\x1B[1;%dm", 29);
    printf("\t\t\t\t\t<--- SALE REPORT --->\n\n");
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
    struct items *ClosingStock;
    OpeningStock = (int *)calloc(productQuantity, sizeof(int));
    ClosingStock = (struct items *)calloc(productQuantity, sizeof(struct items));
    struct pro *Profits;
    Profits = (struct pro *)calloc(productQuantity, sizeof(struct pro));


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
    for (int i = 0; i < productQuantity; i++)
    {
        int SaleInAmount = ClosingStock[i].price * (OpeningStock[i] - ClosingStock[i].quantity);
        float Cost = SaleInAmount / 1.2;
        float MarkUp = SaleInAmount - Cost;
        TotalSaleInAmount += SaleInAmount;
        TotalCost += Cost;
        TotalMarUp += MarkUp;
        strcpy(Profits[i].name, ClosingStock[i].name);
        Profits[i].profit = round(MarkUp);
    }

    for (int i = 0; i < productQuantity; i++)
    {
        for (int j = i; j < productQuantity; j++)
        {
            if (Profits[i].profit < Profits[j].profit)
            {
                struct pro temp = Profits[j];
                Profits[j] = Profits[i];
                Profits[i] = temp;
            }
        }
    }

    for (int i = 100; i >= 0; i -= 2)
    {
        if (i <= Profits[0].profit + 2)
        {
            // printf("i:%d\n",i);
            printf("\x1B[0;%dm", 29);
            printf("\t\t\t%d\t", i);
            for (int j = 0; j < 6; j++)
            {
                printf("\x1B[0;%dm", 30 + j);
                if (Profits[j].profit >= i)
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
    }
    printf("\t\t");
    printf("\x1B[0;%dm", 29);
    for (int i = 0; i < 9; i++)
    {
        printf("________");
    }
    printf("\n\n\t\t\tLegends:\n\t\t\t");
    for (int i = 0; i < 6; i++)
    {
        printf("\x1B[0;%dm", 30 + i);
        printf("%c ", 254);
        printf("\x1B[0;%dm", 29);
        printf("%s\t", Profits[i].name);
    }
    
    printf("\x1B[1;%dm", 29);
    printf("\n\n\n\t\tProduct Name\t\tSale Per Unit\tSale in Amount\tCost\t\tMarkup/Profit\n\t\t");
    printf("\x1B[0;%dm", 29);
    for (int i = 0; i < productQuantity; i++)
    {
        
        int SaleInAmount = ClosingStock[i].price * (OpeningStock[i] - ClosingStock[i].quantity);
        float Cost = SaleInAmount / 1.2;
        float MarkUp = SaleInAmount - Cost;
        printf("%s\t\t\t%d\t\t%d\t\t%.2f\t\t%.2f\n\t\t", ClosingStock[i].name, ClosingStock[i].price, SaleInAmount, Cost, MarkUp);
    }
    for (int i = 0; i < 11; i++)
    {
        printf("=======");
    }
    
    printf("\n\t\tTOTAL:\t\t\t\t\t%.2f\t\t%.2f\t\t%.2f\n\n", TotalSaleInAmount, TotalCost, TotalMarUp);
    free(OpeningStock);
    free(ClosingStock);
    free(Profits);
    return 0;
}
