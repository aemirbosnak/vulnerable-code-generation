//Gemma-7B DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 10

typedef struct MemoryBlock {
  struct MemoryBlock* next;
  void* data;
  int size;
} MemoryBlock;

MemoryBlock* head = NULL;

void* allocate(int size) {
  if (head == NULL) {
    head = malloc(sizeof(MemoryBlock));
    head->next = NULL;
    head->data = malloc(size);
    head->size = size;
  } else {
    MemoryBlock* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = malloc(sizeof(MemoryBlock));
    current->next->next = NULL;
    current->next->data = malloc(size);
    current->next->size = size;
  }

  return head->data;
}

void free(void* ptr) {
  MemoryBlock* current = head;
  MemoryBlock* previous = NULL;

  while (current) {
    if (current->data == ptr) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current->data);
      free(current);
    } else {
      previous = current;
      current = current->next;
    }
  }
}

int main() {
  allocate(10);
  allocate(20);
  allocate(30);
  allocate(40);

  free(allocate(10));
  free(allocate(20));

  printf("%p\n", allocate(50));

  return 0;
}