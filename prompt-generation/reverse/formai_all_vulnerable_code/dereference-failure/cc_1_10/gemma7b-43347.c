//Gemma-7B DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Command {
  char *name;
  char **arguments;
  struct Command *next;
} Command;

Command *parse_commands(char *input) {
  Command *head = NULL;
  char *cmd_start = input;
  char *arg_start;
  int i = 0;

  while (cmd_start) {
    arg_start = strchr(cmd_start, ' ');
    char cmd_name[MAX_CMD_LEN];
    strncpy(cmd_name, cmd_start, arg_start - cmd_start);
    cmd_name[arg_start - cmd_start] = '\0';

    Command *new_cmd = malloc(sizeof(Command));
    new_cmd->name = strdup(cmd_name);
    new_cmd->arguments = malloc(sizeof(char *) * (i + 1));

    new_cmd->arguments[i] = malloc(MAX_CMD_LEN);
    strncpy(new_cmd->arguments[i], arg_start + 1, MAX_CMD_LEN - 1);
    new_cmd->arguments[i++] = NULL;

    if (head) {
      new_cmd->next = head;
    } else {
      head = new_cmd;
    }

    cmd_start = strchr(arg_start + 1, ' ') ? arg_start + 1 : NULL;
  }

  return head;
}

int main() {
  char input[] = "echo hello world\nset foo bar\nlist";
  Command *commands = parse_commands(input);

  for (Command *cmd = commands; cmd; cmd = cmd->next) {
    printf("Command: %s\n", cmd->name);
    printf("Arguments: ");
    for (int i = 0; cmd->arguments[i] != NULL; i++) {
      printf("%s ", cmd->arguments[i]);
    }
    printf("\n");
  }

  return 0;
}