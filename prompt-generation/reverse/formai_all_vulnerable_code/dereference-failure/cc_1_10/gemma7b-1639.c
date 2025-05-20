//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

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

void roundRobin(Node* head) {
  time_t start, end;
  int i, completed = 0, current = 0;
  Node* temp = head;

  start = time(NULL);
  while (!completed) {
    for (i = 0; i < MAX; i++) {
      if (temp->data != current) {
        temp = temp->next;
      } else {
        current = temp->data;
        completed++;
      }
    }
    end = time(NULL);
    printf("Time taken for completion: %f seconds\n", end - start);
  }
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);

  roundRobin(head);

  return 0;
}