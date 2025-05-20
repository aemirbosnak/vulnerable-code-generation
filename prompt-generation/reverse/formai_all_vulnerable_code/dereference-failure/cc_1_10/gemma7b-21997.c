//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* insertNode(Node* head, char data) {
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

void compress(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int count = 1;

  while (current) {
    if (previous && current->data == previous->data) {
      count++;
    } else {
      insertNode(previous, count);
      previous = current;
      count = 1;
    }
  }

  insertNode(previous, count);
}

int main() {
  Node* head = NULL;
  head = insertNode(head, 'a');
  head = insertNode(head, 'a');
  head = insertNode(head, 'b');
  head = insertNode(head, 'b');
  head = insertNode(head, 'c');
  head = insertNode(head, 'c');

  compress(head);

  Node* current = head;
  while (current) {
    printf("%c ", current->data);
  }

  printf("\n");

  return 0;
}