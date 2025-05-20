//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
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

  head = newNode;
}

void printNodes(Node* head) {
  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void cpuSchedule(Node* head) {
  int quantum = 3;
  Node* current = head;
  while (current) {
    printf("Process: %d, Quantum: %d\n", current->data, quantum);
    quantum--;
    if (quantum == 0) {
      current = current->next;
      quantum = 3;
    }
  }
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);

  printNodes(head);
  cpuSchedule(head);

  return 0;
}