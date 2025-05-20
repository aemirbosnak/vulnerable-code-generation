//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
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
    char *p = strtok_r(copy, DELIM, &p);

    while (p!= NULL) {
        words++;
        bufsize += strlen(p) + 1;
        p = strtok_r(NULL, DELIM, &p);
    }

    tokens = (char **)malloc((words + 1) * sizeof(char *));

    p = strtok_r(copy, DELIM, &p);
    int i = 0;
    while (p!= NULL) {
        tokens[i] = p;
        i++;
        p = strtok_r(NULL, DELIM, &p);
    }
    tokens[i] = NULL;

    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // Child Process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "%s: Command not found\n", args[0]);
            return 1;
        }
    } else {
        // Parent Process
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args = NULL;

    printf("Welcome to the Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        launch_shell(args);
    }

    return 0;
}