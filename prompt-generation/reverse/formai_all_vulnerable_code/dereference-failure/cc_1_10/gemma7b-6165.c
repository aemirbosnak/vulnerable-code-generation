//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  struct Node* next;
  char data;
} Node;

void insert(Node** head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void compress(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int count = 1;

  while (current) {
    if (previous && current->data == previous->data) {
      count++;
    } else {
      insert(previous, count);
      previous = current;
      count = 1;
    }
    current = current->next;
  }

  insert(previous, count);
}

int main() {
  Node* head = NULL;
  insert(&head, 'a');
  insert(&head, 'a');
  insert(&head, 'b');
  insert(&head, 'b');
  insert(&head, 'c');
  insert(&head, 'c');

  compress(head);

  Node* current = head;
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}