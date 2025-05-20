//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct item {
  char name[50]; // The name of the item
  int quantity; // The quantity of the item in stock
  float price; // The price of the item
} item;

// Define the structure of the warehouse
typedef struct warehouse {
  item items[MAX_ITEMS]; // The array of items in the warehouse
  int count; // The number of items in the warehouse
} warehouse;

// Create a new warehouse
warehouse* create_warehouse() {
  warehouse* w = (warehouse*)malloc(sizeof(warehouse));
  w->count = 0;
  return w;
}

// Add an item to the warehouse
void add_item(warehouse* w, item i) {
  if (w->count < MAX_ITEMS) {
    w->items[w->count] = i;
    w->count++;
  } else {
    printf("The warehouse is full!\n");
  }
}

// Remove an item from the warehouse
void remove_item(warehouse* w, char* name) {
  for (int i = 0; i < w->count; i++) {
    if (strcmp(w->items[i].name, name) == 0) {
      for (int j = i; j < w->count - 1; j++) {
        w->items[j] = w->items[j + 1];
      }
      w->count--;
      break;
    }
  }
}

// Find an item in the warehouse
item* find_item(warehouse* w, char* name) {
  for (int i = 0; i < w->count; i++) {
    if (strcmp(w->items[i].name, name) == 0) {
      return &w->items[i];
    }
  }
  return NULL;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
  printf("The warehouse contains the following items:\n");
  for (int i = 0; i < w->count; i++) {
    printf("%s: %d units at $%.2f each\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
  }
}

// Get the total value of the warehouse
float get_total_value(warehouse* w) {
  float total = 0;
  for (int i = 0; i < w->count; i++) {
    total += w->items[i].quantity * w->items[i].price;
  }
  return total;
}

// Main function
int main() {
  // Create a new warehouse
  warehouse* w = create_warehouse();

  // Add some items to the warehouse
  item i1 = {"Apple", 10, 1.0f};
  add_item(w, i1);
  item i2 = {"Orange", 5, 2.0f};
  add_item(w, i2);
  item i3 = {"Banana", 15, 3.0f};
  add_item(w, i3);

  // Print the contents of the warehouse
  print_warehouse(w);

  // Get the total value of the warehouse
  float total_value = get_total_value(w);
  printf("The total value of the warehouse is $%.2f\n", total_value);

  // Remove an item from the warehouse
  remove_item(w, "Orange");

  // Print the contents of the warehouse
  print_warehouse(w);

  // Find an item in the warehouse
  item* i4 = find_item(w, "Apple");
  if (i4 != NULL) {
    printf("The warehouse contains %d units of %s.\n", i4->quantity, i4->name);
  } else {
    printf("The warehouse does not contain any %s.\n", "Apple");
  }

  // Free the memory allocated for the warehouse
  free(w);

  return 0;
}