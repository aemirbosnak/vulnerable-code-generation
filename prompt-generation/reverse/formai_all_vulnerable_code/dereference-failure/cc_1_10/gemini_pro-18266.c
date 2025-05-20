//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
// Linus Torvalds-style Warehouse Management System
// Embrace the F-word and optimize like a demon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inventory item structure
typedef struct {
  char *name;
  int quantity;
  float price;
} Item;

// Warehouse structure
typedef struct {
  Item *items;
  int item_count;
  float total_value;
} Warehouse;

// Initialize warehouse
Warehouse *init_warehouse() {
  Warehouse *wh = malloc(sizeof(Warehouse));
  wh->items = NULL;
  wh->item_count = 0;
  wh->total_value = 0.0;
  return wh;
}

// Add new item
void add_item(Warehouse *wh, Item item) {
  wh->items = realloc(wh->items, sizeof(Item) * (wh->item_count+1));
  wh->items[wh->item_count] = item;
  wh->item_count++;
  wh->total_value += (item.price * item.quantity);
}

// Remove item
void remove_item(Warehouse *wh, int index) {
  if (index < 0 || index >= wh->item_count)
    return;
  Item removed = wh->items[index];
  wh->total_value -= (removed.price * removed.quantity);
  for (int i = index; i < wh->item_count-1; i++)
    wh->items[i] = wh->items[i+1];
  wh->item_count--;
  wh->items = realloc(wh->items, sizeof(Item) * wh->item_count);
}

// Update item quantity
void update_quantity(Warehouse *wh, int index, int new_quantity) {
  if (index < 0 || index >= wh->item_count)
    return;
  wh->items[index].quantity = new_quantity;
  wh->total_value = 0.0;
  for (int i = 0; i < wh->item_count; i++)
    wh->total_value += (wh->items[i].price * wh->items[i].quantity);
}

// Print warehouse inventory
void print_inventory(Warehouse *wh) {
  printf("Warehouse Inventory:\n");
  for (int i = 0; i < wh->item_count; i++) {
    Item item = wh->items[i];
    printf("- %s (%d units) @ %.2f each\n", item.name, item.quantity, item.price);
  }
  printf("Total value: %.2f\n", wh->total_value);
}

// Main function
int main() {
  // Creating a new warehouse
  Warehouse *my_warehouse = init_warehouse();

  // Adding some items
  Item item1 = {"Widgets", 100, 5.00};
  add_item(my_warehouse, item1);
  Item item2 = {"Gadgets", 50, 10.00};
  add_item(my_warehouse, item2);
  Item item3 = {"Thingamajigs", 25, 15.00};
  add_item(my_warehouse, item3);

  // Updating quantity and printing
  update_quantity(my_warehouse, 0, 200);
  print_inventory(my_warehouse);

  // Remove item and printing
  remove_item(my_warehouse, 1);
  print_inventory(my_warehouse);

  // Free allocated memory
  free(my_warehouse->items);
  free(my_warehouse);
  return 0;
}