#include <stdio.h>
#include <conio.h>
int main()
{
    int product_len = 6;
    int product_code[6] = {1, 2, 3, 4, 5, 6};
    char *product_name[6] = {"Apple", "Banana", "Cat", "Dog", "Elf", "Fish"};
    int product_quantity[6] = {10,7,12,14,14,15};
    int product_prices[6] = {100,150,120,140,140,150};

    int cart_len = 0;
    int cart_code[6] = {};
    char *cart_name[6] = {};
    int cart_quantity[6] = {};
    int cart_prices[6] = {};
    
    int input_code, input_quantity;
    printf("Input the product code: ");
	scanf(" %i", &input_code);
    
    int m = 0;
    for(int j = 0; j < product_len; j++)
    {
    	if(input_code == product_code[j])
    	{
    		cart_name[m] = product_name[j];
    		cart_code[m] = input_code;
    		do
    		{
    			printf("Enter the quantity: ");
				scanf(" %i", &input_quantity);
    			
			} while (input_quantity > product_quantity[j]);
			product_quantity[j] -= input_quantity;
			cart_quantity[m] = input_quantity;
			m++;
			break;
		}
	}
	for (int k = 0; k < 6; k++)
	{
		printf("\n%s %i\n",product_name[k],product_quantity[k]);
	}
    
    for(int k = 0; k < m; k++)
	{
		printf("\n---------\n%s %i, %u\n",cart_name[k],cart_quantity[k],cart_code[k]);
	}
    
	return 0;
}
