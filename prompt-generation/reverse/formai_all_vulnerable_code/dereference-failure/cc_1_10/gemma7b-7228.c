//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct Memory {
  int address;
  int value;
  struct Memory* next;
} Memory;

void initializeMemory(Memory** head) {
  *head = NULL;
  for (int i = 0; i < MAX_MEMORY; i++) {
    Memory* newMemory = malloc(sizeof(Memory));
    newMemory->address = i;
    newMemory->value = 0;
    newMemory->next = *head;
    *head = newMemory;
  }
}

void writeMemory(Memory** head, int address, int value) {
  Memory* current = *head;
  while (current) {
    if (current->address == address) {
      current->value = value;
      return;
    }
    current = current->next;
  }

  // Memory not found, need to allocate new memory
  Memory* newMemory = malloc(sizeof(Memory));
  newMemory->address = address;
  newMemory->value = value;
  newMemory->next = *head;
  *head = newMemory;
}

int readMemory(Memory** head, int address) {
  Memory* current = *head;
  while (current) {
    if (current->address == address) {
      return current->value;
    }
    current = current->next;
  }

  // Memory not found
  return -1;
}

int main() {
  Memory* head = NULL;
  initializeMemory(&head);

  writeMemory(&head, 5, 10);
  writeMemory(&head, 10, 20);

  int value = readMemory(&head, 5);
  printf("Value at address 5: %d\n", value);

  value = readMemory(&head, 10);
  printf("Value at address 10: %d\n", value);

  return 0;
}