//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;

    for (token = strtok(str, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        words++;
    }

    tokens = malloc((words + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    bufsize = strlen(str) + 1;
    strcpy(tokens[0] = malloc(bufsize), str);

    for (int i = 1; i < words; i++) {
        tokens[i] = malloc(bufsize);
        strcpy(tokens[i], strtok(NULL, DELIM));
    }

    tokens[words] = NULL;

    return tokens;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL)
            continue;

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
            wait(NULL);
        }
    }

    return 0;
}