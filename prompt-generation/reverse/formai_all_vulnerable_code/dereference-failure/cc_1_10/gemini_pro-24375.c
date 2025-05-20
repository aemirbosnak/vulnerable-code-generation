//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the product structure
typedef struct product {
  char name[50];
  int quantity;
  float price;
} product;

// Define the inventory structure
typedef struct inventory {
  product products[MAX_PRODUCTS];
  int num_products;
} inventory;

// Create a new product
product *create_product(char *name, int quantity, float price) {
  product *p = malloc(sizeof(product));
  strcpy(p->name, name);
  p->quantity = quantity;
  p->price = price;
  return p;
}

// Add a product to the inventory
void add_product(inventory *inv, product *p) {
  if (inv->num_products < MAX_PRODUCTS) {
    inv->products[inv->num_products++] = *p;
  } else {
    printf("Error: Inventory is full.\n");
  }
}

// Remove a product from the inventory
void remove_product(inventory *inv, char *name) {
  for (int i = 0; i < inv->num_products; i++) {
    if (strcmp(inv->products[i].name, name) == 0) {
      for (int j = i; j < inv->num_products - 1; j++) {
        inv->products[j] = inv->products[j + 1];
      }
      inv->num_products--;
      break;
    }
  }
}

// Print the inventory
void print_inventory(inventory *inv) {
  printf("Inventory:\n");
  for (int i = 0; i < inv->num_products; i++) {
    printf("%s %d %f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
  }
}

// Get the total value of the inventory
float get_total_value(inventory *inv) {
  float total = 0;
  for (int i = 0; i < inv->num_products; i++) {
    total += inv->products[i].quantity * inv->products[i].price;
  }
  return total;
}

// Main function
int main() {
  // Create a new inventory
  inventory *inv = malloc(sizeof(inventory));
  inv->num_products = 0;

  // Add some products to the inventory
  add_product(inv, create_product("Apple", 10, 1.0));
  add_product(inv, create_product("Orange", 5, 1.5));
  add_product(inv, create_product("Banana", 15, 2.0));

  // Print the inventory
  print_inventory(inv);

  // Get the total value of the inventory
  float total_value = get_total_value(inv);
  printf("Total value of inventory: %f\n", total_value);

  // Remove a product from the inventory
  remove_product(inv, "Orange");

  // Print the inventory again
  print_inventory(inv);

  // Free the memory allocated for the inventory
  free(inv);

  return 0;
}