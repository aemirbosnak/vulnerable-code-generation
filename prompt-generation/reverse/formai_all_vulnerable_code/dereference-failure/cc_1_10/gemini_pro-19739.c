//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct {
  char name[50];
  int quantity;
  float price;
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
  // Check if the warehouse is full
  if (warehouse->num_items >= MAX_ITEMS) {
    printf("Warehouse is full!\n");
    return;
  }

  // Add the item to the warehouse
  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
  // Find the item in the warehouse
  int index = -1;
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // Check if the item was found
  if (index == -1) {
    printf("Item not found!\n");
    return;
  }

  // Remove the item from the warehouse
  for (int i = index; i < warehouse->num_items - 1; i++) {
    warehouse->items[i] = warehouse->items[i + 1];
  }

  warehouse->num_items--;
}

// Get the total value of the warehouse
float get_total_value(Warehouse* warehouse) {
  float total_value = 0;
  for (int i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->items[i].quantity * warehouse->items[i].price;
  }
  return total_value;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
  printf("Warehouse contents:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("  - %s (%d, $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse* warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {"Item 1", 10, 10.0};
  add_item(warehouse, item1);
  Item item2 = {"Item 2", 20, 20.0};
  add_item(warehouse, item2);
  Item item3 = {"Item 3", 30, 30.0};
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Get the total value of the warehouse
  float total_value = get_total_value(warehouse);
  printf("Total value of the warehouse: $%.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(warehouse, "Item 2");

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Get the total value of the warehouse
  total_value = get_total_value(warehouse);
  printf("Total value of the warehouse: $%.2f\n", total_value);

  // Free the memory allocated for the warehouse
  free(warehouse);

  return 0;
}