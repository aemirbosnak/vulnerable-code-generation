//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void InsertAtTail(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void GreedyAlgorithm(Node* head) {
  Node* current = head;
  Node* previous = NULL;

  while (current) {
    int currentData = current->data;
    int previousData = previous ? previous->data : 0;

    if (currentData > previousData) {
      printf("Data: %d, Previous Data: %d, Greed Gain: %d\n", currentData, previousData, currentData - previousData);
    }

    previous = current;
    current = current->next;
  }
}

int main() {
  Node* head = NULL;
  InsertAtTail(head, 10);
  InsertAtTail(head, 20);
  InsertAtTail(head, 30);
  InsertAtTail(head, 40);
  InsertAtTail(head, 50);

  GreedyAlgorithm(head);

  return 0;
}