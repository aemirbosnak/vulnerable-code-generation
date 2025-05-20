//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct {
  int id;
  char name[50];
  int quantity;
} Item;

// Define the structure of the warehouse
typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
} Warehouse;

// Create a new warehouse
Warehouse* create_warehouse() {
  Warehouse* warehouse = malloc(sizeof(Warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
  if (warehouse->num_items < MAX_ITEMS) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
  } else {
    printf("Error: Warehouse is full.\n");
  }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, int id) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
      warehouse->num_items--;
      break;
    }
  }
}

// Get the quantity of an item in the warehouse
int get_quantity(Warehouse* warehouse, int id) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      return warehouse->items[i].quantity;
    }
  }
  return 0;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
  int i;
  printf("Warehouse Contents:\n");
  for (i = 0; i < warehouse->num_items; i++) {
    printf("Item %d: %s (%d)\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
  }
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse* warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = { 1, "Apple", 10 };
  Item item2 = { 2, "Banana", 20 };
  Item item3 = { 3, "Orange", 30 };
  add_item(warehouse, item1);
  add_item(warehouse, item2);
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Get the quantity of an item in the warehouse
  int quantity = get_quantity(warehouse, 2);
  printf("Quantity of item 2: %d\n", quantity);

  // Remove an item from the warehouse
  remove_item(warehouse, 3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  return 0;
}