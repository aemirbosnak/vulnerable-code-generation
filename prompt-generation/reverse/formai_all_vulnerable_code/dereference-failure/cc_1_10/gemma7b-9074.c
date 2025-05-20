//Gemma-7B DATASET v1.0 Category: Password management ; Style: genius
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

typedef struct Password {
  char *name;
  char *password;
  int used;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_passwords() {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].name = malloc(PASSWORD_LENGTH);
    passwords[i].password = malloc(PASSWORD_LENGTH);
    passwords[i].used = 0;
  }
}

void add_password(char *name, char *password) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (!passwords[i].used) {
      passwords[i].name = name;
      passwords[i].password = password;
      passwords[i].used = 1;
      return;
    }
  }

  printf("Error: No more passwords can be added.\n");
}

int main() {
  generate_passwords();

  add_password("Alice", "StrongPassword1");
  add_password("Bob", "SecretSecret");
  add_password("Charlie", "VerySecure");

  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].used) {
      printf("Name: %s, Password: %s\n", passwords[i].name, passwords[i].password);
    }
  }

  return 0;
}