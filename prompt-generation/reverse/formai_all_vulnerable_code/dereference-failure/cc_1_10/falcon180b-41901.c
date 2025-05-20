//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Turing
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
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));

    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("alan@turing:~$ ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);

    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Error");
        exit(1);
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