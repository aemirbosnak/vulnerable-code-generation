//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void parse_command(char **command) {
  *command = malloc(MAX_CMD_LEN);
  printf(shell_prompt);
  fgets(*command, MAX_CMD_LEN, stdin);
  *command = realloc(*command, strlen(*command) + 1);
}

void execute_command(char *command) {
  char **args = NULL;
  char *arg = NULL;
  int i = 0;

  args = malloc(MAX_CMD_LEN * sizeof(char *));

  // Split the command into arguments
  arg = strtok(command, " ");
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
    printf("Error: Unknown command.\n");
  }

  free(args);
  free(command);
}

int main() {
  char *command = NULL;

  while (1) {
    parse_command(&command);
    execute_command(command);
  }

  return 0;
}