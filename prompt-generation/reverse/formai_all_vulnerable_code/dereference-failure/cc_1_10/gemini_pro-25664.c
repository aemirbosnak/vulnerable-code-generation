//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the structure of an item
typedef struct item {
  char name[MAX_NAME_LENGTH];
  int quantity;
  float price;
} item;

// Define the structure of the warehouse
typedef struct warehouse {
  item items[MAX_ITEMS];
  int num_items;
} warehouse;

// Create a new warehouse
warehouse* create_warehouse() {
  warehouse* w = malloc(sizeof(warehouse));
  w->num_items = 0;
  return w;
}

// Add an item to the warehouse
void add_item(warehouse* w, item* i) {
  if (w->num_items >= MAX_ITEMS) {
    printf("Error: Warehouse is full.\n");
    return;
  }
  w->items[w->num_items++] = *i;
}

// Remove an item from the warehouse
void remove_item(warehouse* w, char* name) {
  int i;
  for (i = 0; i < w->num_items; i++) {
    if (strcmp(w->items[i].name, name) == 0) {
      break;
    }
  }
  if (i == w->num_items) {
    printf("Error: Item not found.\n");
    return;
  }
  for (; i < w->num_items - 1; i++) {
    w->items[i] = w->items[i + 1];
  }
  w->num_items--;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
  int i;
  printf("Warehouse contents:\n");
  for (i = 0; i < w->num_items; i++) {
    printf("%s: %d, $%.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
  }
}

// Free the memory allocated for the warehouse
void free_warehouse(warehouse* w) {
  free(w);
}

// Main function
int main() {
  // Create a new warehouse
  warehouse* w = create_warehouse();

  // Add some items to the warehouse
  item item1 = {"Item 1", 10, 10.00};
  add_item(w, &item1);
  item item2 = {"Item 2", 20, 20.00};
  add_item(w, &item2);
  item item3 = {"Item 3", 30, 30.00};
  add_item(w, &item3);

  // Print the contents of the warehouse
  print_warehouse(w);

  // Remove an item from the warehouse
  remove_item(w, "Item 2");

  // Print the contents of the warehouse again
  print_warehouse(w);

  // Free the memory allocated for the warehouse
  free_warehouse(w);

  return 0;
}