//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shellPrompt[] = "$ ";

void executeCommand(char *command) {
  char **args = NULL;
  int numArgs = 0;

  // Parse the command into arguments
  args = splitCommand(command, &numArgs);

  // Execute the command
  switch (numArgs) {
    case 0:
      printf("Error: Command not found.\n");
      break;
    case 1:
      printf("Error: Missing arguments.\n");
      break;
    default:
      // Execute the command with its arguments
      execvp(args[0], args);
  }

  // Free the memory allocated for arguments
  free(args);
}

int splitCommand(char *command, int *numArgs) {
  char **args = NULL;
  char *token = strtok(command, " ");

  *numArgs = 0;
  args = malloc(MAX_CMD_LEN * sizeof(char *));

  while (token) {
    args[*numArgs] = token;
    *numArgs++;
    token = strtok(NULL, " ");
  }

  return args;
}

int main() {
  char command[MAX_CMD_LEN];

  // Print the shell prompt
  printf("%s", shellPrompt);

  // Get the user command
  fgets(command, MAX_CMD_LEN, stdin);

  // Execute the command
  executeCommand(command);

  return 0;
}