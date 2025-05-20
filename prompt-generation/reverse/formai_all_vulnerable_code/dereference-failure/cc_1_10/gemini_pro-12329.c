//GEMINI-pro DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 30

typedef struct password {
  char *name;
  char *password;
  time_t created_at;
} password;

static password passwords[MAX_PASSWORDS];
static int num_passwords = 0;

void add_password(char *name, char *password) {
  if (num_passwords >= MAX_PASSWORDS) {
    fprintf(stderr, "Error: Too many passwords.\n");
    return;
  }

  passwords[num_passwords].name = strdup(name);
  passwords[num_passwords].password = strdup(password);
  passwords[num_passwords].created_at = time(NULL);
  num_passwords++;
}

void remove_password(char *name) {
  int i;

  for (i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].name, name) == 0) {
      free(passwords[i].name);
      free(passwords[i].password);
      passwords[i] = passwords[num_passwords - 1];
      num_passwords--;
      return;
    }
  }

  fprintf(stderr, "Error: Password not found.\n");
}

void get_password(char *name, char *password) {
  int i;

  for (i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].name, name) == 0) {
      strcpy(password, passwords[i].password);
      return;
    }
  }

  fprintf(stderr, "Error: Password not found.\n");
}

void print_passwords() {
  int i;

  for (i = 0; i < num_passwords; i++) {
    printf("%s: %s\n", passwords[i].name, passwords[i].password);
  }
}

int main(int argc, char **argv) {
  char *command;
  char *name;
  char *password;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <command> <name> <password>\n", argv[0]);
    return 1;
  }

  command = argv[1];
  name = argv[2];
  password = argv[3];

  if (strcmp(command, "add") == 0) {
    add_password(name, password);
  } else if (strcmp(command, "remove") == 0) {
    remove_password(name);
  } else if (strcmp(command, "get") == 0) {
    get_password(name, password);
  } else if (strcmp(command, "print") == 0) {
    print_passwords();
  } else {
    fprintf(stderr, "Error: Invalid command.\n");
    return 1;
  }

  return 0;
}