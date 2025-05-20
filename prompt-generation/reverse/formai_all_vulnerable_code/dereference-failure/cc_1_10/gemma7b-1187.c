//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

int main() {
  char cmd[MAX_CMD_LEN];
  char **args;
  int i, status;
  pid_t pid;

  while (1) {
    // Print prompt
    printf("$ ");

    // Get command line input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse command line arguments
    args = NULL;
    i = 0;
    while ((cmd[i] != '\0') && (cmd[i] != '\n')) {
      args = realloc(args, (i + 1) * sizeof(char *));
      args[i++] = strdup(cmd + i);
    }

    // Create a child process
    pid = fork();

    // Child process
    if (pid == 0) {
      // Execute command
      execvp(args[0], args);

      // Error if execvp fails
      perror("Error executing command");
      exit(1);
    }

    // Parent process
    else if (pid > 0) {
      // Wait for child process to complete
      wait(&status);

      // Print child process output
      printf("Child process exit status: %d\n", status);
    }

    // Free memory allocated for arguments
    free(args);

    // Clear command buffer
    memset(cmd, 0, MAX_CMD_LEN);
  }

  return 0;
}