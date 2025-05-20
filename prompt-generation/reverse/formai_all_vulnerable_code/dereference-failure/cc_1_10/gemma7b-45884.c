//Gemma-7B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdlib.h>

struct Node {
  struct Node* next;
  void* data;
};

struct MemoryManager {
  struct Node* head;
  struct Node* tail;
  int size;
};

void* mm_alloc(struct MemoryManager* mm, int size) {
  struct Node* newNode = malloc(sizeof(struct Node) + size);
  newNode->data = (void*)newNode + sizeof(struct Node);
  newNode->next = NULL;

  if (mm->head == NULL) {
    mm->head = newNode;
    mm->tail = newNode;
  } else {
    mm->tail->next = newNode;
    mm->tail = newNode;
  }

  mm->size++;
  return newNode->data;
}

void mm_free(struct MemoryManager* mm, void* ptr) {
  struct Node* nodeToFree = mm->head;

  while (nodeToFree) {
    if (nodeToFree->data == ptr) {
      free(nodeToFree);
      mm->size--;
      return;
    }

    nodeToFree = nodeToFree->next;
  }

  return;
}

int main() {
  struct MemoryManager* mm = malloc(sizeof(struct MemoryManager));
  mm->head = NULL;
  mm->tail = NULL;
  mm->size = 0;

  void* ptr1 = mm_alloc(mm, 10);
  void* ptr2 = mm_alloc(mm, 20);
  void* ptr3 = mm_alloc(mm, 30);

  mm_free(mm, ptr2);

  ptr2 = mm_alloc(mm, 20);

  free(mm);

  return 0;
}