//GEMINI-pro DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
  char *username;
  char *password;
} password_entry;

password_entry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
  if (num_passwords >= MAX_PASSWORDS) {
    printf("Error: Too many passwords!\n");
    return;
  }

  passwords[num_passwords].username = strdup(username);
  passwords[num_passwords].password = strdup(password);
  num_passwords++;
}

char *get_password(char *username) {
  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].username, username) == 0) {
      return passwords[i].password;
    }
  }

  return NULL;
}

void print_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%s: %s\n", passwords[i].username, passwords[i].password);
  }
}

int main() {
  char *username;
  char *password;
  int choice;

  while (1) {
    printf("1. Add password\n");
    printf("2. Get password\n");
    printf("3. Print passwords\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        add_password(username, password);
        break;
      case 2:
        printf("Enter username: ");
        scanf("%s", username);
        password = get_password(username);
        if (password == NULL) {
          printf("Error: Password not found!\n");
        } else {
          printf("Password: %s\n", password);
        }
        break;
      case 3:
        print_passwords();
        break;
      case 4:
        exit(0);
      default:
        printf("Error: Invalid choice!\n");
    }
  }

  return 0;
}