//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
  char item[MAX];
  int quantity;
  struct Node* next;
} Node;

typedef struct Warehouse {
  Node* head;
  Node* tail;
} Warehouse;

void insert(Warehouse* warehouse, char item, int quantity) {
  Node* newNode = (Node*)malloc(sizeof(Node));
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
}

int search(Warehouse* warehouse, char item) {
  Node* current = warehouse->head;
  while (current) {
    if (strcmp(current->item, item) == 0) {
      return current->quantity;
    }
    current = current->next;
  }
  return -1;
}

int main() {
  Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
  warehouse->head = NULL;
  warehouse->tail = NULL;

  insert(warehouse, 'a', 10);
  insert(warehouse, 'b', 5);
  insert(warehouse, 'c', 2);

  int quantity = search(warehouse, 'a');
  printf("Quantity of item %c: %d\n", 'a', quantity);

  return 0;
}