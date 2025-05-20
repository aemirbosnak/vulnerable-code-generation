//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

void readLine(char *line) {
  printf("shell>> ");
  fgets(line, MAX_LINE_LENGTH, stdin);
  line[strlen(line) - 1] = '\0';  // Remove newline character
}

int parseArgs(char *line, char **args) {
  int numArgs = 0;
  char *arg = strtok(line, " ");
  while (arg != NULL && numArgs < MAX_ARGS) {
    args[numArgs++] = arg;
    arg = strtok(NULL, " ");
  }
  return numArgs;
}

void executeCommand(char **args) {
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    execvp(args[0], args);
    perror("Error executing command");
    exit(1);
  } else if (pid > 0) {
    // Parent process
    wait(NULL);
  } else {
    perror("Error forking process");
  }
}

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];

  while (1) {
    readLine(line);
    int numArgs = parseArgs(line, args);
    if (numArgs > 0) {
      if (strcmp(args[0], "exit") == 0) {
        printf("Exiting shell... Bye!\n");
        break;
      } else {
        executeCommand(args);
      }
    }
  }

  return 0;
}