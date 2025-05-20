//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INDEX_SIZE 1024

typedef struct IndexNode {
  char *key;
  struct IndexNode *next;
} IndexNode;

IndexNode **createIndex(char *key) {
  IndexNode **head = (IndexNode **)malloc(sizeof(IndexNode *) * MAX_INDEX_SIZE);
  IndexNode *newNode = (IndexNode *)malloc(sizeof(IndexNode));

  newNode->key = strdup(key);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }

  return head;
}

void searchIndex(IndexNode **head, char *key) {
  IndexNode *current = *head;

  while (current) {
    if (strcmp(current->key, key) == 0) {
      printf("Key found: %s\n", current->key);
      return;
    } else if (strcmp(current->key, key) < 0) {
      current = current->next;
    }
  }

  printf("Key not found: %s\n", key);
}

int main() {
  IndexNode **index = createIndex("John Doe");
  createIndex("Jane Doe");
  createIndex("Peter Pan");

  searchIndex(index, "Jane Doe");
  searchIndex(index, "Bob Smith");

  return 0;
}