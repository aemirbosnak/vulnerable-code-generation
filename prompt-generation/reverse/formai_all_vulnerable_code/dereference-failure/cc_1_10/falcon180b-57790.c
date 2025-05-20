//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define DELIM " \t\r\n\a"
#define MAX_COMMAND_SIZE 4096

char **split_line(char *line) {
    char **tokens = malloc(sizeof(char *) * (MAX_LINE_SIZE / 2 + 1));
    int count = 0;
    char *token = strtok(line, DELIM);
    while (token!= NULL) {
        if (count >= MAX_LINE_SIZE / 2) {
            break;
        }
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_LINE_SIZE];
    char **tokens;
    int background = 0;
    int exit_shell = 0;

    while (!exit_shell) {
        printf("> ");
        if (fgets(input, MAX_LINE_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading input\n");
            exit(1);
        }
        input[strcspn(input, "\n")] = '\0';

        tokens = split_line(input);

        if (tokens[0] == NULL) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(tokens[0], "bg") == 0 && tokens[1]!= NULL) {
            background = 1;
        } else if (strcmp(tokens[0], "fg") == 0 && tokens[1]!= NULL) {
            background = 0;
        } else if (background) {
            if (execute_command(tokens) == -1) {
                fprintf(stderr, "Failed to execute command\n");
            }
        } else {
            if (execute_command(tokens) == -1) {
                fprintf(stderr, "Failed to execute command\n");
            }
        }
    }

    return 0;
}