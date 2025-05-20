//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split_string(char *string);
pid_t fork();
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Surprise Shell\n");

    while (TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL)
            continue;

        pid_t pid = fork();

        if (pid == -1) {
            printf("Fork failed\n");
            exit(1);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            execute_command(args);
            exit(0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    char **tokens = malloc(sizeof(char *));
    int count = 0;
    char *token;

    token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (args[0][0]!= '/') {
            char *path = getenv("PATH");
            char *new_args[3];

            new_args[0] = "/bin/sh";
            new_args[1] = "-c";
            new_args[2] = args[0];

            execvp(new_args[0], new_args);
        } else {
            execvp(args[0], args);
        }

        exit(0);
    }

    return 0;
}