//Gemma-7B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

struct password_node {
  char *password;
  struct password_node *next;
};

void insert_password(struct password_node **head, char *password) {
  struct password_node *new_node = malloc(sizeof(struct password_node));
  new_node->password = strdup(password);
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

int search_password(struct password_node *head, char *password) {
  while (head) {
    if (strcmp(head->password, password) == 0) {
      return 1;
    }
    head = head->next;
  }

  return 0;
}

int main() {
  struct password_node *passwords = NULL;

  insert_password(&passwords, "secret");
  insert_password(&passwords, "supersecret");
  insert_password(&passwords, "hidden");

  if (search_password(passwords, "secret") == 1) {
    printf("Secret password found!\n");
  }

  if (search_password(passwords, "nonexistent") == 1) {
    printf("Nonexistent password found!\n");
  }

  return 0;
}