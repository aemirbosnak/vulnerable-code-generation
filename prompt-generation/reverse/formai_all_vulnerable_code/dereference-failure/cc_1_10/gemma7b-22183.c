//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

int main() {
  char cmd[MAX_CMD_LEN];
  char **args;
  int i;
  pid_t pid;

  // Loop to get user input until they enter "quit"
  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Check if the user entered "quit"
    if (strcmp(cmd, "quit") == 0) {
      break;
    }

    // Split the user's command into arguments
    args = malloc(MAX_CMD_LEN * sizeof(char *));
    i = 0;
    args[i++] = strtok(cmd, " ");

    // Loop over the remaining arguments
    while ((args[i] = strtok(NULL, " ")) != NULL) {
      i++;
    }

    // Create a child process
    pid = fork();

    // If the child process is successful, continue
    if (pid == 0) {
      execvp(args[0], args);
      exit(1);
    }

    // Wait for the child process to complete
    wait(NULL);

    // Free the memory allocated for the arguments
    free(args);
  }

  return 0;
}