//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
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

void printList(Node* head) {
  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void cpuSchedule(Node* head) {
  int i = 0;
  Node* current = head;
  while (current) {
    printf("Process %d is running...\n", current->data);
    sleep(i);
    i++;
    current = current->next;
  }
}

int main() {
  Node* head = insertAtTail(NULL, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);

  printList(head);
  cpuSchedule(head);

  return 0;
}