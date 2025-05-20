//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct Node {
  char item[MAX];
  int quantity;
  struct Node* next;
} Node;

typedef struct Warehouse {
  Node* head;
  int totalItems;
  struct Warehouse* next;
} Warehouse;

Warehouse* createWarehouse() {
  Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
  warehouse->head = NULL;
  warehouse->totalItems = 0;
  warehouse->next = NULL;
  return warehouse;
}

void insertItem(Warehouse* warehouse, char item, int quantity) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item[0] = item;
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newNode;
  } else {
    Node* current = warehouse->head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  warehouse->totalItems++;
}

void removeItem(Warehouse* warehouse, char item) {
  Node* previous = NULL;
  Node* current = warehouse->head;

  while (current) {
    if (strcmp(current->item, item) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        warehouse->head = current->next;
      }
      free(current);
      warehouse->totalItems--;
      return;
    }
    previous = current;
    current = current->next;
  }

  printf("Item not found.");
}

void printInventory(Warehouse* warehouse) {
  Node* current = warehouse->head;
  while (current) {
    printf("%s - %d\n", current->item, current->quantity);
    current = current->next;
  }
}

int main() {
  Warehouse* warehouse = createWarehouse();
  insertItem(warehouse, 'a', 10);
  insertItem(warehouse, 'b', 5);
  insertItem(warehouse, 'c', 2);
  insertItem(warehouse, 'd', 1);
  printInventory(warehouse);
  removeItem(warehouse, 'b');
  printInventory(warehouse);
  return 0;
}