//Gemma-7B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>

#define MAX_ALLOC 10

typedef struct Node {
  struct Node* next;
  void* data;
} Node;

Node* head = NULL;

void insert(void* data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void traverse() {
  Node* current = head;
  while (current) {
    printf("%p ", current->data);
    current = current->next;
  }
}

void free_mem() {
  Node* current = head;
  Node* next = NULL;
  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(40);

  traverse();

  free_mem();

  traverse();

  return 0;
}