//Gemma-7B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

void addPassword(Password *head, char *name, char *password) {
  Password *newPass = malloc(sizeof(Password));
  newPass->name = strdup(name);
  newPass->password = strdup(password);
  newPass->next = NULL;

  if (head == NULL) {
    head = newPass;
  } else {
    head->next = newPass;
  }
}

char *searchPassword(Password *head, char *name) {
  Password *currPass = head;

  while (currPass) {
    if (strcmp(currPass->name, name) == 0) {
      return currPass->password;
    }
    currPass = currPass->next;
  }

  return NULL;
}

int main() {
  Password *passwords = NULL;

  // Add some passwords
  addPassword(passwords, "John Doe", "secret1");
  addPassword(passwords, "Jane Doe", "secret2");
  addPassword(passwords, "Bob Smith", "secret3");

  // Search for a password
  char *password = searchPassword(passwords, "John Doe");

  // Print the password
  if (password) {
    printf("Password for John Doe: %s\n", password);
  } else {
    printf("Password not found.\n");
  }

  return 0;
}