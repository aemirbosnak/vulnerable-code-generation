//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void parse_cmd(char **cmd) {
  char *arg = NULL;
  char *cmd_cpy = strdup(*cmd);

  // Split the command into arguments
  arg = strtok(cmd_cpy, " ");

  // Allocate memory for arguments
  *cmd = malloc(MAX_CMD_LEN);

  // Copy the arguments into the allocated memory
  while (arg) {
    strcpy((*cmd)++, arg);
    arg = strtok(NULL, " ");
  }

  // Free the memory allocated for the command copy
  free(cmd_cpy);
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Loop until the user enters "exit"
  while (1) {
    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_cmd(&cmd);

    // Execute the command
    system(cmd);

    // Free the memory allocated for the command
    free(cmd);
  }

  return 0;
}