//Gemma-7B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  void* data;
} Node;

typedef struct MemoryManager {
  Node* head;
  int size;
} MemoryManager;

MemoryManager* mm_init(int size) {
  MemoryManager* mm = malloc(sizeof(MemoryManager));
  mm->head = NULL;
  mm->size = size;
  return mm;
}

void mm_insert(MemoryManager* mm, void* data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = mm->head;
  mm->head = newNode;
}

void* mm_retrieve(MemoryManager* mm, int index) {
  Node* current = mm->head;
  for (int i = 0; i < index && current; i++) {
    current = current->next;
  }
  return current->data;
}

void mm_free(MemoryManager* mm) {
  Node* current = mm->head;
  while (current) {
    Node* next = current->next;
    free(current);
    current = next;
  }
  free(mm);
}

int main() {
  MemoryManager* mm = mm_init(10);
  mm_insert(mm, "John Doe");
  mm_insert(mm, "Jane Doe");
  mm_insert(mm, "Bill Smith");

  printf("%s\n", (char*)mm_retrieve(mm, 1));

  mm_free(mm);

  return 0;
}