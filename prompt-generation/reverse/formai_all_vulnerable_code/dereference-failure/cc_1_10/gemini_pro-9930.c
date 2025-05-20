//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
  char *password;
  char *website;
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password, char *website) {
  if (num_passwords >= MAX_PASSWORDS) {
    printf("Error: Too many passwords.\n");
    return;
  }

  passwords[num_passwords].password = malloc(strlen(password) + 1);
  strcpy(passwords[num_passwords].password, password);
  passwords[num_passwords].website = malloc(strlen(website) + 1);
  strcpy(passwords[num_passwords].website, website);
  num_passwords++;
}

void print_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%s: %s\n", passwords[i].website, passwords[i].password);
  }
}

void free_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    free(passwords[i].password);
    free(passwords[i].website);
  }
}

int main() {
  add_password("password1", "website1");
  add_password("password2", "website2");
  add_password("password3", "website3");

  print_passwords();

  free_passwords();

  return 0;
}