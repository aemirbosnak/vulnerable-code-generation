//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));

    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;

    return tokens;
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("Shell> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    while (1) {
        launch_shell();
    }

    return 0;
}