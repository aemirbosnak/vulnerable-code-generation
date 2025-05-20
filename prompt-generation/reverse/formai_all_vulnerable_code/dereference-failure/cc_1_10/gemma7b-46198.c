//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
  struct Node* next;
  int data;
} Node;

struct Warehouse {
  Node* head;
  int size;
  char name[20];
};

void insertAtTail(struct Warehouse* warehouse, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = newNode;
  } else {
    warehouse->head->next = newNode;
  }

  warehouse->size++;
}

void search(struct Warehouse* warehouse, int data) {
  Node* current = warehouse->head;

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
  struct Warehouse warehouse;
  warehouse.head = NULL;
  warehouse.size = 0;
  strcpy(warehouse.name, "My Warehouse");

  insertAtTail(&warehouse, 10);
  insertAtTail(&warehouse, 20);
  insertAtTail(&warehouse, 30);

  search(&warehouse, 20);

  return 0;
}