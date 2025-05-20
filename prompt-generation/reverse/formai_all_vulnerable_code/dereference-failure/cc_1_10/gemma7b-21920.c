//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

int main() {
  char cmd[MAX_CMD_LEN];
  char **argv;
  int argc;

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command line arguments
    argc = parse_cmd(cmd, &argv);

    // Execute the command
    if (argc > 0) {
      execvp(argv[0], argv);
    } else {
      printf("Error: invalid command.\n");
    }
  }

  return 0;
}

int parse_cmd(char *cmd, char **argv) {
  int argc = 0;
  char **temp_argv = NULL;
  char *token;

  // Split the command into tokens
  token = strtok(cmd, " ");
  while (token) {
    temp_argv = realloc(temp_argv, (argc + 1) * sizeof(char *));
    temp_argv[argc++] = token;
    token = strtok(NULL, " ");
  }

  // Copy the tokens into argv
  *argv = malloc(argc * sizeof(char *));
  memcpy(argv, temp_argv, argc * sizeof(char *));

  // Free the temporary memory
  free(temp_argv);

  return argc;
}