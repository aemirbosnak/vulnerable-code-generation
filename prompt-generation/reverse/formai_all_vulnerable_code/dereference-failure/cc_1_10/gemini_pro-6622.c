//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Function to execute a command
int execute_command(char *command) {
  // Create a child process
  pid_t pid = fork();

  if (pid == -1) {
    perror("fork");
    return -1;
  } else if (pid == 0) {
    // Child process
    char *args[] = {command, NULL};
    execvp(command, args);
    perror("execvp");
    exit(1);
  } else {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    return status;
  }
}

// Function to read a line from the terminal
char *read_line() {
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, stdin);
  return line;
}

// Function to parse a line into commands
char **parse_line(char *line) {
  char **commands = malloc(sizeof(char *) * 10);
  int i = 0;
  char *token = strtok(line, " ");
  while (token != NULL) {
    commands[i++] = token;
    token = strtok(NULL, " ");
  }
  commands[i] = NULL;
  return commands;
}

// Function to run the shell loop
void run_shell() {
  char *line;
  char **commands;

  while (1) {
    // Print the prompt
    printf("myshell> ");

    // Read a line from the terminal
    line = read_line();

    // Parse the line into commands
    commands = parse_line(line);

    // Execute the commands
    execute_command(commands[0]);

    // Free the memory allocated for the commands
    free(commands);

    // Free the memory allocated for the line
    free(line);
  }
}

// Main function
int main() {
  // Run the shell loop
  run_shell();

  return 0;
}