//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the max size of the inventory
#define MAX_INVENTORY_SIZE 10

// Define the struct for an item in the inventory
typedef struct item {
  char *name;
  int quantity;
} item;

// Define the struct for the inventory
typedef struct inventory {
  item *items;
  int size;
  int capacity;
} inventory;

// Initialize the inventory
inventory *init_inventory() {
  inventory *inv = malloc(sizeof(inventory));
  inv->items = malloc(sizeof(item) * MAX_INVENTORY_SIZE);
  inv->size = 0;
  inv->capacity = MAX_INVENTORY_SIZE;
  return inv;
}

// Add an item to the inventory
void add_item(inventory *inv, char *name, int quantity) {
  if (inv->size >= inv->capacity) {
    inv->capacity *= 2;
    inv->items = realloc(inv->items, sizeof(item) * inv->capacity);
  }
  inv->items[inv->size].name = strdup(name);
  inv->items[inv->size].quantity = quantity;
  inv->size++;
}

// Remove an item from the inventory
void remove_item(inventory *inv, char *name) {
  int i;
  for (i = 0; i < inv->size; i++) {
    if (strcmp(inv->items[i].name, name) == 0) {
      inv->items[i].quantity--;
      if (inv->items[i].quantity == 0) {
        free(inv->items[i].name);
        inv->items[i] = inv->items[inv->size - 1];
        inv->size--;
      }
      break;
    }
  }
}

// Print the inventory
void print_inventory(inventory *inv) {
  int i;
  printf("Inventory:\n");
  for (i = 0; i < inv->size; i++) {
    printf("%s: %d\n", inv->items[i].name, inv->items[i].quantity);
  }
}

// Free the inventory
void free_inventory(inventory *inv) {
  int i;
  for (i = 0; i < inv->size; i++) {
    free(inv->items[i].name);
  }
  free(inv->items);
  free(inv);
}

// Main function
int main() {
  inventory *inv = init_inventory();

  // Add items to the inventory
  add_item(inv, "Water", 10);
  add_item(inv, "Food", 5);
  add_item(inv, "Ammunition", 20);
  add_item(inv, "Medical supplies", 10);
  add_item(inv, "Tools", 5);

  // Print the inventory
  print_inventory(inv);

  // Remove items from the inventory
  remove_item(inv, "Water");
  remove_item(inv, "Ammunition");

  // Print the inventory again
  print_inventory(inv);

  // Free the inventory
  free_inventory(inv);

  return 0;
}