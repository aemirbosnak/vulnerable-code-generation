//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item_t {
  char *name;
  int quantity;
  float price;
} item_t;

typedef struct warehouse_t {
  item_t *items;
  int num_items;
  int capacity;
} warehouse_t;

warehouse_t *create_warehouse(int capacity) {
  warehouse_t *warehouse = malloc(sizeof(warehouse_t));
  warehouse->items = malloc(sizeof(item_t) * capacity);
  warehouse->num_items = 0;
  warehouse->capacity = capacity;
  return warehouse;
}

void destroy_warehouse(warehouse_t *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    free(warehouse->items[i].name);
  }
  free(warehouse->items);
  free(warehouse);
}

void add_item(warehouse_t *warehouse, item_t item) {
  if (warehouse->num_items == warehouse->capacity) {
    warehouse->items = realloc(warehouse->items, sizeof(item_t) * warehouse->capacity * 2);
    warehouse->capacity *= 2;
  }
  warehouse->items[warehouse->num_items++] = item;
}

void remove_item(warehouse_t *warehouse, char *name) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      for (int j = i + 1; j < warehouse->num_items; j++) {
        warehouse->items[j - 1] = warehouse->items[j];
      }
      warehouse->num_items--;
      return;
    }
  }
}

item_t *find_item(warehouse_t *warehouse, char *name) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      return &warehouse->items[i];
    }
  }
  return NULL;
}

void print_warehouse(warehouse_t *warehouse) {
  printf("Warehouse:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("  %s: %d items at $%.2f each\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

int main() {
  warehouse_t *warehouse = create_warehouse(10);

  item_t item1 = {"Widget A", 100, 1.99};
  item_t item2 = {"Widget B", 50, 2.99};
  item_t item3 = {"Widget C", 25, 3.99};

  add_item(warehouse, item1);
  add_item(warehouse, item2);
  add_item(warehouse, item3);

  print_warehouse(warehouse);

  item_t *item = find_item(warehouse, "Widget B");
  if (item != NULL) {
    printf("Found item: %s, %d items at $%.2f each\n", item->name, item->quantity, item->price);
  } else {
    printf("Item not found\n");
  }

  remove_item(warehouse, "Widget C");

  print_warehouse(warehouse);

  destroy_warehouse(warehouse);

  return 0;
}