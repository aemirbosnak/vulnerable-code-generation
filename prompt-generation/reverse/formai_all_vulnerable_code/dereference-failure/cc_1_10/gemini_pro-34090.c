//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct {
  int id;
  char name[50];
  float price;
  int quantity;
} Item;

// Define the structure of the store
typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
} Store;

// Create a new store
Store *create_store() {
  Store *store = malloc(sizeof(Store));
  store->num_items = 0;
  return store;
}

// Add an item to the store
void add_item(Store *store, Item item) {
  if (store->num_items < MAX_ITEMS) {
    store->items[store->num_items] = item;
    store->num_items++;
  } else {
    printf("Error: The store is full.\n");
  }
}

// Find an item in the store by its ID
Item *find_item_by_id(Store *store, int id) {
  for (int i = 0; i < store->num_items; i++) {
    if (store->items[i].id == id) {
      return &store->items[i];
    }
  }
  return NULL;
}

// Find an item in the store by its name
Item *find_item_by_name(Store *store, char *name) {
  for (int i = 0; i < store->num_items; i++) {
    if (strcmp(store->items[i].name, name) == 0) {
      return &store->items[i];
    }
  }
  return NULL;
}

// Print the inventory of the store
void print_inventory(Store *store) {
  printf("Inventory:\n");
  for (int i = 0; i < store->num_items; i++) {
    printf("%d %s %.2f %d\n", store->items[i].id, store->items[i].name, store->items[i].price, store->items[i].quantity);
  }
}

// Main function
int main() {
  // Create a new store
  Store *store = create_store();

  // Add some items to the store
  Item item1 = {1, "Aspirin", 0.99, 100};
  add_item(store, item1);
  Item item2 = {2, "Ibuprofen", 1.99, 50};
  add_item(store, item2);
  Item item3 = {3, "Acetaminophen", 0.99, 100};
  add_item(store, item3);

  // Print the inventory of the store
  print_inventory(store);

  // Find an item in the store by its ID
  Item *item = find_item_by_id(store, 2);
  if (item != NULL) {
    printf("Found item: %d %s %.2f %d\n", item->id, item->name, item->price, item->quantity);
  } else {
    printf("Error: Item not found.\n");
  }

  // Find an item in the store by its name
  item = find_item_by_name(store, "Ibuprofen");
  if (item != NULL) {
    printf("Found item: %d %s %.2f %d\n", item->id, item->name, item->price, item->quantity);
  } else {
    printf("Error: Item not found.\n");
  }

  return 0;
}