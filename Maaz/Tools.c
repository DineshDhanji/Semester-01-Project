#include <stdio.h>

struct items
    {
        int code;
        char name[30];
        int quantity;
        int price;
    };
    struct items b[6] =
        {
            {1, "Apple", 5, 100},
            {2, "Banana", 7, 150},
            {3, "Cat", 12, 120},
            {4, "Dog", 14, 140},
            {5, "Elf", 14, 140},
            {6, "Fish", 15, 150},
        };

    struct items c[6] =
        {
            {1, "Apple", 3, 100},
            {2, "Banana", 4, 150},
            {3, "Cat", 3, 120},
            {4, "Dog", 10, 140},
            {5, "Elf", 1, 140},
            {6, "Fish", 1, 150}
        };


int main()
{
    int input_code, input_quantity, product_code;
    int choice, n, choice1, choice2, m, j;
    while (1)
    {
        system("cls");
        printf("\t\t\tTOOLS\t\t\t");
        printf("\nInput a code");
        printf("\nSelect your option:\nDelete\t\t\t1\nRemove all\t\t2\nGo back\t\t\t3\n========\n");
        scanf("%d", &choice);

        switch (choice)
        {
        //DELETE AN ITEM
        case 1:
        {
            printf("\nDelete an item: ");
            
            do
            {
                printf("\n\tEnter the item code you want to delete: ");
                scanf(" %d", &product_code);

                if(product_code <= 0 || product_code > 6/*countcart()*/)
                {
                    printf("Invalid Input!");
                    break;
                }



                int cont = 0;
                // cont = 1;
                for (int i = 0; i <= 6; i++)
                {
                    if (product_code == c[i].code)
                    {
                        printf("Enter quantity you want to remove: ");
                        scanf(" %d", &n);
                        if (n > c[i].quantity || c[i].quantity < 0 || n < 0)
                        {
                            printf("\nYour input is invalid. Please enter the quantity of your cart items only.");
                        }

                        else
                        {
                            cont = 1;
                            c[i].quantity = c[i].quantity - n;
                            b[i].quantity = b[i].quantity + n;
                            printf("\nStore quantity after deleting: %d", b[i].quantity);
                            printf("\nCart quantity after deleting: %d", c[i].quantity);
                        }
                        break;
                    }
                }
                
                printf("\nDo you want to remove any other item?\nPress 1 for yes\nPress 0 for no\n");
                scanf(" %d", &choice1);

                if (choice1 != 0 && choice1 != 1)
                {
                    printf("Invalid input");
                    break;
                }
                
            } while (choice1);
            break;
        }
            //REMOVE ALL ITEMS FROM CART
        case 2:
        {
            int i;
            printf("Are you sure you want to remove all items from your cart?\nPress 1 to confirm: ");
            scanf("%d", &choice2);
            if (choice2 == 1)
            {
                for (i = 0; i < 6; i++)
                {
                    b[i].quantity = b[i].quantity + c[i].quantity;
                    c[i].quantity = c[i].quantity - c[i].quantity;
                }
                for (i = 0; i < 6; i++)
                {
                    printf("Product %d: %d\n", i+1, b[i].quantity);
                    printf("cart : %d\n", c[i].quantity);
                }
                fflush(stdin);
                getchar();
            }
            else
            {
                printf("\nInvalid Input!");
            }
            break;
        }
            //PROCEED TO CHECK OUT
            //     case 3:
            //     {

            //     }
            //     //BACK TO MENU AND MODIFY CART ITEMS
            //     case 4:
            //     {
            //         printf("\n\t\tGo back to menu: ");
            //         {
            //             break;
            //         }
            //         break;
            //     }
            //     default:
            //         printf("Invalid code! Please input a valid code number.");
            //         break;
            // }
        }
    }
}
