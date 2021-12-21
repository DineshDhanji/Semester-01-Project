#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct items
{
	int code;
	char name[30];
	int quantity;
	int price;
} product[10],
	cart[10];
struct employe
{
	int ID;
	char name[30];
} data[10];

int countproduct();
int countcart();
int countemploye();

void loginPortal();
void adminPortal();
void adminMenu();

int addProduct();
void deleteProduct();

int addEmploye();
void remEmploye();

int main(int argc, char const *argv[])
{
	loginPortal();
	return 0;
}
void loginPortal()
{
	// int choice;
	// do
	// {
	// 	system("cls");
	// 	printf("\t\t\t\t\tWELCOME TO MAAD MART\n\t\t\t\t\t    LOGIN PROTAL\n\n");
	// 	printf("\t\t\t\tSelect the respective option:\n");
	// 	printf("\t\t\t\tLogin as Admin\t\t\t1\n");
	// 	printf("\t\t\t\tLogin as Employee\t\t2\n\n");
	// 	printf("\t\t\t\t\tInput: ");
	// 	fflush(stdin);
	// 	scanf(" %d", &choice);
	// 	if (choice != 1 && choice != 2)
	// 	{
	// 		printf("\t\t\t\t     INVALID INPUT (O-o)\n");
	// 		sleep(1);
	// 	}

	// } while (choice != 1 && choice != 2);

	// switch (choice)
	// {
	// case 1:
	// {
	adminPortal();
	// 	break;
	// }
	// case 2:
	// {
	// 	printf("\t\t\t\t     EMPLOYEE PORTAL\n");
	// 	sleep(1);
	// 	break;
	// }
	// }
}

void adminPortal()
{
	// int choice = 0;
	// char masterID[20] = "panther";
	// char adminID[20];
	// int masterPassword = 10651;
	// int adminPassword;
	// do
	// {
	// 	system("cls");
	// 	fflush(stdin);
	// 	printf("\t\t\t\t\t    LOGIN PROTAL\n\n\t\t\tEnter username or ID: ");
	// 	gets(adminID);
	// 	printf("\t\t\tEnter password: ");
	// 	scanf(" %d", &adminPassword);
	// 	fflush(stdin);
	// 	choice = 0;
	// 	if (strcmp(adminID, masterID) != 0 || masterPassword != adminPassword)
	// 	{
	// 		printf("\n\n\t\t\t\t\tINVALID CREDENTIAL\n");
	// 		if (strcmp(adminID, masterID) != 0)
	// 		{
	// 			printf("\n\n\t\t\t\t\tWRONG USERNAME\n");
	// 		}
	// 		else if (masterPassword != adminPassword)
	// 		{
	// 			printf("\n\n\t\t\t\t\tWRONG PASSWORD\n");
	// 		}
	// 		printf("\t\t\t\tSelect the respective option:\n");
	// 		printf("\t\t\t\tGo Back\t\t\t\t1\n\t\t\t\tRe-Enter\t\t\t2\n");
	// 		do
	// 		{
	// 			printf("\t\t\t\tInput: ");
	// 			scanf(" %d", &choice);
	// 			fflush(stdin);
	// 		} while (choice != 1 && choice != 2);
	// 	}
	// 	else
	// 	{
	adminMenu();
	// 	}

	// } while (choice == 2);
}
void adminMenu()
{
	int choice = 1;

	while (choice)
	{
		// do
		// {
		system("cls");
		printf("\t\t\t\t\t    ADMIN PROTAL\n\t\t\t\tSelect the respective option\n");
		printf("\t\t\t\tAdd A Product\t\t\t1\n\t\t\t\tDelete A Product\t\t2\n\t\t\t\tAdd An Employee\t\t\t3\n\t\t\t\tRemove AN Employee\t\t4\n\t\t\t\tLOG OUT\t\t\t\t5\n");
		printf("\t\t\t\tInput: ");
		fflush(stdin);
		scanf(" %d", &choice);
		// } while (choice < 1 || choice > 5);
		switch (choice)
		{
		case 1:
		{
			choice = addProduct();
			break;
		}
		case 2:
		{
			// deleteProduct();
			break;
		}
		case 3:
		{
			addEmploye();
			break;
		}
		case 4:
		{
			// remEmploye();
			break;
		}
		case 5:
		{
			printf("\t\t\t\t      LOGING OUT ... `\\(^ o ^)/`\n");
			sleep(1);
			break;
		}
		default:
		{
			printf("\n\n\t\t\t\t\tINVALID INPUT @ . @\n");
			sleep(1);
		}
		}
	}
}

int addProduct()
{
	system("cls");
	int num;
	FILE *ptr1, *ptr2, *ptr02;
	ptr1 = fopen("Products Data.txt", "a+");
	ptr2 = fopen("Products.txt", "r");
	ptr02 = fopen("Products.txt", "r+");
	if (ptr1 == NULL && ptr2 == NULL && ptr02 == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	int code, quantity, price, code_B, quantity_B, price_B;
	char name[20], name_B[20];

	fflush(stdin);
	printf("Enter the name of item you want to add to store: ");
	gets(name_B);
	if (strlen(name_B) == 0)
	{
		printf("INVALID NAME (* - *)\n");
		fclose(ptr1);
		fclose(ptr2);
		fclose(ptr02);
		sleep(1);
		return 1;
	}
	printf("Enter the price of \"%s\": ", name_B);
	scanf(" %d", &price_B);
	printf("Enter the quantiity which is available in the mart: ");
	scanf("%i", &quantity_B);

	fscanf(ptr2, "%d", &num);
	num++;
	fseek(ptr02, 0, SEEK_SET);
	fprintf(ptr02, "%d", num);

	while (fscanf(ptr2, "%d %s %d %d", &code, name, &quantity, &price) != EOF)
	{
		fprintf(ptr02, "\n%d %s %d %d", code, name, quantity, price);
	}
	code++;
	fprintf(ptr1, "\n%d %s %d %d", code, name_B, quantity_B, price_B);
	fseek(ptr02, 0, SEEK_END);
	fprintf(ptr02, "\n%d %s %d %d", code, name_B, quantity_B, price_B);
	printf("DONE! Now customers can buy %s by %i as code", name_B, code);
	sleep(1);
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr02);

	return 1;


}

void deleteProduct()
{
	int inCode, choice, i, choice2, flag = 0;
	FILE *ptr;
	ptr = fopen("Products Data.txt", "r");
	if (ptr == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	int code, quantity, price;
	char name[20];
	for (i = 0; fscanf(ptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF; i++)
	{
		product[i].code = code;
		strcpy(product[i].name, name);
		product[i].quantity = quantity;
		product[i].price = price;
	}
	fclose(ptr);
	for (i = 0; i < countproduct(); i++)
	{
		printf("%i %s %i %i \n", product[i].code, product[i].name, product[i].quantity, product[i].price);
	}
	FILE *fp;
	fopen("Products Data.txt", "w");
	printf("Enter the product code you want to delete: ");
	fflush(stdin);
	do
	{
		scanf("%i", &inCode);
	} while (inCode < 0 || inCode > 99999);
	for (i = 0; i < countproduct(); i++)
	{
		if (product[i].code == inCode)
		{
			printf("\t\tAre you sure you want to remove %s\n\t\tPress 1 to Continue\n\t\tPress 2 to go back\n\t\tInput: ", product[i].name);
			do
			{
				scanf("%i", &choice);
			} while (choice != 1 && choice != 2);
			switch (choice)
			{
			case 1:
				product[i].code = NULL;
				strcpy(product[i].name, "");
				product[i].quantity = NULL;
				product[i].price = NULL;
				if (fp == NULL)
				{
					printf("\t\t\t\tCould not open the file. (! . !)\n");
					exit(1);
				}
				printf("Do you want to remove mre items?\n\t\tYes\t\t1\n\t\tNo\t\t0\nInput: ");
				do
				{
					scanf("%i", &choice2);
				} while (choice2 != 1 && choice2 != 0);
				switch (choice2)
				{
				case 1:
					deleteProduct();
					break;
				case 0:
					for (i = 0; i < countproduct(); i++)
					{
						// printf("%d\t", i);
						fprintf(fp, "%d %s %d %d\n", product[i].code, product[i].name, product[i].quantity, product[i].price);
					}
					adminMenu();
					break;
				}
				break;
			case 2:
				deleteProduct();
				break;
			}
			flag = 1;
		}
	}

	if (flag == 0)
	{
		printf("Please enter the valid code!\n");
		sleep(1 / 2);
		deleteProduct();
	}
}
int addEmploye()
{
	system("cls");
	int num;
	FILE *f1;
	f1 = fopen("Employees Data.txt","a+");

	if (f1 == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
    
	int code, i;
	char emp[20],name[20];
	fflush(stdin);
	printf("Enter the name of person you want to hire : ");
	gets(emp);
	if(strlen(emp) == 0)
	{
		printf("INVALID NAME (* - *)\n");
		fclose(f1);

		sleep(1);
		return 1;
	}

	while (fscanf(f1, "%d %s", &code, name) != EOF)
	{
		;
	}
	code++;
	// printf("%d",code);c
	fprintf(f1,"\n%d %s",code,emp);

	printf("DONE! Now %s can login with %d as their ID\n",emp,code);
	sleep(2);
	fclose(f1);


	return 1;


}

void remEmploye()
{
	int inCode, i, j, choice, choice2;
	int id;
	int cur = countemploye();
	char emp[20];
	FILE *fp2;
	FILE *fp;
	fp = fopen("Employees.txt", "r");
	for (i = 0; fscanf(fp, "%d %s", &id, emp) != EOF; i++)
	{
		data[i].ID = id;
		strcpy(data[i].name, emp);
	}
	fclose(fp);
	printf("Enter the code of the employe you want to remove: ");
	scanf("%i", &inCode);

	for (i = 0; i < countemploye(); i++)
	{
		if (data[i].ID == inCode)
		{
			do
			{
				printf("\t\tDo you want to remove %s from the store?\n\t\tYes\t\t1\n\t\tNo\t\t0\nInput:", data[i].name);
				scanf("%i", &choice);
			} while (choice != 1 && choice != 0);
			if (choice == 1)
			{
				data[i].ID = NULL;
				strcpy(data[i].name, "");
				system("cls");
				fp2 = fopen("Employees.txt", "w");
				for (j = 0; j < countemploye(); j++)
				{
					if (data[j].ID > 0)
						fprintf(fp, "%d %s\n", data[j].ID, data[j].name);
				}
				fclose(fp2);
				printf("Do you want to remove more employees?\n\t\tYes\t\t1\n\t\tNo\t\t0\nInput: ");
				do
				{
					fflush(stdin);
					scanf("%i", &choice2);
				} while (choice2 != 1 && choice2 != 0);
				switch (choice2)
				{
				case 1:
					remEmploye();
					break;
				case 0:
					adminMenu();
				}
				break;
			}
			if (choice == 0)
			{
				adminMenu();
				break;
			}
		}
	}
}

int countproduct()
{
	int c = 0;
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

int countemploye()
{
	int c = 0;
	while (data[c].ID > 0)
	{
		c++;
	}
	return c;
}