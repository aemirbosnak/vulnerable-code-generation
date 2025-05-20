//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Heap {
  Node** arr;
  int size;
  int capacity;
} Heap;

Heap* createHeap(int capacity) {
  Heap* heap = malloc(sizeof(Heap));
  heap->arr = NULL;
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

void insertHeap(Heap* heap, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (heap->size == heap->capacity) {
    printf("Heap Overflow\n");
    return;
  }

  heap->arr = realloc(heap->arr, (heap->size + 1) * sizeof(Node));
  heap->arr[heap->size++] = newNode;
}

int peekHeap(Heap* heap) {
  if (heap->size == 0) {
    return -1;
  }
  return heap->arr[0]->data;
}

int main() {
  Heap* heap = createHeap(5);
  insertHeap(heap, 10);
  insertHeap(heap, 20);
  insertHeap(heap, 30);
  insertHeap(heap, 40);
  insertHeap(heap, 50);

  for (int i = 0; i < heap->size; i++) {
    printf("%d ", peekHeap(heap));
  }

  printf("\n");

  return 0;
}