//Gemma-7B DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Command {
  char *name;
  char **arguments;
  struct Command *next;
} Command;

Command *head = NULL;

void execute_command(char *command) {
  char **args = NULL;
  char *cmd_copy = strdup(command);
  char *arg_start = strchr(cmd_copy, ' ');
  int arg_count = 0;

  if (arg_start) {
    args = malloc(sizeof(char *) * (arg_count + 1));
    arg_start++;
    while ((arg_start = strchr(arg_start, ' ')) != NULL) {
      args[arg_count++] = strdup(arg_start);
      arg_start++;
    }
    args[arg_count] = NULL;
  }

  Command *new_command = malloc(sizeof(Command));
  new_command->name = strdup(command);
  new_command->arguments = args;
  new_command->next = head;
  head = new_command;

  if (args) {
    free(args);
  }
  free(cmd_copy);
}

int main() {
  char command[MAX_CMD_LEN];

  printf("Enter a command: ");
  fgets(command, MAX_CMD_LEN, stdin);

  execute_command(command);

  printf("List of commands:\n");
  for (Command *cmd = head; cmd; cmd = cmd->next) {
    printf("%s ", cmd->name);
    printf("(%s)\n", cmd->arguments[0]);
  }

  return 0;
}