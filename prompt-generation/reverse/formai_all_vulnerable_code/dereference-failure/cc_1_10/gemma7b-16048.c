//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef struct Node {
  char name[MAX_LIST_SIZE];
  struct Node* next;
} Node;

void addToTail(Node** head, char* name) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
  }
}

void deleteFromList(Node** head, char* name) {
  Node* prev = NULL;
  Node* current = *head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (prev) {
        prev->next = current->next;
      } else {
        *head = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }

  printf("Error: Name not found.\n");
  return;
}

int main() {
  Node* head = NULL;

  addToTail(&head, "John Doe");
  addToTail(&head, "Jane Doe");
  addToTail(&head, "Peter Pan");

  deleteFromList(&head, "Jane Doe");

  printf("List:");
  for (Node* current = head; current; current = current->next) {
    printf(" %s", current->name);
  }

  return 0;
}