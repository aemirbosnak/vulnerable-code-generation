//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char *cmd) {
  char **args = NULL;
  int i = 0;
  char *arg = NULL;

  cmd = strchr(cmd, ' ') ? strchr(cmd, ' ') : cmd;

  if (cmd) {
    args = malloc(sizeof(char *) * MAX_CMD_LEN);
    arg = strtok(cmd, " ");

    while (arg) {
      args[i++] = strdup(arg);
      arg = strtok(NULL, " ");
    }
  }

  return args;
}

int main() {
  char cmd[MAX_CMD_LEN];

  printf("$ ");
  fgets(cmd, MAX_CMD_LEN, stdin);

  char **args = parse_cmd(cmd);

  if (args) {
    pid_t pid = fork();

    if (pid == 0) {
      execvp(args[0], args);
      exit(1);
    } else if (pid > 0) {
      wait(NULL);
    } else {
      perror("Error");
    }

    free(args);
  }

  return 0;
}