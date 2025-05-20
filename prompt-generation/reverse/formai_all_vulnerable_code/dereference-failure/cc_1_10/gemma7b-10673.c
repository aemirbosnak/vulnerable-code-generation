//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

char shell_prompt[] = "$ ";

void parse_command(char **cmd) {
  *cmd = malloc(MAX_CMD_LEN);
  printf("%s", shell_prompt);
  fgets(*cmd, MAX_CMD_LEN, stdin);
}

void execute_command(char *cmd) {
  char **args = NULL;
  char *arg = NULL;
  int i = 0;

  // Tokenize the command
  args = malloc(MAX_CMD_LEN * sizeof(char *));
  arg = strtok(cmd, " ");
  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (args[0] == "exit") {
    exit(0);
  } else if (args[0] == "help") {
    printf("Available commands:\n");
    printf("  exit: Exit the shell\n");
    printf("  help: Display this help message\n");
  } else {
    printf("Unknown command: %s\n", args[0]);
  }

  // Free memory
  free(args);
  free(*cmd);
}

int main() {
  char *cmd = NULL;

  while (1) {
    parse_command(&cmd);
    execute_command(cmd);
  }

  return 0;
}