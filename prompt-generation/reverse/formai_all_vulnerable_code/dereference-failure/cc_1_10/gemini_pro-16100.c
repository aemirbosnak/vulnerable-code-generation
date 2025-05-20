//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 50

// Define the structure of an item
typedef struct {
  int id;
  char *name;
  int quantity;
  float price;
} Item;

// Define the structure of the warehouse
typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
bool add_item(Warehouse *warehouse, Item item) {
  if (warehouse->num_items >= MAX_ITEMS) {
    return false;
  }
  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
  return true;
}

// Remove an item from the warehouse
bool remove_item(Warehouse *warehouse, int id) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
      warehouse->num_items--;
      return true;
    }
  }
  return false;
}

// Get the total value of the items in the warehouse
float get_total_value(Warehouse *warehouse) {
  float total_value = 0;
  for (int i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->items[i].price * warehouse->items[i].quantity;
  }
  return total_value;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse *warehouse) {
  printf("ID\tName\tQuantity\tPrice\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("%d\t%s\t%d\t%.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

// Free the memory allocated for the warehouse
void destroy_warehouse(Warehouse *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    free(warehouse->items[i].name);
  }
  free(warehouse);
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse *warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {1, "Item 1", 10, 10.0};
  add_item(warehouse, item1);
  Item item2 = {2, "Item 2", 20, 15.0};
  add_item(warehouse, item2);
  Item item3 = {3, "Item 3", 30, 20.0};
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Get the total value of the items in the warehouse
  float total_value = get_total_value(warehouse);
  printf("Total value: %.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(warehouse, 2);

  // Print the contents of the warehouse again
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  destroy_warehouse(warehouse);

  return 0;
}