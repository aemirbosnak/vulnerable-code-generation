//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS_LENGTH 256

int main() {
  char command[MAX_COMMAND_LENGTH];
  char *tokens[MAX_TOKENS_LENGTH];
  int token_count = 0;

  while(1) {
    // Print the prompt
    printf("myShell > ");

    // Get the command from the user
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    // Remove trailing newline character
    if(command[strlen(command) - 1] == '\n') {
      command[strlen(command) - 1] = '\0';
    }

    // Split the command into tokens
    char *token = strtok(command, " ");
    while(token != NULL) {
      tokens[token_count] = token;
      token_count++;
      token = strtok(NULL, " ");
    }
    tokens[token_count] = NULL;

    // Check for exit command
    if(strcmp(tokens[0], "exit") == 0) {
      exit(0);
    }

    // Fork and execute the command
    pid_t pid = fork();
    if(pid == 0) {
      execvp(tokens[0], tokens);
      printf("Invalid command!\n");
      exit(1);
    }

    // Wait for child process to finish
    int status;
    waitpid(pid, &status, 0);
  }

  return 0;
}