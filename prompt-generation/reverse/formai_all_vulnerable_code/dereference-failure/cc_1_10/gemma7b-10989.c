//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  head = newNode;
}

void solveCase(Node* head) {
  int i = 0;
  Node* current = head;

  while (current) {
    i++;
    printf("Node %d: Data = %d\n", i, current->data);
    current = current->next;
  }

  printf("Total number of nodes: %d\n", i);
}

int main() {
  Node* head = NULL;

  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtTail(head, 40);
  insertAtTail(head, 50);

  solveCase(head);

  return 0;
}