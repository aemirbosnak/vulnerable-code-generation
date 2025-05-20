//Gemma-7B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct Node {
  struct Node* next;
  int data;
} Node;

Node* head = NULL;

void* allocate(int size) {
  if (head == NULL) {
    head = malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
  }

  Node* newNode = malloc(size);
  newNode->next = head->next;
  head->next = newNode;
  newNode->data = 0;

  return newNode;
}

void free(void* ptr) {
  Node* prev = NULL;
  Node* current = head;

  while (current) {
    if (current == ptr) {
      if (prev) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }

    prev = current;
    current = current->next;
  }

  return;
}

int main() {
  allocate(20);
  allocate(30);
  allocate(40);

  free(allocate(10));

  return 0;
}