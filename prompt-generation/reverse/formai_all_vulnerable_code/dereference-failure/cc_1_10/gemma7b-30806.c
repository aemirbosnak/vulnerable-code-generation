//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char *cmd) {
  char **args = malloc(MAX_CMD_LEN * sizeof(char *));
  int i = 0;
  char *arg = strtok(cmd, " ");
  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }
  args[i] = NULL;
  return args;
}

int main() {
  char prompt[] = "Ash's Last Shell v1.0 $ ";
  char cmd[MAX_CMD_LEN];

  while (1) {
    printf("%s", prompt);
    fgets(cmd, MAX_CMD_LEN, stdin);

    char **args = parse_cmd(cmd);

    if (!strcmp(args[0], "quit")) {
      free(args);
      exit(0);
    } else if (!strcmp(args[0], "help")) {
      printf("Available commands:\n");
      printf("  quit - Exit the shell\n");
      printf("  help - Show this help message\n");
      printf("  echo - Print a message\n");
      printf("  dir - List directory contents\n");
      free(args);
    } else if (!strcmp(args[0], "echo")) {
      printf("%s\n", args[1]);
      free(args);
    } else if (!strcmp(args[0], "dir")) {
      // Implement directory listing functionality
      free(args);
    } else {
      printf("Unknown command: %s\n", args[0]);
      free(args);
    }
  }

  return 0;
}