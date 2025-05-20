//Falcon-180B DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **tokens = NULL;
    int count = 0;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count - 1] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);
    status = execute_command(args);

    if (WIFEXITED(status)) {
        printf("Command exited with status %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Command terminated by signal %d\n", WTERMSIG(status));
    } else {
        printf("Unknown exit status\n");
    }

    return 0;
}