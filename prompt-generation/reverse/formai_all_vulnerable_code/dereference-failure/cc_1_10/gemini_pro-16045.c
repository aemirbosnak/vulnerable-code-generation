//GEMINI-pro DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
  char *password;
  time_t created_at;
} password_entry;

password_entry *passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password) {
  if (num_passwords == MAX_PASSWORDS) {
    fprintf(stderr, "Error: Password database is full.\n");
    return;
  }

  passwords[num_passwords] = malloc(sizeof(password_entry));
  passwords[num_passwords]->password = strdup(password);
  passwords[num_passwords]->created_at = time(NULL);
  num_passwords++;
}

void remove_password(int index) {
  if (index < 0 || index >= num_passwords) {
    fprintf(stderr, "Error: Invalid password index.\n");
    return;
  }

  free(passwords[index]->password);
  free(passwords[index]);
  for (int i = index; i < num_passwords - 1; i++) {
    passwords[i] = passwords[i + 1];
  }
  num_passwords--;
}

void print_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%3d: %s (created: %s)\n", i + 1, passwords[i]->password, ctime(&passwords[i]->created_at));
  }
}

void generate_password(int length) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    password[i] = (rand() % 26) + 'a';
  }
  password[length] = '\0';
  add_password(password);
  free(password);
}

int main() {
  srand(time(NULL));

  add_password("password1");
  add_password("password2");
  add_password("password3");

  print_passwords();

  remove_password(1);

  print_passwords();

  generate_password(10);

  print_passwords();

  return 0;
}