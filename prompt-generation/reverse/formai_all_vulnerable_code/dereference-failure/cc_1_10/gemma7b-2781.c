//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char cmd_line[MAX_CMD_LEN];

void parse_cmd_line(char *cmd_line) {
  char **argv = NULL;
  char *arg = NULL;
  int i = 0;

  // Allocate memory for argv
  argv = malloc(MAX_CMD_LEN * sizeof(char *));

  // Split the command line into arguments
  arg = strtok(cmd_line, " ");
  while (arg) {
    argv[i++] = arg;
    arg = strtok(NULL, " ");
  }

  // Null terminate the argv array
  argv[i] = NULL;

  // Execute the command
  execvp(argv[0], argv);
}

int main() {
  // Prompt the user for a command
  printf("$ ");

  // Get the command line input
  fgets(cmd_line, MAX_CMD_LEN, stdin);

  // Parse the command line
  parse_cmd_line(cmd_line);

  // Wait for the child process to complete
  wait(NULL);

  // Print the output
  printf("\n");

  return 0;
}