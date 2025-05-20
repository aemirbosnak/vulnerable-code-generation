//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 100

typedef struct Node {
  char name[MAX_SIZE];
  struct Node* next;
} Node;

Node* Insert(Node* head, char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int Index(Node* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;

  Insert(head, "John Doe");
  Insert(head, "Jane Doe");
  Insert(head, "Peter Pan");

  if (Index(head, "Jane Doe") == 1) {
    printf("Jane Doe found.\n");
  } else {
    printf("Jane Doe not found.\n");
  }

  return 0;
}