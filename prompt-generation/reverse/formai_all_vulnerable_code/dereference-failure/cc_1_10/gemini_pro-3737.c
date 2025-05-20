//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
  char *name;
  int quantity;
} item_t;

typedef struct warehouse {
  item_t *items;
  int num_items;
} warehouse_t;

warehouse_t *create_warehouse() {
  warehouse_t *warehouse = malloc(sizeof(warehouse_t));
  warehouse->items = NULL;
  warehouse->num_items = 0;
  return warehouse;
}

void destroy_warehouse(warehouse_t *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    free(warehouse->items[i].name);
  }
  free(warehouse->items);
  free(warehouse);
}

item_t *find_item(warehouse_t *warehouse, char *name) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      return &warehouse->items[i];
    }
  }
  return NULL;
}

int add_item(warehouse_t *warehouse, char *name, int quantity) {
  item_t *item = find_item(warehouse, name);
  if (item != NULL) {
    item->quantity += quantity;
    return 0;
  }

  warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(item_t));
  item = &warehouse->items[warehouse->num_items];
  item->name = malloc(strlen(name) + 1);
  strcpy(item->name, name);
  item->quantity = quantity;
  warehouse->num_items++;
  return 1;
}

int remove_item(warehouse_t *warehouse, char *name, int quantity) {
  item_t *item = find_item(warehouse, name);
  if (item == NULL) {
    return 0;
  }

  if (item->quantity < quantity) {
    return 0;
  }

  item->quantity -= quantity;
  if (item->quantity == 0) {
    for (int i = 0; i < warehouse->num_items - 1; i++) {
      warehouse->items[i] = warehouse->items[i + 1];
    }
    free(warehouse->items[warehouse->num_items - 1].name);
    warehouse->num_items--;
    warehouse->items = realloc(warehouse->items, warehouse->num_items * sizeof(item_t));
  }
  return 1;
}

int main() {
  warehouse_t *warehouse = create_warehouse();
  add_item(warehouse, "Apples", 10);
  add_item(warehouse, "Oranges", 5);
  add_item(warehouse, "Bananas", 15);

  item_t *item = find_item(warehouse, "Apples");
  if (item != NULL) {
    printf("Found %d Apples in the warehouse.\n", item->quantity);
  }

  remove_item(warehouse, "Apples", 5);
  item = find_item(warehouse, "Apples");
  if (item != NULL) {
    printf("Now there are %d Apples in the warehouse.\n", item->quantity);
  }

  destroy_warehouse(warehouse);
  return 0;
}