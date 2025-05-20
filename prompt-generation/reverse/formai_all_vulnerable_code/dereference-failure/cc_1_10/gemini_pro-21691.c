//GEMINI-pro DATASET v1.0 Category: Password management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct password {
  char *service;
  char *username;
  char *password;
} password;

password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
  if (num_passwords == MAX_PASSWORDS) {
    printf("Password list is full. Unable to add new password.\n");
    return;
  }

  char service[100];
  char username[100];
  char password[100];

  printf("Enter the service name: ");
  scanf("%s", service);

  printf("Enter the username: ");
  scanf("%s", username);

  printf("Enter the password: ");
  scanf("%s", password);

  passwords[num_passwords].service = malloc(strlen(service) + 1);
  strcpy(passwords[num_passwords].service, service);

  passwords[num_passwords].username = malloc(strlen(username) + 1);
  strcpy(passwords[num_passwords].username, username);

  passwords[num_passwords].password = malloc(strlen(password) + 1);
  strcpy(passwords[num_passwords].password, password);

  num_passwords++;
}

void show_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("Service: %s\n", passwords[i].service);
    printf("Username: %s\n", passwords[i].username);
    printf("Password: %s\n\n", passwords[i].password);
  }
}

void search_password() {
  char service[100];

  printf("Enter the service name: ");
  scanf("%s", service);

  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].service, service) == 0) {
      printf("Username: %s\n", passwords[i].username);
      printf("Password: %s\n\n", passwords[i].password);
      return;
    }
  }

  printf("Service not found.\n");
}

void delete_password() {
  char service[100];

  printf("Enter the service name: ");
  scanf("%s", service);

  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].service, service) == 0) {
      free(passwords[i].service);
      free(passwords[i].username);
      free(passwords[i].password);

      for (int j = i; j < num_passwords - 1; j++) {
        passwords[j] = passwords[j + 1];
      }

      num_passwords--;
      return;
    }
  }

  printf("Service not found.\n");
}

int main() {
  int choice;

  while (1) {
    printf("1. Add a password\n");
    printf("2. Show all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_password();
        break;
      case 2:
        show_passwords();
        break;
      case 3:
        search_password();
        break;
      case 4:
        delete_password();
        break;
      case 5:
        exit(0);
    }
  }

  return 0;
}