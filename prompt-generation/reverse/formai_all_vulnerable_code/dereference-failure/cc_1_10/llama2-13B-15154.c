//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <utime.h>

#define MAX_USERS 10
#define MAX_COMMANDS 10

// Global variables
int num_users = 0;
int num_commands = 0;
char **user_commands = NULL;

// Functions
void add_user(char *username);
void add_command(char *command);
void execute_commands();
void print_usage();

int main() {
  // Print the program name and version
  printf("Welcome to the C System Administration Program v1.0\n");

  // Print the usage
  print_usage();

  // Loop until the user quits
  while (1) {
    // Print the menu
    printf("--- Menu ---\n");
    printf("1. Add User\n");
    printf("2. Add Command\n");
    printf("3. Execute Commands\n");
    printf("4. Quit\n");

    // Get the user input
    int choice = getchar();

    // Handle user input
    switch (choice) {
      case '1':
        add_user(NULL);
        break;
      case '2':
        add_command(NULL);
        break;
      case '3':
        execute_commands();
        break;
      case '4':
        printf("Goodbye! You have been administrated...\n");
        exit(0);
        break;
      default:
        printf("Invalid input. Try again!\n");
        break;
    }
  }

  return 0;
}

// Function: add_user
void add_user(char *username) {
  // Check if the user already exists
  for (int i = 0; i < num_users; i++) {
    if (strcmp(user_commands[i], username) == 0) {
      printf("User already exists! Try again...\n");
      return;
    }
  }

  // Add the user to the list
  user_commands = realloc(user_commands, (num_users + 1) * sizeof(char *));
  user_commands[num_users] = strdup(username);
  num_users++;

  printf("User added successfully! %s\n", username);
}

// Function: add_command
void add_command(char *command) {
  // Check if the command already exists
  for (int i = 0; i < num_commands; i++) {
    if (strcmp(user_commands[i], command) == 0) {
      printf("Command already exists! Try again...\n");
      return;
    }
  }

  // Add the command to the list
  user_commands = realloc(user_commands, (num_commands + 1) * sizeof(char *));
  user_commands[num_commands] = strdup(command);
  num_commands++;

  printf("Command added successfully! %s\n", command);
}

// Function: execute_commands
void execute_commands() {
  // Loop through the list of commands
  for (int i = 0; i < num_commands; i++) {
    // Execute the command
    system(user_commands[i]);

    // Print the command output
    printf("Command output: %s\n", user_commands[i]);
  }
}

// Function: print_usage
void print_usage() {
  // Print the usage
  printf("Usage: c-admin <command>\n");
  printf("Commands:\n");
  printf("  add <username>      Add a new user\n");
  printf("  add <command>      Add a new command\n");
  printf("  execute            Execute all commands\n");
  printf("  quit               Quit the program\n");
}