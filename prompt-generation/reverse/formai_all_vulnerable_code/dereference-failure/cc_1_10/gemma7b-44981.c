//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdlib.h>

#define BLOCK_SIZE 8

typedef struct Node {
  struct Node* next;
  int data;
} Node;

typedef struct MemMan {
  Node* head;
  int size;
  int alloc_size;
} MemMan;

MemMan* mem_man_init(int size) {
  MemMan* mm = malloc(sizeof(MemMan));
  mm->head = NULL;
  mm->size = size;
  mm->alloc_size = 0;
  return mm;
}

void mem_man_alloc(MemMan* mm, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = mm->head;
  mm->head = newNode;
  mm->alloc_size++;
}

void mem_man_free(MemMan* mm, int data) {
  Node* prev = NULL;
  Node* current = mm->head;
  while (current) {
    if (current->data == data) {
      if (prev) {
        prev->next = current->next;
      } else {
        mm->head = current->next;
      }
      free(current);
      mm->alloc_size--;
      return;
    }
    prev = current;
    current = current->next;
  }
  return;
}

int main() {
  MemMan* mm = mem_man_init(10);
  mem_man_alloc(mm, 10);
  mem_man_alloc(mm, 20);
  mem_man_alloc(mm, 30);
  mem_man_free(mm, 20);
  mem_man_free(mm, 30);
  return 0;
}