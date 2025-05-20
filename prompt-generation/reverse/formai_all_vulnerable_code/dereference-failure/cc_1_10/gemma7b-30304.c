//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 255

char shellPrompt[] = "$ ";

void parseCmd(char *cmd) {
  char **argv = NULL;
  char *arg = NULL;
  int i = 0;

  // Split the command into arguments
  arg = strtok(cmd, " ");
  while (arg) {
    argv = realloc(argv, (i + 1) * sizeof(char *));
    argv[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (argv[0] != NULL) {
    execvp(argv[0], argv);
  } else {
    printf("Error: command not found.\n");
  }

  // Free memory
  free(argv);
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Enter the shell loop
  while (1) {
    // Print the shell prompt
    printf(shellPrompt);

    // Get the user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    parseCmd(cmd);

    // Check if the user wants to exit
    if (strcmp(cmd, "exit") == 0) {
      exit(0);
    }
  }

  return 0;
}