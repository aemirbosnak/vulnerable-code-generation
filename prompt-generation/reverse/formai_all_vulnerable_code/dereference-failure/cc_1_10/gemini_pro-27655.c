//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int quantity;
  double price;
} item_t;

typedef struct {
  char *name;
  int size;
  item_t *items;
} warehouse_t;

warehouse_t *create_warehouse(char *name) {
  warehouse_t *warehouse = malloc(sizeof(warehouse_t));
  warehouse->name = strdup(name);
  warehouse->size = 0;
  warehouse->items = NULL;
  return warehouse;
}

void destroy_warehouse(warehouse_t *warehouse) {
  for (int i = 0; i < warehouse->size; i++) {
    free(warehouse->items[i].name);
  }
  free(warehouse->items);
  free(warehouse->name);
  free(warehouse);
}

int add_item(warehouse_t *warehouse, char *name, int quantity, double price) {
  if (warehouse->size >= 100) {
    return -1;  // Warehouse is full
  }

  for (int i = 0; i < warehouse->size; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      warehouse->items[i].quantity += quantity;
      return 0;  // Item already exists, so just update the quantity
    }
  }

  warehouse->items = realloc(warehouse->items, (warehouse->size + 1) * sizeof(item_t));
  warehouse->items[warehouse->size].name = strdup(name);
  warehouse->items[warehouse->size].quantity = quantity;
  warehouse->items[warehouse->size].price = price;
  warehouse->size++;
  return 0;  // Item added successfully
}

int remove_item(warehouse_t *warehouse, char *name, int quantity) {
  for (int i = 0; i < warehouse->size; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      if (warehouse->items[i].quantity < quantity) {
        return -1;  // Not enough items to remove
      }

      warehouse->items[i].quantity -= quantity;
      if (warehouse->items[i].quantity == 0) {
        free(warehouse->items[i].name);
        for (int j = i; j < warehouse->size - 1; j++) {
          warehouse->items[j] = warehouse->items[j + 1];
        }
        warehouse->size--;
      }
      return 0;  // Item removed successfully
    }
  }

  return -1;  // Item not found
}

int get_item_quantity(warehouse_t *warehouse, char *name) {
  for (int i = 0; i < warehouse->size; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      return warehouse->items[i].quantity;
    }
  }

  return -1;  // Item not found
}

double get_item_price(warehouse_t *warehouse, char *name) {
  for (int i = 0; i < warehouse->size; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      return warehouse->items[i].price;
    }
  }

  return -1.0;  // Item not found
}

int main() {
  warehouse_t *warehouse = create_warehouse("My Warehouse");

  add_item(warehouse, "Apple", 10, 1.0);
  add_item(warehouse, "Banana", 20, 2.0);
  add_item(warehouse, "Orange", 30, 3.0);

  printf("Warehouse contents:\n");
  for (int i = 0; i < warehouse->size; i++) {
    printf("%s: %d, %f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }

  remove_item(warehouse, "Apple", 5);

  printf("\nWarehouse contents after removing 5 apples:\n");
  for (int i = 0; i < warehouse->size; i++) {
    printf("%s: %d, %f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
  }

  destroy_warehouse(warehouse);

  return 0;
}