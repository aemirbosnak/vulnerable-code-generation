//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int bufsize = MAX_COMMAND_LENGTH;
    int words = 0;
    char **tokens = malloc(sizeof(char *) * bufsize);
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        tokens[words] = token;
        words++;

        if (words == bufsize) {
            bufsize += MAX_COMMAND_LENGTH;
            tokens = realloc(tokens, sizeof(char *) * bufsize);
        }

        token = strtok(NULL, DELIM);
    }

    tokens[words] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return 1;

    if (strcmp(tokens[0], "exit") == 0)
        return 0;

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 1;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    printf("Welcome to the Artistic Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        tokens = split_command(input);
        execute_command(tokens);

        free(tokens);
    }

    return 0;
}