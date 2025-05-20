//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct item {
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
warehouse* create_warehouse() {
  warehouse* w = malloc(sizeof(warehouse));
  w->num_items = 0;
  return w;
}

// Add an item to the warehouse
void add_item(warehouse* w, item* i) {
  if (w->num_items < MAX_ITEMS) {
    w->items[w->num_items++] = *i;
  }
}

// Remove an item from the warehouse
void remove_item(warehouse* w, char* name) {
  int i;
  for (i = 0; i < w->num_items; i++) {
    if (strcmp(w->items[i].name, name) == 0) {
      break;
    }
  }
  if (i < w->num_items) {
    for (; i < w->num_items - 1; i++) {
      w->items[i] = w->items[i + 1];
    }
    w->num_items--;
  }
}

// Get the total value of the items in the warehouse
float get_total_value(warehouse* w) {
  float total = 0;
  int i;
  for (i = 0; i < w->num_items; i++) {
    total += w->items[i].quantity * w->items[i].price;
  }
  return total;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
  int i;
  for (i = 0; i < w->num_items; i++) {
    printf("%s %d %.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse* w = create_warehouse();

  // Add some items to the warehouse
  item i1 = {"Item 1", 10, 10.00};
  add_item(w, &i1);
  item i2 = {"Item 2", 20, 20.00};
  add_item(w, &i2);
  item i3 = {"Item 3", 30, 30.00};
  add_item(w, &i3);

  // Print the contents of the warehouse
  printf("Warehouse contents:\n");
  print_warehouse(w);

  // Get the total value of the items in the warehouse
  float total_value = get_total_value(w);
  printf("Total value of items in warehouse: %.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(w, "Item 2");

  // Print the contents of the warehouse
  printf("Warehouse contents after removing Item 2:\n");
  print_warehouse(w);

  // Free the memory allocated for the warehouse
  free(w);

  return 0;
}