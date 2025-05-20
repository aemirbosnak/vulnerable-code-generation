//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

typedef struct ShellState {
  char **history;
  int hist_size;
  char prompt[20];
  FILE *fd;
} ShellState;

ShellState shell_state;

void shell_init() {
  shell_state.history = NULL;
  shell_state.hist_size = 0;
  shell_state.prompt[0] = '$';
  shell_state.fd = stdin;
}

void shell_prompt() {
  printf("%s ", shell_state.prompt);
}

void shell_cmd_parse(char *cmd) {
  // Parse the command and execute it
  char **args = NULL;
  int num_args = 0;

  // Split the command into arguments
  char *arg = strtok(cmd, " ");
  while (arg) {
    args = realloc(args, (num_args + 1) * sizeof(char *));
    args[num_args++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (args[0] == NULL) {
    shell_prompt();
  } else {
    execvp(args[0], args);
  }

  // Free the arguments
  free(args);
}

int main() {
  shell_init();

  // Loop until the user exits
  while (1) {
    char cmd[MAX_CMD_LEN];

    shell_prompt();
    fgets(cmd, MAX_CMD_LEN, shell_state.fd);

    shell_cmd_parse(cmd);
  }

  return 0;
}