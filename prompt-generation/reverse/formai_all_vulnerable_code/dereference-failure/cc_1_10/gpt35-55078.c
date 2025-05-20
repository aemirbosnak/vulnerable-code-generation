//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing information of an item
struct Item {
  char name[100];
  int quantity;
  char location[100];
};

// Initialize the warehouse 
int warehouse_capacity = 1000;
struct Item* warehouse = NULL;

// Function for adding an item to the warehouse
void add_item(char name[100], int quantity, char location[100]) {
  // Check if warehouse is full
  if (sizeof(warehouse) / sizeof(warehouse[0]) >= warehouse_capacity) {
    printf("Warehouse is full. Cannot add item %s\n", name);
    return;
  }

  // Create a new item
  struct Item* new_item = (struct Item*) malloc(sizeof(struct Item));
  strncpy(new_item->name, name, 100);
  new_item->quantity = quantity;
  strncpy(new_item->location, location, 100);

  // Add item to the warehouse
  warehouse[sizeof(warehouse) / sizeof(warehouse[0])] = *new_item;

  // Print success message
  printf("Item %s added to warehouse at location %s\n", name, location);
}

// Function for removing an item from the warehouse
void remove_item(char name[100]) {
  // Search for the item in the warehouse
  int index = -1;
  for (int i = 0; i < sizeof(warehouse) / sizeof(warehouse[0]); i++) {
    if (strcmp(warehouse[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // Check if item was found
  if (index == -1) {
    printf("Item %s not found in warehouse\n", name);
    return;
  }

  // Remove item from warehouse and shift remaining items forward
  for (int i = index; i < sizeof(warehouse) / sizeof(warehouse[0]) - 1; i++) {
    warehouse[i] = warehouse[i + 1];
  }

  // Print success message
  printf("Item %s removed from warehouse\n", name);
}

int main() {

  // Dynamically allocate memory for the warehouse array
  warehouse = (struct Item*) malloc(warehouse_capacity * sizeof(struct Item));

  // Add some items to the warehouse
  add_item("Pencil", 500, "A1");
  add_item("Pen", 250, "B2");
  add_item("Eraser", 100, "C3");

  // Remove an item from the warehouse
  remove_item("Pen");

  // Add some more items to the warehouse
  add_item("Marker", 300, "D4");
  add_item("Highlighter", 150, "E5");

  // Remove an item that doesn't exist in the warehouse
  remove_item("Stapler");

  // Free the dynamically allocated memory
  free(warehouse);

  return 0;
}