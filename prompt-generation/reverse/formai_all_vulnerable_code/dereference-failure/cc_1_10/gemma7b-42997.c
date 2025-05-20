//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char shellPrompt[] = "$ ";

void executeCommand(char **command) {
  char **args = NULL;
  int numArgs = 0;

  // Parse the command line arguments
  for (int i = 0; command[i] != NULL; i++) {
    args = realloc(args, (numArgs + 1) * sizeof(char *));
    args[numArgs++] = command[i];
  }

  // Execute the command
  if (args[0] == NULL) {
    printf("Error: command not found.\n");
  } else if (strcmp(args[0], "exit") == 0) {
    exit(0);
  } else if (strcmp(args[0], "help") == 0) {
    printf("Available commands:\n");
    printf("  exit: Exit the shell.\n");
    printf("  help: Display this help message.\n");
  } else {
    printf("Error: command not recognized.\n");
  }

  free(args);
}

int main() {
  char command[MAX_BUFFER_SIZE];

  // Loop until the user enters "exit"
  while (1) {
    // Print the shell prompt
    printf("%s", shellPrompt);

    // Get the user input
    fgets(command, MAX_BUFFER_SIZE, stdin);

    // Execute the command
    executeCommand(command);
  }

  return 0;
}