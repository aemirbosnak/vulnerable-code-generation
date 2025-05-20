//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct ShellState {
  char **commands;
  int cmd_size;
  int current_cmd_index;
} ShellState;

ShellState shell_state = {NULL, 0, 0};

void shell_init() {
  shell_state.commands = malloc(sizeof(char *) * MAX_CMD_LEN);
  shell_state.cmd_size = MAX_CMD_LEN;
  shell_state.current_cmd_index = 0;
}

void shell_prompt() {
  printf("$ ");
}

void shell_add_command(char *cmd) {
  shell_state.commands[shell_state.current_cmd_index++] = cmd;
}

void shell_execute_commands() {
  for (int i = 0; i < shell_state.current_cmd_index; i++) {
    printf("Command: %s\n", shell_state.commands[i]);
  }
}

int main() {
  shell_init();

  while (1) {
    shell_prompt();
    char cmd[MAX_CMD_LEN];
    scanf("%s", cmd);

    if (strcmp(cmd, "exit") == 0) {
      break;
    }

    shell_add_command(cmd);
  }

  shell_execute_commands();

  return 0;
}