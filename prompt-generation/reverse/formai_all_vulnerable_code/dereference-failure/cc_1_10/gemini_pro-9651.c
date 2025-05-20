//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the system
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
  int id;
  char name[50];
  float price;
  int quantity;
} product;

// Define the structure of the medical store
typedef struct medical_store {
  product products[MAX_PRODUCTS];
  int num_products;
} medical_store;

// Function to create a new medical store
medical_store* create_medical_store() {
  medical_store* store = (medical_store*)malloc(sizeof(medical_store));
  store->num_products = 0;
  return store;
}

// Function to add a new product to the medical store
void add_product(medical_store* store, product product) {
  // Check if the store is full
  if (store->num_products == MAX_PRODUCTS) {
    printf("Error: The medical store is full. Cannot add more products.\n");
    return;
  }

  // Add the product to the store
  store->products[store->num_products] = product;
  store->num_products++;
}

// Function to search for a product in the medical store by name
product* search_product_by_name(medical_store* store, char* name) {
  for (int i = 0; i < store->num_products; i++) {
    if (strcmp(store->products[i].name, name) == 0) {
      return &store->products[i];
    }
  }

  return NULL;
}

// Function to search for a product in the medical store by ID
product* search_product_by_id(medical_store* store, int id) {
  for (int i = 0; i < store->num_products; i++) {
    if (store->products[i].id == id) {
      return &store->products[i];
    }
  }

  return NULL;
}

// Function to sell a product from the medical store
void sell_product(medical_store* store, product* product, int quantity) {
  // Check if the product is in stock
  if (product->quantity < quantity) {
    printf("Error: The product is out of stock. Cannot sell %d units.\n", quantity);
    return;
  }

  // Sell the product
  product->quantity -= quantity;
}

// Function to print the list of products in the medical store
void print_products(medical_store* store) {
  printf("Products in the medical store:\n");
  for (int i = 0; i < store->num_products; i++) {
    printf("%d. %s (%.2f, %d units)\n", store->products[i].id, store->products[i].name, store->products[i].price, store->products[i].quantity);
  }
}

// Main function
int main() {
  // Create a new medical store
  medical_store* store = create_medical_store();

  // Add some products to the store
  product product1 = {1, "Paracetamol", 10.0, 100};
  add_product(store, product1);

  product product2 = {2, "Ibuprofen", 15.0, 50};
  add_product(store, product2);

  product product3 = {3, "Aspirin", 5.0, 200};
  add_product(store, product3);

  // Search for a product by name
  product* product = search_product_by_name(store, "Paracetamol");
  if (product != NULL) {
    printf("Found product by name: %s (%.2f, %d units)\n", product->name, product->price, product->quantity);
  } else {
    printf("Product not found.\n");
  }

  // Search for a product by ID
  product = search_product_by_id(store, 2);
  if (product != NULL) {
    printf("Found product by ID: %s (%.2f, %d units)\n", product->name, product->price, product->quantity);
  } else {
    printf("Product not found.\n");
  }

  // Sell a product
  sell_product(store, product, 20);
  printf("Product sold: %s (%.2f, %d units)\n", product->name, product->price, product->quantity);

  // Print the list of products in the store
  print_products(store);

  return 0;
}