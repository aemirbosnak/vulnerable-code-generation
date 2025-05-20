//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item {
  char *name;
  int quantity;
} Item;

typedef struct Inventory {
  Item *items;
  int size;
} Inventory;

void initInventory(Inventory *inventory) {
  inventory->size = 0;
  inventory->items = NULL;
}

void addItem(Inventory *inventory, char *name, int quantity) {
  inventory->size++;
  inventory->items = realloc(inventory->items, inventory->size * sizeof(Item));
  inventory->items[inventory->size - 1].name = strdup(name);
  inventory->items[inventory->size - 1].quantity = quantity;
}

void removeItem(Inventory *inventory, char *name) {
  for (int i = 0; i < inventory->size; i++) {
    if (strcmp(inventory->items[i].name, name) == 0) {
      inventory->size--;
      for (int j = i; j < inventory->size; j++) {
        inventory->items[j] = inventory->items[j + 1];
      }
      free(inventory->items[inventory->size].name);
      break;
    }
  }
}

void printInventory(Inventory *inventory) {
  printf("Inventory:\n");
  for (int i = 0; i < inventory->size; i++) {
    printf("\t%s: %d\n", inventory->items[i].name, inventory->items[i].quantity);
  }
}

int main() {
  Inventory inventory;
  initInventory(&inventory);

  addItem(&inventory, "Food", 10);
  addItem(&inventory, "Water", 5);
  addItem(&inventory, "Ammunition", 20);
  addItem(&inventory, "Medical Supplies", 10);

  printInventory(&inventory);

  removeItem(&inventory, "Ammunition");

  printf("\nInventory after removing Ammunition:\n");
  printInventory(&inventory);

  return 0;
}