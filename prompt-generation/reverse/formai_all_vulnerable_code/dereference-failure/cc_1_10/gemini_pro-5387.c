//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
  char name[50];
  int quantity;
  float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
  char name[50];
  int num_products;
  product *products;
} warehouse;

// Function to create a new product
product *create_product(char *name, int quantity, float price) {
  product *p = (product *)malloc(sizeof(product));
  strcpy(p->name, name);
  p->quantity = quantity;
  p->price = price;
  return p;
}

// Function to create a new warehouse
warehouse *create_warehouse(char *name, int num_products) {
  warehouse *w = (warehouse *)malloc(sizeof(warehouse));
  strcpy(w->name, name);
  w->num_products = num_products;
  w->products = (product *)malloc(num_products * sizeof(product));
  return w;
}

// Function to add a product to a warehouse
void add_product(warehouse *w, product *p) {
  w->products[w->num_products++] = *p;
}

// Function to remove a product from a warehouse
void remove_product(warehouse *w, char *name) {
  for (int i = 0; i < w->num_products; i++) {
    if (strcmp(w->products[i].name, name) == 0) {
      for (int j = i; j < w->num_products - 1; j++) {
        w->products[j] = w->products[j + 1];
      }
      w->num_products--;
      break;
    }
  }
}

// Function to print the details of a warehouse
void print_warehouse(warehouse *w) {
  printf("Warehouse: %s\n", w->name);
  printf("Number of products: %d\n", w->num_products);
  for (int i = 0; i < w->num_products; i++) {
    printf("Product: %s\n", w->products[i].name);
    printf("Quantity: %d\n", w->products[i].quantity);
    printf("Price: %.2f\n", w->products[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse *w = create_warehouse("Main Warehouse", 5);

  // Add some products to the warehouse
  add_product(w, create_product("Apple", 100, 1.0));
  add_product(w, create_product("Orange", 50, 1.5));
  add_product(w, create_product("Banana", 75, 2.0));
  add_product(w, create_product("Grape", 25, 2.5));
  add_product(w, create_product("Strawberry", 10, 3.0));

  // Print the details of the warehouse
  print_warehouse(w);

  // Remove a product from the warehouse
  remove_product(w, "Banana");

  // Print the details of the warehouse again
  print_warehouse(w);

  return 0;
}