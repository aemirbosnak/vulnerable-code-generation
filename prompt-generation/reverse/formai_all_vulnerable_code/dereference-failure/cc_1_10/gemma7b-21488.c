//Gemma-7B DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

void insert_password(Password **head, char *name, char *password) {
  Password *new_password = (Password *)malloc(sizeof(Password));
  new_password->name = strdup(name);
  new_password->password = strdup(password);
  new_password->next = NULL;

  if (*head == NULL) {
    *head = new_password;
  } else {
    (*head)->next = new_password;
  }
}

void search_password(Password *head, char *name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Password: %s\n", head->password);
      return;
    }
    head = head->next;
  }

  printf("Password not found.\n");
}

int main() {
  Password *head = NULL;

  insert_password(&head, "John Doe", "Secret123");
  insert_password(&head, "Jane Doe", "StrongPaswd");
  insert_password(&head, "Bill Smith", "WeakPaswd");

  search_password(head, "John Doe");
  search_password(head, "Jane Doe");
  search_password(head, "Bill Smith");

  return 0;
}