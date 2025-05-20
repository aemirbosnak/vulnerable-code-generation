//Gemma-7B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024

struct Node {
  struct Node* next;
  char* data;
  int size;
};

struct MemManager {
  struct Node* head;
  struct Node* tail;
  int usedMemory;
  int freeMemory;
};

struct MemManager* memManagerCreate() {
  struct MemManager* manager = malloc(sizeof(struct MemManager));
  manager->head = NULL;
  manager->tail = NULL;
  manager->usedMemory = 0;
  manager->freeMemory = MAX_MEMORY;
  return manager;
}

void memManagerInsert(struct MemManager* manager, char* data, int size) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = malloc(size);
  memcpy(newNode->data, data, size);
  newNode->size = size;
  newNode->next = NULL;

  if (manager->head == NULL) {
    manager->head = newNode;
    manager->tail = newNode;
  } else {
    manager->tail->next = newNode;
    manager->tail = newNode;
  }

  manager->usedMemory += size;
  manager->freeMemory -= size;
}

void memManagerDestroy(struct MemManager* manager) {
  struct Node* current = manager->head;
  struct Node* next = NULL;

  while (current) {
    next = current->next;
    free(current->data);
    free(current);
    current = next;
  }

  free(manager);
}

int main() {
  struct MemManager* manager = memManagerCreate();

  memManagerInsert(manager, "Hello, world!", 13);
  memManagerInsert(manager, "This is a memory management example.", 32);

  printf("Used memory: %d bytes\n", manager->usedMemory);
  printf("Free memory: %d bytes\n", manager->freeMemory);

  memManagerDestroy(manager);

  return 0;
}