#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    unsigned long int cNo;
    int a_check, b_check, c_check, a = 0, id;
    char name[30];
    printf("Are u already a member of our store?\n 1. Yes 2. No\n");
    scanf(" %d", &a_check);
    FILE *fileptr;
    if (a_check == 1)
    {
        fileptr = fopen("Costumer Record.txt", "r");
        if (fileptr == NULL)
        {
            printf("Could not open the file.\n");
            exit(1);
            return 1;
        }
        printf("\nThe file is now opened.\n\n");
        int n = 1, x;
        unsigned long int No;
        while (n)
        {
            rewind(fileptr);
            fscanf(fileptr, " %d", &id);
            int x = 0;
            printf("Enter costumer's mobile number.\n");
            scanf(" %lu", &cNo);
            while (fscanf(fileptr, "%d %s %lu", &id, name, &No) != EOF)
            {
                if (No == cNo)
                {
                    printf("Costumer_Id      Name          Mobile_Number\n");
                    printf("  %d          \t  %s           %lu\n", id, name, No);
                    x = 1;
                    fclose(fileptr);
                    break;
                }
            }
            if (x == 1)
            {
                printf("He is a member. Proceeding to cart.\n");
                n = 0;
            }
            else
            {
                printf("He is not a member.\n\n");
                printf("If you want to check again. \t\t\t\t Press 1\n");
                printf("If he wants to continue shopping without membership. \t Press 2\n");
                scanf(" %d", &b_check);
                if (b_check == 1)
                {
                    n = 1;
                }
                else if (b_check == 2)
                {
                    id = 0;
                    n = 0;
                }
            }
        }

        fclose(fileptr);
    }
    else if (a_check == 2)
    {
        printf("Do you want to become our member? \n1 Yes   2 No\n");
        scanf(" %d", &c_check);
        if (c_check == 1)
        {
            printf("Enter costumer's name.\n");
            fflush(stdin);
            gets(name);
            printf("Enter costumer's Phone number.\n");
            scanf(" %lu", &cNo);
            fileptr = fopen("Costumer Record.txt", "r+");
            fscanf(fileptr, " %d", &id);
            fseek(fileptr, 0, SEEK_SET);
            fprintf(fileptr, "%d", ++id);
            fseek(fileptr, 0, SEEK_END);
            fprintf(fileptr, "\n%d %s %lu", id, name, cNo);
            fclose(fileptr);
        }
        else if (c_check == 2)
        {
            id = 0;
        }
    }
    return 0;
}
