//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

char **tokenize(char *line) {
    char **tokens = malloc(BUFFER_SIZE * sizeof(char *));
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        char **tokens = tokenize(line);

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        } else if (strcmp(tokens[0], "cd") == 0) {
            if (chdir(tokens[1]) != 0) {
                perror("Error changing directory");
            }
        } else {
            pid_t pid = fork();
            if (pid < 0) {
                perror("Error forking");
            } else if (pid == 0) {
                execvp(tokens[0], tokens);
                perror("Error executing command");
                exit(1);
            } else {
                int status;
                waitpid(pid, &status, 0);
            }
        }

        free(tokens);
    }

    free(line);
    return 0;
}