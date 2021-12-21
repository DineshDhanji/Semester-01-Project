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
};
struct user
{
    int code;
    char name[30];
} customer;

// FUNCTIONS
int greeting();
void reportGenerationLoadingScreen();
int Accounts(void);
int update(void);
void RepeatOnInvalid1(void);
int printing();
int countproduct();
int countcart(struct items *);

// MAIN
int main(int argc, char const *argv[])
{
//    // To clean previous lines.
//    system("cls");
//    struct items *product, *cart;
//    FILE *ptr;
//    ptr = fopen("Products.txt", "r+");
//    if (ptr == NULL)
//    {
//        printf("ERROR\n");
//        exit(1);
//    }
//
//    // productQuantity = Qunatity of products in Products.txt
//    int productQuantity;
//    fscanf(ptr, "%d", &productQuantity);
//    product = (struct items *)calloc(productQuantity, sizeof(struct items));
//    cart = (struct items *)calloc(productQuantity, sizeof(struct items));

    int DidYouGreet = 0, IsCustomerAvailable = 0;
//    while (1)
//    {
//        if (DidYouGreet == 0)
//        {
//            DidYouGreet = greeting();
//        }
//        if (DidYouGreet == 1)
//        {
//            if (IsCustomerAvailable == 0)
//            {
                IsCustomerAvailable = Accounts();
//            }
//            else
//            {
//                system("cls");
//                IsCustomerAvailable = printing(ptr, product, cart, productQuantity);
//            }
//
//            // Opening Products.txt file for updating data.
            // Temporary work to stop screen
            // printf("\n");
            // fflush(stdin);
            // getchar();
//        }
//    }
    return 0;
}
int greeting()
{
    int num;
    printf("\t\t\t\t\tWELCOME TO MAAD MART\n\n\t\t\t\tSelect the respective option:\n\t\t\tLogin as Admin\t\t\t0\n\t\t\tLogin as Employ\t\t\t1\n\t\t\tInput: ");
    scanf(" %d", &num);
    switch (num)
    {
    case 0:
        // Temporary work
        printf("\t\t\t\tLOGIN AS ADMIN `\\(O w O)/`\n");
        sleep(1);
        reportGenerationLoadingScreen();
        return 1;
        break;
    case 1:
        // Temporary work
        printf("\t\t\t\t\tLOGIN AS EMPLOY`\\(^ o ^)/`\n");
        sleep(1);
        Accounts();
        system("cls");
        return 1;
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
    fileptr = fopen("Products Data.txt", "r");
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
        // int SaleInAmount = ClosingStock[i].price * (OpeningStock[i] - ClosingStock[i].quantity);
        int SaleInAmount = ClosingStock[i].price * (ClosingStock[i].quantity - OpeningStock[i]);
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

        // int SaleInAmount = ClosingStock[i].price * (OpeningStock[i] - ClosingStock[i].quantity);
        int SaleInAmount = ClosingStock[i].price * (ClosingStock[i].quantity - OpeningStock[i]);
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
int Accounts(void)
{
    system("cls");
    unsigned long int Inputed_Number, Customer_Number;
    int a_check, b_check, c_check, a = 0, x, cont = 1, update_info, z = 0;
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
            fscanf(fileptr, " %d", &customer.code);
            int x = 0;
            printf("\t\t\t\tEnter Customer's mobile number:\n\t\t\t\t");
            scanf(" %lu", &Inputed_Number);
            while (fscanf(fileptr, "%d %s %lu", &customer.code, customer.name, &Customer_Number) != EOF)
            {
                if (Customer_Number == Inputed_Number)
                {
                    printf("\n\t\t\t\tCustomer Id\tName\t\tMobile Number\n");
                    printf("\t\t\t\t%d\t\t%s\t%lu\n", customer.code, customer.name, Customer_Number);
                    printf("Does customer want to update his information?\n\t\t\t\t\tYES\t\t1\n\t\t\t\t\tNo\t\t2\n\t\t\tInput: ");
                    scanf(" %d", &update_info);
                    if (update_info == 1)
                    {
                    	if (z == 0)
						{
							update();
						}
					}
                    x = 1;
                    fclose(fileptr);
                    break;
                }
            }
            if (x == 1)
            {
                printf("\n\t\t\t\t     Welcome Back %s `\\(^o^)/`!\n", customer.name);
                fflush(stdin);
                printf("\t\t\t\t\tPress any key to continue.....");
                getchar();
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
                    customer.code = 0;
                    strcpy(customer.name, "Unknown");
                    cont = 0;
                }
                else
                {
                    RepeatOnInvalid1();
                }
            }
        }
        fclose(fileptr);
        return 1;
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
            gets(name2);
            printf("\t\t\tEnter Customer's Phone number: ");
            scanf(" %lu", &Inputed_Number);
            fileptr = fopen("Customer Info.txt", "r+");
            fscanf(fileptr, " %d", &customer.code);
            while (fscanf(fileptr, "%d %s %lu", &customer.code, customer.name, &Customer_Number) != EOF)
            {
                if (Customer_Number == Inputed_Number)
                {
                    printf("\n\t\t\t\tThis Number already exists in our Data Base.\n");
                    printf("\n\t\t\t\tCustomer Id\tName\t\tMobile Number\n\t\t\t\t%d\t\t%s\t\t%lu\n", customer.code, customer.name, Customer_Number);
                    x = 1;
                    fflush(stdin);
                    printf("\t\t\t\t\tPress any key to continue.....");
                    getchar();
                    return 1;
                    break;
                }
            }
            if (x == 0)
            {
                rewind(fileptr);
                fscanf(fileptr, " %d", &customer.code);
                fseek(fileptr, 0, SEEK_SET);
                fprintf(fileptr, "%d", ++customer.code);
                fseek(fileptr, 0, SEEK_END);
                fprintf(fileptr, "\n%d %s %lu", customer.code, name2, Inputed_Number);
//                 return 1;
            }
            fclose(fileptr);
        }
        else if (c_check == 2)
        {
            customer.code = 0;
            strcpy(customer.name, "Unknown");
        }
        return 1;
    }
}

int update(void)
{
	system("cls");
//    printf("HHHHHHHHHHH");
	unsigned long int temp_Customer_Number, Customer_Number, New_Number;
    int temp_customer_code = customer.code, b, a = 12345, x, cont = 1;
    FILE *fileptr1, *fileptr2;
    fileptr1 = fopen("Customer Info.txt", "r");
    fileptr2 = fopen("Customer Info.txt", "r+");
    if (fileptr1 == NULL && fileptr2 == NULL)
    {
    	printf("\t\t\t\tCould not open the file. (! . !)\n");
        exit(1);
    }
    else
    {
	    printf("Enter new mobile number to update\n");
	    scanf(" %lu", &New_Number);
	    printf("NEw no is : %lu\n", New_Number);
		fseek(fileptr1, 0, SEEK_SET);
		fscanf(fileptr1, " %d", &temp_customer_code);
			printf("Temp customer code is : %d\n", temp_customer_code);
			b = ftell(fileptr1);
			printf(" %d\n", b);
			fprintf(fileptr2, "%d", temp_customer_code);
			fseek(fileptr1, b, SEEK_SET);
			while(fscanf(fileptr1, "%d %s %lu", &customer.code, customer.name, &Customer_Number) != EOF)
			{
				b = ftell(fileptr1);
				printf(" %d\n", b);
				if (temp_customer_code == customer.code)
				{
					b = ftell(fileptr1);
					printf(" %d\n", b);
					fseek(fileptr1, b+4, SEEK_SET);
					b = ftell(fileptr1);
					printf(" %d\n", b);
					fprintf(fileptr2, "%d", New_Number);
				}
				fprintf(fileptr2, "\n%d %s %lu", customer.code, customer.name, Customer_Number);
			}
//			fprintf(fileptr2, "\n%d %s %d %d", &customer.code, customer.name, &Customer_Number);
		
//		fseek(fileptr1, b+4, SEEK_SET);
//		
//		b = ftell(fileptr1);
//		printf(" %d\n", b);
			fclose(fileptr2);
			fclose(fileptr1);
		}
//    if (temp_customer_code == customer.code)
//    {
//    	
//	}
    return 1;
}

int printing(FILE *ptr, struct items *product, struct items *cart, int productQuantity)
{
    int userCode;
    // Accessing new data.
    int i = 0;
    while (fscanf(ptr, "%d %s %d %d", &product[i].code, product[i].name, &product[i].quantity, &product[i].price) != EOF)
    {
        i++;
    }
    printf("\n");
    printf("\t\t\t\t\tWELCOME TO MAAD MART\n");
    for (int i = 0; i < 15; i++)
    {
        printf("--------");
    }
    printf("\nCustomer's ID: %d\n", customer.code);

    printf("\t\t\tPRODUCTS\t\t\t\t\tCART\nCODES\tPRODUCT NAMES\tQUANTITY\tPRICES   |   CODES\tPRODUCT NAMES\tQUANTITY\tPRICES\n");
    for (int i = 0; i < productQuantity; i++)
    {
        printf("%i\t%s\t\t%i\t\t%i\t |", product[i].code, product[i].name, product[i].quantity, product[i].price);
        if (cart[i].quantity != 0)
        {
            printf("   %i\t%s\t\t%i\t\t%i", cart[i].code, cart[i].name, cart[i].quantity, cart[i].price);
        }
        printf("\n");
    }
    printf("\nInput: ");
    scanf(" %d", &userCode);

    if (userCode == 99)
    {
        printf("SPECIAL TOOLS OPEN\n");
        fflush(stdin);
        getchar();
        return 1;
    }
    else if (userCode == 0)
    {
        // int choice;
        // printf("Are You Sure You Want To Check Out ?\nYES\t1\nNO\t2");
        // fflush(stdin);
        // scanf(" %d", &choice);
        printf("CHECKED OUT\nPress any key to continue ...");
        fflush(stdin);
        getchar();

        // NEW WORK
        FILE *fileptr, *temp;
        fileptr = fopen("Customer Data.txt", "r+");
        temp = fopen("Customer Data.txt", "r+");
        if (fileptr == NULL || temp == NULL)
        {
            printf("\t\t\t\tCould not open the file. (! . !)\n");
            exit(1);
        }

        int Customer_Number, found = 0;
        char name[30];
        char check[2];
        char c;
        while (fscanf(temp, "%s", check) != EOF)
        {
            if (strcmp(check, "ID") == 0)
            {
                fscanf(temp, "%d %s", &Customer_Number, name);
                if (Customer_Number == customer.code)
                {
                    found = 1;
                    printf("%d", ftell(temp));
                    fseek(fileptr, ftell(temp), SEEK_CUR);
                    float total = 0;
                    for (int i = 0; i < countcart(cart); i++)
                    {
                        fprintf(fileptr, "\n%d\t", cart[i].code);
                        if (strlen(cart[i].name) <= 3)
                        {
                            fprintf(fileptr, "%s  \t%d\tRs %d\tRs %d", cart[i].name, cart[i].quantity, cart[i].price, cart[i].quantity * cart[i].price);
                        }
                        else
                        {
                            fprintf(fileptr, "%s\t%d\tRs %d\tRs %d", cart[i].name, cart[i].quantity, cart[i].price, cart[i].quantity * cart[i].price);
                        }
                        total += cart[i].quantity * cart[i].price;
                    }
                    fprintf(fileptr, "\nTOTAL:\t\t\t\t\tRs %.2f\n", total);
                    for (int i = 0; i < 10; i++)
                    {
                        fprintf(fileptr, "...");
                    }
                    while ((c = fgetc(temp)) != EOF)
                    {
                        fprintf(fileptr, "%c", c);
                    }
                    break;
                }
            }
        }
        if (found == 0)
        {
            fseek(fileptr, 0, SEEK_END);
            fprintf(fileptr, "\nID\t%d\t%s", customer.code, customer.name);
            float total = 0;
            for (int i = 0; i < countcart(cart); i++)
            {
                fprintf(fileptr, "\n%d\t", cart[i].code);
                if (strlen(cart[i].name) <= 3)
                {
                    fprintf(fileptr, "%s  \t%d\tRs %d\tRs %d", cart[i].name, cart[i].quantity, cart[i].price, cart[i].quantity * cart[i].price);
                }
                else
                {
                    fprintf(fileptr, "%s\t%d\tRs %d\tRs %d", cart[i].name, cart[i].quantity, cart[i].price, cart[i].quantity * cart[i].price);
                }

                total += cart[i].quantity * cart[i].price;
            }
            fprintf(fileptr, "\nTOTAL:\t\t\t\t\tRs %.2f\n", total);
            for (int i = 0; i < 10; i++)
            {
                fprintf(fileptr, "___");
            }
        }

        fclose(fileptr);
        fclose(temp);

        // Cleaning Cart for next iteration
        for (i = 0; i < productQuantity; i++)
        {
            strcpy(cart[i].name, "");
            cart[i].code = NULL;
            cart[i].quantity = NULL;
            cart[i].price = NULL;
        }
        FILE *ptr2;
        ptr2 = fopen("Products.txt", "w");
        fprintf(ptr2, "%d\n", productQuantity);
        for (int i = 0; i < productQuantity; i++)
        {
            fprintf(ptr2, "%d %s %d %d\n", product[i].code, product[i].name, product[i].quantity, product[i].price);
        }
        fclose(ptr2);
        return 0;
    }
    else
    {
        // checkCode = Flag if we are able to find the given code in our products list then "1" else "0"
        int checkCode = 0, cont, userQuantity;
        for (i = 0; i < productQuantity; i++)
        {
            if (userCode == product[i].code)
            {
                checkCode = 1;
                if (product[i].quantity != 0)
                {
                    do
                    {
                        cont = 0;
                        printf("Input the quantity: ");
                        scanf(" %d", &userQuantity);
                        if (userQuantity < 0 || userQuantity > product[i].quantity)
                        {
                            cont = 1;
                            printf("Invalid Input\n");
                            sleep(1);
                        }

                    } while (cont);

                    int present = -1;
                    for (int j = 0; j < productQuantity; j++)
                    {
                        if (product[i].code == cart[j].code)
                        {

                            present = j;
                            break;
                        }
                    }
                    if (present > -1)
                    {
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
                else
                {
                    printf("%s Is Currently Out Of Stock\n", product[i].name);
                    sleep(2);
                }
                break;
            }
        }
        if (checkCode == 0)
        {
            printf("Given code is invalid (o_O)\n");
            fflush(stdin);
            printf("Press any key to continue ... ");
            getchar();
        }
        return 1;
    }
}
void RepeatOnInvalid1(void)
{
    system("cls");
    printf("\t\t\t\tDo you have the membership card of our store ?\n\t\t\t\t\tYES\t\t1\n\t\t\t\t\tNo\t\t2\n\t\t\tInput: ");
    printf("Input : 1\n");
}
int countcart(struct items *cart)
{
    int c = 0;
    while (cart[c].code > 0)
    {
        c++;
    }
    return c;
}