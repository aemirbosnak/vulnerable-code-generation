//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            bufsize++;
        }
        str++;
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));

    str = strtok_r(str, DELIM, &token);
    while (str!= NULL) {
        tokens[i] = strdup(str);
        i++;
        str = strtok_r(NULL, DELIM, &token);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        return 0;
    } else {
        return pid;
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Surprised Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }

        free(args);
    }

    return 0;
}