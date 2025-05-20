//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **tokens = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH + 1));
    int count = 0;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);

    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}

int main() {
    while (1) {
        launch_shell();
    }

    return 0;
}