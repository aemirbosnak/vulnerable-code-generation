//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: romantic
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
warehouse* create_warehouse() {
  warehouse* w = malloc(sizeof(warehouse));
  w->num_items = 0;
  return w;
}

// Add an item to the warehouse
void add_item(warehouse* w, item* i) {
  w->items[w->num_items] = *i;
  w->num_items++;
}

// Remove an item from the warehouse
void remove_item(warehouse* w, int id) {
  int i;
  for (i = 0; i < w->num_items; i++) {
    if (w->items[i].id == id) {
      break;
    }
  }
  if (i < w->num_items) {
    for (int j = i; j < w->num_items - 1; j++) {
      w->items[j] = w->items[j + 1];
    }
    w->num_items--;
  }
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
  printf("ID\tName\tQuantity\tPrice\n");
  for (int i = 0; i < w->num_items; i++) {
    printf("%d\t%s\t%d\t%.2f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse* w = create_warehouse();

  // Add some items to the warehouse
  item i1 = {1, "Item 1", 10, 10.00};
  add_item(w, &i1);
  item i2 = {2, "Item 2", 20, 20.00};
  add_item(w, &i2);
  item i3 = {3, "Item 3", 30, 30.00};
  add_item(w, &i3);

  // Print the contents of the warehouse
  print_warehouse(w);

  // Remove an item from the warehouse
  remove_item(w, 2);

  // Print the contents of the warehouse again
  print_warehouse(w);

  return 0;
}