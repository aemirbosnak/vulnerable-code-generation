//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char item[20];
  int quantity;
  struct Node* next;
};

struct Queue {
  struct Node* head;
  struct Node* tail;
};

void insert(struct Queue* queue, char item, int quantity) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->item, item);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (queue->head == NULL) {
    queue->head = newNode;
    queue->tail = newNode;
  } else {
    queue->tail->next = newNode;
    queue->tail = newNode;
  }
}

void traverse(struct Queue* queue) {
  struct Node* current = queue->head;
  while (current) {
    printf("%s: %d\n", current->item, current->quantity);
    current = current->next;
  }
}

int main() {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->head = NULL;
  queue->tail = NULL;

  insert(queue, "Apple", 10);
  insert(queue, "Banana", 5);
  insert(queue, "Orange", 15);

  traverse(queue);

  return 0;
}