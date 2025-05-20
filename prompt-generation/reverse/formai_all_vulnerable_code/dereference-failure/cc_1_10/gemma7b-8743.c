//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024

typedef struct MemoryCell {
  struct MemoryCell* next;
  char* data;
  int size;
} MemoryCell;

MemoryCell* head = NULL;

void* allocate(int size) {
  MemoryCell* newCell = malloc(sizeof(MemoryCell) + size);
  newCell->next = head;
  head = newCell;
  newCell->size = size;
  newCell->data = (char*)newCell + sizeof(MemoryCell);
  return newCell->data;
}

void free(void* ptr) {
  MemoryCell* currentCell = head;
  MemoryCell* previousCell = NULL;

  while (currentCell && currentCell->data != ptr) {
    previousCell = currentCell;
    currentCell = currentCell->next;
  }

  if (previousCell) {
    previousCell->next = currentCell->next;
  } else {
    head = currentCell->next;
  }

  free(currentCell);
}

int main() {
  void* ptr = allocate(10);
  strcpy(ptr, "Hello, world!");
  printf("%s\n", ptr);

  free(ptr);
  ptr = allocate(20);
  strcpy(ptr, "Goodbye, cruel world!");
  printf("%s\n", ptr);

  free(ptr);

  return 0;
}