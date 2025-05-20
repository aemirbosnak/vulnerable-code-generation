//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **command);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **command;
    int status;

    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        command = split_string(input);
        status = execute_command(command);

        if (status == 1) {
            printf("Child process terminated abnormally.\n");
        }
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **command) {
    pid_t pid;
    int status;

    if (command[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(command[0], command) == -1) {
            printf("Command not found.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}