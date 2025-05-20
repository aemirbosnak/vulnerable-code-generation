//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVES 1000

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

void Hanoi(Node* head) {
  int moves = 0;
  while (head) {
    // Move the top disk to the third peg
    insertAtTail(head, head->data);
    head->data = -1;
    moves++;

    // Move the remaining disks to the second peg
    insertAtTail(head, head->next->data);
    head->next->data = -1;
    moves++;

    // Move the top disk from the third peg to the second peg
    insertAtTail(head, head->data);
    head->data = -1;
    moves++;

    head = head->next;
  }

  printf("Number of moves: %d\n", moves);
}

int main() {
  Node* head = insertAtTail(NULL, 3);
  insertAtTail(head, 2);
  insertAtTail(head, 1);

  Hanoi(head);

  return 0;
}