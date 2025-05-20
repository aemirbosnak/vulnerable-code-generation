//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void compress(Node** head) {
  int count = 0;
  Node* current = *head;
  Node* previous = NULL;

  while (current) {
    int runLength = 1;
    previous = current;

    while (current->next && current->data == previous->data) {
      current = current->next;
      runLength++;
    }

    if (runLength > 1) {
      insertAtTail(head, runLength - 1);
      insertAtTail(head, previous->data);
    } else {
      insertAtTail(head, current->data);
    }

    count++;
  }

  printf("Total nodes after compression: %d\n", count);
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 1);
  insertAtTail(&head, 1);
  insertAtTail(&head, 2);
  insertAtTail(&head, 2);
  insertAtTail(&head, 3);

  compress(&head);

  return 0;
}