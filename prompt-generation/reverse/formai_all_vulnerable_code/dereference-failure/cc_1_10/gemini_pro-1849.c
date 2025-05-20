//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct {
  char name[50];
  int quantity;
  float price;
} Item;

// Define the structure of the store
typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
} Store;

// Create a new store
Store* create_store() {
  Store* store = malloc(sizeof(Store));
  store->num_items = 0;
  return store;
}

// Add an item to the store
void add_item(Store* store, Item item) {
  if (store->num_items == MAX_ITEMS) {
    printf("Error: The store is full.\n");
    return;
  }

  store->items[store->num_items] = item;
  store->num_items++;
}

// Remove an item from the store
void remove_item(Store* store, char* name) {
  // Find the item in the store
  int index = -1;
  for (int i = 0; i < store->num_items; i++) {
    if (strcmp(store->items[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // If the item was not found, print an error message
  if (index == -1) {
    printf("Error: The item was not found.\n");
    return;
  }

  // Remove the item from the store
  for (int i = index; i < store->num_items - 1; i++) {
    store->items[i] = store->items[i + 1];
  }

  store->num_items--;
}

// Print the contents of the store
void print_store(Store* store) {
  printf("Store contents:\n");
  for (int i = 0; i < store->num_items; i++) {
    printf("  %s: %d, %.2f\n", store->items[i].name, store->items[i].quantity, store->items[i].price);
  }
}

// Main function
int main() {
  // Create a new store
  Store* store = create_store();

  // Add some items to the store
  Item item1 = {"Aspirin", 100, 0.50};
  add_item(store, item1);
  Item item2 = {"Ibuprofen", 50, 0.75};
  add_item(store, item2);
  Item item3 = {"Acetaminophen", 25, 0.25};
  add_item(store, item3);

  // Print the contents of the store
  print_store(store);

  // Remove an item from the store
  remove_item(store, "Ibuprofen");

  // Print the contents of the store
  print_store(store);

  // Free the memory allocated for the store
  free(store);

  return 0;
}