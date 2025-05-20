//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

void greedyAlgorithm(Node** head) {
  Node* current = *head;
  Node* previous = NULL;
  int total = 0;

  while (current) {
    int currentData = current->data;
    current->data = total;
    total += currentData;
    previous = current;
    current = current->next;
  }

  *head = previous;
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 10);
  insertAtTail(&head, 20);
  insertAtTail(&head, 30);
  insertAtTail(&head, 40);
  insertAtTail(&head, 50);

  greedyAlgorithm(&head);

  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}