//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Function to split the input line into arguments
char **split_args(char *line) {
  char **args = malloc(sizeof(char *) * MAX_ARGS);
  char *arg = strtok(line, " ");
  int i = 0;
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
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
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

// Main loop
int main() {
  char line[MAX_LINE_LENGTH];
  while (1) {
    // Print the prompt
    printf("> ");
    fflush(stdout);

    // Read the input line
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      break;
    }

    // Split the input line into arguments
    char **args = split_args(line);

    // Execute the command
    int status = execute_command(args);

    // Free the arguments
    free(args);

    // Check if the user entered "exit"
    if (strcmp(args[0], "exit") == 0) {
      break;
    }
  }

  return 0;
}