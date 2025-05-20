//Gemma-7B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdlib.h>

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct MemMan {
  Node *head;
  int size;
  int alloc_size;
} MemMan;

MemMan *createMemMan(int size) {
  MemMan *mm = malloc(sizeof(MemMan));
  mm->head = NULL;
  mm->size = 0;
  mm->alloc_size = size;
  return mm;
}

void addToMemMan(MemMan *mm, void *data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = mm->head;
  mm->head = newNode;
  mm->size++;
}

void *removeFromMemMan(MemMan *mm) {
  if (mm->size == 0) {
    return NULL;
  }
  Node *oldHead = mm->head;
  mm->head = mm->head->next;
  mm->size--;
  free(oldHead);
  return oldHead->data;
}

int main() {
  MemMan *mm = createMemMan(10);
  addToMemMan(mm, "abc");
  addToMemMan(mm, "def");
  addToMemMan(mm, "ghi");
  removeFromMemMan(mm);
  removeFromMemMan(mm);
  printf("%s", removeFromMemMan(mm));
  return 0;
}