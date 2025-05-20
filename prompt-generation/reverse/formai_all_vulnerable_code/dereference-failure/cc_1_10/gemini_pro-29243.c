//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

char *prompt = "$ ";
char *history[MAX_LINE];
int history_idx = 0;

void execute_command(char **args) {
  pid_t pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  } else {
    int status;
    waitpid(pid, &status, 0);
  }
}

void parse_command(char *line, char **args) {
  char *token = strtok(line, " ");
  int i = 0;
  while (token != NULL) {
    args[i++] = token;
    token = strtok(NULL, " ");
  }
  args[i] = NULL;
}

void print_history() {
  for (int i = 0; i < history_idx; i++) {
    printf("%d: %s", i + 1, history[i]);
  }
}

int main() {
  char line[MAX_LINE];
  char *args[MAX_ARGS];
  while (1) {
    printf("%s", prompt);
    fgets(line, MAX_LINE, stdin);
    if (strcmp(line, "exit") == 0) {
      break;
    } else if (strcmp(line, "history") == 0) {
      print_history();
    } else {
      history[history_idx++] = strdup(line);
      parse_command(line, args);
      execute_command(args);
    }
  }
  return 0;
}