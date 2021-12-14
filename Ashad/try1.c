#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// STRUCTURES
struct items
{
    int code;
    char name[30];
    int quantity;
    int price;
} product[10],
    // {
    //     {101, "Apple", 60, 100},
    //     {102, "Banana", 50, 150},
    //     {103, "Cat", 60, 120},
    //     {104, "Dog", 140, 140},
    //     {105, "Elf", 7, 140},
    //     {106, "Fish", 15, 150}},
  cart[10];

// GLOBAL VARIABLE
int id;
// FUNCTIONS
int greeting();
void reportGenerationLoadingScreen();
void Accounts (void);
void RepeatOnInvalid1(void);
void printing();
int countproduct();
int countcart();
void mart();

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
    printf("\t\t\t\t\tWELCOME TO MAAD MART\n\n\t\t\t\tSelect the respective option:\n\t\t\tRequest Report Generator\t\t0\n\t\t\tProceed To Counter\t\t\t1\n\t\t\tInput: ");
    scanf(" %d", &num);
    switch (num)
    {
    case 0:
        // Temporary work
            printf("\t\t\t\tReport Generated `\\(O w O)/`\n");
            sleep(1);
            reportGenerationLoadingScreen();
            return 1;
            // reportGeneration();    to be create
        break;
    case 1:
        // Temporary work
            printf("\t\t\t\t\tOk `\\(^ o ^)/`\n");
            sleep(1);
            Accounts();
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
void reportGenerationLoadingScreen()
{
    int counter = 0;
    for (int i = 0; i < 101; i++)
    {
        if (i % 5 == 0)
        {
            counter += 2;
        }
        system("cls");
        printf("\n\n\n\n\t\t\t   GENERATING REPORT `\\(^ o ^)/`\n\n\t\t\t");
        for (int j = 0; j < counter; j += 10)
        {
            printf("_______");
        }
        printf("\n\n\t\t\t\t\t%d %c\n\n\n", i, 37);
        if (i == 5 || i == 17 || i == 87)
        {
            sleep(1);
        }
        else if (i == 99)
        {
            sleep(2);
        }
        else
        {
            usleep(20000);
        }
    }


	system("cls");
	struct pro
    {
        char name[20];
        float profit;
    };
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


	fflush(stdin);
	printf("Press any key to go forward...\n");
	getchar();
}
void Accounts (void)
{
    unsigned long int Inputed_Number, Customer_Number;
    int a_check, b_check, c_check, a = 0, x, cont = 1;
    char name[30];
    do
    {
        system("cls");
        printf("\t\t\t\tDo you have the membership card of our store ?\n\t\t\t\t\tYES\t\t1\n\t\t\t\t\tNo\t\t2\n\t\t\tInput: ");
        scanf(" %d", &a_check);
    } while (a_check != 1 && a_check != 2);

    FILE *fileptr;
    if (a_check == 1)
    {
        fileptr = fopen("Customer Info.txt", "r");
        if (fileptr == NULL)
        {
            printf("\t\t\t\tCould not open the file. (! . !)\n");
            exit(1);
        }
        // cont means continue
        while (cont)
        {

            rewind(fileptr);
            fscanf(fileptr, " %d", &id);
            int x = 0;
            printf("\t\t\t\tEnter Customer's mobile number:\n\t\t\t\t");
            scanf(" %lu", &Inputed_Number);
            while (fscanf(fileptr, "%d %s %lu", &id, name, &Customer_Number) != EOF)
            {
                if (Customer_Number == Inputed_Number)
                {
                    printf("\n\t\t\t\tCustomer Id\tName\t\tMobile Number\n");
                    printf("\t\t\t\t%d\t\t%s\t%lu\n", id, name, Customer_Number);
                    x = 1;
                    fflush(stdin);
                    printf("\t\t\t\t\tPress any key to continue.....");
                    getchar();
                    fclose(fileptr);
                    break;
                }
            }
            if (x == 1)
            {
                printf("\n\t\t\t\t     Welcome Back %s `\\(^o^)/`!\n", name);
                cont = 0;
            }
            else
            {
                printf("\t\t\t\t\tNO DATA FOUND(o_O)\n\n");
                printf("\t\t\tIf You Want To Input Agian\t\t1\n");
                printf("\t\t\tContinue Without Membership\t\t2\n\t\t\t\tInput: ");
                scanf(" %d", &b_check);
                if (b_check == 1 || b_check < 1)
                {
                    // system("cls");
                    RepeatOnInvalid1();
                    cont = 1;
                }
                else if (b_check == 2)
                {
                    id = 0;
                    cont = 0;
                }
                else
                {
                    RepeatOnInvalid1();
                }
            }
        }

        fclose(fileptr);
    }
    else if (a_check == 2)
    {
        do
        {
            printf("\t\t\t\tDo you want to become our member?\n\t\t\t\t\tYES\t\t1\n\t\t\t\t\tNo\t\t2\n\t\t\tInput: ");
            scanf(" %d", &c_check);
        } while (c_check != 1 && c_check != 2);

        if (c_check == 1)
        {
            char name2[30];
            x = 0;
            printf("\t\t\tEnter Customer's Name: ");
            fflush(stdin);
            gets(name);
            printf("\t\t\tEnter Customer's Phone number: ");
            scanf(" %lu", &Inputed_Number);
            fileptr = fopen("Customer Info.txt", "r+");
            fscanf(fileptr, " %d", &id);
            while (fscanf(fileptr, "%d %s %lu", &id, name2, &Customer_Number) != EOF)
            {
                if (Customer_Number == Inputed_Number)
                {
                    printf("\n\t\t\t\tThis Number already exists in our Data Base.\n");
                    printf("\n\t\t\t\tCustomer Id\tName\t\tMobile Number\n\t\t\t\t%d\t\t%s\t\t%lu\n", id, name2, Customer_Number);
                    x = 1;
                    fflush(stdin);
                    printf("\t\t\t\t\tPress any key to continue.....");
                    getchar();
                    break;
                }
            }
            if (x == 0)
            {
                rewind(fileptr);
                fscanf(fileptr, " %d", &id);
                fseek(fileptr, 0, SEEK_SET);
                fprintf(fileptr, "%d", ++id);
                fseek(fileptr, 0, SEEK_END);
                fprintf(fileptr, "\n%d %s %lu", id, name, Inputed_Number);
            }
            fclose(fileptr);    
        }
        else if (c_check == 2)
        {
            id = 0;
        }
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
    // printf("\nUSER ID: %d\n", id);

    // // Printing Products
    // printf("\t\t\tPRODUCTS\t\t\t\t\tCART\nCODES\tPRODUCT NAMES\tQUANTITY\tPRICES   |   CODES\tPRODUCT NAMES\tQUANTITY\tPRICES\n");
    // for (int i = 0; i < 6; i++)
    // {
        // printf("%i\t%s\t\t%i\t\t%i\t |", product[i].code, product[i].name, product[i].quantity, product[i].price);
    //     // if (cart_len > i)
    //     // {
            // printf("   %i\t\t%s\t\t%i\t\t%i\n", cart_code[i], cart_name[i], cart_quantity[i], cart_prices[i]);
    //     // }
    // //     else
    // //     {
    //         printf("\n");
    // //     }
    // }
	mart();
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
void RepeatOnInvalid1(void)
{
    system("cls");
    printf("\t\t\t\tDo you have the membership card of our store ?\n\t\t\t\t\tYES\t\t1\n\t\t\t\t\tNo\t\t2\n\t\t\tInput: ");
    printf("Input : 1\n");
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
    int c = 0;
    while (cart[c].code > 0)
    {
        c++;
    }
    return c;
}

void mart()
{
	int userCode, userQuantity, quantity = 6, checkCode = 0, cont, i, j;
    while (1)
    {
        system("cls");
  		printf("\t\t\tPRODUCTS\t\t\t\t\tCART\nCODES\tPRODUCT NAMES\tQUANTITY\tPRICES   |   CODES\tPRODUCT NAMES\tQUANTITY\tPRICES\n");

        for (i = 0; i < quantity; i++)
        {
        	printf("%i\t%s\t\t%i\t\t%i\t |", product[i].code, product[i].name, product[i].quantity, product[i].price);
			if(cart[i].quantity != 0)
            	printf("   %i\t\t%s\t\t%i\t\t%i", cart[i].code, cart[i].name, cart[i].quantity, cart[i].price);
			printf("\n");
        }
        // for (i = 0; i < countcart(); i++)
        // {
        // }
        printf("\nInput: ");
        scanf(" %d", &userCode);

        if (userCode == 99)
        {
            printf("SPECIAL TOOLS OPEN\n");
            fflush(stdin);
            getchar();
        }
        else if (userCode == 0)
        {
            printf("CHECK OUT\n");
            fflush(stdin);
            getchar();
            FILE *fileptr;
            fileptr = fopen("Products Data.txt", "w");
            if (fileptr == NULL)
            {
                printf("\t\t\t\tCould not open the file. (! . !)\n");
                exit(1);
            }

            for (i= 0; i < countproduct(); i++)
            {
                // printf("%d\t", i);
                fprintf(fileptr, "%d %s %d %d\n", product[i].code, product[i].name, product[i].quantity, product[i].price);
            }
            for (i= 0; i < countproduct(); i++)
            {
                // strcpy(cart[i].name, "");
                strcpy(cart[i].name, "");
                cart[i].code = NULL;
                // cart[i].name = '\0';
                cart[i].quantity = NULL;
                cart[i].price = NULL;

            }

            fclose(fileptr);
            // exit(1);
        }
        else
        {

            for (i = 0; i < quantity; i++)
            {
                if (userCode == product[i].code)
                {
                    checkCode = 1;
                    do
                    {
                        cont = 0;
                        printf("Input the quantity: ");
                        scanf(" %d", &userQuantity);
                        if(userQuantity < 0)
                        {
                            cont = 1;
                            printf("Invalid Input\n");
                        }
                        else if(product[i].quantity == 0)
                        {
                            printf("%s is currently unavailable\n",product[i].name);
                            sleep(2);
                        }

                    } while (cont);
                    
                    if(product[i].quantity != 0)
                    {
                        int present = -1;
                        for (j = 0; j < quantity; j++)
                        {
                            if (product[i].code == cart[j].code)
                            {
                                printf("x");
                                present = j;
                                break;
                            }
                        }
                        if (present > -1)
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
    // return 0;
}