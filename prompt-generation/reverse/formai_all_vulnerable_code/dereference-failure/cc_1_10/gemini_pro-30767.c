//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
  int id;
  char *name;
  int quantity;
  struct Item *next;
} Item;

typedef struct Warehouse {
  char *name;
  Item *items;
  struct Warehouse *next;
} Warehouse;

Item *create_item(int id, char *name, int quantity) {
  Item *item = malloc(sizeof(Item));
  item->id = id;
  item->name = strdup(name);
  item->quantity = quantity;
  item->next = NULL;
  return item;
}

Warehouse *create_warehouse(char *name) {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  warehouse->name = strdup(name);
  warehouse->items = NULL;
  warehouse->next = NULL;
  return warehouse;
}

void add_item(Warehouse *warehouse, Item *item) {
  if (warehouse->items == NULL) {
    warehouse->items = item;
  } else {
    add_item(warehouse->next, item);
  }
}

void remove_item(Warehouse *warehouse, int id) {
  if (warehouse->items == NULL) {
    return;
  } else if (warehouse->items->id == id) {
    Item *next = warehouse->items->next;
    free(warehouse->items->name);
    free(warehouse->items);
    warehouse->items = next;
  } else {
    remove_item(warehouse->next, id);
  }
}

void print_warehouse(Warehouse *warehouse) {
  if (warehouse == NULL) {
    return;
  } else {
    printf("Warehouse: %s\n", warehouse->name);
    Item *item = warehouse->items;
    while (item != NULL) {
      printf("  Item: %d, %s, %d\n", item->id, item->name, item->quantity);
      item = item->next;
    }
    print_warehouse(warehouse->next);
  }
}

void free_warehouse(Warehouse *warehouse) {
  if (warehouse == NULL) {
    return;
  } else {
    free_warehouse(warehouse->next);
    Item *item = warehouse->items;
    while (item != NULL) {
      Item *next = item->next;
      free(item->name);
      free(item);
      item = next;
    }
    free(warehouse->name);
    free(warehouse);
  }
}

int main() {
  Warehouse *warehouse1 = create_warehouse("Warehouse 1");
  add_item(warehouse1, create_item(1, "Item 1", 10));
  add_item(warehouse1, create_item(2, "Item 2", 20));
  add_item(warehouse1, create_item(3, "Item 3", 30));

  Warehouse *warehouse2 = create_warehouse("Warehouse 2");
  add_item(warehouse2, create_item(4, "Item 4", 40));
  add_item(warehouse2, create_item(5, "Item 5", 50));
  add_item(warehouse2, create_item(6, "Item 6", 60));

  print_warehouse(warehouse1);
  print_warehouse(warehouse2);

  remove_item(warehouse1, 2);
  remove_item(warehouse2, 5);

  print_warehouse(warehouse1);
  print_warehouse(warehouse2);

  free_warehouse(warehouse1);
  free_warehouse(warehouse2);

  return 0;
}