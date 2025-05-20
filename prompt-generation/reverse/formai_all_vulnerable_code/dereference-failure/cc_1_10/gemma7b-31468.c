//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryCell {
  char data[MAX_MEMORY_SIZE];
  struct MemoryCell* next;
} MemoryCell;

void initializeMemory(MemoryCell** head) {
  *head = NULL;
}

void addToMemory(MemoryCell** head, char data) {
  MemoryCell* newCell = malloc(sizeof(MemoryCell));
  newCell->data[0] = data;
  newCell->next = NULL;

  if (*head == NULL) {
    *head = newCell;
  } else {
    (*head)->next = newCell;
  }
}

char retrieveFromMemory(MemoryCell* head, int index) {
  MemoryCell* currentCell = head;
  for (int i = 0; i < index; i++) {
    currentCell = currentCell->next;
  }
  return currentCell->data[0];
}

int main() {
  MemoryCell* head = NULL;
  initializeMemory(&head);

  // Add data to the memory
  addToMemory(&head, 'a');
  addToMemory(&head, 'b');
  addToMemory(&head, 'c');
  addToMemory(&head, 'd');

  // Retrieve data from the memory
  char data = retrieveFromMemory(head, 2);

  // Print the retrieved data
  printf("%c", data);

  return 0;
}