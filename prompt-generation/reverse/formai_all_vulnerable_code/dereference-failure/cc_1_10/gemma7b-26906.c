//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

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

void compress(Node* head) {
  int count = 0;
  Node* current = head;
  Node* previous = NULL;

  while (current) {
    int runs = 1;
    while (previous && current->data == previous->data) {
      runs++;
      previous = previous->next;
    }

    if (runs > 1) {
      insertAtTail(head, runs);
    }

    previous = current;
    current = current->next;
  }

  free(previous);
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 3);
  insertAtTail(head, 4);

  compress(head);

  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}