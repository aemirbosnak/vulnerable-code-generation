//Gemma-7B DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct SystemCommand {
  char **cmd_args;
  int cmd_argc;
  char **cmd_desc;
  struct SystemCommand *next;
} SystemCommand;

SystemCommand *system_command_create(char **cmd_args, int cmd_argc, char **cmd_desc) {
  SystemCommand *new_cmd = malloc(sizeof(SystemCommand));
  new_cmd->cmd_args = cmd_args;
  new_cmd->cmd_argc = cmd_argc;
  new_cmd->cmd_desc = cmd_desc;
  new_cmd->next = NULL;
  return new_cmd;
}

void system_command_add(SystemCommand *head, char **cmd_args, int cmd_argc, char **cmd_desc) {
  SystemCommand *new_cmd = system_command_create(cmd_args, cmd_argc, cmd_desc);
  if (head) {
    new_cmd->next = head;
  }
  head = new_cmd;
}

int main() {
  SystemCommand *commands = NULL;
  system_command_add(commands, "ls", 0, "List files in the current directory.");
  system_command_add(commands, "mkdir", 1, "Create a new directory.");
  system_command_add(commands, "mv", 2, "Move or rename a file or directory.");

  char cmd_line[MAX_CMD_LEN];

  printf("Enter a command: ");
  fgets(cmd_line, MAX_CMD_LEN, stdin);

  char *cmd_args[MAX_CMD_LEN];
  int cmd_argc = 0;
  char **cmd_desc = NULL;

  // Parse the command line
  char *token = strtok(cmd_line, " ");
  while (token) {
    cmd_args[cmd_argc++] = token;
    token = strtok(NULL, " ");
  }

  // Find the command description
  SystemCommand *cmd = commands;
  while (cmd) {
    if (strcmp(cmd->cmd_args[0], cmd_args[0]) == 0) {
      cmd_desc = cmd->cmd_desc;
      break;
    }
    cmd = cmd->next;
  }

  // Print the command description
  if (cmd_desc) {
    printf("Command description: %s\n", cmd_desc);
  } else {
    printf("Error: command not found.\n");
  }

  return 0;
}