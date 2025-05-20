//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
  int id;
  char *name;
  int quantity;
  float price;
};

struct warehouse {
  struct item items[MAX_ITEMS];
  int num_items;
};

struct warehouse *create_warehouse() {
  struct warehouse *warehouse = malloc(sizeof(struct warehouse));
  warehouse->num_items = 0;
  return warehouse;
}

void add_item(struct warehouse *warehouse, struct item *item) {
  warehouse->items[warehouse->num_items++] = *item;
}

void print_warehouse(struct warehouse *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("Item %d: %s, %d, %f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }
}

void free_warehouse(struct warehouse *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    free(warehouse->items[i].name);
  }
  free(warehouse);
}

int main() {
  struct warehouse *warehouse = create_warehouse();

  struct item item1 = {1, "Item 1", 10, 10.0};
  struct item item2 = {2, "Item 2", 20, 20.0};

  add_item(warehouse, &item1);
  add_item(warehouse, &item2);

  print_warehouse(warehouse);

  free_warehouse(warehouse);

  return 0;
}