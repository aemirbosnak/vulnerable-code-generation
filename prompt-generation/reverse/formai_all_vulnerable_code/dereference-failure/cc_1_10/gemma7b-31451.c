//Gemma-7B DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
} Password;

void create_password(Password *passwords) {
  passwords = (Password *)malloc(MAX_PASSWORDS * sizeof(Password));
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].name = (char *)malloc(20 * sizeof(char));
    passwords[i].password = (char *)malloc(20 * sizeof(char));
  }
}

void add_password(Password *passwords, char *name, char *password) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].name == NULL) {
      passwords[i].name = name;
      passwords[i].password = password;
      return;
    }
  }
  printf("Error: Maximum number of passwords exceeded.\n");
}

char *find_password(Password *passwords, char *name) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].name != NULL && strcmp(passwords[i].name, name) == 0) {
      return passwords[i].password;
    }
  }
  return NULL;
}

int main() {
  Password passwords;
  create_password(&passwords);
  add_password(&passwords, "John Doe", "Secret1");
  add_password(&passwords, "Jane Doe", "Secret2");
  add_password(&passwords, "Peter Pan", "Neverland");

  char *password = find_password(&passwords, "John Doe");
  if (password) {
    printf("Password for John Doe: %s\n", password);
  } else {
    printf("Error: Password not found.\n");
  }

  return 0;
}