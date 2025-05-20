//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct item {
  int id;
  char *name;
  int quantity;
  float price;
} item_t;

// Define the structure of the warehouse
typedef struct warehouse {
  item_t *items[MAX_ITEMS];
  int num_items;
} warehouse_t;

// Create a new warehouse
warehouse_t *create_warehouse() {
  warehouse_t *warehouse = malloc(sizeof(warehouse_t));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
void add_item(warehouse_t *warehouse, item_t *item) {
  // Check if the warehouse is full
  if (warehouse->num_items == MAX_ITEMS) {
    printf("Warehouse is full!\n");
    return;
  }

  // Add the item to the warehouse
  warehouse->items[warehouse->num_items] = item;
  warehouse->num_items++;
}

// Remove an item from the warehouse
void remove_item(warehouse_t *warehouse, int id) {
  // Find the item in the warehouse
  int index = -1;
  for (int i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i]->id == id) {
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

// Get the total value of the items in the warehouse
float get_total_value(warehouse_t *warehouse) {
  float total_value = 0;
  for (int i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->items[i]->price * warehouse->items[i]->quantity;
  }
  return total_value;
}

// Print the contents of the warehouse
void print_warehouse(warehouse_t *warehouse) {
  printf("Warehouse contents:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("Item %d:\n", warehouse->items[i]->id);
    printf("  Name: %s\n", warehouse->items[i]->name);
    printf("  Quantity: %d\n", warehouse->items[i]->quantity);
    printf("  Price: %.2f\n", warehouse->items[i]->price);
    printf("\n");
  }
}

// Free the memory allocated for the warehouse
void free_warehouse(warehouse_t *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    free(warehouse->items[i]->name);
    free(warehouse->items[i]);
  }
  free(warehouse);
}

int main() {
  // Create a new warehouse
  warehouse_t *warehouse = create_warehouse();

  // Add some items to the warehouse
  item_t *item1 = malloc(sizeof(item_t));
  item1->id = 1;
  item1->name = strdup("Item 1");
  item1->quantity = 10;
  item1->price = 10.0;
  add_item(warehouse, item1);

  item_t *item2 = malloc(sizeof(item_t));
  item2->id = 2;
  item2->name = strdup("Item 2");
  item2->quantity = 20;
  item2->price = 20.0;
  add_item(warehouse, item2);

  item_t *item3 = malloc(sizeof(item_t));
  item3->id = 3;
  item3->name = strdup("Item 3");
  item3->quantity = 30;
  item3->price = 30.0;
  add_item(warehouse, item3);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Get the total value of the items in the warehouse
  float total_value = get_total_value(warehouse);
  printf("Total value of items in warehouse: %.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(warehouse, 2);

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free_warehouse(warehouse);

  return 0;
}