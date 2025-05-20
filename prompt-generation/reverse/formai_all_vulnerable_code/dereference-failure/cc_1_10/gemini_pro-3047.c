//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CMD_LEN 128

int main() {
  char cmd[MAX_CMD_LEN];
  char *args[MAX_CMD_LEN];
  int argc = 0;
  int i = 0;
  int status = 0;

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command into arguments
    argc = 0;
    char *tok = strtok(cmd, " ");
    while (tok != NULL) {
      args[argc++] = tok;
      tok = strtok(NULL, " ");
    }

    // Check for special commands
    if (!strcmp(args[0], "exit")) {
      return 0;
    } else if (!strcmp(args[0], "cd")) {
      if (args[1] == NULL) {
        printf("Usage: cd <directory>\n");
      } else {
        if (chdir(args[1]) == -1) {
          perror(args[1]);
        }
      }
    } else {
      // Fork a child process to execute the command
      pid_t pid = fork();
      if (pid < 0) {
        perror("fork");
        return 1;
      } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror(args[0]);
        exit(1);
      } else {
        // Parent process
        waitpid(pid, &status, 0);
      }
    }
  }

  return 0;
}