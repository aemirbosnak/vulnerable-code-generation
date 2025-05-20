//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LEN 1024
#define SPACE_DELIM " \t\r\n\a"

void execute(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        if (waitpid(pid, &status, WUNTRACED) == -1) {
            perror("waitpid failed");
        }
    }
}

char *read_line(void) {
    char *line = malloc(MAX_LEN * sizeof(char));
    if (!line) {
        fprintf(stderr, "failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    fgets(line, MAX_LEN, stdin);
    return line;
}

char **parse_args(char *line) {
    int max_tokens = 64;
    int index = 0;
    char **tokens = malloc(max_tokens * sizeof(char*));
    if (!tokens) {
        fprintf(stderr, "failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    char *token = strtok(line, SPACE_DELIM);
    while (token != NULL) {
      tokens[index] = token;
      index++;
      if (index >= max_tokens) {
          max_tokens += 64;
          tokens = realloc(tokens, max_tokens * sizeof(char*));
          if (!tokens) {
              fprintf(stderr, "failed to allocate memory\n");
              exit(EXIT_FAILURE);
          }
      }
      token = strtok(NULL, SPACE_DELIM);
    }
    tokens[index] = NULL;
    return tokens;
}

int main(int argc, char *argv[]) {
    char *line;
    char **args;
    int status = 1;

    while (status) {
        printf("$ ");
        line = read_line();
        args = parse_args(line);
        execute(args);

        free(line);
        free(args);
    }

    return EXIT_SUCCESS;
}