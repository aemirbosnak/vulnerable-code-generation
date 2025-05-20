//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include<stdio.h>
#include<string.h>

struct item{
  char itemName[50];
  int quantity;
  float pricePerUnit;
};

struct warehouse{
  int warehouseID;
  char warehouseLocation[50];
  struct item stock[50];
};

int main(){
  int numOfWarehouses, numOfItems;
  printf("Enter the number of warehouses: ");
  scanf("%d", &numOfWarehouses);

  struct warehouse warehouses[numOfWarehouses];
  for(int i=0; i<numOfWarehouses; i++){
    printf("\n==============WAREHOUSE %d==============\n",i+1);
    printf("Enter warehouse ID: ");
    scanf("%d", &warehouses[i].warehouseID);
    printf("Enter warehouse location: ");
    scanf("%s", &warehouses[i].warehouseLocation);
    printf("Enter number of items in stock: ");
    scanf("%d", &numOfItems);

    for(int j=0; j<numOfItems; j++){
      printf("\nItem %d:\n", j+1);
      printf("Enter item name: ");
      scanf("%s", &warehouses[i].stock[j].itemName);
      printf("Enter quantity: ");
      scanf("%d", &warehouses[i].stock[j].quantity);
      printf("Enter price per unit: ");
      scanf("%f", &warehouses[i].stock[j].pricePerUnit);
    }
  }

  // Displaying the warehouse details
  printf("\n===============WAREHOUSE DETAILS===============\n");
  for(int i=0; i<numOfWarehouses; i++){
    printf("\nWarehouse %d:\n", i+1);
    printf("Warehouse ID: %d\n", warehouses[i].warehouseID);
    printf("Warehouse Location: %s\n", warehouses[i].warehouseLocation);
    printf("Stock Details:\n");

    for(int j=0; j<numOfItems; j++){
      printf("Item %d: %s, Quantity: %d, Price/Unit: %.2f\n",j+1,warehouses[i].stock[j].itemName,warehouses[i].stock[j].quantity,warehouses[i].stock[j].pricePerUnit);
    }
  }

  return 0;
}