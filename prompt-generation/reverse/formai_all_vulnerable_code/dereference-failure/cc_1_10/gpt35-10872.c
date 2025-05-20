//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

char** split_command(char* command) {
  char** tokens = malloc(MAX_COMMAND_LENGTH * sizeof(char*));
  char* token;
  int token_count = 0;

  token = strtok(command, " \n");
  while (token != NULL) {
    tokens[token_count] = token;
    token_count++;
    token = strtok(NULL, " \n");
  }
  tokens[token_count] = NULL;
  return tokens;
}

int execute_command(char** command_tokens) {
  pid_t pid = fork();
  if (pid == 0) {
    if (execvp(command_tokens[0], command_tokens) == -1) {
      printf("Command not found: %s\n", command_tokens[0]);
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    printf("Fork failed\n");
  } else {
    int status;
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

int main() {
  char command[MAX_COMMAND_LENGTH];
  int status = 1;

  while (status) {
    printf("> ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    char** command_tokens = split_command(command);
    status = execute_command(command_tokens);
    
    free(command_tokens);
  }
  return 0;
}