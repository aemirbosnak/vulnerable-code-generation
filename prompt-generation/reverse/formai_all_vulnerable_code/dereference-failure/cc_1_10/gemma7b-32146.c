//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "$ ";

int main() {
  char cmd[MAX_CMD_LEN];
  char **argv;
  int argc;
  int i;

  while (1) {
    // Print shell prompt
    printf("%s", shell_prompt);

    // Read user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse user input into arguments
    argv = malloc(MAX_CMD_LEN * sizeof(char *));
    argc = 0;
    i = 0;
    while (cmd[i] != '\0') {
      if (cmd[i] == ' ') {
        argv[argc++] = malloc(MAX_CMD_LEN * sizeof(char));
        argv[argc - 1][0] = '\0';
        i++;
      } else {
        argv[argc++] = malloc(MAX_CMD_LEN * sizeof(char));
        strcpy(argv[argc - 1], &cmd[i]);
        i++;
      }
    }

    // Execute command
    execvp(argv[0], argv);

    // Free memory
    for (i = 0; i < argc; i++) {
      free(argv[i]);
    }
    free(argv);

  }

  return 0;
}