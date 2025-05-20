//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Define some constants and variables
#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64
#define MY_PID getpid()

// Function to execute a command and print the output
void execute_command(char *cmd) {
  int status;
  char *args[MAX_ARGS];
  char buffer[1024];

  // Tokenize the command into arguments
  char *token = strtok(cmd, " ");
  int i = 0;
  while (token != NULL && i < MAX_ARGS) {
    args[i++] = token;
    token = strtok(NULL, " ");
  }

  // Execute the command
  if (execvp(cmd, args) == -1) {
    perror("execvp failed");
    return;
  }

  // Wait for the command to finish
  wait(&status);

  // Print the command and its output
  printf("Executed command: %s\n", cmd);
  printf("Output: %s\n", buffer);
}

int main() {
  // Create a list of commands to execute
  char *commands[] = {
    "ls -l",
    "mkdir mydir",
    "cd mydir",
    "echo 'Hello, world!' > hello.txt",
    "cat hello.txt",
    "rm -rf mydir"
  };

  // Iterate over the list of commands and execute each one
  for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
    execute_command(commands[i]);
  }

  return 0;
}