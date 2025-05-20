//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  char *line;
  char *args[MAX_LINE_LENGTH / 2];
  int status;
  pid_t pid;

  while (1) {
    printf("$ ");
    fflush(stdout);

    line = malloc(MAX_LINE_LENGTH);
    if (!line) {
      perror("malloc");
      exit(1);
    }

    if (!fgets(line, MAX_LINE_LENGTH, stdin)) {
      break;
    }

    line[strlen(line) - 1] = '\0';

    if (!strcmp(line, "exit")) {
      break;
    }

    if (!parse_line(line, args)) {
      continue;
    }

    if ((pid = fork()) < 0) {
      perror("fork");
      exit(1);
    } else if (pid == 0) {
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else {
      wait(&status);
    }

    free(line);
  }

  free(line);

  return 0;
}

int parse_line(char *line, char *args[]) {
  int i = 0;

  char *token = strtok(line, " ");
  while (token) {
    args[i++] = token;
    token = strtok(NULL, " ");
  }

  args[i] = NULL;

  return i;
}