//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shellPrompt[] = ">> ";

void executeCommand(char *command) {
  char **tokens = NULL;
  char *token = NULL;
  int i = 0;

  tokens = malloc(MAX_CMD_LEN * sizeof(char *));

  // Tokenize the command
  token = strtok(command, " ");
  while (token) {
    tokens[i++] = token;
    token = strtok(NULL, " ");
  }

  // Check if the command is valid
  if (strcmp(tokens[0], "exit") == 0) {
    exit(0);
  } else if (strcmp(tokens[0], "help") == 0) {
    printf("Available commands:\n");
    printf("  exit: Exit the shell\n");
    printf("  help: Show this help message\n");
  } else {
    printf("Error: Command not found.\n");
  }

  free(tokens);
}

int main() {
  char command[MAX_CMD_LEN];

  // Display the shell prompt
  printf("%s", shellPrompt);

  // Get the command from the user
  fgets(command, MAX_CMD_LEN, stdin);

  // Execute the command
  executeCommand(command);

  return 0;
}