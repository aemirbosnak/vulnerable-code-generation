//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: complete
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
void add_item(warehouse *w, item i) {
  if (w->num_items < MAX_ITEMS) {
    w->items[w->num_items++] = i;
  } else {
    printf("Error: Warehouse is full.\n");
  }
}

// Remove an item from the warehouse
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

// Get the total value of the warehouse
float get_total_value(warehouse *w) {
  int i;
  float total = 0;
  for (i = 0; i < w->num_items; i++) {
    total += w->items[i].quantity * w->items[i].price;
  }
  return total;
}

// Print the contents of the warehouse
void print_warehouse(warehouse *w) {
  int i;
  printf("Warehouse contents:\n");
  for (i = 0; i < w->num_items; i++) {
    printf("%s %d %f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse *w = create_warehouse();

  // Add some items to the warehouse
  item i1 = {"Apple", 10, 1.0};
  add_item(w, i1);
  item i2 = {"Banana", 20, 2.0};
  add_item(w, i2);
  item i3 = {"Orange", 30, 3.0};
  add_item(w, i3);

  // Print the contents of the warehouse
  print_warehouse(w);

  // Get the total value of the warehouse
  float total_value = get_total_value(w);
  printf("Total value of the warehouse: %f\n", total_value);

  // Remove an item from the warehouse
  remove_item(w, "Banana");

  // Print the contents of the warehouse again
  print_warehouse(w);

  // Free the memory allocated for the warehouse
  free(w);

  return 0;
}