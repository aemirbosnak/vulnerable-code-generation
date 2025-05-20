//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

char *split_input(char *input) {
    int len = strlen(input);
    input[len - 1] = '\0';
    return input;
}

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Command execution failed.\n");
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed while executing command.\n");
        exit(1);
    } else {
        wait(NULL);
    }
}

void parse_input(char *input) {
    char *args[64];
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    execute_command(args);
}

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf(">> ");
        fgets(input, MAX_INPUT, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        parse_input(split_input(input));
    }

    return 0;
}