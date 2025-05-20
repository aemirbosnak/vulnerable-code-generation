//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

// Function to execute a command and print the output
void execute_command(char *cmd) {
  char *argv[MAX_ARGS];
  int status;

  // Tokenize the command into argv
  char *token = strtok(cmd, " ");
  int i = 0;
  while (token != NULL && i < MAX_ARGS) {
    argv[i++] = token;
    token = strtok(NULL, " ");
  }

  // Execute the command and get the status
  if (execvp(argv[0], argv) == -1) {
    perror("execvp");
    return;
  }

  // Wait for the command to finish
  wait(&status);

  // Print the command and its status
  printf("Command: %s\nStatus: %d\n", cmd, status);
}

int main() {
  char *commands[] = {
    "ls", // 0
    "cd /", // 1
    "ls", // 2
    "echo 'Hello World!'", // 3
    "cat /etc/os-release", // 4
    "grep 'UBUNTU' /etc/os-release" // 5
  };
  int i;

  // Loop through the commands and execute them
  for (i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
    execute_command(commands[i]);
  }

  return 0;
}