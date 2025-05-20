//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NR 10
#define Quantum 4

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* InsertAtTail(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void RoundRobin(Node* head) {
  int i = 0;
  Node* current = head;
  while (current) {
    sleep(Quantum);
    printf("Process %d is running\n", current->data);
    i++;
    if (i == NR) {
      current = head;
      i = 0;
    } else {
      current = current->next;
    }
  }
}

int main() {
  Node* head = InsertAtTail(NULL, 1);
  InsertAtTail(head, 2);
  InsertAtTail(head, 3);
  InsertAtTail(head, 4);
  InsertAtTail(head, 5);

  RoundRobin(head);

  return 0;
}