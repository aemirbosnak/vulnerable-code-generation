//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_LINE_LEN 1024

void execute(char* args[]) {
  pid_t pid;

  pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
    perror("execvp");
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("fork");
  } else {
    waitpid(pid, NULL, 0);
  }
}

int main() {
  char line[MAX_LINE_LEN];
  char* args[MAX_ARGS];
  int num_args;
  int i;

  while (1) {
    printf("# ");
    fgets(line, MAX_LINE_LEN, stdin);

    // Parse the line into arguments
    num_args = 0;
    args[num_args++] = strtok(line, " \t\n");
    while (args[num_args - 1] != NULL) {
      args[num_args++] = strtok(NULL, " \t\n");
    }

    // Check for special commands
    if (strcmp(args[0], "exit") == 0) {
      break;
    } else if (strcmp(args[0], "cd") == 0) {
      if (args[1] == NULL) {
        chdir(getenv("HOME"));
      } else {
        chdir(args[1]);
      }
    } else {
      // Execute the command
      execute(args);
    }
  }

  return 0;
}