//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct Item {
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
    printf("The warehouse is full!\n");
  }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      for (int j = i; j < warehouse->num_items - 1; j++) {
        warehouse->items[j] = warehouse->items[j + 1];
      }
      warehouse->num_items--;
      break;
    }
  }
}

// Get the total value of the items in the warehouse
float get_total_value(Warehouse* warehouse) {
  float total_value = 0;
  for (int i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->items[i].quantity * warehouse->items[i].price;
  }
  return total_value;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
  printf("Warehouse Contents:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("%s: %d @ $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
  printf("Total Value: $%.2f\n", get_total_value(warehouse));
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse* warehouse = create_warehouse();

  // Add some items to the warehouse
  Item item1 = {"Apples", 10, 1.50};
  add_item(warehouse, item1);
  Item item2 = {"Bananas", 20, 2.00};
  add_item(warehouse, item2);
  Item item3 = {"Oranges", 30, 3.00};
  add_item(warehouse, item3);

  // Remove an item from the warehouse
  remove_item(warehouse, "Bananas");

  // Print the contents of the warehouse
  print_warehouse(warehouse);

  // Free the memory allocated for the warehouse
  free(warehouse);

  return 0;
}