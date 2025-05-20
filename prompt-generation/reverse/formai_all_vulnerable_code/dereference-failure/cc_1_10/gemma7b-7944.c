//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shellPrompt[] = "The Cavern Shell$ ";

void parseCommand(char **cmd) {
  // Split the command into words
  char **words = NULL;
  int numWords = 0;
  char *word = strtok(*cmd, " ");
  while (word) {
    words = realloc(words, (numWords + 1) * sizeof(char *));
    words[numWords++] = word;
    word = strtok(NULL, " ");
  }

  // Execute the command
  switch (numWords) {
    case 0:
      printf("Error: No command specified.\n");
      break;
    case 1:
      // Simple commands like "help"
      printf("Command: %s\n", words[0]);
      break;
    case 2:
      // Commands with arguments like "echo hello"
      printf("Command: %s %s\n", words[0], words[1]);
      break;
    default:
      // Complex commands like "mkdir foo"
      printf("Error: Command not recognized.\n");
      break;
  }

  // Free allocated memory
  free(words);
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
    parseCommand(&cmd);

    // Check if the user wants to exit
    if (strcmp(cmd, "exit") == 0) {
      printf("Goodbye!\n");
      exit(0);
    }
  }

  return 0;
}