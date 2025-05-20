//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  int num_items = 0;
  int option;
  char code[10];
  char name[50];
  int quantity;
  float price;
  
  // Prompt user for number of items to add
  printf("How many items would you like to add to the inventory system?\n");
  scanf("%d", &num_items);

  // Create array of structures to hold inventory data
  struct Inventory {
    char code[10];
    char name[50];
    int quantity;
    float price;
  };

  struct Inventory items[num_items];

  // Loop through each item to add data
  for (int i = 0; i < num_items; i++) {
    printf("\nItem %d:\n", i+1);

    // Prompt for code
    printf("Enter item code: ");
    scanf("%s", items[i].code);

    // Prompt for name
    printf("Enter item name: ");
    scanf(" %[^\n]s", items[i].name);

    // Prompt for quantity
    printf("Enter quantity: ");
    scanf("%d", &items[i].quantity);

    // Prompt for price
    printf("Enter price: ");
    scanf("%f", &items[i].price);
  }

  // Display inventory
  printf("\nInventory:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s - %s - %d - %.2f\n", items[i].code, items[i].name, items[i].quantity, items[i].price);
  }

  // Prompt user to update inventory
  printf("\nWould you like to update the inventory? (1 for yes, 0 for no)\n");
  scanf("%d", &option);

  // Update inventory
  if (option == 1) {
    printf("Enter the code of the item to update: ");
    scanf("%s", code);
    for(int i = 0; i < num_items; i++) {
      if (strcmp(code, items[i].code) == 0) {
        printf("Enter new quantity: ");
        scanf("%d", &quantity);
        items[i].quantity = quantity;
        printf("Enter new price: ");
        scanf("%f", &price);
        items[i].price = price;
        printf("\nInventory updated for item %s\n", code);
        break;
      }
    }
  }

  // Display updated inventory
  printf("\nUpdated Inventory:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s - %s - %d - %.2f\n", items[i].code, items[i].name, items[i].quantity, items[i].price);
  }

  return 0;
}