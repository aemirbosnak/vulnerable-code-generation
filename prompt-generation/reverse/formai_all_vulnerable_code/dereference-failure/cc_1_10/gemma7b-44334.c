//Gemma-7B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

Password *createPassword(char *name, char *password) {
  Password *newPassword = malloc(sizeof(Password));
  newPassword->name = strdup(name);
  newPassword->password = strdup(password);
  newPassword->next = NULL;

  return newPassword;
}

void addPassword(Password *passwords, char *name, char *password) {
  Password *newPassword = createPassword(name, password);

  if (passwords == NULL) {
    passwords = newPassword;
  } else {
    passwords->next = newPassword;
  }

  passwords = newPassword;
}

int main() {
  Password *passwords = NULL;

  addPassword(passwords, "john.doe", "secret");
  addPassword(passwords, "jane.doe", "another secret");
  addPassword(passwords, "bill.smith", "top secret");

  Password *currentPassword = passwords;

  while (currentPassword) {
    printf("Name: %s, Password: %s\n", currentPassword->name, currentPassword->password);
    currentPassword = currentPassword->next;
  }

  return 0;
}