//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
  char **argv = NULL;
  int i = 0;

  // Allocate memory for argv
  argv = malloc(MAX_CMD_LEN * sizeof(char *));

  // Split the command into arguments
  while (*cmd) {
    char *arg = strchr(*cmd, ' ');
    argv[i++] = arg ? strndup(*cmd, arg - *cmd) : strndup(*cmd, "");
    *cmd = arg ? cmd + 1 : cmd;
  }

  // Null-terminate argv
  argv[i] = NULL;

  return argv;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Print the prompt
  printf("The Dragon's Lair> ");

  // Get the command
  fgets(cmd, MAX_CMD_LEN, stdin);

  // Parse the command
  char **argv = parse_cmd(&cmd);

  // Execute the command
  if (argv[0] != NULL) {
    system(argv[0]);
  } else {
    printf("Error: Invalid command.\n");
  }

  // Free the memory allocated for argv
  free(argv);

  return 0;
}