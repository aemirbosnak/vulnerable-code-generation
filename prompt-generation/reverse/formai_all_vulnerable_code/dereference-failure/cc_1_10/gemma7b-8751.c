//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
  char **args = NULL;
  int i = 0;

  // Allocate memory for arguments
  args = malloc(MAX_CMD_LEN * sizeof(char *));

  // Tokenize the command line
  char *token = strtok(*cmd, " ");
  while (token) {
    args[i++] = strdup(token);
    token = strtok(NULL, " ");
  }

  // Null terminate the arguments
  args[i] = NULL;

  return args;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Get the user input
  printf("$ ");
  fgets(cmd, MAX_CMD_LEN, stdin);

  // Parse the command line
  char **args = parse_cmd(&cmd);

  // Execute the command
  int pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
  } else {
    wait(NULL);
  }

  // Free the memory allocated for arguments
  free(args);

  return 0;
}