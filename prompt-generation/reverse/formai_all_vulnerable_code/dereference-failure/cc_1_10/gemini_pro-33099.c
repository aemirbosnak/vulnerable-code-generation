//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct {
  int id;
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
  store->items[store->num_items] = item;
  store->num_items++;
}

// Remove an item from the store
void remove_item(Store* store, int id) {
  for (int i = 0; i < store->num_items; i++) {
    if (store->items[i].id == id) {
      store->items[i] = store->items[store->num_items - 1];
      store->num_items--;
      return;
    }
  }
}

// Find an item in the store
Item* find_item(Store* store, int id) {
  for (int i = 0; i < store->num_items; i++) {
    if (store->items[i].id == id) {
      return &store->items[i];
    }
  }
  return NULL;
}

// Print the items in the store
void print_items(Store* store) {
  for (int i = 0; i < store->num_items; i++) {
    printf("Item %d: %s, %d, %f\n", store->items[i].id, store->items[i].name, store->items[i].quantity, store->items[i].price);
  }
}

// Free the memory allocated to the store
void free_store(Store* store) {
  free(store);
}

int main() {
  // Create a new store
  Store* store = create_store();

  // Add some items to the store
  Item item1 = {1, "Item 1", 10, 10.0};
  add_item(store, item1);
  Item item2 = {2, "Item 2", 20, 20.0};
  add_item(store, item2);
  Item item3 = {3, "Item 3", 30, 30.0};
  add_item(store, item3);

  // Print the items in the store
  print_items(store);

  // Find an item in the store
  Item* item = find_item(store, 2);
  if (item != NULL) {
    printf("Found item: %s, %d, %f\n", item->name, item->quantity, item->price);
  } else {
    printf("Item not found\n");
  }

  // Remove an item from the store
  remove_item(store, 2);

  // Print the items in the store
  print_items(store);

  // Free the memory allocated to the store
  free_store(store);

  return 0;
}