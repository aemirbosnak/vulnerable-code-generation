//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 1024

int main() {
  char cmd[MAX_CMD_LEN];
  char **argv;
  int argc;
  int i;

  printf("Welcome to the Happy Shell!\n");

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Split the command into argv and argc
    argv = NULL;
    argc = 0;
    i = 0;
    while (cmd[i] != '\0') {
      if (cmd[i] == ' ') {
        argv = realloc(argv, (argc + 1) * sizeof(char *));
        argv[argc++] = malloc(MAX_CMD_LEN);
        i++;
      } else {
        argv[argc] = malloc(MAX_CMD_LEN);
        strcpy(argv[argc], cmd + i);
        argc++;
      }
      i++;
    }

    // Execute the command
    if (argc > 0) {
      execvp(argv[0], argv);
    } else {
      printf("Error: invalid command.\n");
    }

    // Free memory
    for (i = 0; i < argc; i++) {
      free(argv[i]);
    }
    free(argv);

    // Continue the loop
  }

  return 0;
}