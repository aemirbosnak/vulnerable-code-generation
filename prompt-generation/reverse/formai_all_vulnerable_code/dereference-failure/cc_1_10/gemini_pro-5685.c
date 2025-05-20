//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Built-in commands
#define BUILTIN_CD "cd"
#define BUILTIN_EXIT "exit"

// Maximum command length
#define MAX_COMMAND_LENGTH 1024

// Maximum number of arguments
#define MAX_ARGS 32

// Prompt
#define PROMPT "Visionshell> "

// Function to split a string into an array of strings
char **split_string(char *str, char *delim) {
  char **args = malloc(sizeof(char *) * MAX_ARGS);
  char *arg = strtok(str, delim);
  int i = 0;
  while (arg != NULL) {
    args[i] = arg;
    i++;
    arg = strtok(NULL, delim);
  }
  args[i] = NULL;
  return args;
}

// Function to execute a command
int execute_command(char **args) {
  if (strcmp(args[0], BUILTIN_CD) == 0) {
    // Change directory
    if (chdir(args[1]) != 0) {
      perror("chdir");
      return 1;
    }
    return 0;
  } else if (strcmp(args[0], BUILTIN_EXIT) == 0) {
    // Exit shell
    exit(0);
  } else {
    // Execute command
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
      return WEXITSTATUS(status);
    } else {
      // Error
      perror("fork");
      return 1;
    }
  }
}

// Main loop
int main() {
  while (1) {
    // Print prompt
    printf(PROMPT);

    // Read command
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);

    // Split command into arguments
    char **args = split_string(line, " ");

    // Execute command
    int status = execute_command(args);

    // Free memory
    free(line);
    free(args);

    // Check status
    if (status != 0) {
      printf("Error: %d\n", status);
    }
  }

  return 0;
}