//Gemma-7B DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  int valid;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_passwords() {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].name = malloc(20);
    passwords[i].password = malloc(20);
    passwords[i].valid = 0;
  }
}

int main() {
  generate_passwords();

  passwords[0].name = "alice";
  passwords[0].password = "strongpassword";
  passwords[0].valid = 1;

  passwords[1].name = "bob";
  passwords[1].password = "anotherstrongpassword";
  passwords[1].valid = 1;

  char *username = malloc(20);
  char *password = malloc(20);

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (strcmp(username, passwords[i].name) == 0 && passwords[i].valid) {
      if (strcmp(password, passwords[i].password) == 0) {
        printf("Welcome, %s!\n", passwords[i].name);
        exit(0);
      }
    }
  }

  printf("Error: Invalid username or password.\n");
  exit(1);
}