//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
// Linus Torvalds style C Product Inventory System example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
  char *name;
  int quantity;
  double price;
} product;

// Define the inventory as an array of products
product inventory[MAX_PRODUCTS];

// Initialize the inventory with some sample products
void init_inventory() {
  strcpy(inventory[0].name, "Apple");
  inventory[0].quantity = 10;
  inventory[0].price = 1.00;

  strcpy(inventory[1].name, "Orange");
  inventory[1].quantity = 5;
  inventory[1].price = 1.50;

  strcpy(inventory[2].name, "Banana");
  inventory[2].quantity = 20;
  inventory[2].price = 0.50;
}

// Add a new product to the inventory
void add_product(char *name, int quantity, double price) {
  // Check if the inventory is full
  if (inventory[MAX_PRODUCTS - 1].name != NULL) {
    printf("Error: Inventory is full.\n");
    return;
  }

  // Add the new product to the inventory
  strcpy(inventory[MAX_PRODUCTS - 1].name, name);
  inventory[MAX_PRODUCTS - 1].quantity = quantity;
  inventory[MAX_PRODUCTS - 1].price = price;
}

// Remove a product from the inventory
void remove_product(char *name) {
  // Find the product in the inventory
  int i;
  for (i = 0; i < MAX_PRODUCTS; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      break;
    }
  }

  // Check if the product was found
  if (i == MAX_PRODUCTS) {
    printf("Error: Product not found.\n");
    return;
  }

  // Remove the product from the inventory
  for (i = i + 1; i < MAX_PRODUCTS; i++) {
    strcpy(inventory[i - 1].name, inventory[i].name);
    inventory[i - 1].quantity = inventory[i].quantity;
    inventory[i - 1].price = inventory[i].price;
  }
}

// Print the inventory
void print_inventory() {
  // Print the header
  printf("Inventory:\n");
  printf("Name\tQuantity\tPrice\n");

  // Print the products
  int i;
  for (i = 0; i < MAX_PRODUCTS; i++) {
    if (inventory[i].name != NULL) {
      printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
  }
}

// Main function
int main() {
  // Initialize the inventory
  init_inventory();

  // Add a new product
  add_product("Grape", 10, 1.25);

  // Remove a product
  remove_product("Orange");

  // Print the inventory
  print_inventory();

  return 0;
}