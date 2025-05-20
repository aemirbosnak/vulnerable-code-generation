//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_LINE 80
#define MAX_ARGS 10
#define DELIM " \t\r\n\a"

char **split(char *line) {
    char **args = malloc(MAX_ARGS * sizeof(char*));
    int count = 0;
    char *token = strtok(line, DELIM);
    while (token!= NULL) {
        args[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;
    return args;
}

int main() {
    char line[MAX_LINE];
    char **args;
    pid_t pid;
    int status;

    printf("Welcome to the Basic Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE, stdin);
        args = split(line);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                printf("Error: Directory not specified\n");
            } else {
                if (chdir(args[1])!= 0) {
                    perror("Error");
                }
            }
        } else if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                printf("%s\n", cwd);
            } else {
                perror("Error");
            }
        } else {
            pid = fork();

            if (pid == -1) {
                perror("Error");
            } else if (pid == 0) {
                if (execvp(args[0], args) == -1) {
                    perror("Error");
                }
            } else {
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}