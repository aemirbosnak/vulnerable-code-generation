//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE 1024

static char **args;

static void init_args() {
    args = malloc(sizeof(char *) * MAX_ARGS);
    for (int i = 0; i < MAX_ARGS; i++) {
        args[i] = NULL;
    }
}

static void free_args() {
    for (int i = 0; i < MAX_ARGS; i++) {
        free(args[i]);
    }
    free(args);
}

static void parse_args(char *line) {
    int i = 0;
    char *token = strtok(line, " ");
    while (token != NULL && i < MAX_ARGS) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
}

static int execute_command() {
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        execvp(args[0], args);
        // if execvp returns, it means an error occurred
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        // parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    } else {
        // fork failed
        perror("fork");
        return -1;
    }
}

int main() {
    char line[MAX_LINE];
    init_args();
    while (1) {
        printf("shell> ");
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break;
        }
        line[strlen(line) - 1] = '\0';  // remove newline
        parse_args(line);
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
        execute_command();
    }
    free_args();
    return 0;
}