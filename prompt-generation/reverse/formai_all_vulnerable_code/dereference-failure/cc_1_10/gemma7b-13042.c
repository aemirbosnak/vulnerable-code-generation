//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char shellPrompt[] = "$ ";

void executeCommand(char *command) {
  char **argv = NULL;
  char *path = NULL;
  int argc = 0;
  int i = 0;

  // Parse the command into arguments and path
  argv = malloc(MAX_CMD_LEN * sizeof(char *));
  path = malloc(MAX_CMD_LEN * sizeof(char));

  // Find the path of the executable
  path = strchr(command, '/');

  // If there is a path, extract it
  if (path) {
    strncpy(path, "", MAX_CMD_LEN);
  }

  // If there are any arguments, extract them
  argv[argc++] = path;
  i = 0;
  while ((argv[argc] = strchr(command, ' ')) != NULL) {
    argv[argc++] = strchr(command, ' ') + 1;
    i++;
  }

  // Execute the command
  execvp(argv[0], argv);

  // Free memory
  free(argv);
  free(path);
}

int main() {
  char command[MAX_CMD_LEN];

  // Print the shell prompt
  printf("%s", shellPrompt);

  // Get the user input
  fgets(command, MAX_CMD_LEN, stdin);

  // Execute the command
  executeCommand(command);

  return 0;
}