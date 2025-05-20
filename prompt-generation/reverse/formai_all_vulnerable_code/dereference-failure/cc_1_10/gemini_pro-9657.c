//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

// Function to split a string into an array of arguments
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

// Function to execute a command
int execute_command(char **args) {
  pid_t pid = fork();

  if (pid == -1) {
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

// Function to read a line from the user
char *read_line() {
  char *line = malloc(sizeof(char) * MAX_LINE_LENGTH);
  fgets(line, MAX_LINE_LENGTH, stdin);
  return line;
}

// Main function
int main() {
  char *line;
  char **args;
  int status;

  while (1) {
    printf("$ ");
    line = read_line();

    if (strcmp(line, "exit\n") == 0) {
      break;
    }

    args = split_args(line);
    status = execute_command(args);

    if (status != 0) {
      perror("command failed");
    }
  }

  return 0;
}