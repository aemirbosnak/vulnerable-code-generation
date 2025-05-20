//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Welcome to the Funny Shell!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        args = split_string(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}