//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Item represents a single item in the warehouse.
typedef struct Item {
  char name[MAX_NAME_LENGTH];
  int quantity;
  float price;
} Item;

// Warehouse represents the entire inventory of items.
typedef struct Warehouse {
  Item items[MAX_ITEMS];
  int num_items;
} Warehouse;

// Creates a new warehouse with no items.
Warehouse* create_warehouse() {
  Warehouse* warehouse = malloc(sizeof(Warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

// Adds an item to the warehouse.
void add_item(Warehouse* warehouse, Item item) {
  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
}

// Finds an item in the warehouse by name.
Item* find_item(Warehouse* warehouse, char* name) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      return &warehouse->items[i];
    }
  }
  return NULL;
}

// Prints the inventory of the warehouse.
void print_inventory(Warehouse* warehouse) {
  printf("Inventory:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("  %s (%d, $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

// Main function.
int main() {
  // Create a new warehouse.
  Warehouse* warehouse = create_warehouse();

  // Add some items to the warehouse.
  Item item1 = {"Widget", 10, 5.00};
  add_item(warehouse, item1);
  Item item2 = {"Cog", 25, 2.50};
  add_item(warehouse, item2);

  // Print the inventory of the warehouse.
  print_inventory(warehouse);

  // Find an item in the warehouse by name.
  Item* item = find_item(warehouse, "Widget");
  if (item != NULL) {
    printf("Found item: %s (%d, $%.2f)\n", item->name, item->quantity, item->price);
  } else {
    printf("Item not found.\n");
  }

  // Free the memory used by the warehouse.
  free(warehouse);

  return 0;
}