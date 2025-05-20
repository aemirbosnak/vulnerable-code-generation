//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int bufsize = MAX_COMMAND_LENGTH, position = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        tokens = realloc(tokens, sizeof(char *) * ++position);
        tokens[position - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

pid_t launch_shell(char **tokens) {
    pid_t pid;
    if (tokens[0] == NULL)
        return -1;

    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1]!= NULL)
            chdir(tokens[1]);
        else
            fprintf(stderr, "Expected argument to \"cd\"\n");
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            perror("Error");
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return pid;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **tokens = split_command(input);
        pid_t shell_pid = launch_shell(tokens);

        if (shell_pid == -1)
            break;

        free(tokens);
    }

    return 0;
}