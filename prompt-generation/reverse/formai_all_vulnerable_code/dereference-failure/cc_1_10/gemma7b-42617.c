//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char *cmd) {
  char **args = NULL;
  int i = 0;
  char *arg = NULL;

  // Allocate memory for arguments
  args = malloc(MAX_CMD_LEN * sizeof(char *));

  // Split the command into arguments
  arg = strtok(cmd, " ");
  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Null terminate the arguments
  args[i] = NULL;

  return args;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Prompt the user for a command
  printf("$ ");
  fgets(cmd, MAX_CMD_LEN, stdin);

  // Parse the command
  char **args = parse_cmd(cmd);

  // Execute the command
  if (args[0] != NULL) {
    pid_t pid = fork();
    if (pid == 0) {
      execvp(args[0], args);
      exit(1);
    } else {
      wait(NULL);
    }
  }

  // Free the memory allocated for arguments
  free(args);

  return 0;
}