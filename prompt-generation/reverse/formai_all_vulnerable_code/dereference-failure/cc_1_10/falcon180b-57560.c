//Falcon-180B DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        arguments[argc] = token;
        argc++;

        if (argc >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            exit(1);
        }

        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

void loop(char **commands) {
    while (1) {
        printf("> ");
        fflush(stdout);

        char input[1024];
        fgets(input, sizeof(input), stdin);

        char *command = strtok(input, "\n");
        char *arguments[MAX_ARGUMENTS];

        if (command == NULL) {
            continue;
        }

        int argc = split_command(command);
        strcpy(arguments[argc - 1], input);
        arguments[argc] = NULL;

        int status = execute_command(arguments);

        if (status == 0) {
            printf("\n");
        }
    }
}

int main(int argc, char **argv) {
    char **commands = malloc(MAX_COMMANDS * sizeof(char *));

    commands[0] = "ls";
    commands[1] = "cd";
    commands[2] = "pwd";
    commands[3] = "exit";

    loop(commands);

    return 0;
}