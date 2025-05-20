//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_ARG_LENGTH 1024

char* get_input() {
    char* input = (char*)malloc(MAX_ARG_LENGTH * sizeof(char));
    printf("> ");
    fgets(input, MAX_ARG_LENGTH, stdin);
    return input;
}

void parse_input(char* input, char** args) {
    char* token;
    int i = 0;
    while ((token = strtok(input, " ")) != NULL) {
        args[i] = token;
        input = NULL;
        i++;
    }
    args[i] = NULL;
}

void execute_command(char** args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
    } else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            perror("execvp() failed");
            exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL);
    }
}

int main() {
    while (1) {
        char* input = get_input();
        char* args[MAX_ARGS];
        parse_input(input, args);
        execute_command(args);
        free(input);
    }
    return 0;
}