//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SHELL_NAME "Myshell"
#define SHELL_PROMPT "$ "

// Function to execute a command
int execute_command(char *command) {
  char *argv[100]; // Array to store command arguments
  int argc = 0;     // Number of command arguments

  // Parse the command into arguments
  char *token = strtok(command, " ");
  while (token != NULL) {
    argv[argc++] = token;
    token = strtok(NULL, " ");
  }

  // Execute the command
  pid_t pid = fork();
  if (pid == 0) {
    execvp(argv[0], argv);
    perror("execvp");
    exit(1);
  } else if (pid < 0) {
    perror("fork");
    return -1;
  } else {
    waitpid(pid, NULL, 0);
  }

  return 0;
}

// Function to read a line from the user
char *read_line() {
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, stdin);
  return line;
}

// Main function
int main() {
  // Print the shell name and prompt
  printf("%s%s", SHELL_NAME, SHELL_PROMPT);

  // Read a line from the user
  char *line = read_line();

  // Execute the command
  while (strcmp(line, "exit") != 0) {
    execute_command(line);

    // Print the prompt again
    printf("%s", SHELL_PROMPT);

    // Read a line from the user
    line = read_line();
  }

  // Free the memory allocated for the line
  free(line);

  return 0;
}