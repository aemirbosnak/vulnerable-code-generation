//Gemma-7B DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_NAME_LENGTH 255
#define MAX_COMMAND_LENGTH 1024

typedef struct User {
  char name[MAX_USER_NAME_LENGTH];
  struct User* next;
} User;

typedef struct Command {
  char command[MAX_COMMAND_LENGTH];
  struct Command* next;
} Command;

User* createUser(char* name) {
  User* newUser = malloc(sizeof(User));
  strcpy(newUser->name, name);
  newUser->next = NULL;
  return newUser;
}

Command* createCommand(char* command) {
  Command* newCommand = malloc(sizeof(Command));
  strcpy(newCommand->command, command);
  newCommand->next = NULL;
  return newCommand;
}

int main() {
  User* head = createUser("John Doe");
  User* tail = head;

  Command* headCommand = createCommand("ls");
  Command* tailCommand = headCommand;

  tail->next = createUser("Jane Doe");
  tail = tail->next;

  tailCommand->next = createCommand("pwd");
  tailCommand = tailCommand->next;

  tailCommand->next = createCommand("echo Hello, world!");
  tailCommand = tailCommand->next;

  for (User* user = head; user; user) {
    printf("User: %s\n", user->name);
    for (Command* command = headCommand; command; command) {
      printf("  Command: %s\n", command->command);
    }
    printf("\n");
  }

  return 0;
}