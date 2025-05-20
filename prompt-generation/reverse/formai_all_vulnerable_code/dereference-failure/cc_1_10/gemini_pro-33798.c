//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory.
#define MAX_PRODUCTS 100

// Define the structure of a product.
typedef struct product {
  int id;
  char name[50];
  int quantity;
  float price;
} product;

// Define the structure of the inventory.
typedef struct inventory {
  product products[MAX_PRODUCTS];
  int num_products;
} inventory;

// Create a new inventory.
inventory* create_inventory() {
  inventory* inv = malloc(sizeof(inventory));
  inv->num_products = 0;
  return inv;
}

// Add a product to the inventory.
void add_product(inventory* inv, product* p) {
  if (inv->num_products < MAX_PRODUCTS) {
    inv->products[inv->num_products++] = *p;
  }
}

// Remove a product from the inventory.
void remove_product(inventory* inv, int id) {
  int i;
  for (i = 0; i < inv->num_products; i++) {
    if (inv->products[i].id == id) {
      inv->products[i] = inv->products[inv->num_products - 1];
      inv->num_products--;
      return;
    }
  }
}

// Update the quantity of a product in the inventory.
void update_quantity(inventory* inv, int id, int quantity) {
  int i;
  for (i = 0; i < inv->num_products; i++) {
    if (inv->products[i].id == id) {
      inv->products[i].quantity = quantity;
      return;
    }
  }
}

// Print the inventory.
void print_inventory(inventory* inv) {
  int i;
  for (i = 0; i < inv->num_products; i++) {
    printf("Product %d: %s, Quantity: %d, Price: %.2f\n",
           inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
  }
}

// Main function.
int main() {
  // Create an inventory.
  inventory* inv = create_inventory();

  // Add some products to the inventory.
  product p1 = {1, "Apple", 10, 1.00};
  add_product(inv, &p1);
  product p2 = {2, "Orange", 20, 1.50};
  add_product(inv, &p2);
  product p3 = {3, "Banana", 30, 2.00};
  add_product(inv, &p3);

  // Print the inventory.
  printf("Initial inventory:\n");
  print_inventory(inv);

  // Remove a product from the inventory.
  remove_product(inv, 2);

  // Update the quantity of a product in the inventory.
  update_quantity(inv, 1, 5);

  // Print the inventory.
  printf("\nUpdated inventory:\n");
  print_inventory(inv);

  // Free the memory allocated for the inventory.
  free(inv);

  return 0;
}