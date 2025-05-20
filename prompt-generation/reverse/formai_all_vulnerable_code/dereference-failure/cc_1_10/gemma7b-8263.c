//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct MemoryCell {
  int data;
  struct MemoryCell* next;
} MemoryCell;

void initializeMemory(MemoryCell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_MEMORY; i++) {
    *head = malloc(sizeof(MemoryCell));
    ((*head)->data = 0);
    ((*head)->next = NULL);
    head = &((*head)->next);
  }
}

void storeMemory(MemoryCell** head, int data) {
  *head = malloc(sizeof(MemoryCell));
  ((*head)->data = data);
  ((*head)->next = NULL);
  head = &((*head)->next);
  if (*head) {
    *head = NULL;
  }
}

int retrieveMemory(MemoryCell** head, int address) {
  for (MemoryCell* cell = *head; cell; cell = cell->next) {
    if (cell->data == address) {
      return cell->data;
    }
  }
  return -1;
}

int main() {
  MemoryCell* head = NULL;
  initializeMemory(&head);
  storeMemory(&head, 10);
  storeMemory(&head, 20);
  storeMemory(&head, 30);
  storeMemory(&head, 40);
  storeMemory(&head, 50);
  storeMemory(&head, 60);
  storeMemory(&head, 70);
  storeMemory(&head, 80);
  storeMemory(&head, 90);
  storeMemory(&head, 100);

  int retrievedData = retrieveMemory(&head, 80);
  if (retrievedData != -1) {
    printf("Retrieved data: %d\n", retrievedData);
  } else {
    printf("Data not found.\n");
  }

  return 0;
}