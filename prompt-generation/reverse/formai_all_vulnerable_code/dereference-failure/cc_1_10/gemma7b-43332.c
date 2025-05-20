//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
  char name[MAX_SIZE];
  struct Node* next;
} Node;

struct Node** insertAtTail(struct Node** head, char* name) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }

  return head;
}

int searchByName(struct Node** head, char* name) {
  struct Node* current = *head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main() {
  struct Node** head = NULL;

  insertAtTail(&head, "John Doe");
  insertAtTail(&head, "Jane Doe");
  insertAtTail(&head, "Jack Doe");

  if (searchByName(&head, "Jane Doe") == 1) {
    printf("Jane Doe found!");
  } else {
    printf("Jane Doe not found!");
  }

  return 0;
}