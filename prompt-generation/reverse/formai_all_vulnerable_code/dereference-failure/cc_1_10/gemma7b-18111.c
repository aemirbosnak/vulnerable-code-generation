//Gemma-7B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

Password *createPassword(char *name, char *password) {
  Password *newPass = malloc(sizeof(Password));

  newPass->name = strdup(name);
  newPass->password = strdup(password);
  newPass->next = NULL;

  return newPass;
}

int main() {
  Password *passwords = NULL;
  char name[255], password[255];

  // Create a new password
  printf("Enter a password name: ");
  scanf("%s", name);

  printf("Enter a password: ");
  scanf("%s", password);

  passwords = createPassword(name, password);

  // Add the password to the list
  if (passwords) {
    passwords->next = passwords;
  } else {
    passwords = passwords;
  }

  // Print the list of passwords
  Password *currPass = passwords;
  while (currPass) {
    printf("Name: %s, Password: %s\n", currPass->name, currPass->password);
    currPass = currPass->next;
  }

  return 0;
}