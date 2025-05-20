//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 10

typedef struct IndexNode {
  int key;
  struct IndexNode* next;
} IndexNode;

IndexNode* insertIndexNode(IndexNode* head, int key) {
  IndexNode* newNode = malloc(sizeof(IndexNode));
  newNode->key = key;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    IndexNode* current = head;
    IndexNode* previous = NULL;
    while (current) {
      if (key < current->key) {
        previous = current;
        current = current->next;
      } else if (key == current->key) {
        return NULL;
      }
    }
    previous->next = newNode;
  }

  return head;
}

void printIndex(IndexNode* head) {
  IndexNode* current = head;
  while (current) {
    printf("%d ", current->key);
    current = current->next;
  }
  printf("\n");
}

int main() {
  IndexNode* head = NULL;

  insertIndexNode(head, 5);
  insertIndexNode(head, 3);
  insertIndexNode(head, 8);
  insertIndexNode(head, 2);
  insertIndexNode(head, 4);

  printIndex(head);

  return 0;
}