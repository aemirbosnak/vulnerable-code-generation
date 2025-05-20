//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 1024
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  char line[MAX_LINE];
  char *args[MAX_ARGS];
  int running = 1;

  while (running) {
    printf("jmyshell> ");
    fgets(line, MAX_LINE, stdin);

    // Parse the line into arguments.
    int num_args = 0;
    char *ptr = strtok(line, " ");
    while (ptr != NULL && num_args < MAX_ARGS) {
      args[num_args++] = ptr;
      ptr = strtok(NULL, " ");
    }

    // Check if the user wants to exit.
    if (strcmp(args[0], "exit") == 0) {
      running = 0;
    } else {
      // Create a child process.
      pid_t pid = fork();

      if (pid == 0) {
        // This is the child process.
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
      } else if (pid > 0) {
        // This is the parent process.
        int status;
        waitpid(pid, &status, 0);
      } else {
        perror("fork");
      }
    }
  }

  return 0;
}