//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insert(Node* head, int data) {
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
  int count = 1;
  Node* current = head;
  Node* previous = NULL;

  while (current) {
    if (previous && current->data == previous->data) {
      count++;
    } else {
      previous = current;
      printf("%d ", count);
      count = 1;
    }
  }

  printf("\n");
}

int main() {
  Node* head = insert(NULL, 1);
  insert(head, 1);
  insert(head, 2);
  insert(head, 2);
  insert(head, 3);
  insert(head, 3);
  insert(head, 4);

  compress(head);

  return 0;
}