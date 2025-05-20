//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

char* read_input() {
    char* input = malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(input, MAX_LINE_LENGTH, stdin);
    return input;
}

char** parse_input(const char* input) {
    char** args = malloc(MAX_ARGS * sizeof(char*));
    char* arg = strtok((char*) input, " \n");
    int i = 0;
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " \n");
    }
    args[i] = NULL;
    return args;
}

void execute_command(char** args) {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            printf("Command not found\n");
            exit(1);
        }
    } else {
        wait(NULL);
    }
}

int main(void) {
    char* input;
    char** args;

    while (1) {
        printf("> ");
        input = read_input();
        args = parse_input(input);
        execute_command(args);
        free(input);
        free(args);
    }

    return 0;
}