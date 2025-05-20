//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
  int id;
  char name[50];
  int quantity;
  float price;
} product;

// Function to create a new product
product* create_product(int id, char name[], int quantity, float price) {
  product* new_product = malloc(sizeof(product));
  new_product->id = id;
  strcpy(new_product->name, name);
  new_product->quantity = quantity;
  new_product->price = price;
  return new_product;
}

// Function to add a product to the inventory
void add_product(product* inventory[], int* size, product* new_product) {
  inventory[*size] = new_product;
  (*size)++;
}

// Function to remove a product from the inventory
void remove_product(product* inventory[], int* size, int id) {
  int index = -1;
  for (int i = 0; i < *size; i++) {
    if (inventory[i]->id == id) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    for (int i = index + 1; i < *size; i++) {
      inventory[i - 1] = inventory[i];
    }
    (*size)--;
  }
}

// Function to update a product in the inventory
void update_product(product* inventory[], int size, int id, char name[], int quantity, float price) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (inventory[i]->id == id) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    strcpy(inventory[index]->name, name);
    inventory[index]->quantity = quantity;
    inventory[index]->price = price;
  }
}

// Function to search for a product in the inventory
product* search_product(product* inventory[], int size, int id) {
  for (int i = 0; i < size; i++) {
    if (inventory[i]->id == id) {
      return inventory[i];
    }
  }
  return NULL;
}

// Function to print the inventory
void print_inventory(product* inventory[], int size) {
  printf("Product Inventory:\n");
  printf("-----------------------------------------------------------------------------------------\n");
  printf("| %-10s | %-20s | %-10s | %-10s | %-10s |\n", "Product ID", "Product Name", "Quantity", "Price", "Total Value");
  printf("-----------------------------------------------------------------------------------------\n");
  for (int i = 0; i < size; i++) {
    printf("| %-10d | %-20s | %-10d | %-10.2f | %-10.2f |\n", inventory[i]->id, inventory[i]->name, inventory[i]->quantity, inventory[i]->price, (inventory[i]->quantity * inventory[i]->price));
  }
  printf("-----------------------------------------------------------------------------------------\n");
}

int main() {
  // Create the inventory
  product* inventory[100];
  int size = 0;

  // Add some products to the inventory
  add_product(inventory, &size, create_product(1, "Apple", 100, 1.0));
  add_product(inventory, &size, create_product(2, "Orange", 50, 2.0));
  add_product(inventory, &size, create_product(3, "Banana", 75, 1.5));

  // Print the inventory
  print_inventory(inventory, size);

  // Search for a product in the inventory
  product* product = search_product(inventory, size, 2);

  // Update the product's quantity
  update_product(inventory, size, product->id, product->name, 100, product->price);

  // Print the updated inventory
  print_inventory(inventory, size);

  // Remove the product from the inventory
  remove_product(inventory, &size, product->id);

  // Print the updated inventory
  print_inventory(inventory, size);

  return 0;
}