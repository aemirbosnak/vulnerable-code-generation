//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char prompt[] = "$ ";

void parse_command(char *cmd) {
  char **argv = NULL;
  char *arg = NULL;
  int i = 0;

  // Tokenize the command
  argv = malloc(MAX_CMD_LEN * sizeof(char *));
  arg = strtok(cmd, " ");
  while (arg) {
    argv[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  if (argv[0] && !strcmp(argv[0], "exit")) {
    exit(0);
  } else if (fork() == 0) {
    execvp(argv[0], argv);
  } else {
    printf("Error executing command.\n");
  }

  // Free memory
  free(argv);
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Loop until the user exits
  while (1) {
    // Print the prompt
    printf("%s", prompt);

    // Get the command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_command(cmd);
  }

  return 0;
}