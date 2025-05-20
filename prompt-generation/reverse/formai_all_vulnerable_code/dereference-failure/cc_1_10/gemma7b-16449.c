//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024

typedef struct Node {
  struct Node* next;
  char data[MAX_STRING_LENGTH];
} Node;

typedef struct Heap {
  int size;
  struct Node** nodes;
} Heap;

void insert_node(Heap* heap, char* data) {
  Node* new_node = malloc(sizeof(Node));
  strcpy(new_node->data, data);
  new_node->next = NULL;

  if (heap->size == 0) {
    heap->nodes = malloc(sizeof(Node*) * 1);
    heap->nodes[0] = new_node;
  } else {
    heap->nodes = realloc(heap->nodes, sizeof(Node*) * (heap->size + 1));
    heap->nodes[heap->size++] = new_node;
  }
}

void traverse_heap(Heap* heap) {
  for (int i = 0; i < heap->size; i++) {
    printf("%s ", heap->nodes[i]->data);
  }
  printf("\n");
}

int main() {
  Heap* heap = malloc(sizeof(Heap));
  heap->size = 0;
  heap->nodes = NULL;

  insert_node(heap, "John Doe");
  insert_node(heap, "Jane Doe");
  insert_node(heap, "Peter Pan");
  insert_node(heap, "Captain Hook");

  traverse_heap(heap);

  return 0;
}