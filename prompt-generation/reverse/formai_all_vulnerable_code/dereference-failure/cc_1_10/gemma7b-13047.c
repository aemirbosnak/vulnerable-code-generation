//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void compress(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int count = 1;

  while (current) {
    if (previous && current->data == previous->data) {
      count++;
    } else {
      if (previous) {
        insertAtTail(head, previous->data) -> data = count;
      }

      previous = current;
      count = 1;
    }
  }

  if (previous) {
    insertAtTail(head, previous->data) -> data = count;
  }
}

int main() {
  Node* head = insertAtTail(NULL, 'a');
  insertAtTail(head, 'a');
  insertAtTail(head, 'b');
  insertAtTail(head, 'b');
  insertAtTail(head, 'c');

  compress(head);

  head = head->next;
  while (head) {
    printf("%c ", head->data);
    head = head->next;
  }

  printf("\n");

  return 0;
}