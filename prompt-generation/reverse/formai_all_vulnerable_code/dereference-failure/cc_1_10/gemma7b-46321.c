//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **argv, char *cmd) {
  int argc = 0;
  char **cmd_args = NULL;

  // Tokenize the command line
  char *token = strtok(cmd, " ");
  while (token) {
    argv[argc++] = strdup(token);
    token = strtok(NULL, " ");
  }

  // Allocate memory for the arguments
  cmd_args = malloc(sizeof(char *) * argc);
  memcpy(cmd_args, argv, sizeof(char *) * argc);

  return cmd_args;
}

int main() {
  char cmd[MAX_CMD_LEN];
  char **argv = NULL;
  char **cmd_args = NULL;

  // Loop until the user enters a command or exits
  while (1) {
    // Print the shell prompt
    printf("$ ");

    // Get the user's input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command line
    cmd_args = parse_cmd(argv, cmd);

    // Execute the command
    if (cmd_args) {
      execvp(cmd_args[0], cmd_args);
    }

    // Free the memory allocated for the arguments
    if (cmd_args) {
      free(cmd_args);
    }
  }

  return 0;
}