//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **arguments;

void print_prompt() {
    printf("> ");
}

void execute_command(char *command) {
    int i;
    pid_t pid;
    int status;

    arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    for (i = 0; i < MAX_ARGUMENTS; i++) {
        arguments[i] = NULL;
    }

    i = 0;
    char *token = strtok(command, " ");

    while (token!= NULL) {
        arguments[i] = token;
        i++;

        if (i >= MAX_ARGUMENTS) {
            break;
        }

        token = strtok(NULL, " ");
    }

    arguments[i] = NULL;

    pid = fork();

    if (pid == 0) {
        if (arguments[0] == NULL) {
            fprintf(stderr, "No command specified.\n");
            exit(1);
        }

        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: fork() failed.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        print_prompt();
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        execute_command(input);
    }

    return 0;
}