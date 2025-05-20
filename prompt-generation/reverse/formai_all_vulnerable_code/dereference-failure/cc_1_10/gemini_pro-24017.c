//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t line_length = 0;
  ssize_t read_bytes;

  while (1) {
    printf("$ ");
    read_bytes = getline(&line, &line_length, stdin);
    if (read_bytes == -1) {
      perror("getline");
      exit(EXIT_FAILURE);
    }

    line[strcspn(line, "\n")] = '\0';

    if (strcmp(line, "exit") == 0) {
      break;
    }

    char *args[MAX_ARGS];
    int num_args = 0;

    char *token = strtok(line, " ");
    while (token != NULL) {
      args[num_args++] = token;
      token = strtok(NULL, " ");
    }

    pid_t pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      execvp(args[0], args);
      perror("execvp");
      exit(EXIT_FAILURE);
    } else {
      int status;
      waitpid(pid, &status, 0);
      if (WIFEXITED(status)) {
        printf("Process exited with status %d\n", WEXITSTATUS(status));
      } else if (WIFSIGNALED(status)) {
        printf("Process was terminated by signal %d\n", WTERMSIG(status));
      }
    }
  }

  free(line);
  return EXIT_SUCCESS;
}