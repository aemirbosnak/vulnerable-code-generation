//GEMINI-pro DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Password {
  char *username;
  char *password;
  char *date_created;
  char *date_modified;
} Password;

void print_password(Password *password) {
  printf("Username: %s\n", password->username);
  printf("Password: %s\n", password->password);
  printf("Date created: %s\n", password->date_created);
  printf("Date modified: %s\n", password->date_modified);
}

int main() {
  Password *passwords = malloc(sizeof(Password) * 10);

  // Initialize the passwords array with some sample data
  for (int i = 0; i < 10; i++) {
    passwords[i].username = malloc(sizeof(char) * 100);
    passwords[i].password = malloc(sizeof(char) * 100);
    passwords[i].date_created = malloc(sizeof(char) * 100);
    passwords[i].date_modified = malloc(sizeof(char) * 100);

    sprintf(passwords[i].username, "user%d", i);
    sprintf(passwords[i].password, "password%d", i);
    sprintf(passwords[i].date_created, "2023-01-01");
    sprintf(passwords[i].date_modified, "2023-01-01");
  }

  // Print the passwords to the console
  for (int i = 0; i < 10; i++) {
    print_password(&passwords[i]);
  }

  // Free the memory allocated for the passwords
  for (int i = 0; i < 10; i++) {
    free(passwords[i].username);
    free(passwords[i].password);
    free(passwords[i].date_created);
    free(passwords[i].date_modified);
  }
  free(passwords);

  return 0;
}