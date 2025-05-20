//GEMINI-pro DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *password;
} Password;

Password *passwords;
int num_passwords = 0;

void add_password(char *name, char *password) {
  passwords = realloc(passwords, (num_passwords + 1) * sizeof(Password));
  passwords[num_passwords].name = strdup(name);
  passwords[num_passwords].password = strdup(password);
  num_passwords++;
}

void remove_password(char *name) {
  int i;
  for (i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].name, name) == 0) {
      free(passwords[i].name);
      free(passwords[i].password);
      for (int j = i + 1; j < num_passwords; j++) {
        passwords[j - 1] = passwords[j];
      }
      num_passwords--;
      return;
    }
  }
}

char *get_password(char *name) {
  int i;
  for (i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].name, name) == 0) {
      return passwords[i].password;
    }
  }
  return NULL;
}

void print_passwords() {
  int i;
  for (i = 0; i < num_passwords; i++) {
    printf("%s: %s\n", passwords[i].name, passwords[i].password);
  }
}

int main() {
  add_password("user1", "password1");
  add_password("user2", "password2");
  add_password("user3", "password3");

  print_passwords();

  printf("Getting password for user1: %s\n", get_password("user1"));

  remove_password("user2");

  print_passwords();

  return 0;
}