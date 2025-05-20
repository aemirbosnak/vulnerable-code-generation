//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **argv, char **cmd) {
  int i = 0;
  char **new_argv = NULL;

  // Allocate memory for new argv
  new_argv = malloc(sizeof(char *) * (MAX_CMD_LEN + 1));

  // Split the command into arguments
  while (*cmd) {
    new_argv[i++] = strdup(*cmd);
    cmd++;
  }

  // Null terminator
  new_argv[i] = NULL;

  // Return the new argv
  return new_argv;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Loop until the user enters "exit"
  while (1) {
    // Print prompt
    printf("$ ");

    // Get the command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Remove newline character
    cmd[strcspn(cmd, "\n")] = '\0';

    // Parse the command
    char **argv = parse_cmd(NULL, cmd);

    // Execute the command
    execvp(argv[0], argv);

    // Free the memory allocated for argv
    free(argv);

    // If the command is "exit", exit the shell
    if (strcmp(argv[0], "exit") == 0) {
      exit(0);
    }

    // Error message
    printf("Error: command not found.\n");
  }

  return 0;
}