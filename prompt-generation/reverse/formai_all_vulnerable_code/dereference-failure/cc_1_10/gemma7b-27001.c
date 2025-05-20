//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *cmd) {
  char **argv = NULL;
  int argc = 0;

  // Tokenize the command
  char *token = strtok(cmd, " ");
  while (token) {
    argv = realloc(argv, (argc + 1) * sizeof(char *));
    argv[argc++] = token;
    token = strtok(NULL, " ");
  }

  // Execute the command
  if (execvp(argv[0], argv) < 0) {
    perror("Error executing command");
  }

  // Free the memory allocated for argv
  free(argv);
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Loop until the user enters "quit"
  while (1) {
    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the user's command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Remove the newline character from the command
    cmd[strcspn(cmd, "\n")] = '\0';

    // Execute the command
    if (strcmp(cmd, "quit") == 0) {
      exit(0);
    } else {
      execute_command(cmd);
    }
  }

  return 0;
}