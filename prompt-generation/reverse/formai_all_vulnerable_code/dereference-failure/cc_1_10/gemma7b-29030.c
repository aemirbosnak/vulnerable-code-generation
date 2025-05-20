//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryCell {
  int value;
  struct MemoryCell* next;
} MemoryCell;

MemoryCell* createMemoryCell(int value) {
  MemoryCell* newCell = (MemoryCell*)malloc(sizeof(MemoryCell));
  newCell->value = value;
  newCell->next = NULL;
  return newCell;
}

void insertMemoryCell(MemoryCell* head, int value) {
  MemoryCell* newCell = createMemoryCell(value);
  if (head == NULL) {
    head = newCell;
  } else {
    newCell->next = head;
    head = newCell;
  }
}

int searchMemoryCell(MemoryCell* head, int value) {
  while (head) {
    if (head->value == value) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int main() {
  MemoryCell* head = NULL;
  insertMemoryCell(head, 5);
  insertMemoryCell(head, 10);
  insertMemoryCell(head, 15);
  insertMemoryCell(head, 20);
  insertMemoryCell(head, 25);

  if (searchMemoryCell(head, 10) == 1) {
    printf("10 is in the memory.\n");
  }

  if (searchMemoryCell(head, 30) == 0) {
    printf("30 is not in the memory.\n");
  }

  return 0;
}