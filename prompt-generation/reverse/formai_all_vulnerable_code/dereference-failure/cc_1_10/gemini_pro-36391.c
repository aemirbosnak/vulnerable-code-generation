//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// The maximum length of a command
#define MAX_COMMAND_LENGTH 1024

// The maximum number of arguments in a command
#define MAX_ARGS 10

// The shell's prompt
#define PROMPT "my_shell$ "

// The history of commands
#define HISTORY_SIZE 10

// The history of commands
char history[HISTORY_SIZE][MAX_COMMAND_LENGTH];

// The current history index
int history_index = 0;

// The main function
int main() {
  // Run the shell forever
  while (1) {
    // Print the prompt
    printf(PROMPT);

    // Read the command from the user
    char command[MAX_COMMAND_LENGTH];
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    // Parse the command into arguments
    char *args[MAX_ARGS];
    char *arg = strtok(command, " ");
    int i = 0;
    while (arg != NULL) {
      args[i] = arg;
      i++;
      arg = strtok(NULL, " ");
    }

    // Execute the command
    if (strcmp(args[0], "exit") == 0) {
      // Exit the shell
      exit(0);
    } else if (strcmp(args[0], "history") == 0) {
      // Print the history of commands
      for (int i = 0; i < history_index; i++) {
        printf("%s\n", history[i]);
      }
    } else {
      // Execute the command
      pid_t pid = fork();
      if (pid == 0) {
        // Child process
        execvp(args[0], args);
        // If execvp returns, it means the command was not found
        printf("Command not found\n");
        exit(1);
      } else {
        // Parent process
        waitpid(pid, NULL, 0);
      }
    }

    // Add the command to the history
    strcpy(history[history_index], command);
    history_index++;
    if (history_index == HISTORY_SIZE) {
      history_index = 0;
    }
  }

  return 0;
}