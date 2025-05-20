//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
  int id;
  char name[50];
  int quantity;
  float price;
} product;

// Define the product inventory system
typedef struct inventory_system {
  product products[MAX_PRODUCTS];
  int num_products;
} inventory_system;

// Create a new product inventory system
inventory_system *create_inventory_system() {
  inventory_system *system = malloc(sizeof(inventory_system));
  system->num_products = 0;
  return system;
}

// Add a product to the inventory system
void add_product(inventory_system *system, product product) {
  if (system->num_products < MAX_PRODUCTS) {
    system->products[system->num_products] = product;
    system->num_products++;
  } else {
    printf("Error: The inventory system is full.\n");
  }
}

// Remove a product from the inventory system
void remove_product(inventory_system *system, int id) {
  for (int i = 0; i < system->num_products; i++) {
    if (system->products[i].id == id) {
      system->products[i] = system->products[system->num_products - 1];
      system->num_products--;
      break;
    }
  }
}

// Get a product from the inventory system
product *get_product(inventory_system *system, int id) {
  for (int i = 0; i < system->num_products; i++) {
    if (system->products[i].id == id) {
      return &system->products[i];
    }
  }
  return NULL;
}

// Print the inventory system
void print_inventory_system(inventory_system *system) {
  printf("Inventory System:\n");
  for (int i = 0; i < system->num_products; i++) {
    printf("  %d: %s (%d, %.2f)\n", system->products[i].id, system->products[i].name, system->products[i].quantity, system->products[i].price);
  }
}

// Main function
int main() {
  // Create a new product inventory system
  inventory_system *system = create_inventory_system();

  // Add some products to the inventory system
  product product1 = {1, "Apple", 10, 1.00};
  product product2 = {2, "Orange", 5, 0.50};
  product product3 = {3, "Banana", 15, 0.75};
  add_product(system, product1);
  add_product(system, product2);
  add_product(system, product3);

  // Print the inventory system
  print_inventory_system(system);

  // Remove a product from the inventory system
  remove_product(system, 2);

  // Print the inventory system
  print_inventory_system(system);

  // Get a product from the inventory system
  product *product = get_product(system, 1);

  // Print the product
  printf("Product:\n");
  printf("  ID: %d\n", product->id);
  printf("  Name: %s\n", product->name);
  printf("  Quantity: %d\n", product->quantity);
  printf("  Price: %.2f\n", product->price);

  // Free the memory allocated for the inventory system
  free(system);

  return 0;
}