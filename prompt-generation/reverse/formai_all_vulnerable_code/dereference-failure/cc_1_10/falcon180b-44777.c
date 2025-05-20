//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *input);
int execute_command(char **args);
void loop(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
        char **args = split_string(input);
        execute_command(args);
    }
    return 0;
}

char **split_string(char *input) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    int argc = 0;
    char *token = strtok(input, DELIM);
    while (token!= NULL) {
        args[argc] = token;
        argc++;
        if (argc >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;
    return args;
}

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error: Command not found.\n");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
        char **args = split_string(input);
        execute_command(args);
    }
}