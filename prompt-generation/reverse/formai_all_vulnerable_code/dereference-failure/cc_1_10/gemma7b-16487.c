//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Node* insert(struct Node* head, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int compress(struct Node* head) {
  int count = 0;
  struct Node* current = head;
  struct Node* previous = NULL;

  while (current) {
    int runs = 1;
    while (previous && current->data == previous->data) {
      runs++;
      previous = previous->next;
    }

    if (runs > 1) {
      insert(head, runs - 1);
    }

    previous = current;
    current = current->next;
  }

  return count;
}

int main() {
  struct Node* head = insert(NULL, 1);
  insert(head, 1);
  insert(head, 2);
  insert(head, 2);
  insert(head, 3);
  insert(head, 3);
  insert(head, 4);

  int count = compress(head);

  printf("Number of nodes after compression: %d\n", count);

  return 0;
}