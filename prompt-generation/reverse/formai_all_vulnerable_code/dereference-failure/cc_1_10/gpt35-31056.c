//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for product
typedef struct product {
  int id;
  char name[50];
  int qty;
} Product;

// Function to add a product to the warehouse
void addProduct(Product *products, int *product_count, int max_products) {
  // Check if the maximum number of products has been reached
  if(*product_count >= max_products) {
    printf("Warehouse is full! Cannot add more products.\n");
    return;
  }

  Product newProduct;

  // Get input from user for new product
  printf("Enter product id: ");
  scanf("%d", &newProduct.id);
  printf("Enter product name: ");
  scanf("%s", newProduct.name);
  printf("Enter product quantity: ");
  scanf("%d", &newProduct.qty);

  // Add new product to the array
  products[*product_count] = newProduct;
  (*product_count)++;

  printf("Product added successfully!\n");
}

// Function to remove a product from the warehouse
void removeProduct(Product *products, int *product_count) {
  int remove_id;
  int found_index = -1;

  // Get input from user for product id to remove
  printf("Enter product id to remove: ");
  scanf("%d", &remove_id);

  // Find the index of the product to remove
  for(int i = 0; i < *product_count; i++) {
    if(products[i].id == remove_id) {
      found_index = i;
      break;
    }
  }

  // Check if the product to remove was found
  if(found_index == -1) {
    printf("Product with id %d was not found!\n", remove_id);
    return;
  }

  // Remove the product from the array
  for(int i = found_index; i < (*product_count) - 1; i++) {
    products[i] = products[i+1];
  }
  (*product_count)--;

  printf("Product removed successfully!\n");
}

// Function to display the products in the warehouse
void displayProducts(Product *products, int *product_count) {
  printf("\nPRODUCTS IN THE WAREHOUSE:\n");
  printf("--------------------------\n");
  printf("| %-5s | %-20s | %-5s |\n", "ID", "NAME", "QTY");
  printf("--------------------------\n");
  for(int i = 0; i < *product_count; i++) {
    printf("| %-5d | %-20s | %-5d |\n", products[i].id, products[i].name, products[i].qty);
  }
  printf("--------------------------\n\n");
}

// Main function to run the warehouse management system
int main() {
  int max_products = 50;
  Product *products = (Product *)malloc(max_products * sizeof(Product));
  int product_count = 0;
  int choice;

  printf("\tWELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM\n");

  while(1) {
    printf("\n1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Display products\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addProduct(products, &product_count, max_products);
        break;
      case 2:
        removeProduct(products, &product_count);
        break;
      case 3:
        displayProducts(products, &product_count);
        break;
      case 4:
        free(products);
        exit(0);
      default:
        printf("Invalid choice! Please try again.\n");
        break;
    }
  }

  return 0;
}