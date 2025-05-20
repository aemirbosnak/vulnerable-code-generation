//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_RAM_SIZE 8192
#define RAM_UNIT "KB"

typedef struct MemBlock {
  int used;
  int free;
  struct MemBlock* next;
} MemBlock;

MemBlock* head = NULL;

void updateMemUsage(int size) {
  MemBlock* current = head;
  if (head == NULL) {
    head = malloc(sizeof(MemBlock));
    head->used = size;
    head->free = MAX_RAM_SIZE - size;
    head->next = NULL;
  } else {
    while (current->next) {
      if (current->free < size) {
        current = current->next;
      } else {
        break;
      }
    }

    if (current->free >= size) {
      current->used += size;
      current->free -= size;
    } else {
      MemBlock* newBlock = malloc(sizeof(MemBlock));
      newBlock->used = size;
      newBlock->free = MAX_RAM_SIZE - size;
      newBlock->next = current->next;
      current->next = newBlock;
    }
  }
}

int main() {
  updateMemUsage(2048);
  updateMemUsage(1024);
  updateMemUsage(512);
  updateMemUsage(1536);

  MemBlock* current = head;
  while (current) {
    printf("Block: used %d %s, free %d %s\n", current->used, RAM_UNIT, current->free, RAM_UNIT);
    current = current->next;
  }

  return 0;
}