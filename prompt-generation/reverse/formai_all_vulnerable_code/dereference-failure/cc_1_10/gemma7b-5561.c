//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char cmd_buffer[MAX_CMD_LEN];

void parse_cmd(char *cmd) {
  char **argv = NULL;
  int argc = 0;
  char *ptr = cmd;

  // Tokenize the command
  while (ptr && *ptr) {
    char *arg = strchr(ptr, ' ');
    if (arg) {
      *arg = '\0';
      argv = realloc(argv, (argc + 1) * sizeof(char *));
      argv[argc++] = ptr;
      ptr = arg + 1;
    } else {
      argv = realloc(argv, (argc + 1) * sizeof(char *));
      argv[argc++] = ptr;
      ptr = NULL;
    }
  }

  // Execute the command
  if (argc) {
    execvp(argv[0], argv);
  } else {
    printf("Error: command not found.\n");
  }
}

int main() {
  // Enter the shell loop
  while (1) {
    // Print the prompt
    printf("$ ");

    // Get the command
    fgets(cmd_buffer, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_cmd(cmd_buffer);
  }

  return 0;
}