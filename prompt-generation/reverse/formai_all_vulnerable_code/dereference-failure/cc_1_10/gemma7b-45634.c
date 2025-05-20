//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 1024

typedef struct Node {
  struct Node* next;
  void* data;
  int size;
} Node;

Node* head = NULL;

void* allocate(int size) {
  if (head == NULL) {
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->data = (void*)malloc(size);
    head->size = size;
  } else {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = head;
    head = newNode;
    newNode->data = (void*)malloc(size);
    newNode->size = size;
  }
  return head->data;
}

void free(void* ptr) {
  Node* current = head;
  Node* previous = NULL;
  while (current) {
    if (current->data == ptr) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current->data);
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
  return;
}

int main() {
  allocate(10);
  allocate(20);
  allocate(30);
  allocate(40);

  free(allocate(10));
  free(allocate(20));

  printf("Remaining allocations: %d\n", head->size);

  return 0;
}