//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void freeMemory(Node* head) {
  Node* current = head;
  Node* next = NULL;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  Node* head = NULL;
  int memoryUsed = 0;

  // Allocate memory for the first node
  head = malloc(sizeof(Node));
  head->data = 5;
  head->next = NULL;
  memoryUsed++;

  // Allocate memory for the second node
  head->next = malloc(sizeof(Node));
  head->next->data = 10;
  head->next->next = NULL;
  memoryUsed++;

  // Allocate memory for the third node
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 15;
  head->next->next->next = NULL;
  memoryUsed++;

  // Free memory used
  freeMemory(head);

  // Print memory used
  printf("Memory used: %d bytes\n", memoryUsed);

  return 0;
}