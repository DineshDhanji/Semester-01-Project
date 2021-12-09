#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    unsigned long int Inputed_Number;
    int a_check, b_check, c_check, a = 0, id;
    char name[30];
    printf("\t\t\t\tDo you have the membership card of our store ?\n\t\t\t\t\tYES\t\t1\n\t\t\t\t\tNo\t\t2\n\t\t\tInput: ");
    scanf(" %d", &a_check);
    FILE *fileptr;
    if (a_check == 1)
    {
        fileptr = fopen("Costumer Info.txt", "r");
        if (fileptr == NULL)
        {
            printf("\t\t\t\tCould not open the file. (! . !)\n");
            exit(1);
            return 1;
        }
        // cont means continue
        int cont = 1, x;
        unsigned long int Customer_Number;
        while (cont)
        {
            
            rewind(fileptr);
            fscanf(fileptr, " %d", &id);
            int x = 0;
            printf("\t\t\t\tEnter costumer's mobile number:\n\t\t\t\t");
            scanf(" %lu", &Inputed_Number);
            while (fscanf(fileptr, "%d %s %lu", &id, name, &Customer_Number) != EOF)
            {
                if (Customer_Number == Inputed_Number)
                {
                    printf("\n\t\t\t\tCostumer Id\tName\t\tMobile Number\n");
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
                if (b_check == 1)
                {
                    cont = 1;
                }
                else if (b_check == 2)
                {
                    id = 0;
                    cont = 0;
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
            scanf(" %lu", &Inputed_Number);
            fileptr = fopen("Costumer Info.txt", "r+");
            fscanf(fileptr, " %d", &id);
            fseek(fileptr, 0, SEEK_SET);
            fprintf(fileptr, "%d", ++id);
            fseek(fileptr, 0, SEEK_END);
            fprintf(fileptr, "\n%d %s %lu", id, name, Inputed_Number);
            fclose(fileptr);
        }
        else if (c_check == 2)
        {
            id = 0;
        }
    }
    return 0;
}
