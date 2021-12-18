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
}
data[10];

int countproduct();
int countcart();
int countemploye();

void loginPortal();
void adminPortal();
void adminMenu();

void addProduct(); 
void deleteProduct();

void addEmploye();
void remEmploye();


int main(int argc, char const *argv[])
{
	loginPortal();
	return 0;
}
void loginPortal()
{
	int choice;
	system("cls");
	printf("\t\t\t\t\tWELCOME TO MAAD MART\n\n");
	printf("\t\t\tSelect the respective option\n");
	printf("\t\t\tLogin as admin\t\t\t1\n");
    printf("\t\t\tLogin as employee\t\t2\n");
	printf("Input: ");
    do
	{
		fflush(stdin);
		scanf("%d", &choice);
	}while(choice != 1 && choice != 2);
	switch(choice)
	{
		case 1:
		{
			adminPortal();
			break;
		}

	}
}

void adminPortal()
{
	system("cls");
	int choice = 0;
	char masterID[20] = "panther";
	char adminID [20];
	int masterPassword = 10651;
	int adminPassword;
	fflush(stdin);
	printf("Enter username or ID: ");
	gets(adminID);
	do
	{
		printf("Enter password: ");
		scanf("%i",&adminPassword);
	}while(adminPassword < 0 || adminPassword > 99999999);
	system("cls");
	if((strcmp(adminID,masterID) == 0) && masterPassword == adminPassword)
	{
		adminMenu();
	}
	
	else
	{
		if(strcmp(adminID,masterID) != 0 && masterPassword != adminPassword)
			printf("Wrong entry\n");
		else if(strcmp(adminID,masterID) != 0)
			printf("Wrong username\n");
		else if(masterPassword != adminPassword)
			printf("Wrong password");
		printf("\t\t\tSelect the respective option\n");
		printf("\t\tGo Back\t\t\t\t1\n\t\tRe-Enter\t\t\t2\n");
		choice = 0;
		do
		{
			printf("Input: ");
			scanf("%i",&choice);
		}while(choice != 1 && choice != 2);
		if(choice == 1)
		{
			loginPortal();
		}
		if(choice == 2)
		{
			adminPortal();
		}
	}
	
}
void adminMenu()
{
	int choice;
	system("cls");
	printf("\t\t\tSelect the respective option\n");
	printf("\t\tAdd a product\t\t\t1\n\t\tDelete a product\t\t2\n\t\tAdd a employee\t\t\t3\n\t\tRemove a employee\t\t4\n\t\tGo back\t\t\t\t5\n");
	printf("\t\tInput: ");
	do
	{
		fflush(stdin);
		scanf("%i",&choice);
	}while(choice < 1 || choice > 5);
	switch(choice)
	{
		case 1:
		{
			addProduct();
			break;
		}
		case 2:
		{
			deleteProduct();
			break;
		}
		case 3:
		{
			addEmploye();
			break;
		}
		case 4:
		{
			remEmploye();
			break;
		}
		case 5:
		{
			system("cls");
			loginPortal();
			break;
		}
	}
}

void addProduct()
{
	FILE *ptr,*fp;
    ptr = fopen("Products Data.txt", "r");
    if (ptr == NULL)
    {
        printf("ERROR\n");
        exit(1);
    } 
    int code, quantity, price,i;
    char name[20];

    for (i = 0; fscanf(ptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF; i++)
    {
        product[i].code = code;
        strcpy(product[i].name, name);
        product[i].quantity = quantity;
        product[i].price = price;
    }
	fclose(ptr);
	int cur = countproduct(),curPrice=0,curQuan=0;
	char item[20];
	product[cur].code = (cur+1) + 100;
	fflush(stdin);
	printf("Enter the item you want to add to store: ");
	gets(product[cur].name);
	printf("Enter the price of %s: ",product[cur].name);
	scanf("%i",&curPrice);
	product[cur].price = curPrice;
	printf("Enter the quantiity which is available in the mart: ");
	scanf("%i",&curQuan);
	product[cur].quantity = curQuan;
	printf("DONE! Now customers can buy %s by %i as code",product[cur].name,product[cur].code);
	printf("Do you want to add more items to the store\n\t\tYes\t\t1\n\t\tNo\t\t0\nInput: ");
	int choice;
	do
	{
		scanf("%i",&choice);
	}while(choice != 1 && choice != 0);
	switch(choice)
	{
		case 1:
			addProduct();
			break;
		case 0: 
			fp = fopen("Products Data.txt","w+");
			for (i= 0; i < countproduct(); i++)
			{
				fprintf(ptr, "%d %s %d %d\n", product[i].code, product[i].name,product[i].quantity,product[i].price);
			}
			fclose(fp);
			adminMenu();
			break;

	}
}


void deleteProduct()
{
	int inCode,choice,i,choice2,flag = 0;
	FILE *ptr;
    ptr = fopen("Products Data.txt", "r");
    if (ptr == NULL)
    {
        printf("ERROR\n");
        exit(1);
    } 
    int code, quantity, price;
    char name[20];
    for ( i = 0; fscanf(ptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF; i++)
    {
        product[i].code = code;
        strcpy(product[i].name, name);
        product[i].quantity = quantity;
        product[i].price = price;
	}
	fclose(ptr);
	for( i = 0; i < countproduct(); i++)
	{
		printf("%i %s %i %i \n",product[i].code, product[i].name, product[i].quantity, product[i].price);
	}
	FILE *fp;
	fopen("Products Data.txt", "w");
	printf("Enter the product code you want to delete: ");
	fflush(stdin);
	do
	{
		scanf("%i",&inCode);
	}while(inCode < 0 || inCode > 99999);
	for( i = 0; i < countproduct(); i++)
	{
		if(product[i].code == inCode)
		{
			printf("\t\tAre you sure you want to remove %s\n\t\tPress 1 to Continue\n\t\tPress 2 to go back\n\t\tInput: ",product[i].name);
			do
			{
				scanf("%i",&choice);
			}while(choice != 1 && choice != 2);
			switch (choice)
			{
			case 1:
				product[i].code = NULL;
				strcpy(product[i].name , "");
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
					scanf("%i",&choice2);
				}while(choice2 != 1 && choice2 != 0);
				switch(choice2)
				{
					case 1:
						deleteProduct();
					break;
					case 0:
						for (i= 0; i < countproduct(); i++)
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

	if(flag == 0)
	{
		printf("Please enter the valid code!\n");
		sleep(1/2);
		deleteProduct();
		
	}
}
void addEmploye()
{
	int choice=0;
	int id,i;
	char emp[20];
	FILE *fp2;
	FILE *fp;
	fp = fopen("Employees.txt","r");
	for ( i = 0; fscanf(fp, "%d %s", &id, emp) != EOF; i++)
    {
        data[i].ID = id;
        strcpy(data[i].name, emp);
	}
	fclose(fp);
	int cur = countemploye();
	for(i = 0; i < countemploye();i++)
	{
		printf("%i %s\n",data[i].ID,data[i].name);
	}
	char name[20];
	fflush(stdin);
	printf("Enter the name of the new employee: ");
	gets(name);
	data[cur].ID = cur + 1 + 10000;
	strcpy(data[cur].name,name);
	printf("Done! Now %s can login with an ID as %i",data[cur].name,data[cur].ID);
	printf("\n\nDo you want to add more employee\n\t\tYes \t\t1\n\t\tNo\t\t0\nInput: ");
	do
	{
		scanf("%i",&choice);
	}while(choice != 1 && choice != 0);
	switch(choice)
	{
		case 1:
			addEmploye();
			break;
		case 0:
			fp2 = fopen("Employees.txt","w+");
			for (i= 0; i < countemploye(); i++)
			{
				fprintf(fp, "%d %s\n", data[i].ID, data[i].name);
			}
			fclose(fp2);
			adminMenu();
	}
}

void remEmploye()
{
	int inCode,i,j,choice,choice2;
	int id;
	int cur = countemploye();
	char emp[20];
	FILE *fp2;
	FILE *fp;
	fp = fopen("Employees.txt","r");
	for ( i = 0; fscanf(fp, "%d %s", &id, emp) != EOF; i++)
    {
        data[i].ID = id;
        strcpy(data[i].name, emp);
	}
	fclose(fp);
	printf("Enter the code of the employe you want to remove: ");
	scanf("%i",&inCode);

	for(i = 0; i < countemploye(); i++)
	{
		if(data[i].ID == inCode)
		{
			do
			{
				printf("\t\tDo you want to remove %s from the store?\n\t\tYes\t\t1\n\t\tNo\t\t0\nInput:",data[i].name);
				scanf("%i",&choice);
			}while(choice != 1 && choice != 0);
			if(choice == 1)
			{
				data[i].ID = NULL;
				strcpy(data[i].name,"");
				system("cls");
				fp2 = fopen("Employees.txt","w");
				for (j= 0; j < countemploye(); j++)
				{
					if(data[j].ID > 0)
						fprintf(fp, "%d %s\n", data[j].ID, data[j].name);
				}
				fclose(fp2);
				printf("Do you want to remove more employees?\n\t\tYes\t\t1\n\t\tNo\t\t0\nInput: ");
				do
				{
					fflush(stdin);
					scanf("%i",&choice2);
				}while(choice2 != 1 && choice2 != 0);
				switch(choice2)
				{
					case 1:
						remEmploye();
					break;
					case 0:
						adminMenu();

				}
				break;
			}
			if(choice == 0)
			{
				adminMenu();
				break;
			}
		}
	}
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

int countemploye()
{
	int c = 0;
	while(data[c].ID > 0)
	{
		c++;
	}
	return c;
}