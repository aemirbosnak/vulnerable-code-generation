//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the warehouse
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
  char name[50];
  int quantity;
  float price;
} product;

// Define the structure of the warehouse
typedef struct {
  product products[MAX_PRODUCTS];
  int num_products;
} warehouse;

// Create a new warehouse
warehouse* create_warehouse() {
  warehouse* w = malloc(sizeof(warehouse));
  w->num_products = 0;
  return w;
}

// Add a product to the warehouse
void add_product(warehouse* w, product p) {
  if (w->num_products < MAX_PRODUCTS) {
    w->products[w->num_products] = p;
    w->num_products++;
  }
}

// Remove a product from the warehouse
void remove_product(warehouse* w, char* name) {
  for (int i = 0; i < w->num_products; i++) {
    if (strcmp(w->products[i].name, name) == 0) {
      for (int j = i; j < w->num_products - 1; j++) {
        w->products[j] = w->products[j + 1];
      }
      w->num_products--;
      return;
    }
  }
}

// Get the total value of the products in the warehouse
float get_total_value(warehouse* w) {
  float total = 0;
  for (int i = 0; i < w->num_products; i++) {
    total += w->products[i].quantity * w->products[i].price;
  }
  return total;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
  printf("Warehouse Contents:\n");
  for (int i = 0; i < w->num_products; i++) {
    printf("  %s (%d units at $%.2f)\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
  }
  printf("Total Value: $%.2f\n", get_total_value(w));
}

// Main function
int main() {
  // Create a new warehouse
  warehouse* w = create_warehouse();

  // Add some products to the warehouse
  product p1 = {"iPhone", 10, 999.99};
  add_product(w, p1);
  product p2 = {"iPad", 5, 799.99};
  add_product(w, p2);
  product p3 = {"Macbook Pro", 3, 1299.99};
  add_product(w, p3);

  // Print the contents of the warehouse
  print_warehouse(w);

  // Remove a product from the warehouse
  remove_product(w, "iPad");

  // Print the contents of the warehouse again
  print_warehouse(w);

  return 0;
}