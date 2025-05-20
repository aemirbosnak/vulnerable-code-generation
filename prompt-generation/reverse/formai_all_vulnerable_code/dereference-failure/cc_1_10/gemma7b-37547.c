//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HISTORY 10

char history[MAX_HISTORY][1024];

void parse_command(char **argv) {
  char cmd[256];
  int i = 0;

  printf("$ ");
  fgets(cmd, 256, stdin);

  // Parse the command line arguments
  argv = malloc(10 * sizeof(char *));
  while (cmd[i] != '\0') {
    argv[i] = strdup(cmd + i);
    i++;
  }

  return;
}

void execute_command(char **argv) {
  int i;

  // Check if the command is a built-in command
  if (strcmp(argv[0], "history") == 0) {
    // Print the history
    for (i = 0; i < MAX_HISTORY; i++) {
      if (history[i][0] != '\0') {
        printf("%s\n", history[i]);
      }
    }
  } else if (strcmp(argv[0], "exit") == 0) {
    // Exit the shell
    exit(0);
  } else {
    // Execute the command
    execvp(argv[0], argv);
  }
}

int main() {
  char **argv = NULL;
  parse_command(&argv);
  execute_command(argv);

  return 0;
}