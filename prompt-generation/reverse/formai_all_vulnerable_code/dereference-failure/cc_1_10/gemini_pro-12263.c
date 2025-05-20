//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
  char *password;
  char *username;
  char *website;
} password_entry;

password_entry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password, char *username, char *website) {
  if (num_passwords >= MAX_PASSWORDS) {
    printf("Error: Too many passwords.\n");
    return;
  }

  passwords[num_passwords].password = strdup(password);
  passwords[num_passwords].username = strdup(username);
  passwords[num_passwords].website = strdup(website);

  num_passwords++;
}

void delete_password(int index) {
  if (index < 0 || index >= num_passwords) {
    printf("Error: Invalid index.\n");
    return;
  }

  free(passwords[index].password);
  free(passwords[index].username);
  free(passwords[index].website);

  for (int i = index; i < num_passwords - 1; i++) {
    passwords[i] = passwords[i + 1];
  }

  num_passwords--;
}

void print_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("Password: %s\n", passwords[i].password);
    printf("Username: %s\n", passwords[i].username);
    printf("Website: %s\n\n", passwords[i].website);
  }
}

int main() {
  add_password("password1", "username1", "website1");
  add_password("password2", "username2", "website2");
  add_password("password3", "username3", "website3");

  print_passwords();

  delete_password(1);

  print_passwords();

  return 0;
}