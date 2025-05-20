//Falcon-180B DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(sizeof(char *) * MAX_ARGUMENTS);

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        if (argc >= MAX_ARGUMENTS - 1) {
            fprintf(stderr, "Error: Too many arguments.\n");
            exit(1);
        }
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Enter your command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    arguments = split_command(input);

    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        fprintf(stderr, "Error: %s not found.\n", arguments[0]);
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}