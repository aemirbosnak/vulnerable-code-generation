//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 255

typedef struct ShellState {
  char **history;
  int hist_size;
  int hist_pos;
  char prompt[256];
  FILE *fp;
} ShellState;

ShellState shell_state;

void shell_init() {
  shell_state.history = NULL;
  shell_state.hist_size = 0;
  shell_state.hist_pos = 0;
  shell_state.prompt[0] = '$';
  shell_state.prompt[1] = '\0';
  shell_state.fp = stdin;
}

void shell_prompt() {
  printf("%s", shell_state.prompt);
}

void shell_read_cmd(char **cmd) {
  int len = 0;
  char **tmp_cmd = NULL;

  shell_prompt();

  *cmd = malloc(MAX_CMD_LEN);

  len = read(shell_state.fp, *cmd, MAX_CMD_LEN - 1);

  if (len == -1) {
    perror("Error reading command:");
    exit(1);
  }

  (*cmd)[len] = '\0';

  tmp_cmd = shell_state.history;

  shell_state.history = realloc(shell_state.history, (shell_state.hist_size + 1) * sizeof(char *));

  shell_state.history[shell_state.hist_size++] = *cmd;

  shell_state.hist_pos = shell_state.hist_size - 1;
}

int main() {
  shell_init();

  char **cmd = NULL;

  while (1) {
    shell_read_cmd(&cmd);

    if (strcmp(cmd, "exit") == 0) {
      exit(0);
    } else if (fork() == 0) {
      execvp(cmd[0], cmd);
    } else {
      wait(NULL);
    }

    free(cmd);
  }

  return 0;
}