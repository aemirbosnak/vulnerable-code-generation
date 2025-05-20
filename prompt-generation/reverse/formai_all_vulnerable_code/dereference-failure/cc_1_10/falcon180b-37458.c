//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
pid_t fork();
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Peaceful Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL)
            continue;

        pid_t pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            printf("Error forking process.\n");
        }

        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));

    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens = realloc(tokens, sizeof(char *) * ++count);
        tokens[count - 1] = token;

        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    }

    return 0;
}