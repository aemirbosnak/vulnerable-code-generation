//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024
#define HIST_SIZE 10

char hist[HIST_SIZE][MAX_CMD_LEN];
int hist_pos = 0;

void cmd_history() {
  int i;
  printf("Command history:\n");
  for (i = hist_pos - 1; i >= 0; i--) {
    printf("%d. %s\n", i + 1, hist[i]);
  }
}

void parse_cmd(char *cmd) {
  char **argv = NULL;
  char *arg = NULL;
  int argc = 0;

  // Split the command into arguments
  arg = strtok(cmd, " ");
  while (arg) {
    argv = realloc(argv, (argc + 1) * sizeof(char *));
    argv[argc++] = arg;
    arg = strtok(NULL, " ");
  }

  // Execute the command
  execvp(argv[0], argv);

  // Free the memory allocated for arguments
  free(argv);
}

int main() {
  char cmd[MAX_CMD_LEN];

  // Initialize the command history
  memset(hist, 0, sizeof(hist));

  // Loop until the user enters the exit command
  while (1) {
    // Print the prompt
    printf("$ ");

    // Get the user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Remove the newline character from the command
    cmd[strcspn(cmd, "\n")] = '\0';

    // Store the command in the history
    strcpy(hist[hist_pos], cmd);
    hist_pos++;

    // Parse the command
    parse_cmd(cmd);
  }

  return 0;
}