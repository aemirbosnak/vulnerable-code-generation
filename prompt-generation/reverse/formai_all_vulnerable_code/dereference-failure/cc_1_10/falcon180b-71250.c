//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }

    for (int i = 0; args[i]!= NULL; i++) {
        free(args[i]);
    }
    free(args);

    return 0;
}

int main() {
    printf("Welcome to the Medieval Shell!\n");

    while (1) {
        launch_shell();
    }

    return 0;
}