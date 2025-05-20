//Gemma-7B DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 25

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

void insertPassword(Password **head) {
  Password *new_password = malloc(sizeof(Password));
  new_password->name = malloc(MAX_PASSWORD_LENGTH);
  new_password->password = malloc(MAX_PASSWORD_LENGTH);
  new_password->next = NULL;

  printf("Enter password name: ");
  scanf("%s", new_password->name);

  printf("Enter password: ");
  scanf("%s", new_password->password);

  if (*head == NULL) {
    *head = new_password;
  } else {
    (*head)->next = new_password;
  }
}

void listPasswords(Password *head) {
  while (head) {
    printf("%s: %s\n", head->name, head->password);
    head = head->next;
  }
}

int main() {
  Password *passwords = NULL;

  insertPassword(&passwords);
  insertPassword(&passwords);
  insertPassword(&passwords);

  listPasswords(passwords);

  return 0;
}