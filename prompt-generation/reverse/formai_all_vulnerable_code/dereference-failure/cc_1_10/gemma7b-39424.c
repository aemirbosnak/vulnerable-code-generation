//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next) = newNode;
  }
}

void compress(Node** head) {
  Node* current = *head;
  Node* previous = NULL;
  int count = 0;

  while (current) {
    char currentData = current->data;
    int runs = 1;

    while (previous && currentData == previous->data) {
      runs++;
      current = current->next;
    }

    if (runs > 1) {
      insertAtTail(head, (runs - 1) + 'a' - 1);
    }

    previous = current;
    current = current->next;
  }
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 'a');
  insertAtTail(&head, 'a');
  insertAtTail(&head, 'b');
  insertAtTail(&head, 'b');
  insertAtTail(&head, 'c');

  compress(&head);

  Node* current = head;
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }

  return 0;
}