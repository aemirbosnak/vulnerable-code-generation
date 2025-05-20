//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct item {
  char name[50];
  int quantity;
  float price;
} item_t;

// Define the structure of the warehouse
typedef struct warehouse {
  item_t items[MAX_ITEMS];
  int num_items;
} warehouse_t;

// Create a new warehouse
warehouse_t *create_warehouse() {
  warehouse_t *warehouse = malloc(sizeof(warehouse_t));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
void add_item(warehouse_t *warehouse, item_t item) {
  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
}

// Remove an item from the warehouse
void remove_item(warehouse_t *warehouse, char *name) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      warehouse->num_items--;
      warehouse->items[i] = warehouse->items[warehouse->num_items];
      break;
    }
  }
}

// Find an item in the warehouse
item_t *find_item(warehouse_t *warehouse, char *name) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      return &warehouse->items[i];
    }
  }
  return NULL;
}

// Print the contents of the warehouse
void print_warehouse(warehouse_t *warehouse) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    printf("%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse_t *warehouse = create_warehouse();

  // Add some items to the warehouse
  item_t item1 = {"Apple", 10, 1.00};
  item_t item2 = {"Banana", 20, 1.50};
  item_t item3 = {"Orange", 30, 2.00};
  add_item(warehouse, item1);
  add_item(warehouse, item2);
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  printf("Contents of the warehouse:\n");
  print_warehouse(warehouse);

  // Find an item in the warehouse
  item_t *item = find_item(warehouse, "Banana");
  if (item != NULL) {
    printf("Found item: %s %d %.2f\n", item->name, item->quantity, item->price);
  } else {
    printf("Item not found.\n");
  }

  // Remove an item from the warehouse
  remove_item(warehouse, "Orange");

  // Print the contents of the warehouse
  printf("Contents of the warehouse after removing Orange:\n");
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free(warehouse);

  return 0;
}