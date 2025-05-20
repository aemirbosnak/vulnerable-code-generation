//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

// Function to parse the command line into arguments
int parse_args(char *line, char **args) {
  int i = 0;
  char *arg = strtok(line, " ");
  while (arg != NULL && i < MAX_ARGS) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }
  return i;
}

// Function to execute the command
int execute_command(char **args) {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return -1;
  } else if (pid == 0) {
    // Child process
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  } else {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    return status;
  }
}

// Main function
int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int argc;

  while (1) {
    // Print the prompt
    printf("> ");

    // Read the command line
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the command line into arguments
    argc = parse_args(line, args);

    // If the command is "exit", exit the shell
    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    // Execute the command
    execute_command(args);
  }

  return 0;
}