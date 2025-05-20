//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
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
Warehouse *create_warehouse() {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse *warehouse, Item item) {
  if (warehouse->num_items < MAX_ITEMS) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
  } else {
    printf("Error: Warehouse is full\n");
  }
}

// Remove an item from the warehouse
void remove_item(Warehouse *warehouse, char *name) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
      warehouse->num_items--;
      return;
    }
  }
  printf("Error: Item not found\n");
}

// Print the contents of the warehouse
void print_warehouse(Warehouse *warehouse) {
  printf("Warehouse contents:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("%s %d %f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

// Free the memory allocated for the warehouse
void free_warehouse(Warehouse *warehouse) {
  free(warehouse);
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse *warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {"Item 1", 10, 10.0};
  add_item(warehouse, item1);
  Item item2 = {"Item 2", 20, 20.0};
  add_item(warehouse, item2);
  Item item3 = {"Item 3", 30, 30.0};
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Remove an item from the warehouse
  remove_item(warehouse, "Item 2");

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free_warehouse(warehouse);

  return 0;
}