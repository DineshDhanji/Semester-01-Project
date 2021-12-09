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

// GLOBAL VARIABLE
int id;
// FUNCTIONS
int greeting();
void Accounts (void);
void RepeatOnInvalid1(void)
{
    system("cls");
    printf("\t\t\t\tDo you have the membership card of our store ?\n\t\t\t\t\tYES\t\t1\n\t\t\t\t\tNo\t\t2\n\t\t\tInput: ");
    printf("Input : 1\n");
}

void printing();

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
            system("cls");
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
            return 1;
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
                    printf("\n\t\t\t\tCustomer Id\tName\t\tMobile Number\n\t\t\t\t%d\t\t%s\t%lu\n", id, name2, Customer_Number);
                    x = 1;
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
    printf("\nUSER ID: %d\n", id);

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
