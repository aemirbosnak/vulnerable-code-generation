//Gemma-7B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdlib.h>
#include <stdio.h>

#define MAX_ALLOCATIONS 10

typedef struct Node {
  struct Node* next;
  int data;
} Node;

Node* head = NULL;
int allocations = 0;

void insert(int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }

  allocations++;
  if (allocations >= MAX_ALLOCATIONS) {
    printf("Error: Memory exhausted!\n");
  }
}

void traverse() {
  Node* current = head;
  while (current) {
    printf("Data: %d\n", current->data);
    current = current->next;
  }
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);

  traverse();

  return 0;
}