//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "$ ";

void parse_cmd(char **cmd) {
  *cmd = malloc(MAX_CMD_LEN);
  printf("%s", shell_prompt);
  fgets(*cmd, MAX_CMD_LEN, stdin);
}

void execute_cmd(char *cmd) {
  char **argv = NULL;
  char *arg = NULL;
  int i = 0;

  // Tokenize the command
  argv = malloc(MAX_CMD_LEN * sizeof(char *));
  arg = strtok(cmd, " ");
  while (arg) {
    argv[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (argv[0] == NULL) {
    printf("Error: invalid command.\n");
  } else if (strcmp(argv[0], "exit") == 0) {
    exit(0);
  } else {
    // TODO: Implement other commands
  }

  // Free memory
  free(argv);
  free(cmd);
}

int main() {
  char *cmd = NULL;

  while (1) {
    parse_cmd(&cmd);
    execute_cmd(cmd);
  }

  return 0;
}