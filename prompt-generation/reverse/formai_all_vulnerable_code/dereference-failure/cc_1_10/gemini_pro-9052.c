//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Built-in commands
#define EXIT_CMD "exit"
#define CD_CMD "cd"

// Maximum command line length
#define MAX_LINE_LENGTH 1024

// Maximum number of arguments
#define MAX_ARGS 32

// Parse the command line into arguments
int parse_args(char *line, char **args) {
  int argc = 0;
  char *token = strtok(line, " ");
  while (token != NULL) {
    args[argc++] = token;
    token = strtok(NULL, " ");
  }
  return argc;
}

// Execute the given command
int execute_command(char **args) {
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  } else if (pid > 0) {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    return status;
  } else {
    // Error
    perror("fork");
    return -1;
  }
}

// Handle the built-in commands
int handle_built_in_commands(char **args) {
  if (strcmp(args[0], EXIT_CMD) == 0) {
    // Exit the shell
    exit(0);
  } else if (strcmp(args[0], CD_CMD) == 0) {
    // Change the current directory
    if (args[1] == NULL) {
      // No argument provided, use the home directory
      chdir(getenv("HOME"));
    } else {
      // Change directory to the specified path
      chdir(args[1]);
    }
    return 0;
  } else {
    // Not a built-in command, execute normally
    return execute_command(args);
  }
}

// Main loop
int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];

  while (1) {
    // Print the prompt
    printf("$ ");

    // Read the command line
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the command line into arguments
    int argc = parse_args(line, args);

    // Handle the built-in commands
    int status = handle_built_in_commands(args);

    // If not a built-in command, execute normally
    if (status == -1) {
      // Error occurred, skip this command
      continue;
    }
  }

  return 0;
}