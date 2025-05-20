//Gemma-7B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdlib.h>
#include <unistd.h>

#define MAX_ALLOC 1024

typedef struct Node {
  struct Node* next;
  int data;
} Node;

Node* head = NULL;

void* my_malloc(int size) {
  if (head == NULL) {
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
  }

  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = size;

  head->next = newNode;
  head = newNode;

  return (void*)newNode->data;
}

void my_free(void* ptr) {
  Node* current = head;
  Node* previous = NULL;

  while (current) {
    if (current->data == ptr) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }

      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }

  return;
}

int main() {
  my_malloc(10);
  my_malloc(20);
  my_malloc(30);

  my_free(my_malloc(40));

  return 0;
}