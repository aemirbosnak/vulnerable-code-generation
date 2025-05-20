//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 100

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
      } else if (previous) {
        previous->next = newNode;
        newNode->next = current;
        break;
      }
    }
  }

  return head;
}

int searchIndex(IndexNode* head, int key) {
  IndexNode* current = head;
  while (current) {
    if (key == current->key) {
      return 1;
    } else if (key < current->key) {
      current = current->next;
    }
  }

  return 0;
}

int main() {
  IndexNode* head = NULL;
  insertIndexNode(head, 10);
  insertIndexNode(head, 20);
  insertIndexNode(head, 30);
  insertIndexNode(head, 40);
  insertIndexNode(head, 50);

  if (searchIndex(head, 30) == 1) {
    printf("Key found!\n");
  } else {
    printf("Key not found.\n");
  }

  return 0;
}