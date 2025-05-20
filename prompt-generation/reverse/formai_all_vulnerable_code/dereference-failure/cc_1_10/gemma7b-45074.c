//Gemma-7B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct password {
  char *name;
  char *password;
  int used;
} password_t;

password_t passwords[MAX_PASSWORDS];

void generate_password() {
  char password[20];
  int i;

  for (i = 0; i < 20; i++) {
    password[i] = rand() % 26 + 97;
  }

  passwords[0].password = strdup(password);
  passwords[0].used = 0;
}

void print_passwords() {
  int i;

  for (i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].used) {
      printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
  }
}

int main() {
  int i;

  for (i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].name = NULL;
    passwords[i].password = NULL;
    passwords[i].used = 0;
  }

  generate_password();
  generate_password();
  generate_password();

  print_passwords();

  return 0;
}