//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 32
#define ERROR -1
#define EXIT 0

void print_error(char *msg) {
  fprintf(stderr, "%s\n", msg);
}

int main(int argc, char **argv) {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    // Prompt the user for input
    printf("sh> ");

    // Read the user's input
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      print_error("Error reading input");
      return ERROR;
    }

    // Parse the user's input into arguments
    int num_args = 0;
    char *arg = strtok(line, " ");
    while (arg != NULL && num_args < MAX_ARGS) {
      args[num_args++] = arg;
      arg = strtok(NULL, " ");
    }

    if (strcmp(args[0], "exit") == 0) {
      return EXIT;
    }

    // Fork a new process to execute the command
    pid_t pid = fork();
    if (pid == ERROR) {
      print_error("Error forking");
      return ERROR;
    }

    // If the child process, execute the command
    if (pid == 0) {
      execvp(args[0], args);
      print_error("Error executing command");
      return ERROR;
    }

    // If the parent process, wait for the child process to finish
    else {
      wait(&status);
    }
  }

  return 0;
}