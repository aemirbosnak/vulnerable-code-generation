//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void printList(Node* head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtTail(head, 40);
  insertAtTail(head, 50);

  printList(head);

  // Greedy Algorithm
  Node* current = head;
  Node* previous = NULL;
  while (current) {
    previous = current;
    current = current->next;
    if (previous->data < current->data) {
      insertAtTail(head, previous->data);
      previous->data = current->data;
    }
  }

  printList(head);

  return 0;
}