//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Cmd {
  char **cmd_args;
  char **cmd_history;
  int cmd_index;
  struct Cmd* next;
} Cmd;

Cmd* cmd_init(char* cmd_line) {
  Cmd* cmd = malloc(sizeof(Cmd));
  cmd->cmd_args = malloc(sizeof(char*) * MAX_CMD_LEN);
  cmd->cmd_history = malloc(sizeof(char*) * MAX_CMD_LEN);
  cmd->cmd_index = 0;
  cmd->next = NULL;

  char* cmd_copy = strdup(cmd_line);
  cmd->cmd_args[0] = cmd_copy;

  return cmd;
}

void cmd_add_arg(Cmd* cmd, char* arg) {
  cmd->cmd_args[cmd->cmd_index++] = arg;
}

void cmd_add_history(Cmd* cmd, char* hist) {
  cmd->cmd_history[cmd->cmd_index++] = hist;
}

void cmd_execute(Cmd* cmd) {
  // Execute the command based on the args and history
  printf("Executing command: %s\n", cmd->cmd_args[0]);
  for (int i = 1; cmd->cmd_args[i] != NULL; i++) {
    printf("Arg: %s\n", cmd->cmd_args[i]);
  }
  printf("History: \n");
  for (int i = 0; cmd->cmd_history[i] != NULL; i++) {
    printf("  %s\n", cmd->cmd_history[i]);
  }
}

int main() {
  char cmd_line[MAX_CMD_LEN];

  // Loop until the user enters an exit command
  while (1) {
    printf("$ ");
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    // Create a new command object
    Cmd* cmd = cmd_init(cmd_line);

    // Execute the command
    cmd_execute(cmd);

    // Free the command object
    free(cmd->cmd_args);
    free(cmd->cmd_history);
    free(cmd);
  }

  return 0;
}