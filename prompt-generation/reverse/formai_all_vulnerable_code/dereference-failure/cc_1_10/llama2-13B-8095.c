//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define constants and variables
const int MAX_CMD_LENGTH = 1024;
const char* DEFAULT_SHELL = "/bin/bash";
char* shell;
char* command;
int pid;

// Function to execute a command
void execute_command(const char* command_string) {
  // Parse the command string
  char* argv[32];
  int i = 0;
  char* token;
  while ((token = strtok(command_string, " \t")) != NULL) {
    argv[i++] = token;
  }

  // Set the command to execute
  command = argv[0];

  // Execute the command
  pid = fork();
  if (pid == 0) {
    // Child process
    execvp(command, argv);
  } else {
    // Parent process
    wait(NULL);
  }
}

int main() {
  // Get the user's input
  printf("Enter a command: ");
  fgets(command, MAX_CMD_LENGTH, stdin);

  // Parse the command
  shell = strtok(command, " ");
  if (strcmp(shell, DEFAULT_SHELL) == 0) {
    // Execute the command
    execute_command(command);
  } else {
    // Execute the command with the specified shell
    execute_command(shell);
  }

  return 0;
}