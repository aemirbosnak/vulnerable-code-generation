//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Function to split the input line into arguments
char **split_args(char *line) {
  char **args = malloc(sizeof(char *) * MAX_ARGS);
  char *arg;
  int i = 0;

  arg = strtok(line, " ");
  while (arg != NULL) {
    args[i] = arg;
    i++;
    arg = strtok(NULL, " ");
  }
  args[i] = NULL;

  return args;
}

// Function to execute the command
int execute_command(char **args) {
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(EXIT_FAILURE);
    }
  } else if (pid > 0) {
    // Parent process
    wait(&status);
  } else {
    // Fork failed
    perror("fork");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

// Main function
int main() {
  char line[MAX_LINE_LENGTH];
  char **args;
  int status;

  while (1) {
    // Print the prompt
    printf("my_shell> ");

    // Read the input line
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Split the input line into arguments
    args = split_args(line);

    // Execute the command
    status = execute_command(args);

    // Free the allocated memory
    free(args);
  }

  return EXIT_SUCCESS;
}