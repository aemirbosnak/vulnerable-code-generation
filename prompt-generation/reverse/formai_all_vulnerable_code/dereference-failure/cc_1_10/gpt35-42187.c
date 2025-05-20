//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 20

struct User {
  char *username;
  char *password;
  int admin;
};

struct User users[MAX_USERS];
int num_users = 0;

void add_user(char *username, char *password, int admin) {
  if (num_users == MAX_USERS) {
    printf("Maximum number of users exceeded.\n");
    return;
  }

  struct User *new_user = malloc(sizeof(struct User));
  new_user->username = strdup(username);
  new_user->password = strdup(password);
  new_user->admin = admin;

  users[num_users++] = *new_user;

  printf("User added successfully.\n");
}

void remove_user(char *username) {
  int i;
  for (i = 0; i < num_users; i++) {
    if (strcmp(users[i].username, username) == 0) {
      num_users--;
      *users[i].username = '\0';
      *users[i].password = '\0';
      users[i].admin = 0;

      printf("User removed successfully.\n");
      return;
    }
  }

  printf("User not found.\n");
}

void list_users() {
  int i;
  printf("Username\tAdmin\n");
  for (i = 0; i < num_users; i++) {
    printf("%s\t\t%s\n", users[i].username, users[i].admin ? "yes" : "no");
  }
}

void main() {
  add_user("admin", "password", 1);
  add_user("user1", "password1", 0);

  list_users();
  remove_user("user1");
  list_users();
}