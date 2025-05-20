//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char **cmd_line, int *num_args) {
  char **args = NULL;
  int i = 0;
  *num_args = 0;

  // Allocate memory for arguments
  args = malloc(MAX_CMD_LEN * sizeof(char *));

  // Tokenize the command line
  char *token = strtok(*cmd_line, " ");

  // Loop over tokens
  while (token) {
    args[*num_args] = strdup(token);
    *num_args++;
    token = strtok(NULL, " ");
  }

  return args;
}

int main() {
  char cmd_line[MAX_CMD_LEN];
  int num_args = 0;
  char **args = NULL;

  // Get the command line
  printf("$ ");
  fgets(cmd_line, MAX_CMD_LEN, stdin);

  // Parse the command line
  args = parse_cmd(&cmd_line, &num_args);

  // Print the arguments
  for (int i = 0; i < num_args; i++) {
    printf("%s ", args[i]);
  }

  printf("\n");

  // Free memory
  free(args);

  return 0;
}