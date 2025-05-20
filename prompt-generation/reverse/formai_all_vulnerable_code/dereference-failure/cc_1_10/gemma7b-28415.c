//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void do_command(char **cmd) {
  char **args = NULL;
  char cmd_copy[MAX_CMD_LEN];
  int i = 0;

  strcpy(cmd_copy, cmd[0]);
  args = malloc(sizeof(char *) * MAX_CMD_LEN);

  // Parse the command line arguments
  while (*cmd && *cmd != NULL) {
    args[i++] = strdup(*cmd);
    cmd++;
  }

  // Execute the command
  if (fork() == 0) {
    execvp(cmd_copy, args);
  } else {
    wait(NULL);
  }

  // Free the memory allocated for args
  free(args);
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Display the shell prompt
  printf("%s", shell_prompt);

  // Get the user input
  fgets(cmd, MAX_CMD_LEN, stdin);

  // Remove the newline character from the user input
  cmd[strcspn(cmd, "\n")] = '\0';

  // Do the command
  do_command(&cmd);

  return 0;
}