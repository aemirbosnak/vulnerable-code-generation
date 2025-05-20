//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an inventory item
typedef struct item {
  char *name;
  int quantity;
  float price;
} item;

// Define the structure of the inventory system
typedef struct inventory {
  item *items;
  int num_items;
  float total_value;
} inventory;

// Create a new inventory system
inventory *create_inventory() {
  inventory *inv = malloc(sizeof(inventory));
  inv->items = NULL;
  inv->num_items = 0;
  inv->total_value = 0.0;
  return inv;
}

// Add an item to the inventory system
void add_item(inventory *inv, char *name, int quantity, float price) {
  // Allocate memory for the new item
  item *new_item = malloc(sizeof(item));

  // Copy the item's name, quantity, and price to the new item
  new_item->name = strdup(name);
  new_item->quantity = quantity;
  new_item->price = price;

  // Add the new item to the inventory system
  inv->items = realloc(inv->items, (inv->num_items + 1) * sizeof(item));
  inv->items[inv->num_items++] = *new_item;

  // Update the inventory system's total value
  inv->total_value += (quantity * price);
}

// Remove an item from the inventory system
void remove_item(inventory *inv, char *name) {
  // Find the item to be removed
  int i;
  for (i = 0; i < inv->num_items; i++) {
    if (strcmp(inv->items[i].name, name) == 0) {
      break;
    }
  }

  // If the item was found, remove it from the inventory system
  if (i < inv->num_items) {
    // Update the inventory system's total value
    inv->total_value -= (inv->items[i].quantity * inv->items[i].price);

    // Remove the item from the inventory system
    for (i++; i < inv->num_items; i++) {
      inv->items[i - 1] = inv->items[i];
    }
    inv->num_items--;
    inv->items = realloc(inv->items, inv->num_items * sizeof(item));
  }
}

// Print the inventory system
void print_inventory(inventory *inv) {
  printf("Inventory:\n");
  for (int i = 0; i < inv->num_items; i++) {
    printf("  %s: %d (%f)\n", inv->items[i].name, inv->items[i].quantity,
           inv->items[i].price);
  }
  printf("Total value: %f\n", inv->total_value);
}

// Destroy the inventory system
void destroy_inventory(inventory *inv) {
  for (int i = 0; i < inv->num_items; i++) {
    free(inv->items[i].name);
  }
  free(inv->items);
  free(inv);
}

int main() {
  // Create a new inventory system
  inventory *inv = create_inventory();

  // Add some items to the inventory system
  add_item(inv, "Shotgun", 1, 100.0);
  add_item(inv, "Ammo", 100, 1.0);
  add_item(inv, "Food", 10, 10.0);
  add_item(inv, "Water", 100, 1.0);
  add_item(inv, "Medkit", 1, 50.0);

  // Print the inventory system
  print_inventory(inv);

  // Remove an item from the inventory system
  remove_item(inv, "Shotgun");

  // Print the inventory system
  print_inventory(inv);

  // Destroy the inventory system
  destroy_inventory(inv);

  return 0;
}