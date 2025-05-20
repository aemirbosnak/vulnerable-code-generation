//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Define the structure of an item
typedef struct {
  int id;
  char name[MAX_STRING_LENGTH];
  int quantity;
  float price;
} Item;

// Define the structure of the store
typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
} Store;

// Function to create a new store
Store *create_store() {
  Store *store = malloc(sizeof(Store));
  store->num_items = 0;
  return store;
}

// Function to add an item to the store
void add_item(Store *store, Item item) {
  store->items[store->num_items] = item;
  store->num_items++;
}

// Function to find an item in the store by its ID
Item *find_item_by_id(Store *store, int id) {
  for (int i = 0; i < store->num_items; i++) {
    if (store->items[i].id == id) {
      return &store->items[i];
    }
  }
  return NULL;
}

// Function to delete an item from the store by its ID
void delete_item_by_id(Store *store, int id) {
  for (int i = 0; i < store->num_items; i++) {
    if (store->items[i].id == id) {
      for (int j = i; j < store->num_items - 1; j++) {
        store->items[j] = store->items[j + 1];
      }
      store->num_items--;
      break;
    }
  }
}

// Function to print the store's inventory
void print_inventory(Store *store) {
  for (int i = 0; i < store->num_items; i++) {
    printf("Item %d: %s, quantity: %d, price: %f\n",
           store->items[i].id, store->items[i].name,
           store->items[i].quantity, store->items[i].price);
  }
}

// Main function
int main() {
  // Create a new store
  Store *store = create_store();

  // Add some items to the store
  Item item1 = {1, "Paracetamol", 100, 10.0};
  add_item(store, item1);

  Item item2 = {2, "Ibuprofen", 50, 15.0};
  add_item(store, item2);

  Item item3 = {3, "Aspirin", 25, 5.0};
  add_item(store, item3);

  // Print the store's inventory
  print_inventory(store);

  // Find an item in the store by its ID
  Item *item = find_item_by_id(store, 2);
  if (item != NULL) {
    printf("Found item %d: %s, quantity: %d, price: %f\n",
           item->id, item->name, item->quantity, item->price);
  } else {
    printf("Item not found\n");
  }

  // Delete an item from the store by its ID
  delete_item_by_id(store, 3);

  // Print the store's inventory again
  print_inventory(store);

  // Free the memory allocated for the store
  free(store);

  return 0;
}