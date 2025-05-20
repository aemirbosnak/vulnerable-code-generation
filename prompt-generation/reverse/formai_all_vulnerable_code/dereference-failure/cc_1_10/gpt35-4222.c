//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
   char *name;
   int quantity;
   float price;
} Product;

void displayMenu(void);
void addProduct(Product inventory[], int *inventoryCountPointer);
void sellProduct(Product inventory[], int *inventoryCountPointer);
void showInventory(Product inventory[], int inventoryCount);
bool isNameExists(char *name, Product inventory[], int inventoryCount);

int main(void) {
   Product inventory[MAX_PRODUCTS];
   int inventoryCount = 0;
   int userInput;
   do {
      displayMenu();
      scanf("%d", &userInput);
      switch(userInput){
         case 1:
            addProduct(inventory, &inventoryCount);
            break;
         case 2:
            sellProduct(inventory, &inventoryCount);
            break;
         case 3:
            showInventory(inventory, inventoryCount);
            break;
         case 4:
            printf("Exiting Program\n");
            break;
         default:
            printf("Invalid choice, Please select again.\n");
      }
   } while(userInput != 4);
   return EXIT_SUCCESS;
}

void displayMenu() {
   printf("Product Inventory System - Menu:\n");
   printf("1. Add Product\n");
   printf("2. Sell Product\n");
   printf("3. Show Inventory\n");
   printf("4. Exit\n");
   printf("Enter Choice: ");
}

void addProduct(Product inventory[], int *inventoryCountPointer) {
   printf("Enter Product Name: ");
   char buffer[100];
   scanf("%s", buffer);
   if(isNameExists(buffer, inventory, *inventoryCountPointer)) {
      printf("Product Name already Exists.\n");
      return;
   }
   char *name = (char*) malloc(strlen(buffer) + 1);
   strcpy(name, buffer);
   printf("Enter Quantity: ");
   int quantity;
   scanf("%d", &quantity);
   printf("Enter Price: ");
   float price;
   scanf("%f", &price);
   inventory[*inventoryCountPointer].name = name;
   inventory[*inventoryCountPointer].quantity = quantity;
   inventory[*inventoryCountPointer].price = price;
   printf("Product Added Successfully.\n");
   (*inventoryCountPointer)++;
}

void sellProduct(Product inventory[], int *inventoryCountPointer) {
   printf("Enter Product Name: ");
   char buffer[100];
   scanf("%s", buffer);
   int index = -1;
   for(int i = 0; i < *inventoryCountPointer; i++) {
      if(strcmp(inventory[i].name, buffer) == 0) {
         index = i;
         break;
      }
   }
   if(index == -1) {
      printf("Product Not Found.\n");
      return;
   }
   printf("Enter Quantity: ");
   int quantity;
   scanf("%d", &quantity);
   if(quantity > inventory[index].quantity) {
      printf("Insufficient Quantity.\n");
      return;
   }
   float totalAmount = quantity * inventory[index].price;
   printf("Total Amount: %.2f\n", totalAmount);
   inventory[index].quantity -= quantity;
   printf("Product Sold Successfully.\n");
}

void showInventory(Product inventory[], int inventoryCount) {
   printf("Product\tQuantity\tPrice\n");
   for(int i = 0; i < inventoryCount; i++) {
      printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
   }
}

bool isNameExists(char *name, Product inventory[], int inventoryCount) {
   for(int i = 0; i < inventoryCount; i++) {
      if(strcmp(inventory[i].name, name) == 0) {
         return true;
      }
   }
   return false;
}