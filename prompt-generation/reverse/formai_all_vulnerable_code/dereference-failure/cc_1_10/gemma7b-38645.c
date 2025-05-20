//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "prompt$ ";

void parse_command(char **cmd) {
  char **args = NULL;
  int i = 0;

  // Allocate memory for arguments
  args = malloc(MAX_CMD_LEN * sizeof(char *));

  // Split the command into arguments
  char *cmd_ptr = *cmd;
  while (*cmd_ptr) {
    args[i++] = strdup(cmd_ptr);
    cmd_ptr = strchr(cmd_ptr, ' ');
  }

  // Null-terminate the arguments
  args[i] = NULL;

  // Return the arguments
  *cmd = args;
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Print the shell prompt
  printf("%s", shell_prompt);

  // Get the command from the user
  fgets(cmd, MAX_CMD_LEN, stdin);

  // Parse the command
  parse_command(&cmd);

  // Execute the command
  system(cmd);

  // Free the memory allocated for arguments
  free(cmd);

  return 0;
}