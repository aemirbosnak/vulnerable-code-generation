//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct Item {
  int id;
  char name[50];
  int quantity;
  float price;
} Item;

// Define the structure of the warehouse
typedef struct Warehouse {
  Item items[MAX_ITEMS];
  int num_items;
} Warehouse;

// Create a new warehouse
Warehouse* create_warehouse() {
  Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
  if (warehouse->num_items < MAX_ITEMS) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
  } else {
    printf("Error: Warehouse is full!\n");
  }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, int id) {
  int index = -1;
  for (int i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      index = i;
      break;
    }
  }

  if (index != -1) {
    for (int i = index; i < warehouse->num_items - 1; i++) {
      warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->num_items--;
  } else {
    printf("Error: Item not found!\n");
  }
}

// Find an item in the warehouse
Item* find_item(Warehouse* warehouse, int id) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      return &warehouse->items[i];
    }
  }
  return NULL;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
  printf("Warehouse Contents:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("Item %d: %s, Quantity: %d, Price: %.2f\n",
           warehouse->items[i].id,
           warehouse->items[i].name,
           warehouse->items[i].quantity,
           warehouse->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse* warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {1, "Item 1", 10, 10.00};
  Item item2 = {2, "Item 2", 20, 20.00};
  Item item3 = {3, "Item 3", 30, 30.00};
  add_item(warehouse, item1);
  add_item(warehouse, item2);
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Find an item in the warehouse
  Item* item = find_item(warehouse, 2);
  if (item != NULL) {
    printf("Item found: %s, Quantity: %d, Price: %.2f\n",
           item->name,
           item->quantity,
           item->price);
  } else {
    printf("Item not found!\n");
  }

  // Remove an item from the warehouse
  remove_item(warehouse, 2);

  // Print the contents of the warehouse again
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free(warehouse);

  return 0;
}