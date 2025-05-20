//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

  IndexNode *traversal = head;
  IndexNode *prev = NULL;

  while (traversal) {
    if (strcmp(traversal->key, key) == 0) {
      return traversal;
    } else if (strcmp(traversal->key, key) < 0) {
      prev = traversal;
      traversal = traversal->next;
    } else {
      break;
    }
  }

  if (prev) {
    prev->next = newNode;
  } else {
    head = newNode;
  }

  return head;
}

int main() {
  IndexNode *head = NULL;

  char *key1 = "Surrealist Dream";
  insertIndexNode(head, key1);

  char *key2 = "Metaphysical Journey";
  insertIndexNode(head, key2);

  char *key3 = "Quantum Leap";
  insertIndexNode(head, key3);

  char *key4 = "Temporal Displacement";
  insertIndexNode(head, key4);

  IndexNode *traversal = head;

  while (traversal) {
    printf("%s\n", traversal->key);
    traversal = traversal->next;
  }

  return 0;
}