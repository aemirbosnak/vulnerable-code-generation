//Gemma-7B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 10

typedef struct Node {
  char *password;
  struct Node *next;
} Node;

Node *insert(Node *head, char *password) {
  Node *newNode = malloc(sizeof(Node));
  newNode->password = strdup(password);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = insert(head->next, password);
  }

  return head;
}

void search(Node *head, char *password) {
  while (head) {
    if (strcmp(head->password, password) == 0) {
      printf("Password found.\n");
      return;
    }
    head = head->next;
  }

  printf("Password not found.\n");
}

int main() {
  Node *head = NULL;

  insert(head, "secret");
  insert(head, "qwerty");
  insert(head, "password");

  search(head, "secret");
  search(head, "qwerty");
  search(head, "unknown");

  return 0;
}