//Gemma-7B DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1024

struct Password {
  char *name;
  char *password;
  struct Password *next;
};

void insert(struct Password **head, char *name, char *password) {
  struct Password *new_node = malloc(sizeof(struct Password));
  new_node->name = strdup(name);
  new_node->password = strdup(password);
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

char *search(struct Password *head, char *name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return head->password;
    }
    head = head->next;
  }
  return NULL;
}

int main() {
  struct Password *head = NULL;

  insert( &head, "Anya", "TheOneAndOnly");
  insert( &head, "Boris", "BackFromTheDead");
  insert( &head, "Charlie", "ASecretCode");

  char *password = search(head, "Anya");

  if (password) {
    printf("Anya's password is: %s\n", password);
  } else {
    printf("Anya's password is not found.\n");
  }

  return 0;
}