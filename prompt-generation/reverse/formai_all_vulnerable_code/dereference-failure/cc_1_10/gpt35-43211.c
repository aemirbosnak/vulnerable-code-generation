//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10

char* read_input() {
  char* input = NULL;
  ssize_t bufsize = 0;
  getline(&input, &bufsize, stdin);
  return input;
}

char** split_input(char* input) {
  char** args = malloc(MAX_ARGS * sizeof(char*));
  char* arg;
  int i = 0;

  arg = strtok(input, " \n");
  while (arg != NULL) {
    args[i] = arg;
    i++;
    arg = strtok(NULL, " \n");
  }
  args[i] = NULL;

  return args;
}

void execute_command(char** args) {
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("Unix Shell");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("Unix Shell");
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}

void unix_shell_loop() {
  char* input;
  char** args;
  int status;

  do {
    printf("> ");
    input = read_input();
    args = split_input(input);
    execute_command(args);

    free(input);
    free(args);
  } while (status);
}

int main() {
  printf("Welcome to the Unix-like Shell\n");
  unix_shell_loop();
  return 0;
}