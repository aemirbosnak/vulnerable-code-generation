//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct item {
  int id;
  char name[50];
  int quantity;
  float price;
} item;

// Define the structure of the warehouse
typedef struct warehouse {
  item items[MAX_ITEMS];
  int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
  warehouse *w = malloc(sizeof(warehouse));
  w->num_items = 0;
  return w;
}

// Add an item to the warehouse
void add_item(warehouse *w, item *i) {
  w->items[w->num_items++] = *i;
}

// Remove an item from the warehouse
void remove_item(warehouse *w, int id) {
  for (int i = 0; i < w->num_items; i++) {
    if (w->items[i].id == id) {
      w->items[i] = w->items[w->num_items - 1];
      w->num_items--;
      break;
    }
  }
}

// Get the total value of the warehouse
float get_total_value(warehouse *w) {
  float total_value = 0;
  for (int i = 0; i < w->num_items; i++) {
    total_value += w->items[i].quantity * w->items[i].price;
  }
  return total_value;
}

// Print the warehouse
void print_warehouse(warehouse *w) {
  printf("Warehouse:\n");
  for (int i = 0; i < w->num_items; i++) {
    printf("  - %d: %s (%d, $%.2f)\n", w->items[i].id, w->items[i].name, 
w->items[i].quantity, w->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse *w = create_warehouse();

  // Add some items to the warehouse
  item i1 = {1, "Item 1", 10, 10.0};
  add_item(w, &i1);
  item i2 = {2, "Item 2", 20, 15.0};
  add_item(w, &i2);
  item i3 = {3, "Item 3", 30, 20.0};
  add_item(w, &i3);

  // Print the warehouse
  print_warehouse(w);

  // Get the total value of the warehouse
  float total_value = get_total_value(w);
  printf("Total value of the warehouse: $%.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(w, 2);

  // Print the warehouse
  print_warehouse(w);

  // Free the warehouse
  free(w);

  return 0;
}