//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 256

// Function to split the input line into arguments
char** split_line(char* line) {
  char** args = malloc(MAX_LINE * sizeof(char*));
  char* arg = strtok(line, " ");
  int i = 0;
  while (arg != NULL) {
    args[i] = arg;
    arg = strtok(NULL, " ");
    i++;
  }
  args[i] = NULL;
  return args;
}

// Function to execute a command
int execute_command(char** args) {
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
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    } else {
      return 1;
    }
  }
}

// Function to read a line from the terminal
char* read_line() {
  char* line = malloc(MAX_LINE * sizeof(char));
  fgets(line, MAX_LINE, stdin);
  return line;
}

// Main function
int main() {
  // Welcome message
  printf("Welcome to the Imagination Shell!\n");

  // Run the shell in a loop
  while (1) {
    // Print the prompt
    printf("> ");

    // Read a line from the terminal
    char* line = read_line();

    // Split the line into arguments
    char** args = split_line(line);

    // Execute the command
    int status = execute_command(args);

    // Check if the command was successful
    if (status != 0) {
      printf("Error executing command.\n");
    }

    // Free the memory allocated for the arguments
    free(args);
  }

  return 0;
}