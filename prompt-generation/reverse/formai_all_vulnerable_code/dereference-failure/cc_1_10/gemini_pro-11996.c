//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct Item {
  int id;
  char name[100];
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
  Warehouse* warehouse = malloc(sizeof(Warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
  if (warehouse->num_items < MAX_ITEMS) {
    warehouse->items[warehouse->num_items++] = item;
  } else {
    printf("The warehouse is full!\n");
  }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, int id) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      warehouse->num_items--;
      warehouse->items[i] = warehouse->items[warehouse->num_items];
      break;
    }
  }
}

// Get the total value of the items in the warehouse
float get_total_value(Warehouse* warehouse) {
  int i;
  float total_value = 0;
  for (i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->items[i].price * warehouse->items[i].quantity;
  }
  return total_value;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
  int i;
  printf("The warehouse contains the following items:\n");
  for (i = 0; i < warehouse->num_items; i++) {
    printf("Item %d:\n", warehouse->items[i].id);
    printf("  Name: %s\n", warehouse->items[i].name);
    printf("  Quantity: %d\n", warehouse->items[i].quantity);
    printf("  Price: %.2f\n", warehouse->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse* warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {1, "Item 1", 10, 10.0};
  add_item(warehouse, item1);
  Item item2 = {2, "Item 2", 20, 20.0};
  add_item(warehouse, item2);
  Item item3 = {3, "Item 3", 30, 30.0};
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Get the total value of the items in the warehouse
  float total_value = get_total_value(warehouse);
  printf("The total value of the items in the warehouse is: %.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(warehouse, 2);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free(warehouse);

  return 0;
}