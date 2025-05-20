//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
  char **args = NULL;
  char **ptr = NULL;
  int i = 0;

  *cmd = malloc(MAX_CMD_LEN);

  printf("Enter a command: ");
  fgets(*cmd, MAX_CMD_LEN, stdin);

  // Split the command into arguments
  ptr = strtok(*cmd, " ");
  while (ptr) {
    args = realloc(args, (i + 1) * sizeof(char *));
    args[i++] = ptr;
    ptr = strtok(NULL, " ");
  }

  return args;
}

int main() {
  char **cmd = NULL;
  char **args = NULL;

  while (1) {
    // Parse the command
    args = parse_cmd(&cmd);

    // Print the arguments
    printf("Arguments: ");
    for (int i = 0; args[i] != NULL; i++) {
      printf("%s ", args[i]);
    }

    printf("\n");

    // Free the memory
    free(cmd);
    free(args);
  }

  return 0;
}