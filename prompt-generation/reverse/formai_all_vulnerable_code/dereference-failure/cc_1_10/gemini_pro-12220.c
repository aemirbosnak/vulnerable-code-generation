//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to split the command line into arguments.
char **split_args(char *line) {
  char **args = malloc(sizeof(char *) * 10);  // Allocate memory for 10 arguments.
  int i = 0;
  char *arg;

  while ((arg = strtok(line, " ")) != NULL) {
    args[i++] = arg;
  }

  args[i] = NULL;  // Terminate the array of arguments with a NULL pointer.

  return args;
}

// Function to execute a command.
void execute_command(char **args) {
  pid_t pid = fork();  // Create a child process.

  if (pid == 0) {
    // Child process.
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(1);
    }
  } else if (pid > 0) {
    // Parent process.
    int status;
    waitpid(pid, &status, 0);  // Wait for the child process to terminate.
  } else {
    perror("fork");
    exit(1);
  }
}

// Function to handle the shell loop.
void shell_loop() {
  char *line;
  char **args;

  while (1) {
    // Print the shell prompt.
    printf("> ");
    fflush(stdout);

    // Read a line of input from the user.
    line = malloc(sizeof(char) * 1024);  // Allocate memory for 1024 characters.
    fgets(line, 1024, stdin);

    // Split the command line into arguments.
    args = split_args(line);

    // Execute the command.
    execute_command(args);

    // Free the memory allocated for the arguments.
    free(args);

    // Free the memory allocated for the line.
    free(line);
  }
}

// Main function.
int main() {
  shell_loop();  // Start the shell loop.

  return 0;
}