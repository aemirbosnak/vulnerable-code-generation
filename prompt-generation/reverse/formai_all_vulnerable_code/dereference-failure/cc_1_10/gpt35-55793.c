//FormAI DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10

struct user {
  char name[20];
  char password[20];
};

struct user users[MAX_USERS];
int num_users = 0;

void load_users() {
  FILE *fp = fopen("users.txt", "r");
  if (fp == NULL) {
    printf("Error: Failed to open file 'users.txt'\n");
    exit(1);
  }

  char line[100];
  while (fgets(line, sizeof(line), fp)) {
    // Parse username and password from line
    char *name = strtok(line, " ");
    char *password = strtok(NULL, " ");

    // Copy name and password into new user struct
    struct user new_user;
    strcpy(new_user.name, name);
    strcpy(new_user.password, password);

    // Add new user to users array
    users[num_users++] = new_user;
  }

  fclose(fp);
}

void login() {
  printf("Enter your username: ");
  char name[20];
  scanf("%s", name);

  printf("Enter your password: ");
  char password[20];
  scanf("%s", password);

  // Check if user exists in the users array
  int i;
  for (i = 0; i < num_users; i++) {
    if (strcmp(users[i].name, name) == 0 && strcmp(users[i].password, password) == 0) {
      printf("Login successful!\n");
      return;
    }
  }

  printf("Error: Invalid username or password\n");
}

int main() {
  load_users();

  printf("Welcome to the login page!\n");

  while (1) {
    printf("1. Login\n");
    printf("2. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        login();
        break;
      case 2:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Error: Invalid choice\n");
        break;
    }
  }

  return 0;
}