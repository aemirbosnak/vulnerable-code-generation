//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_INDEX_LENGTH 10

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  int index;
  struct Node* next;
} Node;

void insert(Node** head, char* name, int index) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->index = index;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int find(Node* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return head->index;
    }
    head = head->next;
  }

  return -1;
}

int main() {
  Node* head = NULL;

  insert(&head, "Johnny Chrome", 0);
  insert(&head, "Cyberpunk Sue", 1);
  insert(&head, "The Matrix", 2);

  int index = find(head, "Cyberpunk Sue");

  if (index != -1) {
    printf("Index of Cyberpunk Sue: %d\n", index);
  } else {
    printf("Name not found.\n");
  }

  return 0;
}