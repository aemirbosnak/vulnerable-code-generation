//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct {
  int id;                 // The unique ID of the item
  char *name;             // The name of the item
  int quantity;           // The quantity of the item in stock
  double price;            // The price of the item
} Item;

// Define the structure of the warehouse
typedef struct {
  Item items[MAX_ITEMS];  // The array of items in the warehouse
  int num_items;          // The number of items in the warehouse
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
  if (warehouse->num_items < MAX_ITEMS) {
    warehouse->items[warehouse->num_items++] = *item;
  } else {
    printf("Error: The warehouse is full!\n");
  }
}

// Remove an item from the warehouse
void remove_item(Warehouse *warehouse, int id) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
      warehouse->num_items--;
      return;
    }
  }

  printf("Error: The item with the given ID does not exist!\n");
}

// Print the contents of the warehouse
void print_warehouse(Warehouse *warehouse) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    printf("Item %d: %s, Quantity: %d, Price: %.2f\n", warehouse->items[i].id,
           warehouse->items[i].name, warehouse->items[i].quantity,
           warehouse->items[i].price);
  }
}

// Search for an item in the warehouse
Item *search_item(Warehouse *warehouse, int id) {
  int i;
  for (i = 0; i < warehouse->num_items; i++) {
    if (warehouse->items[i].id == id) {
      return &warehouse->items[i];
    }
  }

  return NULL;
}

// Update the quantity of an item in the warehouse
void update_quantity(Warehouse *warehouse, int id, int new_quantity) {
  Item *item = search_item(warehouse, id);
  if (item != NULL) {
    item->quantity = new_quantity;
  } else {
    printf("Error: The item with the given ID does not exist!\n");
  }
}

// Calculate the total value of the items in the warehouse
double calculate_total_value(Warehouse *warehouse) {
  int i;
  double total_value = 0.0;
  for (i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->items[i].quantity * warehouse->items[i].price;
  }

  return total_value;
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse *warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {1, "iPhone", 10, 999.99};
  add_item(warehouse, &item1);

  Item item2 = {2, "MacBook Pro", 5, 1299.99};
  add_item(warehouse, &item2);

  Item item3 = {3, "Apple Watch", 15, 399.99};
  add_item(warehouse, &item3);

  // Print the contents of the warehouse
  printf("The warehouse contains the following items:\n");
  print_warehouse(warehouse);

  // Search for an item in the warehouse
  Item *item = search_item(warehouse, 2);
  if (item != NULL) {
    printf("Found item: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity,
           item->price);
  } else {
    printf("Item not found!\n");
  }

  // Update the quantity of an item in the warehouse
  update_quantity(warehouse, 1, 15);
  printf("Updated the quantity of iPhone to 15.\n");

  // Calculate the total value of the items in the warehouse
  double total_value = calculate_total_value(warehouse);
  printf("The total value of the items in the warehouse is: %.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(warehouse, 3);
  printf("Removed Apple Watch from the warehouse.\n");

  // Print the contents of the warehouse again
  printf("The warehouse now contains the following items:\n");
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free(warehouse);

  return 0;
}