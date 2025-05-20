//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
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
  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
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

  // Greedy Algorithm - Sort the linked list in descending order

  Node* current = head;
  Node* previous = NULL;
  while (current) {
    Node* next = current->next;
    if (previous && current->data < previous->data) {
      insertAtTail(head, current->data);
      previous->next = next;
      current = next;
    } else {
      previous = current;
    }
  }

  printList(head);

  return 0;
}