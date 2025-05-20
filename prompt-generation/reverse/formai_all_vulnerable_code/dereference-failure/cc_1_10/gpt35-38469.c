//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  char name[50];
  int quantity;
  float price;
};

// function prototypes
void addProduct(struct product* inventory, int* size);
void deleteProduct(struct product* inventory, int* size);
void printInventory(struct product* inventory, int size);
void updateProduct(struct product* inventory, int size);

int main() {
  int option, size = 0;
  struct product* inventory = malloc(sizeof(struct product));

  do {
    printf("\nProduct Inventory Management System\n");
    printf("=====================================\n");
    printf("1. Add Product\n");
    printf("2. Delete Product\n");
    printf("3. Print Inventory\n");
    printf("4. Update Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        addProduct(inventory, &size);
        break;
      case 2:
        deleteProduct(inventory, &size);
        break;
      case 3:
        printInventory(inventory, size);
        break;
      case 4:
        updateProduct(inventory, size);
        break;
      case 5:
        printf("Exiting Program...\n");
        break;
      default:
        printf("Invalid option. Please try again.\n");
    }
  } while(option != 5);

  free(inventory);
  return 0;
}

void addProduct(struct product* inventory, int* size) {
  char name[50];
  int quantity;
  float price;

  printf("\nEnter Product Details\n");
  printf("======================\n");
  printf("Name: ");
  scanf("%s", name);
  printf("Quantity: ");
  scanf("%d", &quantity);
  printf("Price: ");
  scanf("%f", &price);

  // add product to inventory
  strcpy(inventory[*size].name, name);
  inventory[*size].quantity = quantity;
  inventory[*size].price = price;
  (*size)++;
}

void deleteProduct(struct product* inventory, int* size) {
  int idx, i;
  printf("\nEnter Index of Product to be Deleted: ");
  scanf("%d", &idx);

  if(idx >= 0 && idx < *size) {
    // shift all products after deleted product back one index
    for(i = idx; i < (*size - 1); i++) {
      strcpy(inventory[i].name, inventory[i+1].name);
      inventory[i].quantity = inventory[i+1].quantity;
      inventory[i].price = inventory[i+1].price;
    }
    (*size)--;
    printf("Product Deleted Successfully!\n");
  }
  else {
    printf("Invalid Index. Please try again.\n");
  }
}

void printInventory(struct product* inventory, int size) {
  int i;
  printf("\n%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
  printf("========================================================\n");
  for(i = 0; i < size; i++) {
    printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

void updateProduct(struct product* inventory, int size) {
  int idx;
  printf("\nEnter Index of Product to be Updated: ");
  scanf("%d", &idx);

  if(idx >= 0 && idx < size) {
    printf("\nEnter New Product Details\n");
    printf("==========================\n");
    printf("Name: ");
    scanf("%s", inventory[idx].name);
    printf("Quantity: ");
    scanf("%d", &inventory[idx].quantity);
    printf("Price: ");
    scanf("%f", &inventory[idx].price);
    printf("Product Updated Successfully!\n");
  }
  else {
    printf("Invalid Index. Please try again.\n");
  }
}