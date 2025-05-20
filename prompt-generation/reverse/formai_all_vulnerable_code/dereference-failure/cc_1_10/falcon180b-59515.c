//Falcon-180B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **args = NULL;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        count++;
        args = realloc(args, sizeof(char *) * count);
        args[count - 1] = token;
        token = strtok(NULL, DELIM);
    }

    args[count - 1] = NULL;
    return args;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    pid_t child_pid;
    int status;
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(1);
        } else if (child_pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}