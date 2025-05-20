//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024

char *read_line(void) {
  char *line = malloc(MAX_LINE);
  if (!line) {
    perror("malloc");
    exit(1);
  }
  if (!fgets(line, MAX_LINE, stdin)) {
    free(line);
    return NULL;
  }
  return line;
}

char **parse_line(char *line) {
  char **args = malloc(MAX_LINE);
  if (!args) {
    perror("malloc");
    exit(1);
  }
  int i = 0;
  char *arg = strtok(line, " ");
  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }
  args[i] = NULL;
  return args;
}

int execute_command(char **args) {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  } else if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(1);
    }
  } else {
    int status;
    waitpid(pid, &status, 0);
  }
  return 0;
}

int main(void) {
  while (1) {
    char *line = read_line();
    if (!line) {
      break;
    }
    char **args = parse_line(line);
    if (!args) {
      free(line);
      continue;
    }
    if (strcmp(args[0], "exit") == 0) {
      free(line);
      free(args);
      exit(0);
    }
    if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) == -1) {
        perror("chdir");
        free(line);
        free(args);
        continue;
      }
    } else {
      execute_command(args);
    }
    free(line);
    free(args);
  }
  return 0;
}