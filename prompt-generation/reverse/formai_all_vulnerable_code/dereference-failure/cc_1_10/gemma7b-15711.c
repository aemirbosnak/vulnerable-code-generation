//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

char **parse_cmd(char **cmd) {
  int i = 0;
  char **args = NULL;
  char **tmp_args = NULL;

  // Allocate memory for args
  args = malloc(MAX_CMD_LEN * sizeof(char *));
  tmp_args = args;

  // Tokenize the command
  char *token = strtok(*cmd, " ");
  while (token) {
    // Add the token to the args array
    args[i++] = token;

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Null terminate the args array
  args[i] = NULL;

  return tmp_args;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Prompt the user for a command
  printf("$ ");
  fgets(cmd, MAX_CMD_LEN, stdin);

  // Parse the command
  char **args = parse_cmd(&cmd);

  // Print the args
  for (int i = 0; args[i] != NULL; i++) {
    printf("%s ", args[i]);
  }

  // Free the memory allocated for args
  free(args);

  return 0;
}