//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct Command {
  char **args;
  char **history;
  int idx;
} Command;

Command commands[1024];

void add_command(char **cmd) {
  int i = 0;
  for (; commands[i].args; i++) {}
  commands[i].args = cmd;
  commands[i].history = NULL;
  commands[i].idx = i;
}

void execute_command(char **cmd) {
  int i = 0;
  for (; commands[i].args; i++) {
    if (strcmp(commands[i].args[0], cmd[0]) == 0) {
      // Execute command
      break;
    }
  }
  if (commands[i].args == NULL) {
    // Command not found
  }
}

int main() {
  char cmd[MAX_CMD_LEN];

  while (1) {
    // Prompt
    printf("$ ");

    // Get command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Add command to history
    add_command(cmd);

    // Execute command
    execute_command(cmd);
  }

  return 0;
}