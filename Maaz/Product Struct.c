#include <stdio.h>
#include <string.h>

struct product
{
  int code;
  char name[15];
  int qty;
  int price;
};

int main()
{ 
    struct product item[10];
    
  int i; 
  //struct i

  strcpy(item[0].name, "Apple");
  item[0].code = 1;
  item[0].qty = 5;
  item[0].price = 100;
  
  strcpy(item[1].name, "Banana");
  item[1].code = 2;
  item[1].qty = 7;
  item[1].price = 150;
  
  strcpy(item[2].name, "Cat");
  item[2].code = 3;
  item[2].qty = 12;
  item[2].price = 120;
  
  strcpy(item[3].name, "Dog");
  item[3].code = 4;
  item[3].qty = 14;
  item[3].price = 140;
  
  
  strcpy(item[4].name, "Elf");
  item[4].code = 5;
  item[4].qty = 
  item[4].price = 140;

  strcpy(item[5].name, "Fish");
  item[5].code = 6;
  item[5].qty = 15;
  item[5].price = 150;
  
  
  for (i = 0; i < 6; i++)
  {
    printf("\nItem code = %d", item[i].code);
    printf("\nProduct name = %s", item[i].name);
    printf("\nQuantity = %d", item[i].qty);
    printf("\nPrice = %d\n\n", item[i].price);
  }
	return 0;
}
  
