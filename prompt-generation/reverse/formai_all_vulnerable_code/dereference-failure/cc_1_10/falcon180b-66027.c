//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int buf_size = strlen(command) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, command);

    char **tokens = malloc(sizeof(char *));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);

    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[num_tokens] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == 0) {
        setsid();
    }

    return pid;
}

int execute_command(char **tokens) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **tokens = split_command(input);
        execute_command(tokens);
    }

    return 0;
}