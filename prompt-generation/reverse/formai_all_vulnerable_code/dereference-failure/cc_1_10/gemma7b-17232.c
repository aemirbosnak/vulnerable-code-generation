//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

typedef struct Warehouse {
  Item* head;
  struct Warehouse* next;
} Warehouse;

Warehouse* CreateWarehouse() {
  Warehouse* warehouse = malloc(sizeof(Warehouse));
  warehouse->head = NULL;
  warehouse->next = NULL;
  return warehouse;
}

void InsertItem(Warehouse* warehouse, char* name, int quantity) {
  Item* item = malloc(sizeof(Item));
  strcpy(item->name, name);
  item->quantity = quantity;
  item->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = item;
  } else {
    Item* current = warehouse->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = item;
  }
}

void PrintItems(Warehouse* warehouse) {
  Item* item = warehouse->head;
  while (item) {
    printf("%s: %d\n", item->name, item->quantity);
    item = item->next;
  }
}

int main() {
  Warehouse* warehouse = CreateWarehouse();

  InsertItem(warehouse, "Rubber Duck", 10);
  InsertItem(warehouse, "Electric Toaster", 5);
  InsertItem(warehouse, "Singing Fish", 2);

  PrintItems(warehouse);

  return 0;
}