//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        return getpid();
    } else {
        int status;
        waitpid(pid, &status, 0);
        return pid;
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **command;
    pid_t pid;

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        command = split_string(input);

        if (command[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == 0) {
            if (execvp(command[0], command) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}