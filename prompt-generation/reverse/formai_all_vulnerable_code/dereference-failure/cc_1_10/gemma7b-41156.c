//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Command {
  char *name;
  char **args;
  struct Command *next;
} Command;

Command *parse_command(char *cmd) {
  char *cmd_copy = strdup(cmd);
  char *arg_start = strchr(cmd_copy, ' ');
  char **args = NULL;
  int num_args = 0;

  if (arg_start) {
    args = malloc(sizeof(char *) * (num_args + 1));
    arg_start++;
    while (arg_start && *arg_start) {
      args[num_args++] = strdup(arg_start);
      arg_start = strchr(arg_start, ' ');
    }
  }

  Command *command = malloc(sizeof(Command));
  command->name = strdup(cmd_copy);
  command->args = args;
  command->next = NULL;

  return command;
}

int main() {
  char cmd[MAX_CMD_LEN];

  printf("Welcome to the Grand Hall of Oldstone Castle!\n");
  printf("Please enter your command: ");

  fgets(cmd, MAX_CMD_LEN, stdin);

  Command *command = parse_command(cmd);

  if (command) {
    printf("Command: %s\n", command->name);
    printf("Arguments: ");
    for (int i = 0; command->args[i] != NULL; i++) {
      printf("%s ", command->args[i]);
    }
    printf("\n");
  } else {
    printf("Error parsing command.\n");
  }

  return 0;
}