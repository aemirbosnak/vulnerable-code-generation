//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char cmd_line[MAX_CMD_LEN];

void execute_command(char *command) {
  char **args = NULL;
  int num_args = 0;

  // Tokenize the command line into arguments
  args = malloc(MAX_CMD_LEN * sizeof(char *));
  num_args = 0;
  char *arg = strtok(command, " ");
  while (arg) {
    args[num_args++] = strdup(arg);
    arg = strtok(NULL, " ");
  }

  // Add a null terminator to the arguments
  args[num_args] = NULL;

  // Execute the command
  pid_t pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
  } else {
    wait(NULL);
  }

  // Free the memory allocated for the arguments
  free(args);
}

int main() {
  // Prompt the user for a command
  printf("$ ");
  fgets(cmd_line, MAX_CMD_LEN, stdin);

  // Remove the newline character from the command line
  cmd_line[strcspn(cmd_line, "\n")] = '\0';

  // Execute the command
  execute_command(cmd_line);

  return 0;
}