//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *command) {
  char **args = NULL;
  int num_args = 0;
  char *arg = NULL;

  // Parse the command into arguments
  arg = strtok(command, " ");
  while (arg) {
    args = realloc(args, (num_args + 1) * sizeof(char *));
    args[num_args++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (num_args > 0) {
    execvp(args[0], args);
  } else {
    printf("Error: invalid command.\n");
  }

  // Free the allocated memory
  free(args);
}

int main() {
  char command[MAX_CMD_LEN];

  // Loop until the user enters quit
  while (1) {
    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the user input
    fgets(command, MAX_CMD_LEN, stdin);

    // Execute the command
    if (strcmp(command, "quit") == 0) {
      exit(0);
    } else {
      execute_command(command);
    }
  }

  return 0;
}