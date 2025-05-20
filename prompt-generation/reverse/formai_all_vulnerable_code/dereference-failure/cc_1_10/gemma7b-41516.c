//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
  char key[256];
  struct Entry* next;
} Entry;

Entry* insert(Entry* head, char* key) {
  Entry* newNode = malloc(sizeof(Entry));
  strcpy(newNode->key, key);
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  Entry* current = head;
  Entry* previous = NULL;

  while (current) {
    if (strcmp(newNode->key, current->key) < 0) {
      previous = current;
      current = current->next;
    } else {
      break;
    }
  }

  if (previous) {
    previous->next = newNode;
  } else {
    head = newNode;
  }

  return head;
}

int main() {
  Entry* head = NULL;

  insert(head, "apple");
  insert(head, "banana");
  insert(head, "cherry");
  insert(head, "orange");

  Entry* current = head;

  while (current) {
    printf("%s ", current->key);
    current = current->next;
  }

  printf("\n");

  return 0;
}