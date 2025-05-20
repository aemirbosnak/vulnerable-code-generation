//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

typedef struct Cmd {
  char **cmd_args;
  int status;
} Cmd;

Cmd **parse_cmd(char **cmd_line) {
  char **cmd_args = malloc(MAX_CMD_LEN * sizeof(char *));
  int i = 0;

  for (cmd_args[i] = strtok(cmd_line, " "); cmd_args[i] != NULL; i++) {
    cmd_args[i] = strdup(cmd_args[i]);
  }

  Cmd *cmd = malloc(sizeof(Cmd));
  cmd->cmd_args = cmd_args;
  cmd->status = 0;

  return cmd;
}

void execute_cmd(Cmd *cmd) {
  pid_t pid;

  if ((pid = fork()) == 0) {
    execvp(cmd->cmd_args[0], cmd->cmd_args);
    exit(1);
  } else if (pid > 0) {
    wait(NULL);
  } else {
    perror("fork");
  }

  cmd->status = 1;
}

int main() {
  char cmd_line[MAX_CMD_LEN];

  while (1) {
    printf("$ ");
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    Cmd *cmd = parse_cmd(cmd_line);

    execute_cmd(cmd);

    free(cmd->cmd_args);
    free(cmd);
  }

  return 0;
}