//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
  char name[256];
  int quantity;
  double price;
} Product;

void updateInventory(Product *products, int numProducts) {
  for (int i = 0; i < numProducts; i++) {
    printf("Enter the name of the product: ");
    scanf("%s", products[i].name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &products[i].quantity);

    printf("Enter the price of the product: ");
    scanf("%lf", &products[i].price);
  }
}

void displayInventory(Product *products, int numProducts) {
  for (int i = 0; i < numProducts; i++) {
    printf("Name: %s, Quantity: %d, Price: %.2lf\n", products[i].name, products[i].quantity, products[i].price);
  }
}

int main() {
  int numProducts = 0;

  Product *products = NULL;

  while (1) {
    char choice;

    printf("Enter 'a' to add a product, 'd' to display inventory, or 'q' to quit: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        products = realloc(products, (numProducts + 1) * sizeof(Product));
        products[numProducts].name[0] = '\0';
        updateInventory(products, numProducts + 1);
        numProducts++;
        break;
      case 'd':
        displayInventory(products, numProducts);
        break;
      case 'q':
        exit(0);
        break;
      default:
        printf("Invalid input.\n");
    }
  }

  return 0;
}