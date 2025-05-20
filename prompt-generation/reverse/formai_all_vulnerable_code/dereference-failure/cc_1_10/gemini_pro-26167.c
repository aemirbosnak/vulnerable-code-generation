//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
typedef struct Product {
  char *name;
  int quantity;
  double price;
} Product;

// Structure to store warehouse information
typedef struct Warehouse {
  char *name;
  int num_products;
  Product *products;
} Warehouse;

// Function to create a new product
Product *create_product(char *name, int quantity, double price) {
  Product *product = malloc(sizeof(Product));
  product->name = strdup(name);
  product->quantity = quantity;
  product->price = price;
  return product;
}

// Function to create a new warehouse
Warehouse *create_warehouse(char *name) {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  warehouse->name = strdup(name);
  warehouse->num_products = 0;
  warehouse->products = NULL;
  return warehouse;
}

// Function to add a product to a warehouse
void add_product_to_warehouse(Warehouse *warehouse, Product *product) {
  warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(Product));
  warehouse->products[warehouse->num_products] = *product;
  warehouse->num_products++;
}

// Function to print the products in a warehouse
void print_warehouse_products(Warehouse *warehouse) {
  for (int i = 0; i < warehouse->num_products; i++) {
    printf("Product: %s, Quantity: %d, Price: %f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
  }
}

// Function to free the memory allocated for a product
void free_product(Product *product) {
  free(product->name);
  free(product);
}

// Function to free the memory allocated for a warehouse
void free_warehouse(Warehouse *warehouse) {
  for (int i = 0; i < warehouse->num_products; i++) {
    free_product(&warehouse->products[i]);
  }
  free(warehouse->name);
  free(warehouse->products);
  free(warehouse);
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse *warehouse = create_warehouse("My Warehouse");

  // Add some products to the warehouse
  Product *product1 = create_product("Product 1", 10, 10.0);
  Product *product2 = create_product("Product 2", 20, 20.0);
  Product *product3 = create_product("Product 3", 30, 30.0);
  add_product_to_warehouse(warehouse, product1);
  add_product_to_warehouse(warehouse, product2);
  add_product_to_warehouse(warehouse, product3);

  // Print the products in the warehouse
  print_warehouse_products(warehouse);

  // Free the memory allocated for the warehouse
  free_warehouse(warehouse);

  return 0;
}