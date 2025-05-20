//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char item[20];
  int quantity;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  struct Node* tail;
  int totalItems;
  int totalQuantity;
};

void insertItem(struct Warehouse* warehouse, char item, int quantity) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->item[0] = item;
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newNode;
    warehouse->tail = newNode;
  } else {
    warehouse->tail->next = newNode;
    warehouse->tail = newNode;
  }

  warehouse->totalItems++;
  warehouse->totalQuantity += quantity;
}

void removeItem(struct Warehouse* warehouse, char item) {
  struct Node* current = warehouse->head;
  struct Node* previous = NULL;

  while (current) {
    if (strcmp(current->item, item) == 0) {
      if (previous) {
        previous->next = current->next;
        warehouse->tail = previous;
      } else {
        warehouse->head = current->next;
        warehouse->tail = warehouse->head;
      }

      warehouse->totalItems--;
      warehouse->totalQuantity -= current->quantity;
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct Warehouse warehouse;
  warehouse.head = NULL;
  warehouse.tail = NULL;
  warehouse.totalItems = 0;
  warehouse.totalQuantity = 0;

  insertItem(&warehouse, "Apple", 10);
  insertItem(&warehouse, "Banana", 20);
  insertItem(&warehouse, "Orange", 30);

  removeItem(&warehouse, "Banana");

  printf("Items: %d\n", warehouse.totalItems);
  printf("Quantity: %d\n", warehouse.totalQuantity);

  return 0;
}