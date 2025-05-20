//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_string(input);
        int status = execute_command(args);

        if (status == 1) {
            printf("Child process terminated abnormally\n");
        }

        free(args);
    }

    return 0;
}

char **split_string(char *str) {
    int count = 0;
    char *token;
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));

    token = strtok(str, DELIM);
    while (token!= NULL) {
        args[count++] = token;
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Command not found\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}