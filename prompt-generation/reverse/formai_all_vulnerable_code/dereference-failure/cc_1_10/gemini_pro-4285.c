//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse size
#define WAREHOUSE_SIZE 1000

// Define the product structure
typedef struct {
  int id;
  char name[256];
  int quantity;
} Product;

// Define the warehouse structure
typedef struct {
  Product products[WAREHOUSE_SIZE];
  int num_products;
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  if (warehouse == NULL) {
    return NULL;
  }

  warehouse->num_products = 0;

  return warehouse;
}

// Destroy the warehouse and free all its memory
void destroy_warehouse(Warehouse *warehouse) {
  free(warehouse);
}

// Add a product to the warehouse
bool add_product(Warehouse *warehouse, Product product) {
  if (warehouse->num_products == WAREHOUSE_SIZE) {
    return false;
  }

  warehouse->products[warehouse->num_products++] = product;

  return true;
}

// Remove a product from the warehouse
bool remove_product(Warehouse *warehouse, int id) {
  for (int i = 0; i < warehouse->num_products; i++) {
    if (warehouse->products[i].id == id) {
      warehouse->products[i] = warehouse->products[warehouse->num_products - 1];
      warehouse->num_products--;
      return true;
    }
  }

  return false;
}

// Find a product in the warehouse by its ID
Product *find_product(Warehouse *warehouse, int id) {
  for (int i = 0; i < warehouse->num_products; i++) {
    if (warehouse->products[i].id == id) {
      return &warehouse->products[i];
    }
  }

  return NULL;
}

// Print the warehouse inventory
void print_inventory(Warehouse *warehouse) {
  printf("Warehouse Inventory:\n");
  for (int i = 0; i < warehouse->num_products; i++) {
    Product product = warehouse->products[i];
    printf("  - %s (%d): %d\n", product.name, product.id, product.quantity);
  }
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse *warehouse = create_warehouse();

  // Add some products to the warehouse
  Product product1 = {1, "Product 1", 10};
  Product product2 = {2, "Product 2", 20};
  Product product3 = {3, "Product 3", 30};
  add_product(warehouse, product1);
  add_product(warehouse, product2);
  add_product(warehouse, product3);

  // Print the warehouse inventory
  print_inventory(warehouse);

  // Remove a product from the warehouse
  remove_product(warehouse, 2);

  // Print the warehouse inventory again
  print_inventory(warehouse);

  // Destroy the warehouse
  destroy_warehouse(warehouse);

  return 0;
}