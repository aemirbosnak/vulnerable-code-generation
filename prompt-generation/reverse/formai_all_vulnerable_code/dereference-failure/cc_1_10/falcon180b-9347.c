//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        fprintf(stderr, "Error: Empty command\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Error: %s not found\n", tokens[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int background = 0;
    int exit_shell = 0;

    while (!exit_shell) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        tokens = split_string(input);

        if (tokens[0] == NULL) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(tokens[0], "bg") == 0 && tokens[1]!= NULL) {
            int pid = atoi(tokens[1]);
            if (kill(-pid, SIGCONT) == -1) {
                fprintf(stderr, "Error: %s not found\n", tokens[1]);
            }
        } else if (strcmp(tokens[0], "jobs") == 0) {
            system("ps aux");
        } else {
            background = execute_command(tokens);
        }
    }

    return 0;
}