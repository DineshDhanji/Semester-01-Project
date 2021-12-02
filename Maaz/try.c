#include <stdio.h>
#include <string.h>

struct items {
    int code;
    char name[30];
    int quantity;
    int price;
};

int main(int argc, char const *argv[])
{
    FILE *ptr;
    ptr = fopen("Products.txt", "r");
    if (ptr == NULL)
    {
        printf("ERROR\n");
        return 1;
    }
    
    int code, quantity, price;
    char name[20];
    struct items product[10]; 
    for (int i = 0;fscanf(ptr, "%d %s %d %d", &code, name, &quantity, &price) != EOF; i++)
    {
        product[i].code = code; 
        strcpy(product[i].name , name); 
        product[i].quantity = quantity; 
        product[i].price = price; 
          
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("Code: %d\nName: %s\nQuantity: %d \nPrice: %d\n\n", product[i].code,  product[i].name,  product[i].quantity,  product[i].price);
    }
    
    return 0;
}
