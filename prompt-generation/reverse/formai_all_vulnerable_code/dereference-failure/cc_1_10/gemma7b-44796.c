//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *command) {
  char **args = NULL;
  char *arg = NULL;
  int i = 0;

  // Split the command into arguments
  args = malloc(MAX_CMD_LEN * sizeof(char *));
  arg = strtok(command, " ");

  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (args[0] != NULL) {
    system(args[0]);
  } else {
    printf("Error: Invalid command.\n");
  }

  // Free memory
  free(args);
}

int main() {
  char command[MAX_CMD_LEN];

  // Loop until the user enters "exit"
  while (1) {
    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the user input
    fgets(command, MAX_CMD_LEN, stdin);

    // Remove the newline character from the command
    command[strcspn(command, "\n")] = '\0';

    // Execute the command
    execute_command(command);

    // Check if the user wants to exit
    if (strcmp(command, "exit") == 0) {
      break;
    }
  }

  return 0;
}