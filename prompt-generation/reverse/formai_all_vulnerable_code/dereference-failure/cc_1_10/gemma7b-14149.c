//Gemma-7B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
  char **passwords;
  struct Node* next;
} Node;

void insert(Node** head, char* password) {
  Node* newNode = malloc(sizeof(Node));
  newNode->passwords = malloc(MAX * sizeof(char*));
  newNode->next = NULL;

  for (int i = 0; i < MAX; i++) {
    newNode->passwords[i] = NULL;
  }

  int i = 0;
  for (char** p = head; *p; p++) {
    i++;
  }

  newNode->passwords[i] = password;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void search(Node* head, char* password) {
  for (Node* current = head; current; current = current->next) {
    for (int i = 0; current->passwords[i] != NULL; i++) {
      if (strcmp(current->passwords[i], password) == 0) {
        printf("Password found: %s\n", current->passwords[i]);
      }
    }
  }
}

int main() {
  Node* head = NULL;

  insert(&head, "my_secret_password");
  insert(&head, "another_strong_password");
  insert(&head, "weak_password");

  search(head, "my_secret_password");
  search(head, "another_strong_password");
  search(head, "weak_password");

  return 0;
}