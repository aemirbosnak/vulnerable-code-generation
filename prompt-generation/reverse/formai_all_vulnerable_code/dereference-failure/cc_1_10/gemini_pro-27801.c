//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct item {
  char *name;
  int quantity;
  struct item *next;
} item_t;

// Warehouse structure
typedef struct warehouse {
  char *name;
  item_t *items;
  struct warehouse *next;
} warehouse_t;

// Create a new item
item_t *item_create(char *name, int quantity) {
  item_t *item = malloc(sizeof(item_t));
  if (item == NULL) {
    return NULL;
  }
  item->name = strdup(name);
  item->quantity = quantity;
  item->next = NULL;
  return item;
}

// Create a new warehouse
warehouse_t *warehouse_create(char *name) {
  warehouse_t *warehouse = malloc(sizeof(warehouse_t));
  if (warehouse == NULL) {
    return NULL;
  }
  warehouse->name = strdup(name);
  warehouse->items = NULL;
  warehouse->next = NULL;
  return warehouse;
}

// Add an item to a warehouse
void warehouse_add_item(warehouse_t *warehouse, item_t *item) {
  item->next = warehouse->items;
  warehouse->items = item;
}

// Get an item from a warehouse
item_t *warehouse_get_item(warehouse_t *warehouse, char *name) {
  item_t *item = warehouse->items;
  while (item != NULL) {
    if (strcmp(item->name, name) == 0) {
      return item;
    }
    item = item->next;
  }
  return NULL;
}

// Remove an item from a warehouse
void warehouse_remove_item(warehouse_t *warehouse, item_t *item) {
  if (warehouse->items == item) {
    warehouse->items = item->next;
  } else {
    item_t *prev = warehouse->items;
    while (prev->next != item) {
      prev = prev->next;
    }
    prev->next = item->next;
  }
  free(item);
}

// Print a warehouse
void warehouse_print(warehouse_t *warehouse) {
  printf("Warehouse: %s\n", warehouse->name);
  item_t *item = warehouse->items;
  while (item != NULL) {
    printf("  Item: %s, Quantity: %d\n", item->name, item->quantity);
    item = item->next;
  }
}

// Free a warehouse
void warehouse_free(warehouse_t *warehouse) {
  item_t *item = warehouse->items;
  while (item != NULL) {
    item_t *next = item->next;
    free(item->name);
    free(item);
    item = next;
  }
  free(warehouse->name);
  free(warehouse);
}

// Main function
int main() {
  // Create a warehouse
  warehouse_t *warehouse = warehouse_create("Main Warehouse");

  // Add some items to the warehouse
  item_t *item1 = item_create("Item 1", 10);
  warehouse_add_item(warehouse, item1);
  item_t *item2 = item_create("Item 2", 20);
  warehouse_add_item(warehouse, item2);
  item_t *item3 = item_create("Item 3", 30);
  warehouse_add_item(warehouse, item3);

  // Print the warehouse
  warehouse_print(warehouse);

  // Get an item from the warehouse
  item_t *item = warehouse_get_item(warehouse, "Item 2");
  if (item != NULL) {
    printf("Found item: %s, Quantity: %d\n", item->name, item->quantity);
  } else {
    printf("Item not found\n");
  }

  // Remove an item from the warehouse
  warehouse_remove_item(warehouse, item2);

  // Print the warehouse
  warehouse_print(warehouse);

  // Free the warehouse
  warehouse_free(warehouse);

  return 0;
}