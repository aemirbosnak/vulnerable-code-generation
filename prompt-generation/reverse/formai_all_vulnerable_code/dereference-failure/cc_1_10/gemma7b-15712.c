//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: immersive
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

void GreedyAlgortihms(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int total = 0;

  while (current) {
    int currentData = current->data;
    int previousData = previous ? previous->data : 0;

    if (currentData > previousData) {
      total += currentData - previousData;
    }

    previous = current;
    current = current->next;
  }

  printf("Total: %d", total);
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtTail(head, 40);
  insertAtTail(head, 50);

  GreedyAlgortihms(head);

  return 0;
}