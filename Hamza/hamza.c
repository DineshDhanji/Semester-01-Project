#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned long int cNo; 
    int a_check, b_check, c_check, id, a =0;
    char name[30];
    printf("Are u already a member of our store?\n 1. Yes 2. No");
    scanf(" %d", &a_check);
    if ( a_check == 1)
    {
    FILE *fileptr;
    printf("Enter costumer's mobile number.\n");
    scanf(" %lu", &cNo);
    fileptr = fopen("user record.txt", "a+");
    if ( fileptr == NULL )
    {
        printf("Could not open the file.\n");
        return 1;
    }
    printf("The file is now opened.\n") ;
    int No, x = 0, id = a;
    while (fscanf(fileptr,"%d %s %d", &id, name, &No) != EOF)
    {
        if ( No == cNo)
        { 
            printf("%d %s %d\n", id, name, No);
            x = 1;
            break;
        }
    }
    if (x == 1)
    {
        printf("He is a member.\n");
    }
    else
    {
        printf("He is not a member.\n");
        printf("Does he want to continue shopping without membership or do you want to input again?\n1 Yes    2 No\n");
        scanf(" %d", b_check);
        if (b_check == 1)
        {
            id =  a++;
        }
        else if (b_check == 2)
        {
            id =  a++;
        }
    }
    fclose(fileptr);
    }
    else if ( a_check == 2)
    {
        printf("Do you want to become our member? \n1 Yes   2 No\n");
        scanf(" %d", &c_check);
        if (c_check == 1)
        {
        printf("Enter costumer's name.\n");
        while (getchar() != '\n');
        gets(name);
        printf("Enter costumer's Phone number.\n");
        scanf(" %lu", &cNo);
        FILE *fileptr;
        fileptr = fopen("user Record.txt", "a+");
        id = a++;
        fprintf(fileptr, "%d %s %lu\n", id, name,cNo);
        fclose(fileptr);
        }
        else if ( c_check == 2)
        {
            FILE *fileptr;
        fileptr = fopen("user Record.txt", "a+");
            id = a++;
            fclose(fileptr);
        }
    }
    return 0;
}
// #include <stdio.h>
// int main()
// {
// int num; FILE *fptr; char c;
// fptr = fopen("user Record.txt","r");
// if(fptr == NULL)
// {
// printf("Error!");
// }
// else
// {
//     printf("hello!");
// while ((c = fgetc(fptr)) != EOF)
// printf(" %c", c);
// }
// fclose(fptr);
// return 0;
// }
// #include <stdio.h>
// int main()
// {
// int num; FILE *fptr; char c[100], d[100];
// fptr = fopen("user Record.txt","r");
// if(fptr == NULL)
// {
// printf("Error!");
// }
// else
// {
// while (fscanf(fptr,"%s %d",c, &num) != EOF)
// {
//     if (num == 3)
//     {
//         printf("%s %d\n",c, num);   
//     }
    

// }


// }
// fclose(fptr);
// return 0;
// }
