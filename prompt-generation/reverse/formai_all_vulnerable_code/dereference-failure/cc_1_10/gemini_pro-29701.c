//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_ARGS 16
#define MAX_LINE 256

char* args[MAX_ARGS];
char line[MAX_LINE];

void parse(char* s) {
  int i = 0;
  char* token = strtok(s, " ");
  while (token && i < MAX_ARGS) {
    args[i++] = token;
    token = strtok(NULL, " ");
  }
  args[i] = NULL;
}

void execute(int bg) {
  int pid;
  if ((pid = fork()) == 0) {
    if (execvp(args[0], args) < 0) {
      perror(args[0]);
      exit(1);
    }
  } else if (pid < 0) {
    perror("fork");
  } else if (!bg) {
    int status;
    waitpid(pid, &status, 0);
  }
}

int main() {
  int running = 1;
  char* cwd;
  while (running) {
    cwd = getcwd(NULL, 0);
    printf("%s$ ", cwd);
    free(cwd);
    fgets(line, MAX_LINE, stdin);
    if (strlen(line) > 0) {
      line[strlen(line) - 1] = '\0';
      parse(line);
      if (!strcmp(args[0], "exit")) {
        running = 0;
      } else if (!strcmp(args[0], "cd")) {
        if (args[1]) {
          if (chdir(args[1]) < 0) {
            perror(args[1]);
          }
        } else {
          chdir(getenv("HOME"));
        }
      } else if (!strcmp(args[0], "jobs")) {
        int status;
        for (int i = 0;; i++) {
          pid_t pid = waitpid(-1, &status, WNOHANG);
          if (pid == 0) {
            break;
          } else if (pid < 0) {
            perror("waitpid");
            break;
          } else {
            printf("%d %s ", pid, WIFEXITED(status) ? "exited" : "running");
          }
        }
        puts("");
      } else if (!strcmp(args[0], "fg")) {
        int status;
        if (args[1]) {
          waitpid(atoi(args[1]), &status, 0);
        } else {
          waitpid(-1, &status, 0);
        }
      } else if (!strcmp(args[0], "kill")) {
        if (args[1] && args[2]) {
          if (kill(atoi(args[1]), atoi(args[2])) < 0) {
            perror("kill");
          }
        }
      } else {
        int bg = 0;
        if (strcmp(args[strlen(args) - 1], "&") == 0) {
          bg = 1;
          args[strlen(args) - 1] = NULL;
        }
        execute(bg);
      }
    }
  }
  return 0;
}