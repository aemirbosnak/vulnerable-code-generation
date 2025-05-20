//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

void greedyAlgorithms(Node* head) {
  int i = 0;
  Node* current = head;
  Node* previous = NULL;

  while (current) {
    int currentData = current->data;
    int previousData = (previous) ? previous->data : 0;

    if (currentData > previousData) {
      insertAtTail(head, currentData);
      previous = current;
    }
    i++;
    current = current->next;
  }

  printf("Number of operations: %d\n", i);
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtTail(head, 40);
  insertAtTail(head, 50);

  greedyAlgorithms(head);

  return 0;
}