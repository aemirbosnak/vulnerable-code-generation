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
  int totalSpace;
};

void insertItem(struct Warehouse* warehouse, char item, int quantity) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->item, item);
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
  warehouse->totalSpace++;
}

void removeItem(struct Warehouse* warehouse, char item) {
  struct Node* prevNode = NULL;
  struct Node* currentNode = warehouse->head;

  while (currentNode) {
    if (strcmp(currentNode->item, item) == 0) {
      if (prevNode) {
        prevNode->next = currentNode->next;
        warehouse->tail = prevNode;
      } else {
        warehouse->head = currentNode->next;
        warehouse->tail = warehouse->head;
      }

      warehouse->totalItems--;
      free(currentNode);
      return;
    }

    prevNode = currentNode;
    currentNode = currentNode->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
  warehouse->head = NULL;
  warehouse->tail = NULL;
  warehouse->totalItems = 0;
  warehouse->totalSpace = 1000;

  insertItem(warehouse, "Apple", 10);
  insertItem(warehouse, "Banana", 20);
  insertItem(warehouse, "Orange", 30);

  removeItem(warehouse, "Banana");

  printf("Items in the warehouse:");
  struct Node* currentNode = warehouse->head;
  while (currentNode) {
    printf(" %s (%d)", currentNode->item, currentNode->quantity);
  }

  return 0;
}