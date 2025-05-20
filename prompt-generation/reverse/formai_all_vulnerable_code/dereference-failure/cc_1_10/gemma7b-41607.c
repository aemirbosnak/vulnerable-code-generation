//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 255

char shell_prompt[] = "$ ";

void parse_command(char *command) {
  char **args = NULL;
  int num_args = 0;

  // Tokenize the command
  char *token = strtok(command, " ");
  while (token) {
    args = realloc(args, (num_args + 1) * sizeof(char *));
    args[num_args++] = token;
    token = strtok(NULL, " ");
  }

  // Execute the command
  if (args[0] != NULL) {
    execvp(args[0], args);
  } else {
    printf("Error: command not found.\n");
  }

  // Free the allocated memory
  free(args);
}

int main() {
  char command[MAX_CMD_LEN];

  // Loop until the user enters an exit command
  while (1) {
    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the user input
    fgets(command, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_command(command);

    // Check if the user entered the exit command
    if (strcmp(command, "exit") == 0) {
      break;
    }
  }

  return 0;
}