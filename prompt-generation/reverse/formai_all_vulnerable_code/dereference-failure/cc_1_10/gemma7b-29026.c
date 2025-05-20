//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 64

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Pile {
  Node* head;
  int size;
} Pile;

void insert_pile(Pile* p, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (p->head == NULL) {
    p->head = newNode;
  } else {
    p->head->next = newNode;
  }
  p->size++;
}

void move_disk(Pile* from, Pile* to) {
  if (from->size > 0) {
    Node* movedNode = from->head;
    insert_pile(to, movedNode->data);
    from->size--;
    free(movedNode);
  }
}

int main() {
  Pile* pileA = malloc(sizeof(Pile));
  pileA->head = NULL;
  pileA->size = 0;

  Pile* pileB = malloc(sizeof(Pile));
  pileB->head = NULL;
  pileB->size = 0;

  Pile* pileC = malloc(sizeof(Pile));
  pileC->head = NULL;
  pileC->size = 0;

  insert_pile(pileA, 3);
  insert_pile(pileA, 2);
  insert_pile(pileA, 1);

  move_disk(pileA, pileB);
  move_disk(pileB, pileC);

  printf("Final state:");
  for (Node* node = pileC->head; node; node = node->next) {
    printf(" %d", node->data);
  }

  return 0;
}