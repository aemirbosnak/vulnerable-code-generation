//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to parse the command line into tokens
char** parse_args(char* line) {
  char** args = malloc(sizeof(char*) * 10);
  int num_args = 0;
  char* arg = strtok(line, " ");
  while (arg != NULL) {
    args[num_args] = arg;
    num_args++;
    arg = strtok(NULL, " ");
  }
  args[num_args] = NULL;
  return args;
}

// Function to execute a command
int execute_command(char** args) {
  pid_t pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
    fprintf(stderr, "Error: execvp failed\n");
    exit(1);
  } else if (pid < 0) {
    fprintf(stderr, "Error: fork failed\n");
    return 1;
  } else {
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    } else {
      return 1;
    }
  }
}

// Main function
int main() {
  char line[1024];
  char** args;
  int status;

  while (1) {
    printf("> ");
    fgets(line, sizeof(line), stdin);
    args = parse_args(line);
    status = execute_command(args);
    if (status == 1) {
      fprintf(stderr, "Error: command not found\n");
    }
  }

  return 0;
}