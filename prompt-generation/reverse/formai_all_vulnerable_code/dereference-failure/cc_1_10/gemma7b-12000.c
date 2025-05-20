//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void Hanoi(Node* pileA, Node* pileB, Node* pileC) {
  if (pileA->data != 0) {
    Hanoi(pileA, pileB, pileC);
    insertAtTail(pileC, pileA->data);
    pileA->data = 0;
    Hanoi(pileB, pileC, pileA);
  }
}

int main() {
  Node* pileA = insertAtTail(NULL, 3);
  insertAtTail(pileA, 2);
  insertAtTail(pileA, 1);

  Node* pileB = NULL;
  Node* pileC = NULL;

  Hanoi(pileA, pileB, pileC);

  printf("Final state:\n");
  while (pileC) {
    printf("%d ", pileC->data);
    pileC = pileC->next;
  }

  return 0;
}