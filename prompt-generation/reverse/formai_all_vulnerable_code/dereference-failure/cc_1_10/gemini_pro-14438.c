//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME 20
#define MAX_ITEM_DESCRIPTION 100

// Define the item struct
typedef struct item {
  int id;
  char name[MAX_ITEM_NAME];
  char description[MAX_ITEM_DESCRIPTION];
  int quantity;
  float price;
} item;

// Define the warehouse struct
typedef struct warehouse {
  item items[MAX_ITEMS];
  int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
  warehouse *w = (warehouse *)malloc(sizeof(warehouse));
  w->num_items = 0;
  return w;
}

// Add an item to the warehouse
void add_item(warehouse *w, item *i) {
  w->items[w->num_items] = *i;
  w->num_items++;
}

// Get an item from the warehouse by its id
item *get_item(warehouse *w, int id) {
  for (int i = 0; i < w->num_items; i++) {
    if (w->items[i].id == id) {
      return &w->items[i];
    }
  }
  return NULL;
}

// Print the inventory of the warehouse
void print_inventory(warehouse *w) {
  printf("Inventory:\n");
  for (int i = 0; i < w->num_items; i++) {
    printf("%d %s %s %d %.2f\n", w->items[i].id, w->items[i].name, w->items[i].description, w->items[i].quantity, w->items[i].price);
  }
}

// Main function
int main() {
  // Create a new warehouse
  warehouse *w = create_warehouse();

  // Add some items to the warehouse
  item i1 = {1, "Apple", "A delicious fruit", 10, 1.0};
  add_item(w, &i1);
  item i2 = {2, "Banana", "A healthy fruit", 20, 2.0};
  add_item(w, &i2);
  item i3 = {3, "Orange", "A citrus fruit", 30, 3.0};
  add_item(w, &i3);

  // Print the inventory of the warehouse
  print_inventory(w);

  // Get an item from the warehouse by its id
  item *i = get_item(w, 2);
  if (i != NULL) {
    printf("Item found: %d %s %s %d %.2f\n", i->id, i->name, i->description, i->quantity, i->price);
  } else {
    printf("Item not found.\n");
  }

  return 0;
}