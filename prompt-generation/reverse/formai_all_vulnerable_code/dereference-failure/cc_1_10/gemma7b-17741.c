//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void parse_cmd(char **cmd) {
  char **args = NULL;
  int i = 0;

  // Allocate memory for arguments
  *args = malloc(MAX_CMD_LEN * sizeof(char *));

  // Split the command into arguments
  char *cmd_ptr = *cmd;
  while (cmd_ptr && *cmd_ptr) {
    args[i++] = strdup(cmd_ptr);
    cmd_ptr = strchr(cmd_ptr, ' ');
  }

  args[i] = NULL;

  // Return the arguments
  *cmd = args;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Loop until the user exits
  while (1) {
    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_cmd(&cmd);

    // Execute the command
    system(cmd[0]);

    // Free the memory allocated for arguments
    free(cmd);
  }

  return 0;
}