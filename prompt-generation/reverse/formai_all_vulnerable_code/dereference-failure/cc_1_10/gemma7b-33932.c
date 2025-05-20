//Gemma-7B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct Command {
  char **cmd_args;
  int argc;
  char cmd_name[MAX_CMD_LEN];
} Command;

Command *parse_command(char *command_line) {
  Command *cmd = malloc(sizeof(Command));
  cmd->argc = 0;
  cmd->cmd_args = NULL;
  char **tokens = NULL;

  // Tokenize the command line
  tokens = strtok(command_line, " ");

  // Count the number of arguments
  while (tokens) {
    cmd->argc++;
    cmd->cmd_args = realloc(cmd->cmd_args, (cmd->argc) * sizeof(char *));
    cmd->cmd_args[cmd->argc - 1] = strdup(tokens);
    tokens = strtok(NULL, " ");
  }

  // Copy the command name
  strcpy(cmd->cmd_name, tokens);

  return cmd;
}

int main() {
  char command_line[MAX_CMD_LEN] = "ls -l";
  Command *cmd = parse_command(command_line);

  printf("Command name: %s\n", cmd->cmd_name);
  printf("Number of arguments: %d\n", cmd->argc);
  printf("Arguments: ");
  for (int i = 0; i < cmd->argc; i++) {
    printf("%s ", cmd->cmd_args[i]);
  }

  free(cmd);

  return 0;
}