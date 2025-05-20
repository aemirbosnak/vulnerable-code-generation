//Gemma-7B DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Cmd {
  char **cmds;
  int size;
} Cmd;

Cmd *createCmd(int size) {
  Cmd *cmd = malloc(sizeof(Cmd));
  cmd->cmds = malloc(size * sizeof(char *));
  cmd->size = size;
  return cmd;
}

void addCmd(Cmd *cmd, char *cmdStr) {
  cmd->cmds[cmd->size++] = strdup(cmdStr);
}

int executeCmd(Cmd *cmd, char *cmdStr) {
  for (int i = 0; i < cmd->size; i++) {
    if (strcmp(cmdStr, cmd->cmds[i]) == 0) {
      printf("Command: %s\n", cmd->cmds[i]);
      return 1;
    }
  }
  return 0;
}

int main() {
  Cmd *myCmd = createCmd(10);
  addCmd(myCmd, "ls");
  addCmd(myCmd, "pwd");
  addCmd(myCmd, "echo hello");

  char cmdStr[MAX_CMD_LEN];

  printf("Enter a command: ");
  scanf("%s", cmdStr);

  if (executeCmd(myCmd, cmdStr)) {
    printf("Command found!\n");
  } else {
    printf("Command not found.\n");
  }

  return 0;
}