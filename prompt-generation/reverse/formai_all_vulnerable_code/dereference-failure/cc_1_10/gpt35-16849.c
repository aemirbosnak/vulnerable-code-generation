//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
// This is an example program of a Warehouse Management System in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

// Struct definitions
typedef struct {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  int quantity;
  float price;
} Product;

// Global variables
Product products[MAX_PRODUCTS];
int numProducts = 0;

// Functions
void addProduct();
void removeProduct();
void displayProducts();
void saveProductsToFile();
void loadProductsFromFile();

// Main function
int main() {
  int choice;
  do {
    printf("\nWarehouse Management System Menu:\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Display all products\n");
    printf("4. Save products to file\n");
    printf("5. Load products from file\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addProduct();
        break;
      case 2:
        removeProduct();
        break;
      case 3:
        displayProducts();
        break;
      case 4:
        saveProductsToFile();
        break;
      case 5:
        loadProductsFromFile();
        break;
      case 0:
        printf("Exiting Warehouse Management System. Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (choice != 0);
  return 0;
}

void addProduct() {
  if (numProducts >= MAX_PRODUCTS) {
    printf("Maximum number of products reached. Cannot add any more products.\n");
    return;
  }
  printf("Enter the name of the product: ");
  scanf("%s", products[numProducts].name);
  printf("Enter the description of the product: ");
  scanf("%s", products[numProducts].description);
  printf("Enter the quantity of the product: ");
  scanf("%d", &products[numProducts].quantity);
  printf("Enter the price of the product: ");
  scanf("%f", &products[numProducts].price);
  numProducts++;
  printf("Product added successfully.\n");
}

void removeProduct() {
  char productName[MAX_NAME_LENGTH];
  printf("Enter the name of the product to remove: ");
  scanf("%s", productName);
  int index = -1;
  for (int i = 0; i < numProducts; i++) {
    if (strcmp(products[i].name, productName) == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("Product not found.\n");
    return;
  }
  for (int i = index; i < numProducts - 1; i++) {
    products[i] = products[i + 1];
  }
  numProducts--;
  printf("Product removed successfully.\n");
}

void displayProducts() {
  printf("Current products in the warehouse:\n");
  printf("%-20s %-40s %-10s %-10s\n", "Name", "Description", "Quantity", "Price");
  printf("------------------------------------------------------------\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%-20s %-40s %-10d %-10.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
  }
}

void saveProductsToFile() {
  FILE *file = fopen("products.txt", "w");
  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }
  for (int i = 0; i < numProducts; i++) {
    fprintf(file, "%s|%s|%d|%f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
  }
  fclose(file);
  printf("Products saved to file successfully.\n");
}

void loadProductsFromFile() {
  FILE *file = fopen("products.txt", "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }
  char line[256];
  while (fgets(line, sizeof(line), file) != NULL) {
    char *name = strtok(line, "|");
    char *description = strtok(NULL, "|");
    int quantity = atoi(strtok(NULL, "|"));
    float price = atof(strtok(NULL, "|"));
    strcpy(products[numProducts].name, name);
    strcpy(products[numProducts].description, description);
    products[numProducts].quantity = quantity;
    products[numProducts].price = price;
    numProducts++;
  }
  fclose(file);
  printf("Products loaded from file successfully.\n");
}