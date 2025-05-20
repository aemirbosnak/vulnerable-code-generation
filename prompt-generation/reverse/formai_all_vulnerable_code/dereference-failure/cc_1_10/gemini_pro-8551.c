//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
typedef struct {
  char name[100];
  int quantity;
  float price;
  time_t last_update;
} item_t;

typedef struct {
  item_t *items;
  int num_items;
} inventory_t;

inventory_t *create_inventory() {
  return malloc(sizeof(inventory_t));
}

void free_inventory(inventory_t *inventory) {
  if (inventory->items != NULL) {
    free(inventory->items);
  }
  free(inventory);
}

int add_item(inventory_t *inventory, item_t *item) {
  if (inventory->num_items == 0) {
    inventory->items = malloc(sizeof(item_t));
  } else {
    inventory->items = realloc(inventory->items, (inventory->num_items + 1) * sizeof(item_t));
  }
  inventory->items[inventory->num_items++] = *item;
  return 0;
}

item_t *get_item(inventory_t *inventory, char *name) {
  for (int i = 0; i < inventory->num_items; i++) {
    if (strcmp(inventory->items[i].name, name) == 0) {
      return &inventory->items[i];
    }
  }
  return NULL;
}

int remove_item(inventory_t *inventory, char *name) {
  for (int i = 0; i < inventory->num_items; i++) {
    if (strcmp(inventory->items[i].name, name) == 0) {
      inventory->num_items--;
      for (int j = i; j < inventory->num_items; j++) {
        inventory->items[j] = inventory->items[j + 1];
      }
      return 0;
    }
  }
  return -1;
}

int update_item(inventory_t *inventory, char *name, item_t *item) {
  for (int i = 0; i < inventory->num_items; i++) {
    if (strcmp(inventory->items[i].name, name) == 0) {
      inventory->items[i] = *item;
      return 0;
    }
  }
  return -1;
}

int main() {
  inventory_t *inventory = create_inventory();
  item_t item1 = {"Item 1", 10, 10.0, time(NULL)};
  add_item(inventory, &item1);
  item_t item2 = {"Item 2", 20, 20.0, time(NULL)};
  add_item(inventory, &item2);
  item_t *item = get_item(inventory, "Item 1");
  if (item != NULL) {
    printf("Item found: %s, quantity: %d, price: %f, last update: %s", item->name, item->quantity,
           item->price, ctime(&item->last_update));
  } else {
    printf("Item not found\n");
  }
  remove_item(inventory, "Item 2");
  item = get_item(inventory, "Item 2");
  if (item != NULL) {
    printf("Item found: %s, quantity: %d, price: %f, last update: %s", item->name, item->quantity,
           item->price, ctime(&item->last_update));
  } else {
    printf("Item not found\n");
  }
  item_t item3 = {"Item 3", 30, 30.0, time(NULL)};
  update_item(inventory, "Item 1", &item3);
  item = get_item(inventory, "Item 1");
  if (item != NULL) {
    printf("Item found: %s, quantity: %d, price: %f, last update: %s", item->name, item->quantity,
           item->price, ctime(&item->last_update));
  } else {
    printf("Item not found\n");
  }
  free_inventory(inventory);
  return 0;
}