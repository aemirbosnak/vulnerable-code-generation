//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Warehouse {
  struct Node* head;
  struct Node* tail;
  int size;
};

void insert(struct Warehouse* warehouse, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newNode;
    warehouse->tail = newNode;
  } else {
    warehouse->tail->next = newNode;
    warehouse->tail = newNode;
  }

  warehouse->size++;
}

void search(struct Warehouse* warehouse, int data) {
  struct Node* current = warehouse->head;

  while (current) {
    if (current->data == data) {
      printf("Item found!\n");
      return;
    }

    current = current->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
  warehouse->head = NULL;
  warehouse->tail = NULL;
  warehouse->size = 0;

  insert(warehouse, 10);
  insert(warehouse, 20);
  insert(warehouse, 30);
  insert(warehouse, 40);

  search(warehouse, 20);
  search(warehouse, 50);

  return 0;
}