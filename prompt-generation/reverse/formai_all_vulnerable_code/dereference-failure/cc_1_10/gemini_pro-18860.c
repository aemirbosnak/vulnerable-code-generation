//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: safe
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
  if (w->num_items == MAX_ITEMS) {
    printf("Warehouse is full!\n");
    return;
  }

  w->items[w->num_items++] = *i;
}

// Remove an item from the warehouse
void remove_item(warehouse* w, char* name) {
  for (int i = 0; i < w->num_items; i++) {
    if (strcmp(w->items[i].name, name) == 0) {
      for (int j = i; j < w->num_items - 1; j++) {
        w->items[j] = w->items[j + 1];
      }
      w->num_items--;
      return;
    }
  }

  printf("Item not found!\n");
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
  printf("Warehouse contents:\n");
  for (int i = 0; i < w->num_items; i++) {
    printf("  %s: %d, $%.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
  }
}

// Get the total value of the warehouse
float get_total_value(warehouse* w) {
  float total = 0;
  for (int i = 0; i < w->num_items; i++) {
    total += w->items[i].quantity * w->items[i].price;
  }
  return total;
}

// Main function
int main() {
  // Create a new warehouse
  warehouse* w = create_warehouse();

  // Add some items to the warehouse
  item i1 = {"Apple", 10, 1.0};
  item i2 = {"Banana", 20, 1.5};
  item i3 = {"Orange", 30, 2.0};
  add_item(w, &i1);
  add_item(w, &i2);
  add_item(w, &i3);

  // Print the contents of the warehouse
  print_warehouse(w);

  // Get the total value of the warehouse
  float total_value = get_total_value(w);
  printf("Total value of the warehouse: $%.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(w, "Banana");

  // Print the contents of the warehouse
  print_warehouse(w);

  // Free the memory used by the warehouse
  free(w);

  return 0;
}