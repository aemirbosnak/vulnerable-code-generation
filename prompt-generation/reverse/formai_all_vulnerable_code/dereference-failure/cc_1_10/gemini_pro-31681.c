//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the store
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
  char name[50];
  int quantity;
  float price;
} Product;

// Define the structure of the store
typedef struct {
  Product products[MAX_PRODUCTS];
  int num_products;
} Store;

// Create a new store
Store* create_store() {
  Store* store = malloc(sizeof(Store));
  store->num_products = 0;
  return store;
}

// Add a product to the store
void add_product(Store* store, Product product) {
  if (store->num_products >= MAX_PRODUCTS) {
    printf("Error: The store is full!\n");
    return;
  }

  store->products[store->num_products] = product;
  store->num_products++;
}

// Remove a product from the store
void remove_product(Store* store, char* name) {
  int i;
  for (i = 0; i < store->num_products; i++) {
    if (strcmp(store->products[i].name, name) == 0) {
      break;
    }
  }

  if (i == store->num_products) {
    printf("Error: The product does not exist!\n");
    return;
  }

  for (i = i + 1; i < store->num_products; i++) {
    store->products[i - 1] = store->products[i];
  }

  store->num_products--;
}

// Print the products in the store
void print_products(Store* store) {
  int i;
  for (i = 0; i < store->num_products; i++) {
    printf("%s %d %.2f\n", store->products[i].name, store->products[i].quantity, store->products[i].price);
  }
}

// Free the memory allocated for the store
void free_store(Store* store) {
  free(store);
}

// Main function
int main() {
  // Create a new store
  Store* store = create_store();

  // Add some products to the store
  Product product1 = {"Aspirin", 100, 0.50};
  add_product(store, product1);
  Product product2 = {"Ibuprofen", 50, 1.00};
  add_product(store, product2);
  Product product3 = {"Acetaminophen", 75, 0.75};
  add_product(store, product3);

  // Print the products in the store
  printf("Products in the store:\n");
  print_products(store);

  // Remove a product from the store
  remove_product(store, "Ibuprofen");

  // Print the products in the store
  printf("Products in the store after removing Ibuprofen:\n");
  print_products(store);

  // Free the memory allocated for the store
  free_store(store);

  return 0;
}