//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Heap {
  Node* root;
  int size;
} Heap;

void insert(Heap* h, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (h->root == NULL) {
    h->root = newNode;
  } else {
    Node* lastNode = h->root;
    while (lastNode->next) {
      lastNode = lastNode->next;
    }
    lastNode->next = newNode;
  }

  h->size++;
}

void traverse(Heap* h) {
  Node* current = h->root;
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Heap* h = malloc(sizeof(Heap));
  h->root = NULL;
  h->size = 0;

  insert(h, 'a');
  insert(h, 'b');
  insert(h, 'c');
  insert(h, 'd');

  traverse(h);

  return 0;
}