//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_SIZE 256

typedef struct {
  char *name;
  char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *name, char *password) {
  if (num_passwords >= MAX_PASSWORDS) {
    fprintf(stderr, "Error: too many passwords\n");
    return;
  }

  passwords[num_passwords].name = strdup(name);
  passwords[num_passwords].password = strdup(password);
  num_passwords++;
}

char *get_password(char *name) {
  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].name, name) == 0) {
      return passwords[i].password;
    }
  }

  return NULL;
}

void delete_password(char *name) {
  for (int i = 0; i < num_passwords; i++) {
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

void print_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%s: %s\n", passwords[i].name, passwords[i].password);
  }
}

int main() {
  add_password("Neo", "theOne");
  add_password("Trinity", "love");
  add_password("Morpheus", "wakeUp");
  add_password("Tank", "fishburne");
  add_password("Dozer", "wiggins");
  add_password("Mouse", "jeffers");

  char *password = get_password("Neo");
  printf("Neo's password: %s\n", password);

  delete_password("Tank");
  printf("Tank's password deleted\n");

  print_passwords();

  return 0;
}