//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 1024

char **parse_command(char **cmd);
void execute_command(char **cmd);

int main() {
  char cmd[MAX_CMD_LEN];
  char **parsed_cmd;

  printf("Welcome to the Shell!\n");

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    parsed_cmd = parse_command(cmd);

    if (parsed_cmd) {
      execute_command(parsed_cmd);
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}

char **parse_command(char **cmd) {
  // Remove trailing newline character
  cmd[strcspn(cmd, "\n")] = '\0';

  // Tokenize the command
  char **parsed_cmd = malloc(sizeof(char *) * MAX_CMD_LEN);
  int i = 0;
  char *token = strtok(cmd, " ");

  while (token) {
    parsed_cmd[i++] = token;
    token = strtok(NULL, " ");
  }

  parsed_cmd[i] = NULL;

  return parsed_cmd;
}

void execute_command(char **cmd) {
  // Check if the command is a built-in command
  if (strcmp(cmd[0], "exit") == 0) {
    exit(0);
  } else if (strcmp(cmd[0], "help") == 0) {
    printf("Available commands:\n");
    printf("  exit\n");
    printf("  help\n");
  } else {
    // Execute the command
    system(cmd[0]);
  }
}