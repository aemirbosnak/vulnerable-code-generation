//Gemma-7B DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  time_t timestamp;
} Password;

void generate_password(char *password, int length) {
  for (int i = 0; i < length; i++) {
    password[i] = rand() % 36 + 'a';
  }
}

void store_password(Password *passwords, char *name, char *password) {
  passwords[0].name = strdup(name);
  passwords[0].password = strdup(password);
  passwords[0].timestamp = time(NULL);
}

void list_passwords(Password *passwords) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].name) {
      printf("%s: %s (Last used: %s)\n", passwords[i].name, passwords[i].password, ctime(&passwords[i].timestamp));
    }
  }
}

int main() {
  Password passwords[MAX_PASSWORDS] = {0};
  int num_passwords = 0;

  // Generate a new password
  char *new_password = malloc(16);
  generate_password(new_password, 16);

  // Store the password
  store_password(passwords, "John Doe", new_password);

  // List all passwords
  list_passwords(passwords);

  return 0;
}