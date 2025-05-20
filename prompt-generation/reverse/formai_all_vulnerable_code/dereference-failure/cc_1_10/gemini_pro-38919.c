//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
  char name[50];
  int quantity;
  float price;
} product;

// Function to create a new product
product* create_product(char* name, int quantity, float price) {
  product* p = (product*)malloc(sizeof(product));
  strcpy(p->name, name);
  p->quantity = quantity;
  p->price = price;
  return p;
}

// Function to add a product to the inventory
void add_product(product** inventory, int* size, product* p) {
  *inventory = (product*)realloc(*inventory, (*size + 1) * sizeof(product));
  (*inventory)[*size] = *p;
  *size = *size + 1;
}

// Function to find a product in the inventory
product* find_product(product** inventory, int size, char* name) {
  for (int i = 0; i < size; i++) {
    if (strcmp((*inventory)[i].name, name) == 0) {
      return &(*inventory)[i];
    }
  }
  return NULL;
}

// Function to update the quantity of a product in the inventory
void update_product(product** inventory, int size, char* name, int quantity) {
  product* p = find_product(inventory, size, name);
  if (p != NULL) {
    p->quantity = quantity;
  }
}

// Function to remove a product from the inventory
void remove_product(product** inventory, int* size, char* name) {
  int index = -1;
  for (int i = 0; i < *size; i++) {
    if (strcmp((*inventory)[i].name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    for (int i = index; i < *size - 1; i++) {
      (*inventory)[i] = (*inventory)[i + 1];
    }
    *inventory = (product*)realloc(*inventory, (*size - 1) * sizeof(product));
    *size = *size - 1;
  }
}

// Function to print the inventory
void print_inventory(product** inventory, int size) {
  printf("Inventory:\n");
  for (int i = 0; i < size; i++) {
    printf("%s %d %.2f\n", (*inventory)[i].name, (*inventory)[i].quantity,
           (*inventory)[i].price);
  }
}

// Main function
int main() {
  // Create an inventory
  product* inventory = NULL;
  int size = 0;

  // Add some products to the inventory
  add_product(&inventory, &size, create_product("Apple", 10, 1.0));
  add_product(&inventory, &size, create_product("Banana", 20, 2.0));
  add_product(&inventory, &size, create_product("Orange", 30, 3.0));

  // Print the inventory
  print_inventory(&inventory, size);

  // Find a product in the inventory
  product* p = find_product(&inventory, size, "Apple");
  if (p != NULL) {
    printf("Found product: %s %d %.2f\n", p->name, p->quantity, p->price);
  }

  // Update the quantity of a product in the inventory
  update_product(&inventory, size, "Banana", 50);

  // Print the inventory
  print_inventory(&inventory, size);

  // Remove a product from the inventory
  remove_product(&inventory, &size, "Orange");

  // Print the inventory
  print_inventory(&inventory, size);

  // Free the memory allocated for the inventory
  free(inventory);

  return 0;
}