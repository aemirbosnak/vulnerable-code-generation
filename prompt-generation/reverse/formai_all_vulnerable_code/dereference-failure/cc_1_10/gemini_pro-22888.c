//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse.
#define MAX_ITEMS 100

// Define the structure of an item.
typedef struct {
  char *name;
  int quantity;
} item;

// Define the structure of the warehouse.
typedef struct {
  item items[MAX_ITEMS];
  int num_items;
} warehouse;

// Create a new warehouse.
warehouse *create_warehouse() {
  warehouse *w = malloc(sizeof(warehouse));
  w->num_items = 0;
  return w;
}

// Add an item to the warehouse.
void add_item(warehouse *w, item *i) {
  if (w->num_items < MAX_ITEMS) {
    w->items[w->num_items] = *i;
    w->num_items++;
  } else {
    printf("Error: Warehouse is full.\n");
  }
}

// Remove an item from the warehouse.
void remove_item(warehouse *w, char *name) {
  int i;
  for (i = 0; i < w->num_items; i++) {
    if (strcmp(w->items[i].name, name) == 0) {
      w->items[i] = w->items[w->num_items - 1];
      w->num_items--;
      return;
    }
  }
  printf("Error: Item not found.\n");
}

// Print the contents of the warehouse.
void print_warehouse(warehouse *w) {
  int i;
  for (i = 0; i < w->num_items; i++) {
    printf("%s: %d\n", w->items[i].name, w->items[i].quantity);
  }
}

// Free the memory allocated for the warehouse.
void free_warehouse(warehouse *w) {
  int i;
  for (i = 0; i < w->num_items; i++) {
    free(w->items[i].name);
  }
  free(w);
}

// The main function.
int main() {
  // Create a new warehouse.
  warehouse *w = create_warehouse();

  // Add some items to the warehouse.
  item i1 = {"Item 1", 10};
  add_item(w, &i1);
  item i2 = {"Item 2", 20};
  add_item(w, &i2);
  item i3 = {"Item 3", 30};
  add_item(w, &i3);

  // Print the contents of the warehouse.
  print_warehouse(w);

  // Remove an item from the warehouse.
  remove_item(w, "Item 2");

  // Print the contents of the warehouse.
  print_warehouse(w);

  // Free the memory allocated for the warehouse.
  free_warehouse(w);

  return 0;
}