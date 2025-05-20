//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

typedef struct Command {
  char *cmd_name;
  char **cmd_args;
  int cmd_fd;
} Command;

int main() {

  char prompt[] = "$ ";
  char cmd_line[MAX_CMD_LEN];
  Command cmd;
  int cmd_num = 0;

  while (1) {
    printf("%s", prompt);
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    // Parse the command line
    char *cmd_start = strchr(cmd_line, ' ');
    char *cmd_name = strtok(cmd_start, " ");

    // Get the command arguments
    char **cmd_args = strtok(NULL, " ");

    // Create a new command
    cmd.cmd_name = strdup(cmd_name);
    cmd.cmd_args = cmd_args;
    cmd.cmd_fd = -1;

    // Add the command to the list
    cmd_num++;
    // (In a real shell, this list would be stored in memory)

    // Execute the command
    switch (fork()) {
      case 0:
        execvp(cmd.cmd_name, cmd.cmd_args);
        break;
      case -1:
        perror("Error executing command");
        break;
    }

    // Print the output of the command
    wait(NULL);
    printf("\n");
  }

  return 0;
}