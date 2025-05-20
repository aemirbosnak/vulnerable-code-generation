//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string, int *count) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);
    int i = 0;

    while (token!= NULL && i < MAX_ARGUMENTS) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, DELIM);
    }

    *count = i;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == 0) {
        return pid;
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return 1;
    }

    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1])!= 0) {
            perror("chdir");
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        }

        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int count;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        tokens = split_string(input, &count);
        if (execute_command(tokens) == 0) {
            break;
        }
    }

    return 0;
}