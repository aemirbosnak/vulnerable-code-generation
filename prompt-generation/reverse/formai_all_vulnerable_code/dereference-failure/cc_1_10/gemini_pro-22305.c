//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

char *args[MAX_ARGS];
char *envp[] = {NULL};

void parse_line(char *line) {
  int i = 0;
  char *token;
  token = strtok(line, " ");
  while (token != NULL) {
    args[i++] = token;
    token = strtok(NULL, " ");
  }
  args[i] = NULL;
}

void execute(char *cmd) {
  if (strcmp(cmd, "exit") == 0) {
    exit(0);
  } else if (strcmp(cmd, "cd") == 0) {
    if (args[1] == NULL) {
      fprintf(stderr, "cd: no argument\n");
      return;
    }
    if (chdir(args[1]) != 0) {
      fprintf(stderr, "cd: %s: no such directory\n", args[1]);
      return;
    }
  } else {
    int pid = fork();
    if (pid == 0) {
      execvp(cmd, args);
      fprintf(stderr, "%s: command not found\n", cmd);
      exit(1);
    } else {
      int status;
      waitpid(pid, &status, 0);
    }
  }
}

int main() {
  char line[MAX_LINE];
  while (1) {
    printf("$$ ");
    fgets(line, MAX_LINE, stdin);
    parse_line(line);
    execute(args[0]);
  }
  return 0;
}