//Gemma-7B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

struct Password {
  char *name;
  char *password;
  int used;
} passwords[MAX_PASSWORDS];

void generate_passwords() {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].name = malloc(PASSWORD_LENGTH);
    passwords[i].password = malloc(PASSWORD_LENGTH);
    passwords[i].used = 0;
  }
}

void store_password(char *name, char *password) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (!passwords[i].used) {
      passwords[i].name = name;
      passwords[i].password = password;
      passwords[i].used = 1;
      return;
    }
  }

  printf("Error: No more passwords can be stored.\n");
}

char *retrieve_password(char *name) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].name && strcmp(passwords[i].name, name) == 0) {
      return passwords[i].password;
    }
  }

  return NULL;
}

int main() {
  generate_passwords();

  store_password("John Doe", "Secret123!");
  store_password("Jane Doe", "Secret456!");

  char *password = retrieve_password("John Doe");
  if (password) {
    printf("Password for John Doe: %s\n", password);
  } else {
    printf("Error: Password not found.\n");
  }

  return 0;
}