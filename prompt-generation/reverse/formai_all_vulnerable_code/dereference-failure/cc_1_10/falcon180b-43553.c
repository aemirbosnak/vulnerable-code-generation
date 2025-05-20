//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_COMMANDS * sizeof(char *));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int main() {
    char input[1024];
    char **args;
    pid_t pid;
    int status;

    printf("Welcome to the Visionary Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, 1024, stdin);
        args = split_string(input);

        if (args[0] == NULL)
            continue;

        pid = fork();

        if (pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("Command not found.\n");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}