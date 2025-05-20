//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: visionary
// Visionary Warehouse Management System (WMS)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Product {
  char name[50];
  int quantity;
  float price;
} Product;

typedef struct Warehouse {
  Product *products;
  int capacity;
  int count;
} Warehouse;

// Function prototypes
Warehouse *create_warehouse(int capacity);
void add_product(Warehouse *warehouse, Product product);
void remove_product(Warehouse *warehouse, char *name);
void print_warehouse(Warehouse *warehouse);
void sort_warehouse(Warehouse *warehouse);

// Main function
int main() {
  // Create a warehouse with a capacity of 100 products
  Warehouse *warehouse = create_warehouse(100);

  // Add some products to the warehouse
  Product product1 = {"Apple", 10, 1.0};
  add_product(warehouse, product1);
  Product product2 = {"Banana", 20, 1.5};
  add_product(warehouse, product2);
  Product product3 = {"Orange", 30, 2.0};
  add_product(warehouse, product3);

  // Print the warehouse
  printf("Warehouse:\n");
  print_warehouse(warehouse);

  // Remove a product from the warehouse
  remove_product(warehouse, "Banana");

  // Print the warehouse again
  printf("\nWarehouse (after removing Banana):\n");
  print_warehouse(warehouse);

  // Sort the warehouse by product name
  sort_warehouse(warehouse);

  // Print the warehouse one last time
  printf("\nWarehouse (sorted):\n");
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free(warehouse->products);
  free(warehouse);

  return 0;
}

// Function definitions

// Creates a warehouse with a given capacity
Warehouse *create_warehouse(int capacity) {
  Warehouse *warehouse = (Warehouse *)malloc(sizeof(Warehouse));
  warehouse->products = (Product *)malloc(capacity * sizeof(Product));
  warehouse->capacity = capacity;
  warehouse->count = 0;
  return warehouse;
}

// Adds a product to the warehouse
void add_product(Warehouse *warehouse, Product product) {
  if (warehouse->count == warehouse->capacity) {
    printf("Warehouse is full!\n");
    return;
  }
  warehouse->products[warehouse->count] = product;
  warehouse->count++;
}

// Removes a product from the warehouse by name
void remove_product(Warehouse *warehouse, char *name) {
  int i;
  for (i = 0; i < warehouse->count; i++) {
    if (strcmp(warehouse->products[i].name, name) == 0) {
      warehouse->products[i] = warehouse->products[warehouse->count - 1];
      warehouse->count--;
      return;
    }
  }
  printf("Product not found!\n");
}

// Prints the warehouse
void print_warehouse(Warehouse *warehouse) {
  int i;
  for (i = 0; i < warehouse->count; i++) {
    printf("%s (%d, %.2f)\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
  }
}

// Sorts the warehouse by product name
void sort_warehouse(Warehouse *warehouse) {
  int i, j;
  for (i = 0; i < warehouse->count - 1; i++) {
    for (j = i + 1; j < warehouse->count; j++) {
      if (strcmp(warehouse->products[i].name, warehouse->products[j].name) > 0) {
        Product temp = warehouse->products[i];
        warehouse->products[i] = warehouse->products[j];
        warehouse->products[j] = temp;
      }
    }
  }
}