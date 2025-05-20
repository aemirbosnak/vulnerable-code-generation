//Gemma-7B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOC_SIZE 1024

typedef struct Node {
  char data[MAX_ALLOC_SIZE];
  struct Node* next;
} Node;

Node* newNode(char data) {
  Node* node = malloc(sizeof(Node));
  if (!node) {
    return NULL;
  }

  node->data[0] = data;
  node->next = NULL;

  return node;
}

int main() {
  Node* head = newNode('a');
  if (!head) {
    return EXIT_FAILURE;
  }

  head->next = newNode('b');
  if (!head->next) {
    return EXIT_FAILURE;
  }

  head->next->next = newNode('c');
  if (!head->next->next) {
    return EXIT_FAILURE;
  }

  head->next->next->next = newNode('d');
  if (!head->next->next->next) {
    return EXIT_FAILURE;
  }

  head->next->next->next->next = newNode('e');
  if (!head->next->next->next->next) {
    return EXIT_FAILURE;
  }

  for (Node* current = head; current; current = current->next) {
    printf("%c ", current->data);
  }

  return EXIT_SUCCESS;
}