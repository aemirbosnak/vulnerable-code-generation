//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

// Structure to represent a product
typedef struct {
  char name[50];
  int quantity;
  float price;
} Product;

// Function to display the main menu
void displayMenu() {
  printf("\nProduct Inventory System\n");
  printf("------------------------\n");
  printf("1. Add a product\n");
  printf("2. Edit a product\n");
  printf("3. Delete a product\n");
  printf("4. Search for a product\n");
  printf("5. List all products\n");
  printf("6. Exit\n");
  printf("Enter your choice: ");
}

// Function to add a product
void addProduct(Product products[], int *numProducts) {
  if (*numProducts >= MAX_PRODUCTS) {
    printf("Product list is full. Cannot add more products.\n");
    return;
  }

  // Get the product details from the user
  printf("Enter the product name: ");
  scanf(" %s", products[*numProducts].name);

  printf("Enter the product quantity: ");
  scanf(" %d", &products[*numProducts].quantity);

  printf("Enter the product price: ");
  scanf(" %f", &products[*numProducts].price);

  // Increment the number of products
  (*numProducts)++;
}

// Function to edit a product
void editProduct(Product products[], int numProducts) {
  int choice;

  // Display the list of products
  printf("Select a product to edit:\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%d. %s\n", i + 1, products[i].name);
  }
  printf("Enter your choice: ");
  scanf(" %d", &choice);

  // Get the new product details from the user
  printf("Enter the new product name: ");
  scanf(" %s", products[choice - 1].name);

  printf("Enter the new product quantity: ");
  scanf(" %d", &products[choice - 1].quantity);

  printf("Enter the new product price: ");
  scanf(" %f", &products[choice - 1].price);
}

// Function to delete a product
void deleteProduct(Product products[], int *numProducts) {
  int choice;

  // Display the list of products
  printf("Select a product to delete:\n");
  for (int i = 0; i < *numProducts; i++) {
    printf("%d. %s\n", i + 1, products[i].name);
  }
  printf("Enter your choice: ");
  scanf(" %d", &choice);

  // Shift the products after the deleted product to the left
  for (int i = choice - 1; i < *numProducts - 1; i++) {
    products[i] = products[i + 1];
  }

  // Decrement the number of products
  (*numProducts)--;
}

// Function to search for a product
void searchProduct(Product products[], int numProducts) {
  char name[50];

  // Get the product name from the user
  printf("Enter the product name to search for: ");
  scanf(" %s", name);

  // Search for the product
  int found = 0;
  for (int i = 0; i < numProducts; i++) {
    if (strcmp(products[i].name, name) == 0) {
      found = 1;

      // Display the product details
      printf("Product found:\n");
      printf("Name: %s\n", products[i].name);
      printf("Quantity: %d\n", products[i].quantity);
      printf("Price: %.2f\n", products[i].price);
      break;
    }
  }

  if (!found) {
    printf("Product not found.\n");
  }
}

// Function to list all products
void listProducts(Product products[], int numProducts) {
  if (numProducts == 0) {
    printf("Product list is empty.\n");
    return;
  }

  // Display the list of products
  printf("Product list:\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%d. %s - %d - %.2f\n", i + 1, products[i].name,
           products[i].quantity, products[i].price);
  }
}

// Main function
int main() {
  Product products[MAX_PRODUCTS];
  int numProducts = 0;

  int choice;
  do {
    // Display the main menu
    displayMenu();

    // Get the user's choice
    scanf(" %d", &choice);

    // Perform the selected action
    switch (choice) {
    case 1:
      addProduct(products, &numProducts);
      break;
    case 2:
      editProduct(products, numProducts);
      break;
    case 3:
      deleteProduct(products, &numProducts);
      break;
    case 4:
      searchProduct(products, numProducts);
      break;
    case 5:
      listProducts(products, numProducts);
      break;
    case 6:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice. Please enter a number from 1 to 6.\n");
    }
  } while (choice != 6);

  return 0;
}