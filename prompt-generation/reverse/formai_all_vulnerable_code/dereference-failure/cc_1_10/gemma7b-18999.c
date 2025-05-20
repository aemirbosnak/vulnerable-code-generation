//Gemma-7B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  int valid;
} Password;

void createPassword(Password *passwords) {
  passwords = malloc(MAX_PASSWORDS * sizeof(Password));
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].name = NULL;
    passwords[i].password = NULL;
    passwords[i].valid = 0;
  }
}

void addPassword(Password *passwords, char *name, char *password) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].valid == 0) {
      passwords[i].name = strdup(name);
      passwords[i].password = strdup(password);
      passwords[i].valid = 1;
      return;
    }
  }
  printf("Error: Maximum number of passwords exceeded.\n");
}

void printPasswords(Password *passwords) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].valid) {
      printf("Name: %s\n", passwords[i].name);
      printf("Password: %s\n", passwords[i].password);
    }
  }
}

int main() {
  Password *passwords = NULL;
  createPassword(passwords);
  addPassword(passwords, "John Doe", "Secret1");
  addPassword(passwords, "Jane Doe", "Secret2");
  printPasswords(passwords);

  return 0;
}