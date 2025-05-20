//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a warehouse item
typedef struct {
  int id;
  char *name;
  int quantity;
  float price;
} Item;

// Define the structure of a warehouse
typedef struct {
  Item *items;
  int num_items;
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  warehouse->items = NULL;
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to a warehouse
void add_item(Warehouse *warehouse, Item item) {
  warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
}

// Find an item in a warehouse by its ID
Item *find_item_by_id(Warehouse *warehouse, int id) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      return &warehouse->items[i];
    }
  }
  return NULL;
}

// Print the contents of a warehouse
void print_warehouse(Warehouse *warehouse) {
  printf("Warehouse contains:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("Item %d: %s, quantity: %d, price: %f\n",
      warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

// Free the memory allocated for a warehouse
void free_warehouse(Warehouse *warehouse) {
  if (warehouse->items != NULL) {
    free(warehouse->items);
  }
  free(warehouse);
}

int main() {
  // Create a new warehouse
  Warehouse *warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {1, "Item 1", 10, 10.0f};
  add_item(warehouse, item1);
  Item item2 = {2, "Item 2", 20, 20.0f};
  add_item(warehouse, item2);
  Item item3 = {3, "Item 3", 30, 30.0f};
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Find an item in the warehouse by its ID
  Item *item = find_item_by_id(warehouse, 2);
  if (item != NULL) {
    printf("Found item: %s, quantity: %d, price: %f\n",
      item->name, item->quantity, item->price);
  } else {
    printf("Item not found.\n");
  }

  // Free the memory allocated for the warehouse
  free_warehouse(warehouse);

  return 0;
}