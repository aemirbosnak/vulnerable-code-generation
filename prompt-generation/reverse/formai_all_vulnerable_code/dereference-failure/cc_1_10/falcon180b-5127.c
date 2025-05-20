//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input);
        execute_command(arguments);
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(sizeof(char *) * MAX_ARGUMENTS);
    char *token;

    for (token = strtok(string, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        tokens[count] = token;
        count++;

        if (count == MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            exit(1);
        }
    }

    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    if (strcmp(arguments[0], "exit") == 0) {
        return 0;
    } else if (strcmp(arguments[0], "cd") == 0) {
        if (arguments[1] == NULL) {
            printf("Expected argument for \"cd\" command.\n");
        } else {
            if (chdir(arguments[1])!= 0) {
                perror("Error");
            }
        }
    } else if (strcmp(arguments[0], "pwd") == 0) {
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
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            execvp(arguments[0], arguments);
            perror("Error");
            exit(1);
        }
    }

    return 1;
}