//Gemma-7B DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

struct password_t {
  char *name;
  char *pass;
  int used;
};

void store_password(char *name, char *pass) {
  struct password_t *passwords = (struct password_t *)malloc(MAX_PASSWORDS * sizeof(struct password_t));
  int i = 0;
  for (; i < MAX_PASSWORDS && passwords[i].name != NULL; i++) {
    if (strcmp(name, passwords[i].name) == 0) {
      passwords[i].pass = pass;
      passwords[i].used = 1;
      return;
    }
  }

  passwords[i].name = name;
  passwords[i].pass = pass;
  passwords[i].used = 0;
  return;
}

char *retrieve_password(char *name) {
  struct password_t *passwords = (struct password_t *)malloc(MAX_PASSWORDS * sizeof(struct password_t));
  int i = 0;
  for (; i < MAX_PASSWORDS && passwords[i].name != NULL; i++) {
    if (strcmp(name, passwords[i].name) == 0) {
      return passwords[i].pass;
    }
  }

  return NULL;
}

int main() {
  store_password("john.doe@example.com", "secret123");
  char *pass = retrieve_password("john.doe@example.com");
  if (pass) {
    printf("Your password is: %s\n", pass);
  } else {
    printf("No password found for that user.\n");
  }

  return 0;
}