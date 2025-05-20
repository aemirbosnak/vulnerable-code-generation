//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the warehouse
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

// Function to create a new warehouse
warehouse *create_warehouse() {
  warehouse *w = malloc(sizeof(warehouse));
  w->num_products = 0;
  return w;
}

// Function to add a new product to the warehouse
void add_product(warehouse *w, product p) {
  if (w->num_products < MAX_PRODUCTS) {
    w->products[w->num_products] = p;
    w->num_products++;
  } else {
    printf("Warehouse is full!\n");
  }
}

// Function to remove a product from the warehouse
void remove_product(warehouse *w, char *name) {
  int i;
  for (i = 0; i < w->num_products; i++) {
    if (strcmp(w->products[i].name, name) == 0) {
      break;
    }
  }
  if (i < w->num_products) {
    for (int j = i; j < w->num_products - 1; j++) {
      w->products[j] = w->products[j + 1];
    }
    w->num_products--;
  } else {
    printf("Product not found!\n");
  }
}

// Function to find a product in the warehouse
product *find_product(warehouse *w, char *name) {
  int i;
  for (i = 0; i < w->num_products; i++) {
    if (strcmp(w->products[i].name, name) == 0) {
      return &w->products[i];
    }
  }
  return NULL;
}

// Function to print the contents of the warehouse
void print_warehouse(warehouse *w) {
  printf("Warehouse contents:\n");
  for (int i = 0; i < w->num_products; i++) {
    printf("%s %d %.2f\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse *w = create_warehouse();

  // Add some products to the warehouse
  product p1 = {"Apple", 10, 1.0};
  add_product(w, p1);
  product p2 = {"Orange", 5, 1.5};
  add_product(w, p2);
  product p3 = {"Banana", 15, 2.0};
  add_product(w, p3);

  // Print the contents of the warehouse
  print_warehouse(w);

  // Find a product in the warehouse
  product *p = find_product(w, "Orange");
  if (p != NULL) {
    printf("Found product: %s %d %.2f\n", p->name, p->quantity, p->price);
  } else {
    printf("Product not found!\n");
  }

  // Remove a product from the warehouse
  remove_product(w, "Banana");

  // Print the contents of the warehouse
  print_warehouse(w);

  // Free the memory allocated for the warehouse
  free(w);

  return 0;
}