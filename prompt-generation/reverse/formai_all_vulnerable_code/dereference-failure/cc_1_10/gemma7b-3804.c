//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char *cmd) {
  char **argv = NULL;
  int i = 0;

  // Allocate memory for argv
  argv = malloc(MAX_CMD_LEN * sizeof(char *));

  // Split the command into arguments
  char *token = strtok(cmd, " ");
  while (token) {
    argv[i++] = token;
    token = strtok(NULL, " ");
  }

  // Null terminate the argv array
  argv[i] = NULL;

  return argv;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Enter the shell loop
  while (1) {
    // Print the shell prompt
    printf("$ ");

    // Get the user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_cmd(cmd);

    // Fork the child process
    pid_t pid = fork();

    // If the fork was successful, the child process begins
    if (pid == 0) {
      // Execute the command
      execvp(argv[0], argv);

      // If execvp fails, print an error message
      perror("Error executing command");
      exit(1);
    }

    // The parent process waits for the child process to complete
    wait(NULL);

    // Free the memory allocated for argv
    free(argv);
  }

  return 0;
}