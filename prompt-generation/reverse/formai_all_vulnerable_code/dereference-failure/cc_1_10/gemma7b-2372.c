//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char shellPrompt[] = "$ ";

void parse_cmd(char *cmd) {
  char **args = NULL;
  char *arg = NULL;
  int i = 0;

  // Tokenize the command
  args = malloc(MAX_CMD_LEN * sizeof(char *));
  arg = strtok(cmd, " ");
  while (arg) {
    args[i++] = strdup(arg);
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (args[0] != NULL) {
    execvp(args[0], args);
  } else {
    printf("Error: Command not found.\n");
  }

  // Free memory
  free(args);
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Enter the shell loop
  while (1) {
    // Print the shell prompt
    printf("%s", shellPrompt);

    // Get the user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_cmd(cmd);
  }

  return 0;
}