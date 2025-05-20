//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char **argv, char **cmd_line) {
  char **new_argv = NULL;
  int i = 0;
  int cmd_len = 0;

  *argv = malloc(MAX_CMD_LEN);
  new_argv = malloc((MAX_CMD_LEN / 16) * sizeof(char *));

  cmd_len = strlen(cmd_line);

  for (i = 0; i < cmd_len && cmd_line[i] != '\0'; i++) {
    if (cmd_line[i] == ' ') {
      new_argv[i] = malloc(MAX_CMD_LEN);
      strncpy(new_argv[i], cmd_line + i + 1, MAX_CMD_LEN - 1);
      i++;
    } else {
      argv[i] = malloc(MAX_CMD_LEN);
      strncpy(argv[i], cmd_line + i, MAX_CMD_LEN - 1);
      i++;
    }
  }

  new_argv[i] = NULL;

  return new_argv;
}

int main() {
  char cmd_line[MAX_CMD_LEN];

  printf("Enter a command: ");
  fgets(cmd_line, MAX_CMD_LEN, stdin);

  char **argv = NULL;
  char **new_argv = parse_cmd(&argv, cmd_line);

  if (new_argv) {
    execvp(new_argv[0], new_argv);
  } else {
    printf("Error executing command.\n");
  }

  return 0;
}