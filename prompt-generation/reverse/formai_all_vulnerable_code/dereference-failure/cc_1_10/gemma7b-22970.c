//Gemma-7B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  void* data;
} Node;

typedef struct MemoryManager {
  Node* head;
  Node* tail;
  int size;
} MemoryManager;

MemoryManager* mm_init() {
  MemoryManager* mm = malloc(sizeof(MemoryManager));
  mm->head = NULL;
  mm->tail = NULL;
  mm->size = 0;
  return mm;
}

void mm_insert(MemoryManager* mm, void* data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (mm->head == NULL) {
    mm->head = node;
    mm->tail = node;
  } else {
    mm->tail->next = node;
    mm->tail = node;
  }

  mm->size++;
}

void mm_free(MemoryManager* mm, void* data) {
  Node* node = mm->head;
  while (node) {
    if (node->data == data) {
      free(node);
      mm->size--;
      break;
    }
    node = node->next;
  }
}

int main() {
  MemoryManager* mm = mm_init();

  mm_insert(mm, "a");
  mm_insert(mm, "b");
  mm_insert(mm, "c");

  mm_free(mm, "b");

  printf("%s\n", mm->head->data);
  printf("%s\n", mm->tail->data);

  free(mm);
  return 0;
}