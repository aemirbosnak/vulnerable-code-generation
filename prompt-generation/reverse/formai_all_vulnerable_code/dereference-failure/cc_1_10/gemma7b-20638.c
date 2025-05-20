//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode {
  char *key;
  struct IndexNode *next;
} IndexNode;

IndexNode *insertIndexNode(IndexNode *head, char *key) {
  IndexNode *newNode = malloc(sizeof(IndexNode));
  newNode->key = strdup(key);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  IndexNode *traversingNode = head;
  while (traversingNode->next) {
    traversingNode = traversingNode->next;
  }

  traversingNode->next = newNode;
  return head;
}

int searchIndex(IndexNode *head, char *key) {
  IndexNode *traversingNode = head;
  while (traversingNode) {
    if (strcmp(traversingNode->key, key) == 0) {
      return 1;
    }
    traversingNode = traversingNode->next;
  }

  return 0;
}

int main() {
  IndexNode *head = NULL;
  head = insertIndexNode(head, "John");
  head = insertIndexNode(head, "Mary");
  head = insertIndexNode(head, "Bob");
  head = insertIndexNode(head, "Alice");

  if (searchIndex(head, "Mary") == 1) {
    printf("Mary is found!");
  } else {
    printf("Mary is not found!");
  }

  return 0;
}