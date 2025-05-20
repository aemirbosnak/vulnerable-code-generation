//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char *cmd) {
  char **argv = NULL;
  int i = 0;
  char *token = strtok(cmd, " ");

  while (token) {
    argv = realloc(argv, (i + 1) * sizeof(char *));
    argv[i++] = token;
    token = strtok(NULL, " ");
  }

  return argv;
}

int main() {
  char cmd[MAX_CMD_LEN];

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char **argv = parse_cmd(cmd);

    if (!argv) {
      printf("Error parsing command.\n");
      continue;
    }

    int pid = fork();

    if (pid == 0) {
      execvp(argv[0], argv);
      exit(1);
    } else if (pid > 0) {
      wait(NULL);
    } else {
      printf("Error executing command.\n");
    }

    free(argv);
  }

  return 0;
}