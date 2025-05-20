//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char name[20];
  int quantity;
  double price;
  struct Item* next;
};

struct Warehouse {
  struct Item* head;
  struct Item* tail;
  int totalItems;
  double totalValue;
  struct Warehouse* next;
};

void insertItem(struct Warehouse* warehouse, char* name, int quantity, double price) {
  struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
  strcpy(newItem->name, name);
  newItem->quantity = quantity;
  newItem->price = price;
  newItem->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newItem;
    warehouse->tail = newItem;
  } else {
    warehouse->tail->next = newItem;
    warehouse->tail = newItem;
  }

  warehouse->totalItems++;
  warehouse->totalValue += quantity * price;
}

void removeItem(struct Warehouse* warehouse, char* name) {
  struct Item* previousItem = NULL;
  struct Item* currentItem = warehouse->head;

  while (currentItem) {
    if (strcmp(currentItem->name, name) == 0) {
      if (previousItem) {
        previousItem->next = currentItem->next;
        warehouse->tail = previousItem;
      } else {
        warehouse->head = currentItem->next;
        warehouse->tail = warehouse->head;
      }

      warehouse->totalItems--;
      warehouse->totalValue -= currentItem->quantity * currentItem->price;
      free(currentItem);
      return;
    }

    previousItem = currentItem;
    currentItem = currentItem->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
  warehouse->head = NULL;
  warehouse->tail = NULL;
  warehouse->totalItems = 0;
  warehouse->totalValue = 0;
  warehouse->next = NULL;

  insertItem(warehouse, "Apple", 10, 1.2);
  insertItem(warehouse, "Banana", 5, 0.8);
  insertItem(warehouse, "Orange", 7, 1.0);
  insertItem(warehouse, "Peach", 2, 1.5);

  removeItem(warehouse, "Banana");

  printf("Total items: %d\n", warehouse->totalItems);
  printf("Total value: %.2lf\n", warehouse->totalValue);

  return 0;
}