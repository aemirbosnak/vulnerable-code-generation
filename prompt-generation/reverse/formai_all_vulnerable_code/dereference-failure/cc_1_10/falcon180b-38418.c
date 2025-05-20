//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
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

    char *copy = strdup(str);
    token = strtok(copy, DELIM);

    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, DELIM);
    }

    tokens = malloc((words + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    bufsize = 0;
    words = 0;
    copy = strdup(str);
    token = strtok(copy, DELIM);

    while (token!= NULL) {
        tokens[words] = strdup(token);
        bufsize += strlen(tokens[words]) + 1;
        words++;
        token = strtok(NULL, DELIM);
    }

    tokens[words] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "Expected argument for \"cd\"\n");
            } else {
                if (chdir(args[1]) == -1) {
                    perror("chdir");
                }
            }
        } else {
            pid = fork();

            if (pid == 0) {
                execvp(args[0], args);
            } else if (pid == -1) {
                perror("fork");
            }

            waitpid(pid, NULL, 0);
        }

        for (int i = 0; args[i]!= NULL; i++) {
            free(args[i]);
        }
        free(args);
    }

    return 0;
}