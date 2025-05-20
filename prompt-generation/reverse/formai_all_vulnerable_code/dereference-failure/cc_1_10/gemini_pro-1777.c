//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

// Function to parse the command line into arguments
char **parse_args(char *line) {
  char **args = malloc(sizeof(char *) * MAX_ARGS);
  char *arg;
  int i = 0;

  while ((arg = strtok(line, " \t\n")) != NULL) {
    args[i++] = arg;
  }

  args[i] = NULL;
  return args;
}

// Function to execute a command
int execute_command(char **args) {
  pid_t pid;

  // Create a new process
  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(EXIT_FAILURE);
    }
  } else if (pid > 0) {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
  } else {
    // Error
    perror("fork");
    exit(EXIT_FAILURE);
  }

  return 0;
}

// Main function
int main(int argc, char **argv) {
  char line[MAX_LINE];
  char **args;
  int status;

  while (1) {
    // Prompt the user for input
    printf("> ");
    fflush(stdout);

    // Read the input line
    if (fgets(line, MAX_LINE, stdin) == NULL) {
      break;
    }

    // Parse the input line into arguments
    args = parse_args(line);

    // Execute the command
    status = execute_command(args);

    // Free the allocated memory
    free(args);
  }

  return EXIT_SUCCESS;
}