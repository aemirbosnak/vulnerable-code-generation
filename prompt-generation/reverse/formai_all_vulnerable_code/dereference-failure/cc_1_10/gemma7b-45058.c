//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 255

char shellPrompt[] = "$ ";

void executeCommand(char *command) {
  char **args = NULL;
  char *arg = NULL;
  int i = 0;

  // Split the command into arguments
  args = malloc(MAX_CMD_LEN * sizeof(char *));
  arg = strtok(command, " ");
  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Create a child process
  pid_t pid = fork();

  // If the child process is created successfully
  if (pid == 0) {
    // Executing the command
    execvp(args[0], args);
  } else if (pid > 0) {
    // Waiting for the child process to complete
    wait(NULL);

    // Free the memory allocated for the arguments
    free(args);
  } else {
    // Error in creating the child process
    perror("Error executing command");
  }
}

int main() {
  char command[MAX_CMD_LEN];

  // Prompt the user for a command
  printf("%s", shellPrompt);
  scanf("%s", command);

  // Execute the command
  executeCommand(command);

  return 0;
}