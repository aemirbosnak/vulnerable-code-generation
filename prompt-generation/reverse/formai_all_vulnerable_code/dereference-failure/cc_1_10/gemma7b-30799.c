//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Command {
  char *cmd;
  char **args;
  int numArgs;
} Command;

Command *parseCmd(char *cmdStr) {
  Command *cmd = malloc(sizeof(Command));
  cmd->cmd = strdup(cmdStr);
  cmd->args = NULL;
  cmd->numArgs = 0;

  char *arg = strtok(cmdStr, " ");
  while (arg) {
    cmd->args = realloc(cmd->args, (cmd->numArgs + 1) * sizeof(char *));
    cmd->args[cmd->numArgs++] = strdup(arg);
    arg = strtok(NULL, " ");
  }

  return cmd;
}

void executeCmd(Command *cmd) {
  if (strcmp(cmd->cmd, "exit") == 0) {
    exit(0);
  } else if (strcmp(cmd->cmd, "help") == 0) {
    printf("Available commands:\n");
    printf("  exit\n");
    printf("  help\n");
    printf("  dir\n");
  } else if (strcmp(cmd->cmd, "dir") == 0) {
    system("ls");
  } else {
    printf("Error: command not found.\n");
  }
}

int main() {
  char cmdStr[MAX_CMD_LEN];

  printf("Enter a command: ");
  fgets(cmdStr, MAX_CMD_LEN, stdin);

  Command *cmd = parseCmd(cmdStr);
  executeCmd(cmd);

  free(cmd->cmd);
  free(cmd->args);
  free(cmd);

  return 0;
}