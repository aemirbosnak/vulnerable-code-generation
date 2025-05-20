//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Define the product structure
typedef struct {
  int id;
  char name[50];
  int quantity;
  float price;
} Product;

// Define the inventory structure
typedef struct {
  Product products[MAX_PRODUCTS];
  int num_products;
} Inventory;

// Create a new inventory
Inventory* create_inventory() {
  Inventory* inventory = malloc(sizeof(Inventory));
  inventory->num_products = 0;
  return inventory;
}

// Add a product to the inventory
void add_product(Inventory* inventory, Product product) {
  inventory->products[inventory->num_products] = product;
  inventory->num_products++;
}

// Print the inventory
void print_inventory(Inventory* inventory) {
  for (int i = 0; i < inventory->num_products; i++) {
    Product product = inventory->products[i];
    printf("%d %s %d %.2f\n", product.id, product.name, product.quantity, product.price);
  }
}

// Find a product by ID
Product* find_product_by_id(Inventory* inventory, int id) {
  for (int i = 0; i < inventory->num_products; i++) {
    Product product = inventory->products[i];
    if (product.id == id) {
      return &product;
    }
  }
  return NULL;
}

// Delete a product by ID
void delete_product_by_id(Inventory* inventory, int id) {
  for (int i = 0; i < inventory->num_products; i++) {
    if (inventory->products[i].id == id) {
      for (int j = i; j < inventory->num_products - 1; j++) {
        inventory->products[j] = inventory->products[j + 1];
      }
      inventory->num_products--;
      break;
    }
  }
}

int main() {
  // Create a new inventory
  Inventory* inventory = create_inventory();

  // Add some products to the inventory
  Product product1 = {1, "Apple", 10, 1.0};
  add_product(inventory, product1);
  Product product2 = {2, "Banana", 20, 2.0};
  add_product(inventory, product2);
  Product product3 = {3, "Orange", 30, 3.0};
  add_product(inventory, product3);

  // Print the inventory
  printf("Initial inventory:\n");
  print_inventory(inventory);

  // Find a product by ID
  Product* found_product = find_product_by_id(inventory, 2);
  if (found_product != NULL) {
    printf("Found product: %d %s %d %.2f\n", found_product->id, found_product->name, found_product->quantity, found_product->price);
  } else {
    printf("Product not found.\n");
  }

  // Delete a product by ID
  delete_product_by_id(inventory, 2);

  // Print the inventory after deleting a product
  printf("Inventory after deleting a product:\n");
  print_inventory(inventory);

  // Free the inventory
  free(inventory);

  return 0;
}